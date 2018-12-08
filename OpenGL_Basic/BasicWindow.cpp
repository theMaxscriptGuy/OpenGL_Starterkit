/*
	OpenGL is strictly a graphics API. Hence, do not assume opengl
	to create or close instances of windows on your desktop. It 
	does not contain any commands to do so.

	A GL contxt is a platform specific object which enables 
	OpenGL's functionality.

	Always remember to include opengl.lib in the libraries. Without
	which you shall encounter linker errors.

	What is GLFW?
	https://www.glfw.org/faq.html#11---what-is-glfw
	This helps us to quickly create a GL context and get started
	with a few lines of code.

	Please read the ReadMe for important links.

*/

#include <GLFW/glfw3.h>
#include <iostream>
int main() {

	if (!glfwInit())
	{
		return 0;
	}

	//Define the width and height of the window
	int width = 512;
	int height = 512;

	GLFWwindow * glWindow;
	glWindow = glfwCreateWindow(width, height, "glfw", NULL, NULL);

	if (!glWindow) 
	{
		glfwTerminate();
		return 0;
	}
	//Assign the glWindow we created as the current context to render our program
	glfwMakeContextCurrent(glWindow);

	printf("show the window\n");

	while (!glfwWindowShouldClose(glWindow)) 
	{
		//Run this code till the time user does not click the close button
		//This can be called the Game Loop or the Main Loop
		glViewport(0, 0, width, height);
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*
			As we shall talk about the FrameBuffers (front and back),
			here we ask to swap them so that the back buffer which 
			has already rendered the image is now seen.
			Also, the front buffer is sent to the back to write the next frame.
		*/
		glfwSwapBuffers(glWindow);
		glfwPollEvents();
	}

	//Destroy the window
	glfwDestroyWindow(glWindow);
	glfwTerminate();
	return 0;
}
