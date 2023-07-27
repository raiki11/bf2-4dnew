#pragma once
#include"Player.h"

#define P_MAX 0.5f
#define G_MAX 1.0f
#define R_MAX 1.5f



struct ENEMY
{
	int type;
	int score;
	float MaxSpeed;
};
class Enemy
{
private:
	float ELocationX;
	float ELocationY;
	float EMoveX;
	float EMoveY;
	int time;
	int fpscount;
	int i;
	int Flag;
	int reboundFlgStageY;
	int reboundFlgStageX;
	int flyingFlg;
	float PSpeedY;
	float PSpeedX;
	int eflg;
	int count;
	int aflg;
	int Estate;
	int f;      //左右に揺れるやつ

	static int Score;

	int changeimg;//エネミー落下画像切り替え用
	int changeCt;//画像切り替えのカウント
	float cy;		//敵が倒されたときのY座標加算用
	int swy;		//敵が倒されたときの座標加算切り替え用
	int cycount;

	int P_img[18];
	int R_img[18];
	int G_img[18];

	ENEMY enemy;

	
	int Epoint;
	int cnt;
	int Escore1;
	int Escore2;
	int Escore3;
	int Escore4;
	int Escore5;
	int Eflgcnt;
	bool onlyOnce;
	int n_score;	// 現在のスコア
	int hi_score;	// ハイスコア
	

public:
	Enemy(int set_X,int set_Y);
	~Enemy();

	int cflg;		//死亡アニメーションフラグ
	static int DeadFlg;		//死亡フラグ
	static int EdeadCount;//エネミーがやられた数のカウント
	static int ElastFlg;

	void EnemyUpdate(Player P,int& j);
	void EnemyDraw() const;
	void EnemyMoveX(Player P);
	void EnemyMoveY(Player P);
	void EAnimation();

	void EPA();

	void EDeadAnim();

	//敵が死ぬアニメーションになるか確認する用
	void DebagHit(Player P);

	float GetEnemyLocationX() { return ELocationX; }
	float GetEnemyLocationY() { return ELocationY; }
	float GetEnemyMoveX() { return EMoveX; }
	float GetEnemyMoveY() { return EMoveY; }

	int EGetReboundFlgStageX() { return reboundFlgStageX; }
	void ESetReboundFlgStageY(int f)
	{
		reboundFlgStageY = f;
	}
	void ESetReboundFlgStageX(int f)
	{
		reboundFlgStageX = f;
	}
	void ESetFlyingFlg(int f)
	{
		flyingFlg = f;
	}

	static  int GetScore() { return Score; }

	int EScore();
    int  Eflg;
	 int c;
};

