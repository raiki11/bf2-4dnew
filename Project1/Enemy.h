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
	int Estate;

	static int Score;

	int changeimg;//�G�l�~�[�����摜�؂�ւ��p
	int changeCt;//�摜�؂�ւ��̃J�E���g
	float cy;		//�G���|���ꂽ�Ƃ���Y���W���Z�p
	int swy;		//�G���|���ꂽ�Ƃ��̍��W���Z�؂�ւ��p
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
	int n_score;	// ���݂̃X�R�A
	int hi_score;	// �n�C�X�R�A

public:
	Enemy(int set_X,int set_Y);
	~Enemy();

	int cflg;		//���S�A�j���[�V�����t���O
	static int DeadFlg;		//���S�t���O
	static int EdeadCount;//�G�l�~�[�����ꂽ���̃J�E���g
	static int ElastFlg;	//�Ō�̈�C���m�F����t���O

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
	int spc;
	bool spflg;


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

	static int GetScore() { return Score; }

	int EScore();
    int  Eflg;
	 int c;
	 bool once;
	 void ECheckY();
};

