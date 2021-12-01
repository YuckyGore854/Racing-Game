#include "car.h"
#include<iostream>

void car::update() {


	calculateVelocity();
	entRect.x += entXVel;
	entRect.y += entYVel;
}

void car::update(const Uint8* keyboard) {

	if (playerControlled) {
		//calculateVelocity();

		if (keyboard[SDL_SCANCODE_W]) {
			velocity = -1;
		}
		if (keyboard[SDL_SCANCODE_S]) {
			velocity = 1;
		}

		if (!keyboard[SDL_SCANCODE_W] && !keyboard[SDL_SCANCODE_S] || keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_S]) {
			velocity = 0;
		}
		if (keyboard[SDL_SCANCODE_A]) {
			angle--;
		}
		if (keyboard[SDL_SCANCODE_D]) {
			angle++;
		}calculateVelocity();
		std::cout << angle << std::endl;
	}

	if (angle > 360) {
		angle = 0;
	}
	if (angle < 0) {
		angle = 360;
	}
}

void car::draw(SDL_Renderer* renderer) {
	SDL_RenderCopyExF(renderer, entText, NULL, &entRect, angle-90, NULL, SDL_FLIP_NONE);
}

void car::calculateVelocity() {
	entXVel = cos(angle*(M_PI/180)) * velocity;
	entYVel = sin(angle*(M_PI/180)) * velocity;
	entRect.x += entXVel;
	entRect.y += entYVel;
}


void car::playerInput() {

}