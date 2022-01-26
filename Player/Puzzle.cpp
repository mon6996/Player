#include "includeAll.h"
#include "Puzzle.h"

void Puzzle::initTexture()
{
	if (!this->textureSheet.loadFromFile("Pictures/Sasuke.png"))
	{
		cout << "ERROR::PUZZLE::Cloud not load the pictue sheet!\n";
	}
}

void Puzzle::initSprite()
{
	this->picture.setTexture(this->textureSheet);
	this->picture.setTextureRect(IntRect(0, 0, 1024, 1843));

	this->picture.setScale(0.5f, 0.5f);
}

void Puzzle::initFont()
{
	if (!this->font.loadFromFile("Fonts/DM Weekend Regular.ttf"))
	{
		cout << "ERROR::PUZZLE::Cloud not load font!\n";
	}
}

void Puzzle::initQuestion()
{
	this->question.setFont(font);
	this->question.setCharacterSize(80);
	this->question.setLineSpacing(10.f);
	this->question.setFillColor(Color::Black);
	this->question.setPosition(0.f, 150.f);
	this->question.setString("What is this character name?");
}

void Puzzle::deleteLastChar()
{
	string t = this->answer.str();
	string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	this->answer.str("");
	this->answer << newT;
	this->textAns.setString(this->answer.str() + "_");
}

void Puzzle::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		if (charTyped >= 97 && charTyped <= 122)
			this->answer << static_cast<char>(charTyped - 32);
		else
			this->answer << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (this->answer.str().length() > 0)
			deleteLastChar();
	}
	this->textAns.setString(this->answer.str() + "_");
}


void Puzzle::initTextBox()
{
	this->textbox.setSize(Vector2f(15 * limit, 30));
	this->textbox.setOutlineThickness(1);
	this->textbox.setOutlineColor(Color::Black);
	this->textbox.setPosition(400.f, 300.f);

	this->textAns.setFont(font);
	this->textAns.setLineSpacing(10.f);
	this->textAns.setFillColor(Color::Black);
	this->textAns.setPosition(410.f, 295.f);
	this->textAns.setCharacterSize(30);
	this->hasLimit = true;
	this->limit = limit - 1;
	this->isSelected = true;
	if (this->isSelected)
		this->textAns.setString("_");
	else
		this->textAns.setString("");
}

void Puzzle::initButton()
{
	this->button.setSize(Vector2f(100.f, 60.f));
	this->button.setFillColor(Color(127, 127, 127));
	this->button.setPosition(500.f, 400.f);

	this->text.setFont(font);
	this->text.setCharacterSize(60);
	this->text.setLineSpacing(10.f);
	this->text.setFillColor(Color::Black);
	float xPos = this->button.getPosition().x + (this->button.getSize().x / 4.5) - this->text.getLocalBounds().width;
	float yPos = this->button.getPosition().y - (this->button.getSize().y / 4.5) + this->text.getLocalBounds().height;
	this->text.setPosition(xPos, yPos);
	this->text.setString("OK");
}

string Puzzle::getAns()
{
	return this->answer.str();
}

Puzzle::Puzzle()
{
	this->initTexture();
	this->initSprite();

	this->initFont();
	this->initQuestion();

	this->initTextBox();
	this->initButton();
}

Puzzle::~Puzzle()
{

}

void Puzzle::setSelected(bool sel)
{
	this->isSelected = sel;

	if (!sel)
	{
		string t = this->answer.str();
		string newT = "";

		for (int i = 0; i < t.length(); i++)
			newT += t[i];

		this->textAns.setString(newT);
	}
}

void Puzzle::inputAns(Event input)
{
	if (this->isSelected)
	{
		int charTyped = input.text.unicode;

		if (charTyped < 128)
		{
			if (this->hasLimit)
			{
				if (this->answer.str().length() <= this->limit)
					inputLogic(charTyped);
				else if (this->answer.str().length() > this->limit && charTyped == DELETE_KEY)
					deleteLastChar();
			}
			else
				inputLogic(charTyped);
		}
	}
}

bool Puzzle::isMouseOver(RenderWindow& window)
{
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	int btnPosX = this->button.getPosition().x;
	int btnPosY = this->button.getPosition().y;

	int btnxPosWidth = this->button.getPosition().x + this->button.getSize().x;
	int btnyPosHeight = this->button.getPosition().y + this->button.getSize().y;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
		return true;

	return false;
}

bool Puzzle::checkAns()
{
	this->correctAns = "SASUKE";
	if (this->correctAns == this->answer.str())
		return true;
	return false;
}

void Puzzle::update()
{

}

void Puzzle::render(RenderTarget& target)
{
	target.draw(this->picture);
	target.draw(this->question);
	target.draw(this->textbox);
	target.draw(this->textAns);
	target.draw(this->button);
	target.draw(this->text);
}