#include "End.h"
#include <DxLib.h>

End::End()
{
    image = 0;
}

End::~End()
{
}

AbstractScene* End::Update()
{
    return nullptr;
}

void End::Draw() const
{
    DrawFormatString(250, 250, 0xffffff, "GameOver");
}
