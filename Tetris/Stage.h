#pragma once
#include "value.h"
class Stage // 스테이지
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
    void AddBlock(class Shape* s, const POSITION& pos);
    bool CheckBlock(int x, int y);
    int GetSpeed() const { return speed; };
    void SetSpeed(int v) { speed = v; };

};

 