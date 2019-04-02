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
    m_manager->get(QNetworkRequest(QUrl("https://stackoverflow.com/")));
    /*
    qt.network.ssl: QSslSocket: cannot call unresolved function SSLv23_client_method
    qt.network.ssl: QSslSocket: cannot call unresolved function SSL_CTX_new
    qt.network.ssl: QSslSocket: cannot call unresolved function SSL_library_init
    qt.network.ssl: QSslSocket: cannot call unresolved function ERR_get_error
    qt.network.ssl: QSslSocket: cannot call unresolved function ERR_get_error
    https://stackoverflow.com/questions/10846536/unresolved-functions-while-working-with-qsslsocket
    On Windows/MinGW you need to copy these files to your exe directory.
    C:\Qt\Tools\mingw492_32\opt\bin\libeay32.dll
    C:\Qt\Tools\mingw492_32\opt\bin\ssleay32.dll

*/

}

void GetPages::replyFinished(QNetworkReply *pReply)
{
    QByteArray data=pReply->readAll();
    QString str(data);
    qDebug()<<str;
}
