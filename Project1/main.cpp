#include "DxLib.h"
#include "SceneManager.h"
#include "PadInput.h"

#define FRAMERATE 60.0	//フレームレート

//BGM用変数
int BGM;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Fps fps;
	SetMainWindowText("タイトル");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//画面サイズの設定

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	BGM = LoadSoundMem("sound/BGM.wav");

	//BGMの再生
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, TRUE);

	SceneManager* sceneMng;

	try // シーンを選ぶとそこからスタートする（最終的にはTitleを入れる）
	{
		sceneMng = new SceneManager((AbstractScene*)new Title());

	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);
		//ファイルオープン
		fopen_s(&fp, "ErrLog.txt", "a");
		//エラーデータの書き込み
		fprintf_s(fp, "%02d年 %02d月 %02d日 %02d時 %02d分 %02d秒 : %sがありません。\n", data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);

		return 0;
	}

	// ゲームループ
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr)) {

		ClearDrawScreen();		// 画面の初期化
		PAD_INPUT::UpdateKey();
		sceneMng->Draw();
		//強制終了
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}
		fps.Update();	//更新
		ScreenFlip();			// 裏画面の内容を表画面に反映
		fps.Wait();		//待機
	}
	return 0;
}