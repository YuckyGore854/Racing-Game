#include "car.h"
#include<iostream>

void car::update() {
	/*
	std::cout << "here" << std::endl;
	calculateVelocity();
	entRect.x += entXVel;
	entRect.y += entYVel;
	*/
}

void car::update(const Uint8* keyboard, bool collide) {
	//std::cout << "Here" << std::endl;
	if (playerControlled) {
		playerInput(keyboard);		
	}
	calculateVelocity(collide);
	if (angle > 360) {
		angle = 0;
	}
	if (angle < 0) {
		angle = 360;
	}
}

void car::draw(SDL_Renderer* renderer, float xOffset, float yOffset) {
	SDL_FRect drawRect = entRect;
	drawRect.x = entRect.x + xOffset;
	drawRect.y = entRect.y + yOffset;
	//if (entRect.y < 720 / 2)
	//	entRect.y += yOffset;
	//else
	//	entRect.y -= yOffset;
	SDL_RenderCopyExF(renderer, entText, NULL, &drawRect, angle - 90, NULL, SDL_FLIP_NONE);
}

void car::calculateVelocity(bool collide) {
	if (collide) {
		velocity *= 0.1;
	}
	entXVel = cos(angle*(M_PI/180)) * velocity;
	entYVel = sin(angle*(M_PI/180)) * velocity;
	entRect.x += entXVel;
	entRect.y += entYVel;

}


void car::playerInput(const Uint8* keyboard) {
	
	if (abs(velocity) < 6) {
		if (keyboard[SDL_SCANCODE_W]) {
			velocity += -.4;
		}
		if (keyboard[SDL_SCANCODE_S]) {
			velocity += .4;
		}
	}
	if (!keyboard[SDL_SCANCODE_W] && !keyboard[SDL_SCANCODE_S] || keyboard[SDL_SCANCODE_W] && keyboard[SDL_SCANCODE_S]) {
		velocity *= 0.95;
	}
	if (keyboard[SDL_SCANCODE_A] && velocity != 0) {
		angle += velocity / 2;
	}
	if (keyboard[SDL_SCANCODE_D] && velocity != 0) {

		angle -= velocity / 2;
	}
	
}