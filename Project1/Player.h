#pragma once
#include "DxLib.h"
#define INERTIA (0.1f)

class Player
{
private:
	float playerLocationX, playerLocationY;
	float playerMoveX, playerMoveY;

	int balloonNum;
	
	int fps;
	int flyButtonFlg;
	int rButtonFlg, lButtonFlg;
	int rFlg, lFlg;

	int count;
	int moveFpsCountY, moveFpsCountX;

	int upFlg;
	int rebound;
	int reboundFrameCntX;
	int reboundFlgY;
	int reboundFlgStageY;
	int reboundFlgStageX;

	int interval;

	int flyingFlg;

	int playerImg[24];
	int playerImgNum;
	int playerImgReturnFlg;
	int playerImgFpsCnt;
	int playerImgFly;
	int playerImgFlyFlg;
public:
	Player();
	~Player();
	
	void PlayerUpdate();
	void PlayerDraw() const;

	void PlayerMoveX();
	void PlayerMoveY();

	int PlayerFlyAnim();

	float GetPlayerLocationX() { return playerLocationX; }
	float GetPlayerLocationY() { return playerLocationY; }

	int GetReboundFlgStageX() { return reboundFlgStageX; }
	int GetReboundFrameCntX() { return reboundFrameCntX; }
	float GetPlayerMoveX() { return playerMoveX; }

	void SetFlyingFlg(int f)
	{
		flyingFlg = f;
	}

	void SetReboundFlgStageY(int f)
	{
		reboundFlgStageY = f;
	}
	void SetReboundFlgStageX(int f)
	{
		reboundFlgStageX = f;
	}

};

