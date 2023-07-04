#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"

GameMain::GameMain()
{
	PauseFlg = FALSE;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	//�|�[�Y�t���O�؂�ւ�����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		PauseFlg = !PauseFlg;

	}
	//�|�[�Y���łȂ��Ƃ�
	if (PauseFlg == FALSE) {
		//
	}

	return this;
}

void GameMain::Draw() const
{
	
	
	//�|�[�Y���̕`��
	if (PauseFlg == TRUE)
	{
		DrawFormatString(0, 0, 0xffffff, "pause");
	}
	else {
		DrawFormatString(0, 0, 0xffffff, "�Q�[�����C��");
	}
}
