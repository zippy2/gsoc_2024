#pragma once

#include <stdint.h>
#include <glib.h>

typedef struct _Db Db;
typedef void *DbItem;
typedef DbItem *DbItemList;

typedef int (*DbItemGetIdFunc) (const DbItem);
typedef int * (*DbItemGetRefsFunc)(const DbItem);
typedef void (*DbItemFreeFunc)(DbItem);

Db *DbNew(DbItemFreeFunc free_cb,
          DbItemGetIdFunc get_id_cb,
          DbItemGetRefsFunc get_ref_ids_cb);

void DbInsert(Db *db, DbItem item);

DbItem
DbPeek(Db *db, int id);

DbItem
DbGet(Db *db, int id);

const DbItemList *
DbPeekAll(Db *db, int id);

size_t
DbPrune(Db *db);

void
DbFree(Db *db);

G_DEFINE_AUTOPTR_CLEANUP_FUNC(Db, DbFree)
