#pragma once

class Thunder {
private:
	// ���̉摜
	int ThunderImg[3];
	// ����X���W
	float ThunderX;
	// ����Y���W
	float ThunderY;
	// ���̃t���O
	int ThunderFlg = 2; // ���̏�ԁi0: �ړ��� 1: �o�[�ڐG 2: �ҋ@��ԁj
	// �X�s�[�h�t���O
	int ThunderSpeed;
	// ���̊p�x
	float ThunderAngle = 0.625f;
	// ��������X���W�̗�
	int MoveX;
	// ��������Y���W�̗�
	int MoveY;
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

	// ���̓����蔻���p�̍��W
	int tx1 = ThunderX - 32;
	int tx2 = ThunderX + 32;
	int ty1 = ThunderY - 32;
	int ty2 = ThunderY + 32;




	//���W���l���A�ǋL�� �k��
	int GetThunderX() { return ThunderX; }
	int GetThunderY() { return ThunderY; }

	// �����ʂ��擾
	float GetThunderMoveLocationX() { return MoveX; }
	float GetThunderMoveLocationY() { return MoveY; }
};
