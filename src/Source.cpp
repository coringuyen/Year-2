//#include "MyApplication.h" 
#include <vector>
#include "stdio.h"
#include <gl_core_4_4.h>
#include <Gizmos.h>
#include <GLFW/glfw3.h> 
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <iostream>
#include "MyApplication.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

struct Vertex { vec4 position; vec4 colour; };

unsigned int m_VAO; 
unsigned int  m_VBO; 
unsigned int m_IBO;
unsigned int m_programID;
unsigned int m_shader;

void generateGrid(unsigned int rows, unsigned int cols)
{
	Vertex* aoVertices = new Vertex[rows * cols];  
	for (unsigned int r = 0; r < rows; ++r) 
		for (unsigned int c = 0; c < cols; ++c) 
		{
			aoVertices[r * cols + c].position = vec4((float)c, 0, (float)r, 1);
			// create some arbitrary colour based off something                  
			// that might not be related to tiling a texture                 
			vec3 colour = vec3( sinf( (c / (float)(cols - 1)) * ( r / (float)(rows - 1))) );       
			aoVertices[ r * cols + c ].colour = vec4( colour, 1 );   
		}

	unsigned int* auiIndices = new unsigned int[(rows - 1) * (cols - 1) * 6];
	unsigned int index = 0; for (unsigned int r = 0; r < (rows - 1); ++r) 
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

	glGenBuffers(1, &m_VBO); 
	glGenBuffers(1, &m_IBO);
	glGenVertexArrays(1, &m_VAO);

	mat4 m_view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 m_projection = glm::perspective(glm::pi<float>()*0.25f, 16 / 9.f, 0.1f, 1000.f);
	mat4 m_projectionViewMatrix = m_projection * m_view;

	glUseProgram(m_programID);
	unsigned int projectionViewUniform = glGetUniformLocation(m_programID, "ProjectionView");
	glUniformMatrix4fv(projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix));

	glBindVertexArray(m_VAO);
	unsigned int indexCount = (rows - 1) * (cols - 1) * 6;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ARRAY_BUFFER, (rows * cols) * sizeof(Vertex), aoVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (rows - 1) * (cols - 1) * 6 * sizeof(unsigned int), auiIndices, GL_STATIC_DRAW); 

	glBindAttribLocation(0, m_shader, "Position");
	glBindAttribLocation(1, m_shader, "Colour");

	glEnableVertexAttribArray(0); 
	glEnableVertexAttribArray(1); 
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); 
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(vec4)));
	
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// we�ll do more here soon!  
	delete[] aoVertices; 
}

void createShader()
{
	const char* vsSource = "#version 410\n \     layout(location=0) in vec4 Position; \     layout(location=1) in vec4 Colour; \     out vec4 vColour; \     uniform mat4 ProjectionView; \     void main() { vColour = Colour; gl_Position = ProjectionView * Position;}";

	const char* fsSource = "#version 410\n \     in vec4 vColour; \     out vec4 FragColor; \     void main() { FragColor = vColour; }";   

	int success = GL_FALSE;  
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0); 
	glCompileShader(vertexShader);  
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0); 
	glCompileShader(fragmentShader);    

	m_programID = glCreateProgram(); 
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader); 
	glLinkProgram(m_programID);   
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

void main()
{
	Application *theApp = new Application();

	if (theApp->startup() == true)
	{
		while (theApp->update() == true)
		{
			//theApp->draw();
			createShader();
			generateGrid(5, 5);
		}
		theApp->shutdown();
	}

	delete theApp;
}