#pragma once
#include "value.h"
class Stage // 스테이지
{
private:
    friend class StageMNG;
    char stage[STAGE_HEIGHT][STAGE_WIDTH];
public:
    Stage();
    ~Stage();
public:
    bool Init();
    void Render();
};

 