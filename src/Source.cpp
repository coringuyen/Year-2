#include <vector>
#include "stdio.h"
#include <gl_core_4_4.h>
#include <Gizmos.h>
#include <GLFW/glfw3.h> 
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <iostream>
#include "MyApplication.h"
#include <iostream>
#include <fstream>

#include "tiny_obj_loader.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

struct Vertex { vec4 position; vec4 colour; };

unsigned int m_VAO; 
unsigned int m_VBO; 
unsigned int m_IBO;
unsigned int m_programID;
GLFWwindow *window;
mat4 m_projectionViewMatrix;

struct OpenGLInfo
{
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	unsigned int m_index_count;
};

std::vector<OpenGLInfo> m_gl_info;

void generateGrid(unsigned int rows, unsigned int cols)
{
	Vertex *aoVertices = new Vertex[rows * cols];  
	for (unsigned int r = 0; r < rows; ++r) 
		for (unsigned int c = 0; c < cols; ++c) 
		{
			aoVertices[r * cols + c].position = vec4((float)c, 0, (float)r, 1);
			               
			vec3 colour = vec3( sinf( (c / (float)(cols - 1)) * ( r / (float)(rows - 1))) );       
			aoVertices[ r * cols + c ].colour = vec4( 1, 0.8f, 0.3f, 1 );   
		}

	unsigned int *auiIndices = new unsigned int[(rows - 1) * (cols - 1) * 6];
	unsigned int index = 0; 
	for (unsigned int r = 0; r < (rows - 1); ++r) 
		for (unsigned int c = 0; c < (cols - 1); ++c) 
		{   
			// triangle 1   
			auiIndices[ index++ ] = r * cols + c;   
			auiIndices[ index++ ] = (r + 1) * cols + c;   
			auiIndices[ index++ ] = (r + 1) * cols + (c + 1);

			// triangle 2   
			auiIndices[ index++ ] = r * cols + c;   
			auiIndices[ index++ ] = (r + 1) * cols + (c + 1);   
			auiIndices[ index++ ] = r * cols + (c + 1);  
		}
	// generate buffers with reference
	glGenBuffers(1, &m_VBO); 
	glGenBuffers(1, &m_IBO);

	// generate array
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);	

	// put the buffers in the graphic card which is where the generate buffer had created
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	// how much space the array will be use
	glBufferData(GL_ARRAY_BUFFER, (rows * cols) * sizeof(Vertex), aoVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (rows - 1) * (cols - 1) * 6 * sizeof(unsigned int), auiIndices, GL_STATIC_DRAW); 

	glEnableVertexAttribArray(0); 
	glEnableVertexAttribArray(1); 
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(vec4)));  

	// unbind
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_programID);
	unsigned int projectionViewUniform = glGetUniformLocation(m_programID, "ProjectionView");
	glUniformMatrix4fv(projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix));

	glBindVertexArray(m_VAO);
	unsigned int indexCount = (rows - 1) * (cols - 1) * 6;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);


	// we�ll do more here soon!  
	delete[] aoVertices; 
	delete[] auiIndices;
}

std::string readFile(std::string path)
{
	std::string data;
	std::string storeData;
	std::ifstream file;

	file.open(path);

	if (file.is_open())
	{
		while (std::getline(file, data))
		{
			storeData = storeData + data + "\n";
		}
		file.close();
	}
	else
	{
		std::cout << "File not open" << std::endl;
	}

	return storeData;
}

void createShader()
{
	std::string VertexShader = readFile("VertexShader.txt");
	std::string FragmentShader = readFile("FragmentShader.txt");

	const char* vsSource = VertexShader.c_str();
	const char* fsSource = FragmentShader.c_str();
	 
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0); 
	glCompileShader(vertexShader);  
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0); 
	glCompileShader(fragmentShader);    

	m_programID = glCreateProgram(); 
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader); 
	glBindAttribLocation(0, m_programID, "Position");
	glBindAttribLocation(1, m_programID, "Colour");
	glLinkProgram(m_programID);  

	int success = GL_FALSE; 
	glGetProgramiv(m_programID, GL_LINK_STATUS, &success); 
	if (success == GL_FALSE) 
	{ 
		int infoLogLength = 0;  
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);  

		char* infoLog = new char[infoLogLength];     
		glGetProgramInfoLog(m_programID, infoLogLength, 0, infoLog);  
		printf("Error: Failed to link shader program!\n");  
		printf("%s\n", infoLog);  

		delete[] infoLog; 
	}
	
	glDeleteShader(fragmentShader); 
	glDeleteShader(vertexShader);
}

