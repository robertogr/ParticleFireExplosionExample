/*
 * Screen.h
 *
 *  Created on: 18/6/2015
 *      Author: roberto.gonzalez
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL.h>
#include <iostream>

namespace MyParticleFireExplosionTest {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	// "m_" indicate that they are variable members
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
public:
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvents();
	bool close();

};
};
#endif /* SCREEN_H_ */
