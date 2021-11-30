#pragma once
#include "entity.h"
class car : public entity{
public:
	void update();
	void calculateVelocity();
	void draw(SDL_Renderer* renderer);
private:
	double Xangle;
	double Yangle;
	double generalAngle;
};

