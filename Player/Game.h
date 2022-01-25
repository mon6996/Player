#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Item.h"
#include "Puzzle.h"

class Game
{
private:
	RenderWindow window;
	Event event;

	Item* item;
	Player* player;
	Puzzle* puzzle;

	void initWindow();
	void initItem();
	void initPlayer();
	void initPuzzle();

public:
	Game();
	virtual ~Game();

	void updatePlayer();
	void updateCollision();
	void updateItem();
	void updatePuzzle();
	void update();
	void renderItem();
	void renderPlayer();
	void renderPuzzle();
	void render();
	const RenderWindow& getWindow() const;
};

#endif