#pragma once
class Stage
{
private:
	int Cloud;//�_�̉摜
	int St_Footing;//
	int St_Land_Left;
	int St_Land_Right;
	int St_Sea;
	int stage1;

public:
	//�R���X�g���N�^
	Stage();
	~Stage();

	void DrawStage() const;
};

