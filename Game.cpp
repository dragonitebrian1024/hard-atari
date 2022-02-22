#include "Game.h"
#include <string>
#include "SDL.h"
#include "ball.h"
Ball* ball;

Game::Game()
{
	isRunning = true;

}
Game::~Game()
{

}

void Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;

	SDL_RenderSetLogicalSize(renderer, 600, 800);

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised" << std::endl;
		window = SDL_CreateWindow("hard atari", xpos, ypos, width, height, flags);
		SDL_INIT_EVERYTHING;

		if (window)
		{
			std::cout << "Window created" << std::endl;
		}


		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}

		ball = new Ball();

		ball->init(renderer, (400 / 2) - 12, (400 / 2) - 12);

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void Game::update(double delta_time)
{
	ball->update(1.0/60.0);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	ball->draw(renderer);
	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	ball->~Ball();
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}
