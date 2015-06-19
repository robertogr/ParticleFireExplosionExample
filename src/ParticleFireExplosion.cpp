//============================================================================
// Name        : ParticleFireExplosion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Screen.h"
#include <iostream>

using namespace std;
using namespace MyParticleFireExplosionTest;

int main(int argc, char* argv[]) {

	Screen screen;
	if(!screen.init())

		cout << "Error initializing the window" << endl;

	while(true)
	{
		if(screen.processEvents()==false)
			break;
	}
	screen.close();

	return 0;
}

