#pragma once
#include "entity.h"
class camera : public entity {
public:
	float getXOffset() { return entRect.x; }
	float getYOffset() { return entRect.y; }
	void setYOffset(float y) { entRect.y = y; }
	void setXOffset(float x) { entRect.x = x; }
};

