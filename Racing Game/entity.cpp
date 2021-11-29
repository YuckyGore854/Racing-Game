#include "entity.h"

void entity::draw(SDL_Renderer* renderer) {
	SDL_RenderDrawRectF(renderer, &entRect);
}
void entity::update() {
	entRect.x += entXVel;
	entRect.y += entYVel;
}
void entity::loadSprite(char* entImage[]) {
	SDL_Surface tempSurface;
	tempSurface
}