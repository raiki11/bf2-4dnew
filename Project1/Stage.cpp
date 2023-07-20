#include "Stage.h"
#include "DxLib.h"

float Stage::EnemyX[stagenum][6] = { {320,420,220},{320,420,220,440},{320,420,220,440},{320,420,220,440},{320,420,220,440} };
float Stage::EnemyY[stagenum][6] = { {230,230,230},{230,230,230,230},{320,420,220,440},{320,420,220,440},{320,420,220,440} };
//ステージごとのエネミー数



int Stage::Snum = 0;
int Stage::EnemyMax[5]={2,3,2,2,2};

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

	stage1 = LoadGraph("images/StageSample/Stage_5.png");

}

Stage::~Stage() {

}



void Stage::DrawStage()const{
	Stage1();
	//Stage2();
	//Stage3();
	//Stage4();
	//Stage5();
}

void Stage::Stage1()const {
	//ステージ1の表示
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
	DrawGraph(321, 87, cloud, TRUE);
}

void Stage::Stage2()const {
	//浮島の表示
	DrawGraph(175, 280, St_Footing, TRUE);
	DrawBox(175, 282, 455, 297, 0xff0000, FALSE);

	//浮島右上の表示
	DrawGraph(100, 167, St_Footing2, TRUE);
	DrawBox(100, 169, 222, 184, 0xff0000, FALSE);

	//浮島左上の表示
	DrawGraph(460, 150, St_Footing2, TRUE);
	DrawBox(460, 152, 582, 167, 0xff0000, FALSE);

	//左下の地面表示
	DrawGraph(0, 414, St_Land_Left, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//右下の地面表示
	DrawGraph(480, 414, St_Land_Right, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//海表示
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//雲左表示
	DrawGraph(80, 220, cloud, TRUE);
	//雲右表示
	DrawGraph(480, 188, cloud, TRUE);
}

void Stage::Stage3()const {

//右下T浮島表示
DrawGraph(160, 268, St_FootingT, TRUE);
DrawBox(160,270,221,285,0xff0000,FALSE);//横
DrawBox(181, 285, 199, 333, 0x00ff00, FALSE);//縦

//中央T浮島表示
DrawGraph(318, 182, St_FootingT, TRUE);
DrawBox(318, 184, 379, 199,0xff0000, FALSE);//横
DrawBox(339, 199, 357, 247, 0x00ff00, FALSE);//縦

////左上T浮島表示
DrawGraph(500, 99, St_FootingT, TRUE);
DrawBox(500, 101, 561, 116, 0xff0000, FALSE);//横
DrawBox(521, 116, 539, 164, 0x00ff00, FALSE);//縦

//右上小さい浮島表示
DrawGraph(200, 99, St_FootingM, TRUE);
DrawBox(200, 101, 242, 117, 0xff0000, FALSE);

//中央下の浮島表示
DrawGraph(280, 365, St_Footing3, TRUE);
DrawBox(280, 367, 361, 383, 0xff0000, FALSE);

//左下の地面表示
DrawGraph(0, 414, St_Land_Left, TRUE);
DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

//右下の地面表示
DrawGraph(480, 414, St_Land_Right, TRUE);
DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

//海表示
DrawGraph(160, 442, St_Sea, TRUE);
DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

//雲左表示
DrawGraph(80, 121, cloud, TRUE);
//雲右表示
DrawGraph(441, 253, cloud, TRUE);
}

void Stage::Stage4()const {


	//左端浮島表示
	DrawGraph(120, 265, St_Footing6, TRUE);
	DrawBox(120, 267, 182, 283, 0x00ffff, FALSE);

	//左側浮島表示
	DrawGraph(240, 300, St_Footing6, TRUE);
	DrawBox(240, 302, 302, 318, 0x00ffff, FALSE);

	//上側浮島表示
	DrawGraph(320, 182, St_Footing6, TRUE);
	DrawBox(320, 184, 382, 200, 0x00ffff, FALSE);

	//下側浮島表示
	DrawGraph(360, 366, St_Footing6, TRUE);
	DrawBox(360, 368, 422, 384, 0x00ffff, FALSE);

	//右端浮島表示
	DrawGraph(460, 285, St_Footing6, TRUE);	
	DrawBox(460, 287, 522, 303, 0x00ffff, FALSE);

	//左下の地面表示
	DrawGraph(0, 414, St_LL, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//右下の地面表示
	DrawGraph(480, 414, St_LR, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//海表示
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//雲左表示
	DrawGraph(160, 85, cloud, TRUE);
	//雲右表示
	DrawGraph(480, 152, cloud, TRUE);

}

void Stage::Stage5()const {

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawGraph(0, 0, stage1, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//茶色の浮島　海面付近の左
	DrawGraph(200, 330, St_Footing6, TRUE);
	DrawBox(201, 332, 260, 348, 0x00ff00, FALSE);

	//茶色の浮島　海面付近の右
	DrawGraph(380, 335, St_Footing6, TRUE);
	DrawBox(381, 337, 440, 353, 0x00ff00, FALSE);

	//茶色の浮島　上
	DrawGraph(220, 80, St_Footing6, TRUE);
	DrawBox(221, 82, 280, 98, 0x00ff00, FALSE);


	//i字型浮島左端
	DrawGraph(100, 200, St_Footing7, TRUE);
	DrawBox(101, 202, 120, 251, 0x00ff00, FALSE);

	//i字型浮島中央
	DrawGraph(260, 168, St_Footing7, TRUE);
	DrawBox(261, 170, 280, 219, 0x00ff00, FALSE);

	//i字型の長い浮島右端
	DrawGraph(500, 150, St_Footing8, TRUE);
	DrawBox(501, 152, 520, 217, 0x00ff00, FALSE);

	//左下の地面表示
	DrawGraph(0, 414, St_LL, TRUE);
	DrawBox(0, 419, 160, 480, 0xff0000, FALSE);

	//右下の地面表示
	DrawGraph(480, 414, St_LR, TRUE);
	DrawBox(480, 419, 640, 480, 0xff0000, FALSE);

	//海表示
	DrawGraph(160, 442, St_Sea, TRUE);
	DrawBox(160, 419, 480, 478, 0x00ff00, FALSE);

	//雲左表示
	DrawGraph(80, 85, cloud, TRUE);
	//雲右表示
	DrawGraph(360, 121, cloud, TRUE);

}

	//デバッグ
	//DrawFormatString(100, 0, 0xffffff, "%d", StageXY[0][0][1]);
