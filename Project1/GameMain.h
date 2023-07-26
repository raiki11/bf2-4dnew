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
    
   

    int a;
    int reboundFlg;
   
public:

    // コンストラクタ
    GameMain();

    //デストラクタ
    ~GameMain();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;

};