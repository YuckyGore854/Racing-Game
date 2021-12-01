#pragma once
#include "entity.h"
#include <math.h>
class car : public entity{
public:
	void update();
	void update(const Uint8* keyboard);
	void calculateVelocity();
	void draw(SDL_Renderer* renderer);
	void playerInput();
	car() { playerControlled = false; }
	car(bool playerControl) { playerControlled = playerControl; }
private:

	double angle = 0;
	double velocity = 0;
	bool playerControlled = false;
};

