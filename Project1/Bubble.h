#pragma once

class Babble {
private:

public:
	// �R���X�g���N�^
	Babble();

	// �f�X�g���N�^
	~Babble();

	// �o�u���̃A�b�v�f�[�g
	void BabbleUpdate();

	// �o�u���̕`��
	void BabbleDraw() const;

	// �o�u���̍��W
	int BabbleX;
	int BabbleY;

};
