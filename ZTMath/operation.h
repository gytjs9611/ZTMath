#ifndef OPERATION_H
#define OPERATION_H

#include <stdlib.h>
#include <time.h>
#include <QObject> // for Q_INVOKABLE
#include <iostream>
#include <math.h>
#include <random>
#include <QPair>


typedef struct {
    int id;
    int num1, num2;
    int operatorSymbol;
    int answer;
} Question;

class Operation: public QObject {
    Q_OBJECT
    Q_PROPERTY(int level READ getLevel WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(bool complete READ getComplete NOTIFY completeChanged)
    Q_PROPERTY(bool randOption READ getRandOption WRITE setRandOption NOTIFY randOptionChanged)
    Q_PROPERTY(bool selected READ getSelectedState WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(int num READ getNumOfQuestion WRITE setNumOfQuestion NOTIFY numChanged)
    Q_PROPERTY(int diff1 READ getDifficulty1 WRITE setDifficulty1 NOTIFY diff1Changed)
    Q_PROPERTY(int diff2 READ getDifficulty2 WRITE setDifficulty2 NOTIFY diff2Changed)

public:
//    explicit PlusOperation(QObject* parent = nullptr);
    explicit Operation();

    Q_INVOKABLE void setLevel(int);
    Q_INVOKABLE void init();
    Q_INVOKABLE void mallocQuestion();
    Q_INVOKABLE void setRandOption(bool);
    Q_INVOKABLE void setSelected(bool);
    Q_INVOKABLE void setNumOfQuestion(int);
    Q_INVOKABLE void setDifficulty1(int);
    Q_INVOKABLE void setDifficulty2(int);
    Q_INVOKABLE virtual void createQuestion(); // virtual for overriding
    void questionLvHigh();
    void questionLvMid();
    void questionLvLow();
    Q_INVOKABLE void combineQuestion(bool, Operation*, Operation*, Operation*, Operation*);
    void combineEach(int, Operation*);


    Q_INVOKABLE int getLevel();
    Q_INVOKABLE bool getComplete();
    Q_INVOKABLE bool getRandOption();
    Q_INVOKABLE bool getSelectedState();
    Q_INVOKABLE int getNumOfQuestion();
    Q_INVOKABLE int getDifficulty1();
    Q_INVOKABLE int getDifficulty2();
    Q_INVOKABLE Question getQuestion(int);
    Q_INVOKABLE int getQuestNum1(int);
    Q_INVOKABLE int getQuestNum2(int);
    Q_INVOKABLE int getOperator(int);
    Q_INVOKABLE int getAnswer(int);


signals:
    void levelChanged();
    void completeChanged();
    void randOptionChanged();
    void numChanged();
    void selectedChanged();
    void diff1Changed();
    void diff2Changed();

protected: // private->inherited class can't use this
    int m_level;
    bool m_complete;
    bool m_randOption;
    bool m_selected;
    int m_num;
    int m_diff1, m_diff2;
    Question* m_question;

};



#endif // OPERATION_H
