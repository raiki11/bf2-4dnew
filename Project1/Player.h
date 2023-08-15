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
	int splashImg[4];
	int playerImgNum;
	int playerImgReturnFlg;
	int playerImgFpsCnt;
	int playerImgTakeOffNum;
	int playerImgFlyFlg;
	int playerNoInputFlg;
	int playerThunderFlg;
	int noInputFps;

	int splashNum;
	int St_Sea;

	int playerDeathState; //âΩÇ≈éÄÇÒÇæÇ© 0,ïóëDÇ™Ç»Ç≠Ç»Ç¡ÇΩÅ@1,óã

	int reboundFlgEnemyY;
	int reboundFlgEnemyX;
	//SE
	int SE_playerjump;
	int SE_playerwalk;
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
	int PlayerThunderDeathAnim();
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
	int GetDeathFlg() { return deathFlg; }
	int GetRemainBalloon() { return remainBalloon; }
	int GetPlayerImgNum() { return playerImgNum; }
	int GetNoInputFlg() { return playerNoInputFlg; }

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
	
	void SetPlayerDeathFlg(int f)
	{
		deathFlg = f;
	}

	void SetPlayerDeathFState(int s)
	{
		playerDeathState = s;
	}

	void SubtractRemainBalloon()
	{
		remainBalloon--;
	}

	void SetPlayerMoveY()
	{
		playerMoveY *= -1;
	}

	void SetReboundEnemyX(int f)
	{
		reboundFlgEnemyX = f;
	}

	void SetReboundEnemyY(int f)
	{
		reboundFlgEnemyY = f;
	}

	void SetPlayerLocationX()
	{
		playerLocationX += playerMoveX * 10;
	}

	void SetPlayerLocationY()
	{
		playerLocationY += -10;
	}
	void SetFallLimit();
	void SetRemainBalloon();
	int AnyButtons();
	void InitPlayer();

};

