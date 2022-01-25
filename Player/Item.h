#ifndef ITEM_H
#define ITEM_H

#include "Player.h"

class Item
{
private:
	Sprite box;
	Texture textureSheet;
	Clock animationTimer;

	IntRect currentFrame;

	Player* player;

	void initTexture();
	void initSprite();
	
public:
	Item();
	virtual ~Item();

	bool isPlayerOver();
	void updateAnimations();
	void update();
	void render(RenderTarget& target);

};

#endif