#pragma once
#include "AbstractScene.h"

// シーンマネージャークラス
// 各シーンの切り替えを管理する

class End :
    public AbstractScene
{
private:
    int image;
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