#include"Thunder.h"
#include"DxLib.h"


Thunder::Thunder() 
{
	LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, ThunderImg);
	MoveX = 0.0f;
	MoveY = 0.0f;
	// 雷のX座標
	ThunderX = 300.0;
	// 雷のY座標
	ThunderY = 400.0;
}

Thunder::~Thunder()
{

}

void Thunder::ThunderUpdate() 
{
	if (ThunderFlg == 2) {
		ThunderFlg = 0;  // 雷の状態を移動中に設定する
		// スピードとアングルによる移動量計算
		ThunderSpeed = 2;
		ThunderAngle = 0.625f;

		ChangeAngle(/*MoveX,MoveY*/);
	}
	else {
		ThunderX += MoveX;
		ThunderY += MoveY;
	}

	/* 壁・天井の反射 */
	if (ThunderX < 16 || ThunderX > 640 - 16) {
		if (ThunderX < 16) {
			ThunderX = 16;
		}
		else {
			ThunderX = 640 - 16;
		}
		ThunderAngle = (1 - ThunderAngle) + 0.5f;
		if (ThunderAngle > 1)ThunderAngle -= 1.0f;
		ChangeAngle(/*MoveX,MoveY*/);
	}

	if (ThunderY < 8) {
		ThunderAngle = (1 - ThunderAngle);
		ChangeAngle(/*MoveX,MoveY*/);
	}
	//if (ThunderY > 480 + 32) { // 雷が画面下に落ちた時
	//	ThunderFlg = 2; // 雷をスタート状態にする
	//}


	//デバッグ
	//// 雷のX座標
	//ThunderX = 200;
	//// 雷のY座標
	//ThunderY = 350;

}

void Thunder::ThunderDraw() const
{
	DrawRotaGraph(ThunderX, ThunderY, 1.0f, 0, ThunderImg[2], TRUE, FALSE);
	/* デバック用 */
	DrawFormatString(400, 130, 0xffffff, "ThunderLocationX::%f", ThunderX);
	DrawFormatString(400, 230, 0xffffff, "ThunderLocationY::%f", ThunderY);
	DrawFormatString(400, 260, 0xffffff, "MoveX::%f", MoveX);
	DrawFormatString(400, 290, 0xffffff, "MoveY::%f", MoveY);

}

void Thunder::ChangeAngle(/*float MoveX,float MoveY*/)
{
	float rad = ThunderAngle * (float)M_PI * 2;
	MoveX = (float)(ThunderSpeed * cosf(rad));
	MoveY = (float)(ThunderSpeed * sinf(rad));
}
