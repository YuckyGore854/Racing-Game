#include "map.h"
#include<iostream>

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

map::map() {
	entRect.w = 1280 / 100;
	entRect.h = 720 / 100;
}

bool map::collision(SDL_FRect* targetCar) {
	float targetLeftSide = targetCar->x;
	float targetRightSide = targetCar->x + targetCar->w;
	float targetTop = targetCar->y;
	float targetBottom = targetCar->y + targetCar->h;

	float mapLefSide = 0;
	float mapRightSide = 0;
	float mapTop = 0;
	float mapBottom = 0;
	float mapWidth = 1280 / 100;
	float mapHeight = 720 / 100;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			mapLefSide = j * mapWidth;
			mapRightSide = j * mapWidth + mapWidth;
			mapTop = i * mapHeight;
			mapBottom = i * mapHeight + mapHeight;
			if (level1[i][j] == 1) {

				if (targetLeftSide<mapRightSide && targetRightSide > mapLefSide && targetBottom > mapTop && targetTop < mapBottom) {
					std::cout << "COLLISION" << std::endl;
				}
			}
		}
	}
	return false;
}