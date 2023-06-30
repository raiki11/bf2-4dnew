#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
#include "Stage.h"

// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ����Ǘ�����

class GameMain :
    public AbstractScene
{
private:
    //�Q�[�����C���Ŏg���ϐ��̐錾
    Stage stage;

public:

    // �R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;


};