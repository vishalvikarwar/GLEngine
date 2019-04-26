#ifndef  GLWINDOW_H
#define GLWINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);

class GLWindow
{
private:
	GLFWwindow* window;

public:
	GLWindow();
	~GLWindow();

	void CreateGLWindow(const unsigned int width, const unsigned int height);
	void SwapBuffers();
	void ProcessEvents();
	bool IsClosed();
};

#endif // ! WINDOW_H

