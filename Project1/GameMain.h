#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "HitBox.h"
#include "Fish.h"
#include "UI.h"
#include"Thunder.h"
#include "TitleScene.h"
#include"Bubble.h"
// シーンマネージャークラス
// 各シーンの切り替えを管理する

class GameMain :
    public AbstractScene
{
private:
    //ゲームメインで使う変数の宣言
    Stage stage;
    UI UI;
    //ゲームメインで使う変数の宣言
    Player player;
    //Enemy enemy;

    //Enemy enemy2;
    //Enemy enemy3;
    HitBox hit;
    Fish fish;
    Thunder thunder;
    Bubble bubble;
    bool PauseFlg;            // ポーズ
    
    bool ClearFlg;            //ステージclearフラグ
    int Elast;                //最後のエネミーの番号受け取り用
    int count;

    int OldSnum;//ステージ数比較用

    int fishi;//サカナに渡すエネミーの番号保管用
    int playerAndFishFlg;

    int a;
    int reboundFlg;
    //BGM用変数
    int BGM;
public:

    // コンストラクタ
    GameMain();

    //デストラクタ
    ~GameMain();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;
    int tst;

    /* デバック用 */
    int b;
};