#include "multoperation.h"

void MultOperation::createQuestion()
{
    Operation::createQuestion();
    int lv = this->m_level;
    switch(lv){
    case 0:
        questionLvHigh();
        break;
    case 1:
        questionLvMid();
        break;
    case 2:
        questionLvLow();
        break;
    }

    for(int i = 1; i<m_num+1; i++){
        int temp = m_question[i].num1 * m_question[i].num2;
        m_question[i].operatorSymbol = 3;
        m_question[i].answer = temp;
    }
}

void MultOperation::questionLvHigh(){
    int from, to;
    int len2 = this->m_diff2;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len2-1));
    to = (int)(pow(10, len2)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        this->m_question[i].num2 = dis(gen);
    }
}
void MultOperation::questionLvMid(){
    int from, to;
    int len2 = this->m_diff2;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len2-1));
    to = (int)(pow(10, len2)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        this->m_question[i].num2 = dis(gen);
    }
}
void MultOperation::questionLvLow(){
    int from, to;
    int len2 = this->m_diff2;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len2-1));
    to = (int)(pow(10, len2)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        this->m_question[i].num2 = dis(gen);
    }
}

