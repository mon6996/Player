#include "includeAll.h"
#include "Game.h"

void Game::initWindow()
{
	this->window.create(VideoMode(800, 600), "Test Player", Style::Close | Style::Titlebar);
	this->window.setFramerateLimit(50);
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
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

void Game::update()
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window.close();
		else if (this->event.type == Event::KeyPressed && this->event.key.code == Keyboard::Escape)
			this->window.close();
	}

	this->updatePlayer();

	this->updateCollision();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::render()
{
	this->window.clear(Color::White);
	
	this->renderPlayer();
	
	this->window.display();
}

const RenderWindow& Game::getWindow() const
{
	return this->window;
}
