#include <iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>
#include"window.h"
#include"entity.h"
#include"car.h"
#include"map.h"
#include"camera.h"

using namespace std;


int main(int argc, char* argv[]) {
	vector<entity*> entVec;
	vector<entity*>::iterator entIter;


	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window Window;

	entVec.push_back(new car(true));
	char entityString[] = {"New Piskel (5).png"};
	entIter = entVec.begin();
	(*entIter)->loadSprite(Window.renderer, entityString);
	
	bool running = true;
	int fps = 200;//these variables are for manually capping the framerate
	int frameDelay = 1000 / fps;//this is the frameDelay variable, or approximately how long each frame should take
	Uint32 frameStart;//this variable holds the amount of time at the beginning of a frame
	int frameTime;//this variable holds the actual time of the current frame
	map* Map = new map;
	camera* Camera = new camera;
	//map Map;

	int mousex = 0;
	int mousey = 0;
	Uint8 mouseButtons;
	SDL_Event event;
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);
	while (running) {
		std::cout << Camera->getYOffset() << std::endl;
		frameStart = SDL_GetTicks();
		SDL_SetRenderDrawColor(Window.renderer, 0, 0, 0, 255);
		SDL_RenderClear(Window.renderer);

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT || keyboard[SDL_SCANCODE_ESCAPE]) {
				running = false;
			}
			if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN) {
				keyboard = SDL_GetKeyboardState(NULL);
			}
		}

		for (entIter = entVec.begin(); entIter != entVec.end(); ++entIter) {
			if ((*entIter)->getString() == "car") {
				(*entIter)->update(keyboard, (*Map).collision((*entIter)->getRect()));
				if ((*entIter)->getRect()->x > 1280 / 2) {
					Camera->setXOffset(1280 / 2 - (*entIter)->getRect()->x);
				}
				if ((*entIter)->getRect()->y > 720 / 2) {
					Camera->setYOffset(720 / 2 - (*entIter)->getRect()->y);
				}
			}
			else
			(*entIter)->update();
			(*entIter)->draw(Window.renderer, Camera->getXOffset(), Camera->getYOffset());
		}
		
		(*Map).draw(Window.renderer, Camera->getXOffset(), Camera->getYOffset());
		
		mouseButtons = SDL_GetMouseState(&mousex, &mousey);
		SDL_RenderPresent(Window.renderer);
		frameTime = SDL_GetTicks() - frameStart;//calculates how long a frame has been rendered for

		if (frameDelay > frameTime)//if the wanted amount of time between frames is bigger than the current amount of time it took to render the last frame
			SDL_Delay(frameDelay - frameTime);//delay the game until 16.66... miliseconds have passed
	}
	SDL_Quit();
	return 0;
}