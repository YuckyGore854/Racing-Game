#include <iostream>
#include<SDL.h>
#include"window.h"

using namespace std;


int main(int argc, char* argv[]) {
	
	SDL_Init(SDL_INIT_EVERYTHING);
	window Window;
	while (!false) {
		SDL_Event event;

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				return true;
			}
		}

		SDL_SetRenderDrawColor(Window.renderer, 255, 255, 255, 255);
		SDL_RenderClear(Window.renderer);
		SDL_RenderPresent(Window.renderer);
	}
	return 0;
}