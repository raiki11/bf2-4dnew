#pragma once
#define INERTIA (0.1f)

class Player
{
private:
	float playerLocationX;
	float playerLocationY;
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

	int flyingFlg;
public:
	Player();
	~Player();

	void PlayerUpdate();
	void PlayerDraw() const;

	void PlayerMoveX();
	void PlayerMoveY();
};

