#include"Bubble.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>


#define DEGREE_RADIAN(_deg)	(M_PI*(_deg)/180.0f)

Bubble::Bubble() {
	babbleaddX = 0;
	LoadDivGraph("images/Stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg);
	BabbleY = 500;
	additionX = 0;
	additionY = 0;
	count = 0;
	rad = DEGREE_RADIAN(180.0);
	flg = TRUE;
	Px = 0;
	Py = 0;
	babbleaddY = BabbleY;
	a, b, c = 0;
	check = FALSE;
	bimgnum = 0;
	bimgcnt = 0;
	amp = 0.85f;
	fre = 0.9f;
	BDeleteFlg = FALSE;
}

Bubble::~Bubble() 
{

}

void Bubble::BubbleUpdate(Player p, int ex)
{
	//座標受け取って当たり判定するのと、エネミーが死んだ時の座標貰ってそこから発生させる
	//BabbleX += 1/sqrt(2);
	//BabbleY -= 1 / sqrt(2);
	
	if(flg==TRUE){
		babbleaddX = ex;
		flg = FALSE;
	}


	Px=p.GetPlayerLocationX();
	Py=p.GetPlayerLocationY()+10;

	//babbleaddX = BabbleX + additionX;


	a = Px - babbleaddX;
	b = Py - babbleaddY;
	c = sqrt((a * a) + (b * b));
	
	//switch (count++)
	//{
	//case 0:
	//	rad = DEGREE_RADIAN(0);
	//	break;
	//case 10:
	//	rad = DEGREE_RADIAN(45.0);
	//	break;
	//case 20:
	//	rad = DEGREE_RADIAN(90.0);
	//	break;
	//case 30:
	//	rad = DEGREE_RADIAN(135.0);
	//	break;
	//case 40:
	//	rad = DEGREE_RADIAN(180.0);
	//	break;
	//case 50:
	//	rad = DEGREE_RADIAN(225.0);
	//	break;
	//case 60:
	//	rad = DEGREE_RADIAN(270.0);
	//	break;
	//case 70:
	//	rad = DEGREE_RADIAN(315.0);
	//	break;
	//case 80:
	//	rad = DEGREE_RADIAN(360.0);
	//	break;
	//case 90:
	//	count = 0;
	//	break;
	//default:
	//	break;
	//}

	//0~1~0~-1

	if (c <= 50) {
		check = TRUE;
	}

	/*
	switch (flg) {
	case 0:
		additionX += 0.3;
		if (additionX > 13) {
			flg = 1;
		}
		break;
	case 1:
		additionX -= 0.1;
		if (count++ > 5) {
			count = 0;
			flg = 2;
		}
		break;
	case 2:
		if (count++ > 5) {
			count = 0;
			flg = 3;
		}
		break;
	case 3:
		additionX -= 0.3;
		if (additionX < -13) {
			flg = 4;
		}
		break;
	case 4:
		if (count++ > 5) {
			count = 0;
			flg = 5;
		}
	case 5:
		additionX += 0.1;
		if (count++ > 5) {
			count = 0;
			flg = 0;
		}
		break;
	default:
		break;
	}*/


		if (check == TRUE) {
			//スコア＋５００
			//シャボン玉消去
			BDeleteFlg = TRUE;
		}
		else {
			count++;
			babbleaddY -= 0.18;
			if (count > 2) {
				babbleaddX += amp * sin(fre * GetNowCount() / 300.0f);
				count = 0;
			}
		}


		if (bimgcnt++>200) {
			bimgnum += 1;
			bimgcnt = 0;
		}

		if (bimgnum == 2) {
			bimgnum = 0;
		}

}

void Bubble::BubbleDraw() const 
{
	//DrawCircle(BabbleX + additionX, BabbleY + additionY, 20, 0xffffff, TRUE);
	DrawCircle(BabbleX + additionX, BabbleY + additionY, 2, 0xff00ff, TRUE);
	DrawCircle(Px,Py, 2, 0xfff0ff, TRUE);
	DrawBox(Px-24, Py-20, Px+24, Py+34, 0xffffff, FALSE);
	DrawFormatString(400, 400, 0xffffff, "addX%f", additionX);
	DrawFormatString(400, 440, 0xffffff, "addY%f", additionY);
	if (check == TRUE) {
		//DrawCircle(BabbleX + additionX, BabbleY + additionY, 20, 0xff00ff, TRUE);
		DrawRotaGraph(babbleaddX,babbleaddY, 1.0f, 0, BubbleImg[3], TRUE, FALSE);

	}
	else {
		DrawRotaGraph(babbleaddX, babbleaddY, 1.0f, 0, BubbleImg[bimgnum], TRUE, FALSE);

	}
}

int Bubble::BubbleDelete() {

	if (BDeleteFlg == TRUE) {
		return TRUE;
	}
	return FALSE;
}