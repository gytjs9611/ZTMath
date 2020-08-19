#include "pagestate.h"

PageState::PageState()
{
    this->m_errorMainMsg = "경고!";
    this->m_errorSubMsg = "에러입니다.";
    this->m_errorState = false;
    this->m_totalPage = 1;
    this->m_currentPage = 0;
    this->m_answerTotalPage = 1;
    this->m_answerCurrentPage = 1;
    this->m_answerMode = false;
}
void PageState::setErrorMainMsg(QString data){
    m_errorMainMsg = data;
    emit errorMainMsgChanged();
}
void PageState::setErrorSubMsg(QString data){
    m_errorSubMsg = data;
    emit errorSubMsgChanged();
}
void PageState::setErrorState(bool state){
    m_errorState = state;
    emit errorStateChanged();
}
void PageState::setTotalPage(int n){
    m_totalPage = n;
    emit totalPageChanged();
}
void PageState::setCurrentPage(int n){
    m_currentPage = n;
    emit currentPageChanged();
}
void PageState::setAnswerTotalPage(int n){
    m_answerTotalPage = n;
    emit answerTotalPageChanged();
}
void PageState::setAnswerCurrentPage(int n){
    m_answerCurrentPage = n;
    emit answerCurrentPageChanged();
}
void PageState::setAnswerMode(bool mode){
    m_answerMode = mode;
    emit answerModeChanged();
}


QString PageState::getErrorMainMsg(){
    return m_errorMainMsg;
}
QString PageState::getErrorSubMsg(){
    return m_errorSubMsg;
}
bool PageState::getErrorState(){
    return m_errorState;
}
int PageState::getTotalPage(){
    return m_totalPage;
}
int PageState::getCurrentPage(){
    return m_currentPage;
}
int PageState::getAnswerTotalPage(){
    return m_answerTotalPage;
}
int PageState::getAnswerCurrentPage(){
    return m_answerCurrentPage;
}
bool PageState::getAnswerMode(){
    return m_answerMode;
}
