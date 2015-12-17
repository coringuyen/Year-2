#include "stdio.h"
#include <gl_core_4_4.h> 
#include <GLFW/glfw3.h> 
#include <Gizmos.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;

int x = 0;
int y = 2;
//#include "MyApplication.h"

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

	//initialises all of our gizmos for perspective view
	Gizmos::create();
	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>()*0.25f, 16 / 9.f, 0.1f, 1000.f);


	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		 // game logic and update code goes here!
		 //so does our render code!
		glClearColor(0.25f, 0.25f, 0.25f, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//GL_COLOR_BUFFER_BIT tells OpenGL to wipe the back-buffer colors
			//GL_DEPTH_BUFFER_BIT clear the distance to the closest pixel. We do this that openGL loads are new images from frame to fram

		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));

		vec4 white(1);
		vec4 black(0, 0, 0, 1);

		for (int i = 0; i < 21; i++)
		{
			Gizmos::addLine(vec3(-10 + i, 0, 10),
							vec3(-10 + i, 0, -10),
							i == 10 ? white : black);

			Gizmos::addLine(vec3(10, 0, -10 + i),
							vec3(-10, 0, -10 + i),
							i == 10 ? white : black);
		}

		
		if (x <= 0 && y <= 0)
		{
			x--;
			y++;
		}
		if (x <= 0 && y >= 0)
		{
			x++;
			y++;
		}
		if (y >= 0 && x >= 0)
		{
			y--;
			x++;
		}
		if (y <= 0 && x >= 0)
		{
			y--;
			x--;
		}
		//sun
		Gizmos::addSphere(vec3(0, 0, 0), 1.f, 10, 10, glm::vec4(1, .5, 0, 1));
		//orbit ring
		Gizmos::addArcRing(vec3(0, 0, 0), 0.f, 2.7f, 2.8f, 4.f, 100, glm::vec4(1), &glm::mat4(1.02));
		Gizmos::addArcRing(vec3(0, 0, 0), 0.f, 2.7f, 2.8f, 4.f, 100, glm::vec4(1), &glm::mat4(2.02));
		Gizmos::addArcRing(vec3(0, 0, 0), 0.f, 2.7f, 2.8f, 4.f, 100, glm::vec4(1), &glm::mat4(3.02));
		//Mercury
		
		Gizmos::addSphere(vec3(x,0,y), .2f, 10, 10, glm::vec4(1, 0, 0, 1), &glm::mat4(1.5));
		Gizmos::addSphere(vec3(x*2, 0, y*2), .2f, 10, 10, glm::vec4(1, 0, 0, 1), &glm::mat4(1.5));
		Gizmos::addSphere(vec3(x*2.5, 0, y*2.5), .2f, 10, 10, glm::vec4(1, 0, 0, 1), &glm::mat4(1.5));

		Gizmos::draw(projection * view);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//When the window is colsing
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();

	//
	//Application *theApp = new Application;
	//if(theApp->startup() == true) 
	//{
	//	while (theApp->update() == true)
	//	{
	//		theApp->draw();
	//	}
	//	theApp->shutdown();
	//}

	//delete theApp;
	return 0;
}