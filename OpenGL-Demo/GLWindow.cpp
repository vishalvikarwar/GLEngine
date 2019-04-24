#include "GLWindow.h"

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


GLWindow::GLWindow()
{
	//initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
}

//terminate, clearing all previously allocated GLFW resources.
GLWindow::~GLWindow()
{
	glfwTerminate();
}

// glfw window creation
void GLWindow::CreateGLWindow(const unsigned int width, const unsigned int height)
{
	window = glfwCreateWindow(width, width, "OpenGL-Demo", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

	//load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

//swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
void GLWindow::SwapBuffers()
{
	glfwSwapBuffers(window);
}

void GLWindow::ProcessEvents()
{
	glfwPollEvents();
}

bool GLWindow::IsClosed()
{
	return glfwWindowShouldClose(window);
}
