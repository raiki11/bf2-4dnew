#include "Stage.h"
#include "DxLib.h"

Stage::Stage() {
	St_Footing = LoadGraph("images/Stage/Stage_Footing01.png");
	St_Footing2 = LoadGraph("images/Stage/Stage_Footing02.png");
	St_Footing3 = LoadGraph("images/Stage/Stage_Footing03.png");
	St_FootingT = LoadGraph("images/Stage/Stage_Footing04.png");
	St_FootingM = LoadGraph("images/Stage/Stage_Footing05.png");

	St_Footing6= LoadGraph("images/Stage/Stage_Footing06.png");
	St_Footing7 = LoadGraph("images/Stage/Stage_Footing07.png");
	St_Footing8 = LoadGraph("images/Stage/Stage_Footing08.png");

	St_Land_Left = LoadGraph("images/Stage/Stage_Land_Left01.png");
	St_Land_Right = LoadGraph("images/Stage/Stage_Land_Right01.png");
	St_LL= LoadGraph("images/Stage/Stage_Land_Left02.png");
	St_LR= LoadGraph("images/Stage/Stage_Land_Right02.png");
	St_Sea= LoadGraph("images/Stage/Stage_Sea01.png");
	cloud = LoadGraph("images/Stage/Stage_Cloud01.png");

	stage1 = LoadGraph("images/StageSample/Stage_4.png");

}

Stage::~Stage() {

}



void Stage::DrawStage()const{
	//Stage1();
	//Stage2();
	//Stage3();
	Stage4();
}

void Stage::Stage1()const {
	//�X�e�[�W1�̕\��
	//�����̕\��
	DrawGraph(175, 280, St_Footing, TRUE);
	DrawBox(175, 282, 455, 297, 0xff0000, FALSE);

	//�����̒n�ʕ\��
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//�E���̒n�ʕ\��
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//�C�\��
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//�_�\��
	DrawGraph(321, 87, cloud, TRUE);
}

void Stage::Stage2()const {
	//�����̕\��
	DrawGraph(175, 280, St_Footing, TRUE);
	DrawBox(175, 282, 455, 297, 0xff0000, FALSE);

	//�����E��̕\��
	DrawGraph(100, 167, St_Footing2, TRUE);
	DrawBox(100, 169, 222, 184, 0xff0000, FALSE);

	//��������̕\��
	DrawGraph(460, 150, St_Footing2, TRUE);
	DrawBox(460, 152, 582, 167, 0xff0000, FALSE);

	//�����̒n�ʕ\��
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//�E���̒n�ʕ\��
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//�C�\��
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//�_���\��
	DrawGraph(80, 220, cloud, TRUE);
	//�_�E�\��
	DrawGraph(480, 188, cloud, TRUE);
}

void Stage::Stage3()const {

//�E��T�����\��
DrawGraph(160, 268, St_FootingT, TRUE);
DrawBox(160,270,221,285,0xff0000,FALSE);//��
DrawBox(181, 285, 199, 333, 0x00ff00, FALSE);//�c

//����T�����\��
DrawGraph(318, 182, St_FootingT, TRUE);
DrawBox(318, 184, 379, 199,0xff0000, FALSE);//��
DrawBox(339, 199, 357, 247, 0x00ff00, FALSE);//�c

////����T�����\��
DrawGraph(500, 99, St_FootingT, TRUE);
DrawBox(500, 101, 561, 116, 0xff0000, FALSE);//��
DrawBox(521, 116, 539, 164, 0x00ff00, FALSE);//�c

//�E�㏬���������\��
DrawGraph(200, 99, St_FootingM, TRUE);
DrawBox(200, 101, 242, 117, 0xff0000, FALSE);

//�������̕����\��
DrawGraph(280, 365, St_Footing3, TRUE);
DrawBox(280, 367, 361, 383, 0xff0000, FALSE);

//�����̒n�ʕ\��
DrawGraph(0, 414, St_Land_Left, TRUE);
DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

//�E���̒n�ʕ\��
DrawGraph(480, 414, St_Land_Right, TRUE);
DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

//�C�\��
DrawGraph(160, 442, St_Sea, TRUE);
DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

//�_���\��
DrawGraph(80, 121, cloud, TRUE);
//�_�E�\��
DrawGraph(441, 253, cloud, TRUE);
}

void Stage::Stage4()const {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawGraph(0, 0, stage1, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//���[�����\��
	DrawGraph(120, 265, St_Footing6, TRUE);
	DrawBox(120, 265, 182, 283, 0x00ffff, FALSE);

	//���������\��
	DrawGraph(240, 300, St_Footing6, TRUE);

	//�㑤�����\��
	DrawGraph(320, 182, St_Footing6, TRUE);

	//���������\��
	DrawGraph(360, 366, St_Footing6, TRUE);

	//�E�[�����\��
	DrawGraph(460, 285, St_Footing6, TRUE);



	//�����̒n�ʕ\��
	DrawGraph(0, 414, St_LL, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//�E���̒n�ʕ\��
	DrawGraph(480, 414, St_LR, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//�C�\��
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//�_���\��
	DrawGraph(160, 85, cloud, TRUE);
	//�_�E�\��
	DrawGraph(480, 152, cloud, TRUE);

}