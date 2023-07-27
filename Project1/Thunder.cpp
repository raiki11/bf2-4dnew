#include"Thunder.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>

Thunder::Thunder() 
{
	LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, ThunderImg);
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

		ChangeAngle();
	}
	else {
		ThunderX += MoveX;
		ThunderY += MoveY;
	}
	//ThunderFlg = 0;  // 雷の状態を移動中に設定する
	//// スピードとアングルによる移動量計算
	//ThunderSpeed = 1;
	//ThunderAngle = 0.625f;

	//ChangeAngle();

	/* 壁・天井の反射 */
	if (ThunderX < 32 || ThunderX > 640 - 32) {
		if (ThunderX < 32) {
			ThunderX = 32;
		}
		else {
			ThunderX = 640 - 32;
		}
		ThunderAngle = (1 - ThunderAngle) + 0.5f;
		if (ThunderAngle > 1)ThunderAngle -= 1.0f;
		ChangeAngle();
	}

	if (ThunderY < 8) {
		ThunderAngle = (1 - ThunderAngle);
		ChangeAngle();
	}
	if (ThunderY > 480 + 32) { // 雷が画面下に落ちた時
		ThunderFlg = 2; // 雷をスタート状態にする
	}


	//デバッグ
	//// 雷のX座標
	//ThunderX = 200;
	//// 雷のY座標
	//ThunderY = 350;

}

void Thunder::ThunderDraw() const
{
	DrawRotaGraph(ThunderX, ThunderY, 1.0f, 0, ThunderImg[2], TRUE, FALSE);
	DrawFormatString(400, 130, 0xffffff, "ThunderLocationX::%d", ThunderX);
	DrawFormatString(400, 230, 0xffffff, "ThunderLocationY::%d", ThunderY);
}

void Thunder::ChangeAngle()
{
	float rad = ThunderAngle * (float)M_PI * 2;
	MoveX = (int)(ThunderSpeed * cosf(rad));
	MoveY = (int)(ThunderSpeed * sinf(rad));
}
