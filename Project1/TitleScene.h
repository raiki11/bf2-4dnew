#pragma once
#include "AbstractScene.h"
class TitleScene :
    public AbstractScene
{
private:
    int titleLogo;
    int titleSelectImg;
    int titleBalloon[4];
    int titleCredit;

    int time;
    int num;
    int turnNum;
    
    int selectNum;
public:
    TitleScene();
    ~TitleScene();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;

};

