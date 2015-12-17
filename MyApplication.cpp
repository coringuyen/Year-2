#include "MyApplication.h"

Application::Application() {}

void Application::startup()
{
	Application::window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
	}


	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}

void Application::update()
{
	Gizmos::create();

	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		// our game logic and update code goes here!
		// so does our render code!
		glClearColor(0.25f, 0.25f, 0.25f, 1);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//GL_COLOR_BUFFER_BIT tells OpenGL to wipe the back-buffer colors
		//GL_DEPTH_BUFFER_BIT clear the distance to the closest pixel. We do this that openGL loads are new images from frame to fram

	}
}

void Application::draw()
{
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


	if (Application::m_x <= 0 && Application::m_y <= 0)
	{
		Application::m_x--;
		Application::m_y++;
	}
	if (Application::m_x <= 0 && Application::m_y >= 0)
	{
		Application::m_x++;
		Application::m_y++;
	}
	if (Application::m_y >= 0 && Application::m_x >= 0)
	{
		Application::m_y--;
		Application::m_x++;
	}
	if (Application::m_y <= 0 && Application::m_x >= 0)
	{
		Application::m_y--;
		Application::m_x--;
	}
	//sun
	Gizmos::addSphere(vec3(0, 0, 0), 1.f, 10, 10, glm::vec4(1, .5, 0, 1));
	//orbit ring
	Gizmos::addArcRing(vec3(0, 0, 0), 0.f, 2.7f, 2.8f, 4.f, 100, glm::vec4(1), &glm::mat4(1.02));
	Gizmos::addArcRing(vec3(0, 0, 0), 0.f, 2.7f, 2.8f, 4.f, 100, glm::vec4(1), &glm::mat4(2.02));
	Gizmos::addArcRing(vec3(0, 0, 0), 0.f, 2.7f, 2.8f, 4.f, 100, glm::vec4(1), &glm::mat4(3.02));
	//Mercury

	Gizmos::addSphere(vec3(Application::m_x, 0, Application::m_y), .2f, 10, 10, glm::vec4(1, 0, 0, 1), &glm::mat4(1.5));
	Gizmos::addSphere(vec3(Application::m_x * 2, 0, Application::m_y * 2), .2f, 10, 10, glm::vec4(1, 0, 0, 1), &glm::mat4(1.5));
	Gizmos::addSphere(vec3(Application::m_x * 2.5, 0, Application::m_y*2.5), .2f, 10, 10, glm::vec4(1, 0, 0, 1), &glm::mat4(1.5));



	Gizmos::draw(Application::m_projection  * Application::m_view);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Application::shutdown()
{
	Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
}