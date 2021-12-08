#pragma once
#include "entity.h"
#include <math.h>
class car : public entity{
public:
	void update();
	void update(const Uint8* keyboard, bool collide);
	void calculateVelocity(bool collide);
	void draw(SDL_Renderer* renderer, float xOffset, float yOffset);
	void playerInput(const Uint8* keyboard);
	float getX() { return entRect.x; }
	float getY() { return entRect.y; }
	car() { playerControlled = false; entString = "car"; }
	car(bool playerControl) { playerControlled = playerControl; entString = "car"; }
private:
	
	double angle = 0;
	double velocity = 0;
	bool playerControlled = false;
};

