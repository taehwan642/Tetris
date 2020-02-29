#pragma once
#include "value.h"
class Stage
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

 