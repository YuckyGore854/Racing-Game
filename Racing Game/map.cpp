#include "map.h"

void map::draw(SDL_Renderer* renderer) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			entRect.x = j * (1280 / 100);
			if (level1[i][j] == 1) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderDrawRectF(renderer, &entRect);
				SDL_RenderCopyF(renderer, entText, NULL, &entRect);
			} 
		}
		entRect.y = i * (720 / 100);
	}
}