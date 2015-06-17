//============================================================================
// Name        : ParticleFireExplosion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char* argv[]) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	bool quit = false;
	if(SDL_Init(SDL_INIT_VIDEO) <0 )
	{
		cout << "Problems initializing SDL_INIT" << endl;
		return 1;
	}
	SDL_Window *window = SDL_CreateWindow("Particle fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		cout << "An error has occurred creating window: " << SDL_GetError();
		SDL_Quit();
		return 2;
	}

	else
	{
		cout << "Window has been created " << endl;

	}
	SDL_Event event;
	while (!quit)
	{
		//here we are going to update particles
		//draw those particles
		//check for messages/events
		while(SDL_PollEvent(&event))
		{
			//if you click in the cross of a window it raise and event SDL_QUIT
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
