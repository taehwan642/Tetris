#pragma once
#include "value.h"
class Stage // ��������
{
private:
    friend class StageMNG;
    char stage[STAGE_HEIGHT][STAGE_WIDTH];
    int speed;
public:
    Stage();
    ~Stage();
    bool Init();
    void Render();
    int GetSpeed() const { return speed; };
    void SetSpeed(int v) { speed = v; };

};

 