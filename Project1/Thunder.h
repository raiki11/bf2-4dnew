#pragma once

class Thunder {
private:

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

	// ���̉摜
	int ThunderImg[3];

	// ����X���W
	int ThunderX = 300;
	// ����Y���W
	int ThunderY = 200;
	// ���̃t���O
	int ThunderFlg = 2; // ���̏�ԁi0: �ړ��� 1: �o�[�ڐG 2: �ҋ@��ԁj
	// �X�s�[�h�t���O
	int ThunderSpeed; 
	// ���̊p�x
	float ThunderAngle;
	// ��������X���W�̗�
	int MoveX;
	// ��������Y���W�̗�
	int MoveY;  
	// ���̓����蔻���p�̍��W
	int tx1 = ThunderX - 32;
	int tx2 = ThunderX + 32;
	int ty1 = ThunderY - 32;
	int ty1 = ThunderY + 32;

};
