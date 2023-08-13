#include"Bubble.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>


#define DEGREE_RADIAN(_deg)	(M_PI*(_deg)/180.0f)


Bubble::Bubble() 
{
	LoadDivGraph("images/Stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg);
	BabbleX = 300;
	BabbleY = 400;
	additionX = 0;
	additionY = 0;
	count = 0;
	rad = DEGREE_RADIAN(180.0);
	flg = 0;
	Px = 0;
	Py = 0;
	babbleaddX = 0;
	babbleaddY = 0;
	a, b, c = 0;
	check = FALSE;
}

Bubble::~Bubble() 
{

}

void Bubble::BabbleUpdate(Player p, Enemy e)
{
	//座標受け取って当たり判定するのと、エネミーが死んだ時の座標貰ってそこから発生させる
	//BabbleX += 1/sqrt(2);
	//BabbleY -= 1 / sqrt(2);
	
	Px=p.GetPlayerLocationX();
	Py=p.GetPlayerLocationY();

	babbleaddX = BabbleX + additionX;
	babbleaddY = BabbleY + additionY;

	a = babbleaddX - Px;
	b = babbleaddY - Py;
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

	if (c+10 <= 20) {
		check = TRUE;
	}
	else {
		check = FALSE;
	}

	//switch (flg) {
	//case 0:
	//	additionX += 0.15;
	//	additionY -= 0.3;
	//	if (additionX > 13.5) {
	//		flg = 1;
	//	}
	//	break;
	//case 1:
	//	additionX += 0.3;
	//	additionY -= 0.2;
	//	if (count++ > 5) {
	//		count = 0;
	//		flg = 2;
	//	}
	//	break;
	//case 2:
	//	additionY -= 0.2;
	//	if (count++ > 20) {
	//		count = 0;
	//		flg = 3;
	//	}
	//	break;
	//case 3:
	//	additionX -= 0.15;
	//	additionY -= 0.3;
	//	if (additionX < -13) {
	//		flg = 4;
	//	}
	//	break;
	//case 4:
	//	additionX -= 0.3;
	//	additionY -= 0.2;
	//	if (count++ > 5) {
	//		count = 0;
	//		flg = 5;
	//	}
	//case 5:
	//	additionY -= 0.2;
	//	if (count++ > 20) {
	//		count = 0;
	//		flg = 0;
	//	}
	//	break;
	//default:
	//	break;
	//}


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

		//additionX =sin(rad);


	//64*64の真ん中

}

void Bubble::BabbleDraw() const 
{
	DrawRotaGraph(BabbleX+additionX, BabbleY+additionY, 1.0f, 0, BubbleImg[0], TRUE, FALSE);
	DrawCircle(BabbleX + additionX, BabbleY + additionY, 20, 0xffffff, TRUE);
	DrawCircle(BabbleX + additionX, BabbleY + additionY, 2, 0xff00ff, TRUE);
	DrawCircle(Px,Py, 2, 0xfff0ff, TRUE);
	DrawBox(Px-24, Py-20, Px+24, Py+34, 0xffffff, FALSE);
	DrawFormatString(400, 400, 0xffffff, "addX%f", additionX);
	DrawFormatString(400, 440, 0xffffff, "addY%f", additionY);
	if (check == TRUE) {
		DrawCircle(BabbleX + additionX, BabbleY + additionY, 20, 0xff00ff, TRUE);

	}
}