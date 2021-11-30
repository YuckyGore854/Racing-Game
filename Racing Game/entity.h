#include<SDL.h>
#include<SDL_image.h>

#pragma once
class entity{
protected:
	SDL_FRect entRect{ 20,20,0,0 };
	double entXVel = 0;
	double entYVel = 0;
	SDL_Texture* entText;
public:
	void update();
	void draw(SDL_Renderer* renderer);
	void loadSprite(SDL_Renderer* renderer, char entImage[]);
	void setXpos(float xPos);
	void setYpos(float yPos);
};

