#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "UI.h"
#include "Enemy.h"
#include "Stage.h"
// シーンマネージャークラス
// 各シーンの切り替えを管理する

class End :
    public AbstractScene
{
private:
    int image;
    int SE; //ゲームオーバーSE
    Stage stage;
    UI UI;
    Enemy* enemy[6];
    //ゲームメインで使う変数の宣言
    Player player;
public:
    int EndCount = 0;

    // コンストラクタ
    End();

    //デストラクタ
    ~End();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;

private:
};