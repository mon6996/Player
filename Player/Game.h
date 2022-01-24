#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
private:
	RenderWindow window;
	Event event;

	Player* player;

	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	void updatePlayer();
	void updateCollision();
	void update();
	void renderPlayer();
	void render();
	const RenderWindow& getWindow() const;
};

#endif