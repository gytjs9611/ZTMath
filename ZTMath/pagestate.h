#ifndef PAGESTATE_H
#define PAGESTATE_H
#include <QObject>


class PageState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString errorMainMsg READ getErrorMainMsg WRITE setErrorMainMsg NOTIFY errorMainMsgChanged);
    Q_PROPERTY(QString errorSubMsg READ getErrorSubMsg WRITE setErrorSubMsg NOTIFY errorSubMsgChanged);
    Q_PROPERTY(bool errorState READ getErrorState WRITE setErrorState NOTIFY errorStateChanged);
    Q_PROPERTY(int totalPage READ getTotalPage WRITE setTotalPage NOTIFY totalPageChanged);
    Q_PROPERTY(int currentPage READ getCurrentPage WRITE setCurrentPage NOTIFY currentPageChanged);
    Q_PROPERTY(int answerTotalPage READ getAnswerTotalPage WRITE setAnswerTotalPage NOTIFY answerTotalPageChanged);
    Q_PROPERTY(int answerCurrentPage READ getAnswerCurrentPage WRITE setAnswerCurrentPage NOTIFY answerCurrentPageChanged);
    Q_PROPERTY(bool answerMode READ getAnswerMode WRITE setAnswerMode NOTIFY answerModeChanged);

public:
    PageState();
    Q_INVOKABLE void setErrorMainMsg(QString);
    Q_INVOKABLE void setErrorSubMsg(QString);
    Q_INVOKABLE void setErrorState(bool);
    Q_INVOKABLE void setTotalPage(int);
    Q_INVOKABLE void setCurrentPage(int);
    Q_INVOKABLE void setAnswerTotalPage(int);
    Q_INVOKABLE void setAnswerCurrentPage(int);
    Q_INVOKABLE void setAnswerMode(bool);

    Q_INVOKABLE QString getErrorMainMsg();
    Q_INVOKABLE QString getErrorSubMsg();
    Q_INVOKABLE bool getErrorState();
    Q_INVOKABLE int getTotalPage();
    Q_INVOKABLE int getCurrentPage();
    Q_INVOKABLE int getAnswerTotalPage();
    Q_INVOKABLE int getAnswerCurrentPage();
    Q_INVOKABLE bool getAnswerMode();


private:
    QString m_errorMainMsg;
    QString m_errorSubMsg;
    bool m_errorState;
    int m_totalPage;
    int m_currentPage;
    int m_answerTotalPage;
    int m_answerCurrentPage;
    bool m_answerMode;

signals:
    void errorMainMsgChanged();
    void errorSubMsgChanged();
    void errorStateChanged();
    void totalPageChanged();
    void currentPageChanged();
    void answerTotalPageChanged();
    void answerCurrentPageChanged();
    void answerModeChanged();

};

#endif // PAGESTATE_H
