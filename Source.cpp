#include "stdio.h"
#include <gl_core_4_4.h> 
#include <GLFW/glfw3.h> 
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
using glm::vec3;
using glm::vec4;
using glm::mat4;

int main()
{
	if (glfwInit() == false)
		return -1;

	GLFWwindow * window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}
	//make the glfw window 
	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf_s("GL: %i.%i\n", major, minor);

	//initialize all of our gizmos and set up the virtual camera
	Gizmos::create();
	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f,
		16 / 9.f, 0.1f, 1000.f);	/*
	The Gizmo class works by allowing us to add geometric shapes and lines to it. We can then draw
	anything that has been added to it. The shapes remain until we call Gizmos::clear() which removes
	all shapes and lines, and we can add new ones.
	*/

	
	glClearColor(0.25f, 0.25f, 0.25f, 1);//set the clear color
	glEnable(GL_DEPTH_TEST); // enables the depth buffer	
	
	
	
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//GL_COLOR_BUFFER_BIT informs OpenGL to wipe the back-buffer colours clean.
		//GL_DEPTH_BUFFER_BIT informs it to clear the distance to the closest pixels.
		//If we didn’t do this then OpenGL may think the image of the last frame is still there
		//and our new visuals may not display
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear the backbuffer
		// our game logic and update code goes here!
		// so does our render code!
		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));

		vec4 white(1);
		vec4 black(0, 0, 0, 1);

		for (int i = 0; i < 21; ++i)
		{
			Gizmos::addLine(vec3(-10 + i, 0, 10), vec3(-10 + i, 0, -10), i == 10 ? white : black);
			Gizmos::addLine(vec3(10, 0, -10 + i), vec3(-10, 0, -10 + i), i == 10 ? white : black);
		}

		Gizmos::draw(projection * view);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Gizmos::destroy();
	// the rest of our code goes here!
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void Update()
{

}