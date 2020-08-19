#include "divoperation.h"

void DivOperation::createQuestion()
{
    Operation::createQuestion();
    int lv = this->m_level;
    int temp;

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
        if(m_question[i].num1<m_question[i].num2){
            temp = m_question[i].num1;
            m_question[i].num1 = m_question[i].num2;
            m_question[i].num2 = temp;
        }
        int temp = m_question[i].num1 / m_question[i].num2;
        m_question[i].operatorSymbol = 4;
        m_question[i].answer = temp;
    }
}
void DivOperation::questionLvHigh(){
    int from, to;
    int len2 = this->m_diff2;
    int temp;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len2-1));
    to = (int)(pow(10, len2)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        temp = dis(gen);
        if(temp==1){
            temp++;
        }
        this->m_question[i].num2 = temp;
    }
}
void DivOperation::questionLvMid(){
    int from, to;
    int len2 = this->m_diff2;
    int temp;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len2-1));
    to = (int)(pow(10, len2)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        temp = dis(gen);
        if(temp==1){
            temp++;
        }
        this->m_question[i].num2 = temp;
    }
}
void DivOperation::questionLvLow(){
    int from, to;
    int len2 = this->m_diff2;
    int temp;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len2-1));
    to = (int)(pow(10, len2)-1);
    std::uniform_int_distribution<int> dis(from, to);

    for(int i = 1; i<m_num+1; i++){
        temp = dis(gen);
        if(temp==1){
            temp++;
        }
        this->m_question[i].num2 = temp;
    }
}
