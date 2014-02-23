#include "db/asyncqueryrunner.h"
#include "db/sqlresults.h"
#include "db/db.h"
#include <QDebug>

AsyncQueryRunner::AsyncQueryRunner(const QString &query, const QVariant& args, Db::Flags flags)
    : query(query), args(args), flags(flags)
{
    init();
}

void AsyncQueryRunner::init()
{
    setAutoDelete(false);
}

void AsyncQueryRunner::run()
{
    if (!db)
    {
        qCritical() << "No Db defined in AsyncQueryRunner!";
        emit finished(this);
    }

    SqlResultsPtr res;
    if (args.userType() == QVariant::List)
    {
        res = db->exec(query, args.toList(), flags);
    }
    else if (args.userType() == QVariant::Hash)
    {
        res = db->exec(query, args.toHash(), flags);
    }
    else
    {
        qCritical() << "Invalid argument type in AsyncQueryRunner::run():" << args.userType();
    }

    results = SqlResultsPtr(res);
    emit finished(this);
}

SqlResultsPtr AsyncQueryRunner::getResults()
{
    return results;
}


void AsyncQueryRunner::setDb(Db *db)
{
    this->db = db;
}

void AsyncQueryRunner::setAsyncId(quint32 id)
{
    asyncId = id;
}

quint32 AsyncQueryRunner::getAsyncId()
{
    return asyncId;
}
