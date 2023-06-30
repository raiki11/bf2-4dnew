#pragma once
class Player
{
private:
	int playerLocationX;
	int playerLocationY;
	int playerMoveX;
	int playerMoveY;
	int speed;

	int balloonNum;

	int fps;
	int aButtonFlg;
public:
	Player();
	~Player();

	void PlayerUpdate();
	void PlayerDraw() const;

};

