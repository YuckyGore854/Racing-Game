#include<SDL.h>

#pragma once
class entity{
private:
	SDL_Rect entRect;

public:
	void draw(SDL_Renderer renderer);
};

