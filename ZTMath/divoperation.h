#ifndef DIVOPERATION_H
#define DIVOPERATION_H
#include "operation.h"


//typedef struct {
//    int id;
//    int num1, num2;
//    int operatorSymbol;
//    float answer;
//} Question_div;

class DivOperation : public Operation
{
public:
    Q_INVOKABLE void createQuestion();
    void questionLvHigh();
    void questionLvMid();
    void questionLvLow();

};

#endif // DIVOPERATION_H
