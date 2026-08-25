#pragma once

struct ControllerState
{
    bool cross = false;
    bool circle = false;
    float leftX = 0.0f;
    float leftY = 0.0f;
};

ControllerState neutralController();
