#include "includeAll.h"
#include "Item.h"

void Item::initTexture()
{
	if (!this->textureSheet.loadFromFile("Item/box.png"))
	{
		cout << "ERROR::ITEM::Cloud not load the box sheet!\n";
	}
}

void Item::initSprite()
{
	this->box.setTexture(this->textureSheet);
	this->currentFrame = IntRect(0, 0, 32, 32);

	this->box.setTextureRect(this->currentFrame);
	this->box.setPosition(Vector2f(400.f, 550.f));

	this->box.setScale(1.f, 1.f);
}

Item::Item()
{
	initTexture();
	initSprite();
}

Item::~Item()
{

}

bool Item::isPlayerOver()
{
	int playerX = 400;
	int playerY = 550;

	int boxX = this->box.getPosition().x;
	int boxY = this->box.getPosition().y;

	int boxPosWidth = this->box.getPosition().x + 32;
	int boxPosHeight = this->box.getPosition().y + 32;

	if (playerX < boxPosWidth && playerX > boxX && playerY < boxPosHeight && playerY > boxY)
		return true;

	return false;
}

void Item::updateAnimations()
{
	for (int i = 1; i < 4; i++)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5f)
		{
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 128.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->box.setTextureRect(this->currentFrame);
		}
	}
}

void Item::update()
{
	this->updateAnimations();
	
}

void Item::render(RenderTarget& target)
{
	target.draw(this->box);
}
