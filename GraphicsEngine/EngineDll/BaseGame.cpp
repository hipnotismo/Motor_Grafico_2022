#include "BaseGame.h"
#include <glew.h>
#include <glfw3.h>
#include<iostream>

#define ENGINE_EXPORT

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
bool BaseGame::Running()
{
	return window->ShouldClose();
}

void BaseGame::UpdateBegin()
{
	renderer->BeginDraw();
}

void BaseGame::UpdateEnd()
{
	renderer->SwapBuffer(window->GetWindow());
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