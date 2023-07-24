#pragma once
#include "AbstractScene.h"
class TitleScene :
    public AbstractScene
{
private:
    int titleLogo;
    int titleSlectImg;
    int titleBalloon[4];
    int titleCredit;

    int time;
    int num;
public:
    TitleScene();
    ~TitleScene();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;

};

