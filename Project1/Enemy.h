#pragma once
#include"Player.h"


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

	int changeimg;//エネミー落下画像切り替え用
	int changeCt;//画像切り替えのカウント
	int cflg;		//敵が倒された時の仮フラグ
	float cy;		//敵が倒されたときのY座標加算用
	int swy;		//敵が倒されたときの座標加算切り替え用
	int cycount;

	int img[24];
	

public:
	Enemy(int set_X,int set_Y);
	~Enemy();

	void EnemyUpdate(Player P);
	void EnemyDraw() const;

	void EnemyMoveX(Player P);

	void EAnimation();

	void EDeadAnim();

	//敵が死ぬアニメーションになるか確認する用
	void DebagHit(Player P);

	float GetEnemyLocationX() { return ELocationX; }
	float GetEnemyLocationY() { return ELocationY; }
};

