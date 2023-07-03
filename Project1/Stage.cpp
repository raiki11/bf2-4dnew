#include "Stage.h"
#include "DxLib.h"

Stage::Stage() {
	St_Footing = LoadGraph("images/Stage/Stage_Footing01.png");
	St_Land_Left= LoadGraph("images/Stage/Stage_Land_Left01.png");
	St_Land_Right= LoadGraph("images/Stage/Stage_Land_Right01.png");
	St_Sea= LoadGraph("images/Stage/Stage_Sea01.png");
	cloud = LoadGraph("images/Stage/Stage_Cloud01.png");
	stage1 = LoadGraph("images/StageSample/Stage_1.png");

}

Stage::~Stage() {

}



void Stage::DrawStage()const{
	//�X�e�[�W���\��
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	//DrawGraph(0, 0, stage1, TRUE);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//�X�e�[�W�\��
	//�����̕\��
	DrawGraph(175, 280, St_Footing, TRUE);
	DrawBox(175, 280, 455, 297, 0xff0000, FALSE);

	//�����̒n�ʕ\��
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawBox(0, 414, 160, 480, 0xff0000, FALSE);

	//�E���̒n�ʕ\��
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawBox(480, 414, 640, 480, 0xff0000, FALSE);

	//�C�\��
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 442, 480, 414, 0x0000ff, TRUE);
	DrawBox(160, 442, 480, 478, 0x00ff00, TRUE);

	//�_�\��
	DrawGraph(321, 87,cloud,TRUE);
}
