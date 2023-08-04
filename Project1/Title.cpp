#include "Title.h"
#include "UI.h"
int UI::getsco;
Title::Title()
{
}

Title::~Title()
{
}

AbstractScene* Title::Update()
{
    return nullptr;
}

void Title::Draw() const
{
}

int  Title::ResetScore()
{
    return UI::getsco = 0;
}
