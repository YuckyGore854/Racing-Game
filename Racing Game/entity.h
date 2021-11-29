#include<SDL.h>
#include<SDL_image.h>

#pragma once
class entity{
private:
	SDL_FRect entRect{ 0,0,0,0 };
	double entXVel = 0;
	double entYVel = 0;
	SDL_Texture* entText;
public:
	void update();
	void draw(SDL_Renderer* renderer);
	void loadSprite(char* entImage[]);
};

