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
	//ステージ仮表示
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	//DrawGraph(0, 0, stage1, TRUE);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//ステージ表示
	//浮島の表示
	DrawGraph(175, 280, St_Footing, TRUE);
	DrawBox(175, 280, 455, 297, 0xff0000, FALSE);

	//左下の地面表示
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawBox(0, 414, 160, 480, 0xff0000, FALSE);

	//右下の地面表示
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawBox(480, 414, 640, 480, 0xff0000, FALSE);

	//海表示
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 442, 480, 414, 0x0000ff, TRUE);
	DrawBox(160, 442, 480, 478, 0x00ff00, TRUE);

	//雲表示
	DrawGraph(321, 87,cloud,TRUE);
}
