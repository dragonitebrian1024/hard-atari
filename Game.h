#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include <string>
#pragma once
#include "SDL_image.h"

static SDL_Renderer* renderer;
static bool isRunning;

static class Game {

public:
	Game();
	double delta_time;
	~Game();

	void init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update(double delta_time);
	void render();
	void clean();
	void handleEvents();
	bool lose;
    

	bool running() { return isRunning; }


	SDL_Window* window;

};
