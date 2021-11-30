#include "car.h"

void car::update() {
	if (generalAngle < 360) {
		generalAngle++;
	}
	else {
		generalAngle = 0;
	}
}

void car::draw(SDL_Renderer* renderer) {
	SDL_RenderCopyExF(renderer, entText, NULL, &entRect, generalAngle, NULL, SDL_FLIP_NONE);
}