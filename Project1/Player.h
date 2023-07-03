#pragma once
#define INERTIA (0.1f)

class Player
{
private:
	int playerLocationX;
	int playerLocationY;
	float playerMoveX;
	float playerMoveY;
	int speed;

	int balloonNum;

	int fps;
	int aButtonFlg;
	int rButtonFlg;
	int lButtonFlg;
	int count;
	int moveFpsCountY;
	int moveFpsCountX;
	int upFlg;
	int rebound;
	int reboundFlg;
public:
	Player();
	~Player();

	void PlayerUpdate();
	void PlayerDraw() const;

};

