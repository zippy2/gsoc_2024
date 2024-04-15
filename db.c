#include <stdbool.h>
#include <glib.h>

#include "db.h"


struct _Db {
    /* Implement me */
};


/**
 * DbNew:
 * @free_cb: pointer to a free function for single DbItem
 * @get_id_cb: pointer to a function returning DbItem's ID
 * @get_refs_cb: pointer to a function returning DbItem's reference IDs
 *
 * Allocates and initializes Db structure.
 *
 * If @get_refs_cb is NULL the DbItem does not support references
 *
 * Use DbFree() to free the structure or use g_autoptr(Db);
 *
 * Returns: An allocated Db structure.
 */
Db *DbNew(DbItemFreeFunc free_cb,
          DbItemGetIdFunc get_id_cb,
          DbItemGetRefsFunc get_refs_cb)
{
    /* Implement me */
}


/**
 * DbPrune:
 * @db: database to prune
 *
 * Removes items with unreferenced IDs from the database.
 *
 * Returns: Number of removed items
 */
size_t
DbPrune(Db *db)
{
    /* Implement me */
}

/**
 * DbInsert:
 * @item: DbItem to insert
 *
 * Inserts the @item into the database, if an item with the same ID exists it
 * gets overridden.
 */
void
DbInsert(Db *db, DbItem item)
{
    /* Implement me */
}

/**
 * DbPeek:
 * @id: DbItem ID to search for
 *
 * Returns the DbItem with the requested @id or NULL if it was not found.
 *
 * The returned DbItem stays in the database and must not be freed by the caller.
 */
DbItem
DbPeek(Db *db, int id)
{
    /* Implement me */
}

/**
 * DbPeekAll:
 * @id: DbItem ID to search for
 *
 * Returns DbItem list of all referenced items.
 *
 * The returned items stay in the database and must not be freed by the caller.
 * The list itself must be freed by the caller.
 */
const DbItemList *
DbPeekAll(Db *db, int id)
{
    /* Implement me */
}

/**
 * DbGet:
 * @id: DbItem ID to search for
 *
 * Returns the DbItem with the requested @id or NULL if it was not found.
 *
 * The returned DbItem must be freed by the caller.
 */
DbItem
DbGet(Db *db, int id)
{
    /* Implement me */
}

/**
 * DbFree:
 * @db: database to free
 *
 * Frees the database, including individual items.
 * if @db is NULL then this function is a NOP.
 */
void
DbFree(Db *db)
{
    /* Implement me */
}
