#pragma once

class Bubble {
private:

public:
	// �R���X�g���N�^
	Bubble();

	// �f�X�g���N�^
	~Bubble();

	// �o�u���̃A�b�v�f�[�g
	void BabbleUpdate();

	// �o�u���̕`��
	void BabbleDraw() const;

	// �o�u���̉摜�\��
	int BubbleImg[4];

	// �o�u���̍��W
	int BabbleX = 400;
	int BabbleY = 300;

};
