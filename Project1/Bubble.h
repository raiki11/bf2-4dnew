#pragma once

class Bubble {
private:
	// �o�u���̉摜�\��
	int BubbleImg[4];

	// �o�u���̔������W
	float BabbleX;
	float BabbleY;

	double rad;
	int count;
	int flg;//0:X���W�v���X 1:X���W���̂܂܁@2:X���W�}�C�i�X

	//�o�u���̈ړ��p
	double additionX;
	double additionY;

	//�o�u���̓����蔻��p

public:
	// �R���X�g���N�^
	Bubble();

	// �f�X�g���N�^
	~Bubble();

	// �o�u���̃A�b�v�f�[�g
	void BabbleUpdate();

	// �o�u���̕`��
	void BabbleDraw() const;
};
