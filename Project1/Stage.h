#pragma once
class Stage
{
private:
	int St_Footing;		//
	int St_Land_Left;	//
	int St_Land_Right;	//
	int St_Sea;			//�C�̉摜
	int cloud;			//�_�̉摜
	int stage1;			//�X�e�[�W�̉��摜

public:
	//�R���X�g���N�^
	Stage();
	~Stage();

	void DrawStage() const;
};

