#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "HitBox.h"
#include "Fish.h"
#include "UI.h"
#include"Thunder.h"
#include "TitleScene.h"
#include"Bubble.h"
// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ����Ǘ�����

class GameMain :
    public AbstractScene
{
private:
    //�Q�[�����C���Ŏg���ϐ��̐錾
    Stage stage;
    UI UI;
    //�Q�[�����C���Ŏg���ϐ��̐錾
    Player player;
    //Enemy enemy;

    //Enemy enemy2;
    //Enemy enemy3;
    HitBox hit;
    Fish fish;
    Thunder thunder;
    bool PauseFlg;            // �|�[�Y
    
    bool ClearFlg;            //�X�e�[�Wclear�t���O
    int Elast;                //�Ō�̃G�l�~�[�̔ԍ��󂯎��p
    int count;

    int OldSnum;//�X�e�[�W����r�p

    int fishi;//�T�J�i�ɓn���G�l�~�[�̔ԍ��ۊǗp
    int playerAndFishFlg;

    int a;
    int reboundFlg[20];
    int reboundPflg;
    //BGM�p�ϐ�
    int BGM;
    // SE�p�ϐ�
    int Start_SE;
    int SE_crack;
    int SE_defealtheenemy;
    int SE_eatable;
    int SE_enemymove;
    int SE_falling;
    int SE_parachute;
    int SE_perfect;
    int SE_restart;
    int SE_splash;
    int SE_stageclear;
    int o; // SEnokaisuu

    int SE_playerjump;
    int SE_playerwalk;

  
    //int reboundFlg;

    bool BubbleFlg;//�V���{���ʗp�t���O
    int getenemyX[6]={0,0,0,0,0,0};

    bool GameoverFlg;//�Q�[���I�[�o�[�t���O
    int image;  //gameover�摜�\��

public:

    // �R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;
    int tst;

    /* �f�o�b�N�p */
    int b;
};