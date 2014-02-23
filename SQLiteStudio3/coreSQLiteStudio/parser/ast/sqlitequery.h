#ifndef SQLITEQUERY_H
#define SQLITEQUERY_H

#include "sqlitestatement.h"
#include "sqlitequerytype.h"

/**
 * @addtogroup sqlite_statement
 * @brief The SqliteQuery class
 */
class API_EXPORT SqliteQuery : public SqliteStatement
{
    public:
        SqliteQuery();
        SqliteQuery(const SqliteQuery& other);

        bool isReadOnly();

        SqliteQueryType queryType = SqliteQueryType::UNDEFINED;

        bool explain = false;
        bool queryPlan = false;
};

/**
 * Shared pointer to SqliteQuery.
 */
typedef QSharedPointer<SqliteQuery> SqliteQueryPtr;

#endif // SQLITEQUERY_H
