#ifndef MULTOPERATION_H
#define MULTOPERATION_H
#include "operation.h"

class MultOperation : public Operation
{
public:
    Q_INVOKABLE void createQuestion();
    void questionLvHigh();
    void questionLvMid();
    void questionLvLow();
};

#endif // MULTOPERATION_H
