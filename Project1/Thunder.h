#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

class Thunder {
private:
	// ���̉摜
	int ThunderImg[3];
	// ����X���W
	float ThunderX;
	// ����Y���W
	float ThunderY;
	// ���̃t���O
	int ThunderFlg; // ���̏�ԁi0: �ړ��� 1: �o�[�ڐG 2: �ҋ@��ԁj
	
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
	void ChangeAngle(/*float MoveX,float MoveY*/);

	// �X�s�[�h�t���O
	int ThunderSpeed;
	// ���̊p�x
	float ThunderAngle;


	//���W���l���A�ǋL�� �k��
	float GetThunderX() { return ThunderX; }
	float GetThunderY() { return ThunderY; }

	// �����ʂ��擾
	float GetThunderMoveLocationX() { return MoveX; }
	float GetThunderMoveLocationY() { return MoveY; }
};
