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

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawGraph(0, 0, stage1, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawGraph(0, 0, St_Footing, TRUE);
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawGraph(160, 414, St_Sea, TRUE);
	DrawGraph(321, 87,cloud,TRUE);
}