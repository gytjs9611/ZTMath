#ifndef PLUSOPERATION_H
#define PLUSOPERATION_H
#include "operation.h"

class PlusOperation : public Operation
{
public:
    Q_INVOKABLE void createQuestion();
    void questionLvHigh();
    void questionLvMid();
    void questionLvLow();
};

#endif // PLUSOPERATION_H
