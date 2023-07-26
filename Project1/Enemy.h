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
	float PSpeed;
	int eflg;
	int count;
	int aflg;

	int changeimg;//�G�l�~�[�����摜�؂�ւ��p
	int changeCt;//�摜�؂�ւ��̃J�E���g
	int cflg;		//�G���|���ꂽ���̉��t���O
	float cy;		//�G���|���ꂽ�Ƃ���Y���W���Z�p
	int swy;		//�G���|���ꂽ�Ƃ��̍��W���Z�؂�ւ��p
	int cycount;

	int P_img[18];
	int R_img[18];
	int G_img[18];

	ENEMY enemy;

	
	int Epoint;
	int cnt;

public:
	Enemy(int set_X,int set_Y);
	~Enemy();

	void EnemyUpdate(Player P);
	void EnemyDraw() const;
	void EnemyMoveX(Player P);
	void EnemyMoveY(Player P);
	void EAnimation();

	void EPA();

	void EDeadAnim();

	//�G�����ʃA�j���[�V�����ɂȂ邩�m�F����p
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
};

