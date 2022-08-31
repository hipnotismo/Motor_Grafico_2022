#include "BaseGame.h"
#include <glew.h>
#include <glfw3.h>
#include<iostream>

#define ENGINE_EXPORT

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

BaseGame::BaseGame()
{
	window = new Window();
	renderer = new Renderer();
}
BaseGame::~BaseGame()
{
	if (window != NULL) delete window;
	if (renderer != NULL) delete renderer;
}
int BaseGame::EngineInit(int width, int height, const char* title)
{
	if (!glfwInit())
		return -1;
	else if (WindowInit(width, height, title))
		return -1;
	glewInit();
	if (glewInit() != GLEW_OK)
	{
		std::cout << "error" << std::endl;
	}
	return 0;
}

int BaseGame::WindowInit(int width, int height, const char* title)
{
	window = new Window(width, height, title, NULL, NULL);
	if (!window)
	{
		return -1;
	}
	window->WindowContext();
	return 0;
}

void BaseGame::RendererInit()
{
	renderer->CreateBuffers();
	renderer->BindBuffers();
	renderer->CreateProgram(vertexShaderSource,
		fragmentShaderSource);
	renderer->DefVertexAttribute();

}

bool BaseGame::Running()
{
	return window->ShouldClose();
}

void BaseGame::UpdateBegin()
{
	window->ClearBackground();
}

void BaseGame::UpdateEnd()
{
	renderer->Draw();
	window->SwapBuffer();
	glfwPollEvents();
}
void BaseGame::UpdateEngine()
{
	while (Running())
	{
		UpdateBegin();
		Update();
		UpdateEnd();
	}
	EngineEnd();
}
void BaseGame::EngineEnd()
{
	glfwTerminate();
}