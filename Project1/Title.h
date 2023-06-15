#pragma once

#include "AbstractScene.h"

class Title :
    public AbstractScene

{
private:
    enum class MENU
    {
        PLAY,
        HELP,
        EXIT,
        MENU_SIZE
    };
    const char* menu_items[static_cast<int>(MENU::MENU_SIZE)] = {
      "PLAY",
      "HELP",
      "EXIT"
    };
    //現在選択してるメニュー
    int now_menu;
    //フォント
    int font_handle;
    //決定SE
    int decision_se;
    //背景画像
    int background_image;
    //先生
    int sensei_image;
    //操作間隔時間
    int input_margin;
public:
    //コンストラクタ
    Title();

    //デストラクタ
    ~Title();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;
};


