#ifndef MINUSOPERATION_H
#define MINUSOPERATION_H
#include "operation.h"

class MinusOperation : public Operation
{
public:
    Q_INVOKABLE void createQuestion();
    void questionLvHigh();
    void questionLvMid();
    void questionLvLow();
};

#endif // MINUSOPERATION_H
