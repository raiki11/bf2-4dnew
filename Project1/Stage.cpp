#include "Stage.h"
#include "DxLib.h"

Stage::Stage() {/*
	St_Footing = LoadGraph("images/Stage/Stage_Footing01.png");
	Cloud = LoadGraph("images/Stage/Stage_Cloud01.png");*/
	stage1 = LoadGraph("images/StageSample/Stage_1.png");

}

void Stage::DrawStage()const{
	DrawGraph(0, 0, stage1, TRUE);
}