int createWindow()
{
	if (glfwInit() == false)
		return -1;

	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	//the rest of our code goes here!
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	//testing what version of OpenGL we are running
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf_s("GL: %i.%i\n", major, minor);

	mat4 m_view = glm::lookAt(vec3(10, 6, 40), vec3(0), vec3(0, 1, 0));
	mat4 m_projection = glm::perspective(glm::pi<float>()*0.25f, 16 / 9.f, 0.1f, 1000.f);
	m_projectionViewMatrix = m_projection * m_view;

	return 0;
}

void createOpenGLBuffers(std::vector<tinyobj::shape_t> &shapes)
{
	m_gl_info.resize(shapes.size());

	for (unsigned int mesh_index = 0; mesh_index < shapes.size(); ++mesh_index)
	{
		glGenVertexArrays(1, &m_gl_info[mesh_index].m_VAO);
		glGenBuffers(1, &m_gl_info[mesh_index].m_VBO);
		glGenBuffers(1, &m_gl_info[mesh_index].m_IBO);
		glBindVertexArray(m_gl_info[mesh_index].m_VAO);

		unsigned int float_count = shapes[mesh_index].mesh.positions.size();
		float_count += shapes[mesh_index].mesh.normals.size();
		float_count += shapes[mesh_index].mesh.texcoords.size();

		std::vector<float> vertex_data;
		vertex_data.reserve(float_count);

		vertex_data.insert(vertex_data.end(),
			shapes[mesh_index].mesh.positions.begin(),
			shapes[mesh_index].mesh.positions.end());

		vertex_data.insert(vertex_data.end(),
			shapes[mesh_index].mesh.normals.begin(),
			shapes[mesh_index].mesh.normals.end());

		m_gl_info[mesh_index].m_index_count =
			shapes[mesh_index].mesh.indices.size();

		glBindBuffer(GL_ARRAY_BUFFER, m_gl_info[mesh_index].m_VBO);
		glBufferData(GL_ARRAY_BUFFER,
			vertex_data.size() * sizeof(float),
			vertex_data.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_gl_info[mesh_index].m_IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			shapes[mesh_index].mesh.indices.size() * sizeof(unsigned int),
			shapes[mesh_index].mesh.indices.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0); //position
		glEnableVertexAttribArray(1); //normal data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 0,
			(void*)(sizeof(float)*shapes[mesh_index].mesh.positions.size()));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		
	}

	glUseProgram(m_programID);
	int view_proj_uniform = glGetUniformLocation(m_programID, "ProjectionView");
	glUniformMatrix4fv(view_proj_uniform, 1, GL_FALSE, glm::value_ptr(m_projectionViewMatrix));

	for (unsigned int i = 0; i < m_gl_info.size(); ++i)
	{
		glBindVertexArray(m_gl_info[i].m_VAO);
		glDrawElements(GL_TRIANGLES, m_gl_info[i].m_index_count, GL_UNSIGNED_INT, 0);
	}
}

//void main()
//{
//	Application *theApp = new Application();
//
//	if (theApp->startup() == true)
//	{
//		while (theApp->update() == true)
//		{
//			//theApp->draw();
//			createShader();
//			generateGrid(5, 5);
//		}
//		theApp->shutdown();
//	}
//
//	delete theApp;
//}

int main()
{
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;
	tinyobj::LoadObj(shapes, materials, err, "./models/buddha.obj");

	createWindow();
	createShader();

	/*createOpenGLBuffers(shapes);
	glfwSwapBuffers(window);
	glfwPollEvents();*/


	/*while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{*///}	

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//generateGrid(4, 4);

	createOpenGLBuffers(shapes);

	glfwSwapBuffers(window);
	glfwPollEvents();
	

	system("Pause");
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}