#pragma once
#include<SDL.h>
class window{
public:
	SDL_Window* Window = SDL_CreateWindow("Racing Extreme", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(Window, -1, NULL);
};

