#ifndef BASEGAME_H
#define BASEGAME_H
#include "Renderer.h"
struct GLFWmonitor;
struct GLFWwindow;
class BaseGame
{
private:
	Window* window;
	Renderer* renderer;
	void UpdateBegin();
	void UpdateEnd();
	void EngineEnd();
public:
	BaseGame();
	~BaseGame();
	int EngineInit(int width, int height, const char* title);
	int WindowInit(int width, int height, const char* title);

	bool Running();
	void UpdateEngine();
	void virtual Update() = 0;
	void virtual Draw() = 0;
};
#endif