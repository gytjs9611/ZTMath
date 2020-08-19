#include "operation.h"



Operation::Operation(){
    this->m_level = 1;
    this->m_complete = false;
    this->m_randOption = false;
    this->m_selected = false;
    this->m_num = 20;
    this->m_diff1 = 3;
    this->m_diff2 = 3;
}
void Operation::mallocQuestion(){
    this->m_question = (Question*)malloc(sizeof(Question)*(this->m_num+1));
}
void Operation::init(){
    setRandOption(false);
    setSelected(false);
    setNumOfQuestion(20);
    setDifficulty1(3);
    setDifficulty2(3);
}
void Operation::setLevel(int value){
    this->m_level = value;
    emit levelChanged();
}
void Operation::setRandOption(bool value){
    this->m_randOption = value;
    emit randOptionChanged();
}
void Operation::setSelected(bool value){
    this->m_selected = value;
    emit this->selectedChanged();
}
void Operation::setNumOfQuestion(int num){
    this->m_num = num;
    emit this->numChanged();
}
void Operation::setDifficulty1(int n){
    this->m_diff1 = n;
    emit this->diff1Changed();
}
void Operation::setDifficulty2(int n){
    this->m_diff2 = n;
    emit this->diff2Changed();
}
void Operation::createQuestion(){
    int len1, len2;
    int level;
    int from, to;
    Question temp;

    if(this->m_diff1<this->m_diff2){ // longer one must be at the first
        int temp;
        temp = this->m_diff1;
        this->m_diff1 = this->m_diff2;
        this->m_diff2 = temp;
    }

    this->mallocQuestion();


    len1 = this->m_diff1;
    len2 = this->m_diff2;
    level = this->m_level;

    std::random_device rd;
    std::mt19937 gen(rd());

    from = (int)(pow(10, len1-1));
    to = (int)(pow(10, len1)-1);
    std::uniform_int_distribution<int> dis(from, to);


    for(int i = 1; i<this->m_num+1; i++){
        temp.id = i;
////        temp.num1 = rand()%(9*(int)pow(10, len1-1))+pow(10, len1-1);
////        temp.num2 = rand()%(9*(int)pow(10, len2-1))+pow(10, len2-1);
        temp.num1 = dis(gen);
        temp.num2 = 0;
        temp.operatorSymbol = 0;
        temp.answer = 0;
        this->m_question[i] = temp;
    }


}
void Operation::combineQuestion(bool rand_option, Operation* a, Operation* b, Operation* c, Operation* d){
    if(rand_option){

    }
    else{
        int start = 0;
        if(a->getSelectedState()){
            combineEach(start, a);
            start += a->getNumOfQuestion();
        }
        if(b->getSelectedState()){
            combineEach(start, b);
            start += b->getNumOfQuestion();
        }
        if(c->getSelectedState()){
            combineEach(start, c);
            start += c->getNumOfQuestion();
        }
        if(d->getSelectedState()){
            combineEach(start, d);
            start += d->getNumOfQuestion();
        }

        this->m_complete = true;
        emit completeChanged();

    }
}
void Operation::combineEach(int start, Operation* data){
    for(int i = 1; i<data->getNumOfQuestion()+1; i++){
        this->m_question[start+i] = data->getQuestion(i);
    }
}



int Operation::getLevel(){
    return this->m_level;
}
bool Operation::getComplete(){
    return this->m_complete;
}
bool Operation::getRandOption(){
    return this->m_randOption;
}
bool Operation::getSelectedState(){
    return this->m_selected;
}
int Operation::getNumOfQuestion(){
    return this->m_num;
}
int Operation::getDifficulty1(){
    return this->m_diff1;
}
int Operation::getDifficulty2(){
    return this->m_diff2;
}
Question Operation::getQuestion(int id){
    return this->m_question[id];
}
int Operation::getQuestNum1(int id){
    return this->m_question[id].num1;
}
int Operation::getQuestNum2(int id){
    return this->m_question[id].num2;
}
int Operation::getOperator(int id){
    return this->m_question[id].operatorSymbol;
}
int Operation::getAnswer(int id){
    return this->m_question[id].answer;
}
