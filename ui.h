#pragma once
using namespace std;
class UI
{
public:
    virtual void displayMenu() = 0;
    virtual void handleOperations() = 0;
    virtual ~UI() {}
};

