#include "MyApplication.h"

Application::Application()
{
	m_x = 0;
	m_y = 2;
	m_view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	m_projection = glm::perspective(glm::pi<float>()*0.25f, 16 / 9.f, 0.1f, 1000.f);
}

int Application::startup()
{
	if (glfwInit() == false)
		return -1;

	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	if (window == nullptr)
		glfwTerminate();

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

	return 0;
}

int Application::update()
{
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		// our game logic and update code goes here!
		// so does our render code!
		glClearColor(0.25f, 0.25f, 0.25f, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//GL_COLOR_BUFFER_BIT tells OpenGL to wipe the back-buffer colors
		//GL_DEPTH_BUFFER_BIT clear the distance to the closest pixel. We do this that openGL loads are new images from frame to fram
		return 1;
	}

	return 0;

}

void Application::draw()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Application::shutdown()
{
	std::printf("shutting down...");
	//Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
}

