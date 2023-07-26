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

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

};

