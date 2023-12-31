#pragma once
#include"Player.h"

#define P_MAX 0.5f
#define G_MAX 0.8f
#define R_MAX 1.2f



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
	int point;		// ポイント表示の変数
	int count;
	int aflg;
	int Estate;
	int f;      //左右に揺れるやつ
	int EfectFlag;
	int EfectScore;
	int efectcout;
	int e;
	int E_Gflg;
	int E_count;
	int E_rand;


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

	int ranonce;//Rand関数一度だけやる用

	bool SEonce;

public:
	Enemy(int set_X,int set_Y);
	~Enemy();

	int cflg;		//0:通常状態　1:パラシュート状態　2:死亡状態
	static int DeadFlg;		//死亡フラグ
	static int EdeadCount;//エネミーがやられた数のカウント
	static int ElastFlg;	//最後の一匹か確認するフラグ
	static bool FishFlg;	//サカナが出てくるか

	void EnemyUpdate(Player P,int& j);
	void EnemyDraw() const;
	void EnemyMoveX(Player P);
	void EnemyMoveY(Player P);
	void EAnimation();
	int AnimCount;

	void EPA();

	void EDeadAnim();
	void EsplashAnim();
	int EspAnim[4];
	int spc;	//スプラッシュアニメーションカウント
	bool spflg;	//スプラッシュアニメーション用フラグ

	static int SE_enemyMove;
	static int SE_PA;
	int on;

	//敵が死ぬアニメーションになるか確認する用
	void DebagHit(Player P);

	float GetEnemyLocationX() { return ELocationX; }
	float GetEnemyLocationY() { return ELocationY; }
	float GetEnemyMoveX() { return EMoveX; }
	float GetEnemyMoveY() { return EMoveY; }

	int EGetReboundFlgStageX() { return reboundFlgStageX; }

	int GetI() { return i; }
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

	void Efect();

	static int GetScore() { return Score; }

	static int GetFishflg() { return FishFlg; }


	static int EgetFx;
	int Fishprobability;
	
	int EScore();
    static int  Eflg;
	 int c;
	 bool once;
	 void ECheckY();
	 static int Score;
};

