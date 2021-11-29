#include <iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"window.h"

using namespace std;


int main(int argc, char* argv[]) {
	
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_init(IMG_INIT_PNG);
	window Window;
	while (!false) {
		SDL_SetRenderDrawColor(Window.renderer, 255, 255, 255, 255);
		SDL_RenderClear(Window.renderer);
		SDL_Event event;
		const Uint8 *keyboard;
		int mousex = 0;
		int mousey = 0;
		Uint8 mouseButtons;


		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				return true;
			}
			if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN) {
				keyboard = SDL_GetKeyboardState(NULL);
			}
		}
		mouseButtons = SDL_GetMouseState(&mousex, &mousey);
		SDL_RenderPresent(Window.renderer);
	}
	return 0;
}