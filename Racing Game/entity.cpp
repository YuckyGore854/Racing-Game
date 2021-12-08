#include "entity.h"
#include<iostream>
void entity::draw(SDL_Renderer* renderer, float xOffset, float yOffset) {
	entRect.x += xOffset;
	entRect.y += yOffset;
	if (entText == NULL) {
		SDL_RenderDrawRectF(renderer, &entRect);
	}
	else {
		SDL_RenderCopyF(renderer, entText, NULL, &entRect);
	}
}
void entity::update() {
	entRect.x += entXVel;
	entRect.y += entYVel;
}
void entity::loadSprite(SDL_Renderer* renderer, char entImage[]) {
	SDL_Surface* tempSurface;
	tempSurface = IMG_Load(entImage);
	entText = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	entRect.w = 60;
	entRect.h = 80;
}
void entity::setXpos(float xPos) {
	entRect.x = xPos;
}
void entity::setYpos(float yPos) {
	entRect.y = yPos;
}
