#include "includeAll.h"
#include "Game.h"

void Game::initWindow()
{
	this->window.create(VideoMode(800, 600), "Test Player", Style::Close | Style::Titlebar);
	this->window.setFramerateLimit(50);
}

void Game::initItem()
{
	this->item = new Item();
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initPuzzle()
{
	this->puzzle = new Puzzle();
}

Game::Game()
{
	this->initWindow();
	this->initItem();
	this->initPlayer();
	this->initPuzzle();
}

Game::~Game()
{
	delete this->player;
	delete this->item;
	delete this->puzzle;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision()
{
	if (this->player->getGlobalBounds().top + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition
		(
			this->player->getGlobalBounds().left,
			this->window.getSize().y - this->player->getGlobalBounds().height
		);
	}
	if (this->player->getGlobalBounds().left + this->player->getGlobalBounds().width > this->window.getSize().x)
	{
		this->player->resetVelocityX();
		this->player->setPosition
		(
			this->window.getSize().x - this->player->getGlobalBounds().width,
			this->player->getGlobalBounds().top
		);
	}
	if (this->player->getGlobalBounds().left + this->player->getGlobalBounds().width < this->player->getGlobalBounds().width)
	{
		this->player->resetVelocityX();
		this->player->setPosition
		(
			0.f,
			this->player->getGlobalBounds().top
		);
	}
}

void Game::updateItem()
{
	this->item->update();
}

void Game::updatePuzzle()
{
	this->puzzle->update();
}

void Game::update()
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window.close();
		else if (this->event.type == Event::KeyPressed && this->event.key.code == Keyboard::Escape)
			this->window.close();
		else if (this->item->isPlayerOver() && this->event.key.code == Keyboard::Space)
		{
			if (this->event.type == Event::TextEntered)
			{
				this->puzzle->inputAns(this->event);
			}
			else if ((this->event.type == Event::MouseButtonPressed && this->puzzle->isMouseOver(this->window)) || this->event.key.code == Keyboard::Enter)
			{

				if (this->puzzle->checkAns())
				{
					cout << "correct\n";
					
				}
				else
					cout << "fail\n";
			}
		}
	}

	this->updatePlayer();

	this->updateCollision();

	this->updatePuzzle();
	
	this->updateItem();
}

void Game::renderItem()
{
	this->item->render(this->window);
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderPuzzle()
{
	this->puzzle->render(this->window);
}

void Game::render()
{
	this->window.clear(Color::White);

	//this->renderPuzzle();
	
	this->renderItem();

	this->renderPlayer();
	
	this->window.display();
}

const RenderWindow& Game::getWindow() const
{
	return this->window;
}
