#pragma once
#include "DxLib.h"
#define INERTIA (0.1f)

class Player
{
private:
	float playerLocationX, playerLocationY;
	float playerMoveX, playerMoveY;
	float fallLimit;

	int remainBalloon;
	int deathFlg;
	int playerLife;
	int splashFlg;

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
	int takeOffFlg;
	int flapFlg;
	int flapInterval;

	int playerImg[32];
	int splashImg[3];
	int playerImgNum;
	int playerImgReturnFlg;
	int playerImgFpsCnt;
	int playerImgTakeOffNum;
	int playerImgFlyFlg;
	int playerNoInputFlg;

	int splashNum;
public:
	Player();
	~Player();
	
	void PlayerUpdate();
	void PlayerDraw() const;

	void PlayerMoveX();
	void PlayerMoveY();

	int PlayerTakeOffAnim();
	int PlayerFlyAnim();
	int PlayerWaitAnim();
	int PlayerWalkAnim();
	int PlayerFlyingAnim();
	int PlayerDeathAnim();
	int PlayerNoInputAnim();
	int PlayerSplashAnim();

	float GetPlayerLocationX() { return playerLocationX; }
	float GetPlayerLocationY() { return playerLocationY; }

	int GetTakeOffFlg() { return takeOffFlg; }
	int GetFlyingFlg() { return flyingFlg; }
	int GetReboundFlgStageX() { return reboundFlgStageX; }
	int GetReboundFrameCntX() { return reboundFrameCntX; }
	float GetPlayerMoveX() { return playerMoveX; }
	int GetPlayerLife() { return playerLife; }

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

	void SetPlayerImgFpsCnt(int n)
	{
		playerImgFpsCnt = n;
	}

	void SetFallLimit();
	void SetRemainBalloon();
	int AnyButtons();
};

