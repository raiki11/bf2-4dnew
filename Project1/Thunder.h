#pragma once

class Thunder {
private:
	// ���̉摜
	int ThunderImg[3];
	// ����X���W
	float ThunderX = 300;
	// ����Y���W
	float ThunderY = 400;
	// ���̃t���O
	int ThunderFlg = 2; // ���̏�ԁi0: �ړ��� 1: �o�[�ڐG 2: �ҋ@��ԁj
	// �X�s�[�h�t���O
	int ThunderSpeed;
	// ���̊p�x
	float ThunderAngle = 0.625f;
	// ��������X���W�̗�
	float MoveX;
	// ��������Y���W�̗�
	float MoveY;
	//// ���̓����蔻���p�̍��W
	//int tx1 = ThunderX - 32;
	//int tx2 = ThunderX + 32;
	//int ty1 = ThunderY - 32;
	//int ty2 = ThunderY + 32;

public:
	// �R���X�g���N�^
	Thunder();

	// �f�X�g���N�^
	~Thunder();

	// ���̃A�b�v�f�[�g
	void ThunderUpdate();

	// ���̕`��
	void ThunderDraw() const;

	// �p�x����
	void ChangeAngle();

	// ����X���W�������Ă���֐�
	float GetThunderLocationX() { return ThunderX; }
	// ����Y���W�������Ă���֐�
	float GetThunderLocationY() { return ThunderY; }
	// ���������Ă���X���W�������Ă���֐�
	float GetThunderMoveLocationX() { return MoveX; }
	// ���������Ă���Y���W�������Ă���֐�
	float GetThunderMoveLocationY() { return MoveY; }
	
};
