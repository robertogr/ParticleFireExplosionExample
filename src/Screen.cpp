/*
 * Screen.cpp
 *
 *  Created on: 18/6/2015
 *      Author: roberto.gonzalez
 */

#include "Screen.h" //It is not necessary to include SDL.h because it's already included in Screen.h
#include <mem.h>
using namespace std;
using namespace MyParticleFireExplosionTest;
Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
	// TODO Auto-generated constructor stub

}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Problems initializing SDL_INIT" << endl;
		return false;
	}

	//1. Create Window
	m_window = SDL_CreateWindow("Particle fire explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == NULL) {
		cout << "An error has occurred creating window: " << SDL_GetError();
		SDL_Quit();
		return false;
	}

	else {
		cout << "Window has been created " << endl;
	}

	//2. Create renderer for the window
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL) {
		cout << "Could not create renderer" << endl;
		//TODO refactor this code
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	//3. Create texture for the renderer
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_texture == NULL) {
		cout << "Could not create texture" << endl;
		//TODO refactor this code
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	//A type defined by SDL to assure that it is an int of 32 bits. C++ is platform-dependent and an int could be 16,32...
	//we need 32 bits because each pixel is RBGA8888 = 32 bits,
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	//write some information in the buffer
	//with menset allocate a portion of memory
	try {
		memset(m_buffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); //paint all buffer with 255 (it is the white color)
	} catch (exception &ex) {
		cout << "ERROR in menset: " << ex.what() << endl;
	}
	//0xFF is the maximun value can store in a single byte in hexadecimal
	m_buffer[30000] = 0xFFFFFFFF; //4 bytes

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer[i] = 0x00FF00FF;
	}

	//Update the buffer of pixel data
	/*************************************************************/
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32) // The pitch -> The number of bytes in a row of pixel data.
			);
	SDL_RenderClear(m_renderer); //Clear the rendering target
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	/*************************************************************/

	return true;
}

bool Screen::processEvents() {
	SDL_Event event;
	//here we are going to update particles
	//draw those particles
	//check for messages/events
	while (SDL_PollEvent(&event)) {
		//if you click in the cross of a window it raise and event SDL_QUIT
		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;
}
bool Screen::close() {
	delete[] m_buffer;
		//TODO refactor this code
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	return true;
}

