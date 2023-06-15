#pragma once
#include "AbstractScene.h"
#include "DxLib.h"

// シーンマネージャークラス
// 各シーンの切り替えを管理する

class GameMain :
    public AbstractScene
{

public:

    // コンストラクタ
    GameMain();

    //デストラクタ
    ~GameMain();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;
private:
    //ゲームメインで使う変数の宣言
};