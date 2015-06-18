//============================================================================
// Name        : ParticleFireExplosion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <mem.h>

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

	//1. Create Window
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

	//2. Create renderer for the window
	SDL_Renderer *renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
	{
		cout << "Could not create renderer" << endl;
		//TODO refactor this code
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	//3. Create texture for the renderer
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH, SCREEN_HEIGHT);

	if(texture == NULL)
	{
		cout << "Could not create texture" << endl;
		//TODO refactor this code
		SDL_DestroyTexture(texture);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	//A type defined by SDL to assure that it is an int of 32 bits. C++ is platform-dependent and an int could be 16,32...
	//we need 32 bits because each pixel is RBGA8888 = 32 bits,
	Uint32 *buffer;
	try{
		buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
		//write some information in the buffer
		//with menset allocate a portion of memory
		memset(buffer, 255, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)); //paint all buffer with 255 (it is the white color)
	}
	catch (exception* ex)
	{
		cout<< "Error allocating memory pixels buffer: " << ex->what() << endl;
	}


	//Update the buffer of pixel data
	/*************************************************************/
	SDL_UpdateTexture(texture, NULL, buffer,
			SCREEN_WIDTH*sizeof(Uint32) // The pitch -> The number of bytes in a row of pixel data.
	);
	SDL_RenderClear(renderer); //Clear the rendering target
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	/*************************************************************/
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

	delete[] buffer;
	//TODO refactor this code
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
