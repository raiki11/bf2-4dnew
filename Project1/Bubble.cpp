#include"Bubble.h"
#include"DxLib.h"
#include "Enemy.h"
#define _USE_MATH_DEFINES
#include<math.h>


#define DEGREE_RADIAN(_deg)	(M_PI*(_deg)/180.0f)



Bubble::Bubble() {
	babbleaddX = 0;
	LoadDivGraph("images/Stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg);
	BabbleY = 500;
	count = 0;
	flg = TRUE;
	Px = 0;
	Py = 0;
	babbleaddY = BabbleY;
	a, b, c = 0;
	check = 0;
	bimgnum = 0;
	bimgcnt = 0;
	amp = 1.5f;
	fre = 0.9f;
	BDeleteFlg = FALSE;
	BscoFlg = TRUE;
	Bscoimg = LoadGraph("images/Score/GetScore_500.png");
	pdeathFlg = FALSE;
	//BGMÇÃâπó ïœçX
	SE_bubble= LoadSoundMem("sounds/SE_Bubble.wav");
	ChangeVolumeSoundMem(70, SE_bubble);

}

Bubble::~Bubble() 
{

}

void Bubble::BubbleUpdate(Player p, int ex)
{

	pdeathFlg = p.GetDeathFlg();

	if (check != 2) {
		if (flg == TRUE) {
			babbleaddX = ex;
			flg = FALSE;
		}

		Px = p.GetPlayerLocationX();
		Py = p.GetPlayerLocationY() + 10;

		a = Px - babbleaddX;
		b = Py - babbleaddY;
		c = sqrt((a * a) + (b * b));

		if (pdeathFlg != TRUE) {
			if (c <= 50) {
				check = 1;
			}
		}

		if (check == 1) {
			//ÉXÉRÉAÅ{ÇTÇOÇO
			if (BscoFlg == TRUE) {
				Enemy::Score += 500;
				BscoFlg = FALSE;
			}

			//ÉVÉÉÉ{Éìã è¡ãé
			if (count++ > 3) {
				check = 2;
				//BDeleteFlg = TRUE;
			}
		}
		else {
			count++;
			babbleaddY -= 0.3;
			if (count > 2) {
				babbleaddX += amp * sin(fre * GetNowCount() / 300.0f);
				count = 0;
			}
		}


		if (bimgcnt++ > 70) {
			bimgnum += 1;
			bimgcnt = 0;
		}

		if (bimgnum == 2) {
			bimgnum = 0;
		}
	}
else {
if (count++ > 60) {
	BDeleteFlg = TRUE;
	}
}

}

void Bubble::BubbleDraw() const 
{

	switch (check)
	{
	case 0:
		DrawRotaGraph(babbleaddX, babbleaddY, 1.0f, 0, BubbleImg[bimgnum], TRUE, FALSE);
		break;
	case 1:
		PlaySoundMem(SE_bubble, DX_PLAYTYPE_BACK, TRUE);
		DrawRotaGraph(babbleaddX, babbleaddY, 1.0f, 0, BubbleImg[3], TRUE, FALSE);
		break;
	case 2:
		DrawGraph(babbleaddX - 20, babbleaddY - 30, Bscoimg, TRUE);
		break;
	default:
		break;
	}

}

int Bubble::BubbleDelete() {

	if (BDeleteFlg == TRUE) {
//		BscoFlg = TRUE;
		return TRUE;
	}
	return FALSE;
}