#include "stdio.h"
#include <gl_core_4_4.h> 
#include <GLFW/glfw3.h> 
#include <Gizmos.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "MyApplication.h"


int main()
{
	Application *theApp = new Application();
	
	if(theApp->startup() == true) 
	{
		while (theApp->update() == true)
		{
			theApp->draw();
		}
		theApp->shutdown();
	}
	

 
 


	//delete theApp;
	return 0;
}