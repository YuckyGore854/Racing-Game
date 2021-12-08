#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#pragma once
class entity{
protected:
	SDL_FRect entRect{ 20,20,0,0 };
	SDL_Texture* entText;
	double entXVel = 0;
	double entYVel = 0;
	std::string entString = "entity";

public:
	virtual void update();
	virtual void update(const Uint8* keyboard, bool collide) {  };
	virtual void draw(SDL_Renderer* renderer, float xOffset, float yOffset);
	void loadSprite(SDL_Renderer* renderer, char entImage[]);
	void setXpos(float xPos);
	void setYpos(float yPos);
	SDL_FRect* getRect() { return &entRect; }
	std::string getString() { return entString; }
	entity() { entString = "entity"; }
};

