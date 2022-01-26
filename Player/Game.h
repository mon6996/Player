#ifndef GAME_H
#define GAME_H

#include "StateMain.h"
#include "Asset.h"
#include "Player.h"
#include "Item.h"
#include "Puzzle.h"

struct Context
{
	unique_ptr<Engine::Asset> assets;
	unique_ptr<Engine::StateMain> states;
	unique_ptr<RenderWindow> window;

	Context()
	{
		assets = make_unique<Engine::Asset>();
		states = make_unique<Engine::StateMain>();
		window = make_unique<RenderWindow>();
	}
};

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