#pragma once
#define INERTIA (0.1f)

class Player
{
private:
	float playerLocationX, playerLocationY;
	float playerMoveX, playerMoveY;

	int balloonNum;

	int fps;
	int aButtonFlg;
	int rButtonFlg, lButtonFlg;
	int rFlg, lFlg;

	int count;
	int moveFpsCountY, moveFpsCountX;

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

	float GetPlayerLocationX() { return playerLocationX; }
	float GetPlayerLocationY() { return playerLocationY; }
};

