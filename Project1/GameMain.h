#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "HitBox.h"
#include "Fish.h"
#include "UI.h"
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
    bool PauseFlg;            // �|�[�Y
    
    bool ClearFlg;            //�X�e�[�Wclear�t���O
    int Elast;                //�Ō�̃G�l�~�[�̔ԍ��󂯎��p
    bool once;                //��񂾂�
    int count;

    int OldSnum;//�X�e�[�W����r�p

    int a;
    int reboundFlg;
   
public:

    // �R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

    //�G�l�~�[�`�F�b�N
    void CheckEnemy(void);
};