#pragma once
class Task
{
    char title[50];
    char description[150];
    bool status;
public:
    void input();
    void print();
};

