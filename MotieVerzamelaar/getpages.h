#ifndef GETPAGES_H
#define GETPAGES_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class GetPages : public QObject
{
    Q_OBJECT
public:
    GetPages();
    void fetch();
public slots:
    void replyFinished(QNetworkReply*);
private:
    QNetworkAccessManager* m_manager;
};

#endif // GETPAGES_H
