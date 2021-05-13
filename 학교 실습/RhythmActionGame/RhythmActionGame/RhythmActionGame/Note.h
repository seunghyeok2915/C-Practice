#pragma once
class Note
{
private:
    int x;
    int y;
    int idx;

public:
    void InitNote();

    void DrawNote();
    void DownNote();

    void CheckEnd();

    void playSound();
};
