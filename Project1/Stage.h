#pragma once
class Stage
{
private:
	int St_Footing;		//���������̉摜
	int St_Land_Left;	//���̒n�ʂ̉摜
	int St_Land_Right;	//�E�̒n�ʂ̉摜
	int St_Sea;			//�C�̉摜
	int cloud;			//�_�̉摜
	int stage1;			//�X�e�[�W�̉��摜

public:
	//�R���X�g���N�^
	Stage();
	~Stage();

	void DrawStage() const;
};

