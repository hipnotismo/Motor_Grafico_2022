#include "renderer.h"
#include <glfw3.h>

Renderer::Renderer()
{
}

void Renderer::BeginDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapBuffer(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}