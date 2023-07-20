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
	int cflg;
	float cy;		//やられたときのY座標加算用
	int swy;
	int cycount;

	int img[24];
	

public:
	Enemy(int set_X,int set_Y);
	~Enemy();

	void EnemyUpdate(Player P);
	void EnemyDraw() const;

	void EnemyMoveX(Player P);

	void EAnimation();


	float GetEnemyLocationX() { return ELocationX; }
	float GetEnemyLocationY() { return ELocationY; }
};

