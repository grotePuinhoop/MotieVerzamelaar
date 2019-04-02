#include "getpages.h"
#include <QDebug>
GetPages::GetPages()
{
    qDebug()<<Q_FUNC_INFO;
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    fetch();
}

void GetPages::fetch()
{
    m_manager->get(QNetworkRequest(QUrl("http://stackoverflow.com")));
}

void GetPages::replyFinished(QNetworkReply *pReply)
{
    QByteArray data=pReply->readAll();
    QString str(data);
}
