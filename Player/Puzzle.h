#ifndef PUZZLE_H
#define PUZZLE_H

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Puzzle
{
private:
	Text question;
	Font font;

	Sprite picture;
	Texture textureSheet;

	String correctAns;

	RectangleShape textbox;
	Text textAns;
	ostringstream answer;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 20;

	RectangleShape button;
	Text text;

	void initTexture();
	void initSprite();

	void initFont();
	void initQuestion();

	void deleteLastChar();
	void inputLogic(int charTyped);

	void initTextBox();
	void initButton();
	string getAns();

public:
	Puzzle();
	virtual ~Puzzle();

	void setSelected(bool sel);
	void inputAns(Event input);
	bool isMouseOver(RenderWindow& window);
	bool checkAns();
	void update();
	void render(RenderTarget& target);
};

#endif