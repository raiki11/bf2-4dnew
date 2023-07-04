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

	//ステージ表示
	//浮島の表示
	DrawGraph(175, 280, St_Footing, TRUE);
	DrawBox(175, 282, 455, 297, 0xff0000, FALSE);

	//左下の地面表示
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//右下の地面表示
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//海表示
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//雲表示
	DrawGraph(321, 87,cloud,TRUE);
}
