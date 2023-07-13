#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "UI.h"
#include "Enemy.h"
#include "Stage.h"
// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ����Ǘ�����

class End :
    public AbstractScene
{
private:
    int image;
    Stage stage;
    UI UI;
    //�Q�[�����C���Ŏg���ϐ��̐錾
    Player player;
    Enemy enemy;
public:
    int EndCount = 0;

    // �R���X�g���N�^
    End();

    //�f�X�g���N�^
    ~End();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

private:
};