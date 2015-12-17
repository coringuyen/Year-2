#pragma once
#include "stdio.h"
#include <gl_core_4_4.h> 
#include <GLFW/glfw3.h> 
#include <Gizmos.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;

class Application
{
	int m_x = 0;
	int m_y = 2;
	GLFWwindow *window;
	mat4 m_view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 m_projection = glm::perspective(glm::pi<float>()*0.25f, 16 / 9.f, 0.1f, 1000.f);
public :
	Application();

	void startup();
	void update();
	void draw();
	void shutdown();
};