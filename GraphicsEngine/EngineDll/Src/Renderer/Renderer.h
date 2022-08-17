#ifndef RENDERER_H
#define RENDERER_H
#include "Window.h"
struct GLFWwindow;
class Renderer
{
private:
public:
	Renderer();
	void BeginDraw();
	void SwapBuffer(GLFWwindow* window);

};


#endif