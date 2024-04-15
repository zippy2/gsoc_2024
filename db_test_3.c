#include <stdio.h>

#include "db.h"

typedef struct _MyItem MyItem;
struct _MyItem {
    int id;
    /* char *data; */
};

static void
item_free(DbItem item)
{
    g_free(item);
}

static int
item_get_id(DbItem item)
{
    MyItem *my_item = item;

    return my_item->id;
}

G_DEFINE_AUTOPTR_CLEANUP_FUNC(MyItem, item_get_id);

int
main(int argc G_GNUC_UNUSED,
     char **argv G_GNUC_UNUSED)
{
    g_autoptr(Db) db = DbNew(item_free, item_get_id, NULL);
    MyItem *item = g_new(MyItem, 1);
    size_t i = 0;

    item->id = 3;

    DbInsert(db, item);

    for (i = 0; i < 10; i++) {
        if (!DbPeek(db, 3)) {
            fprintf(stderr, "Item not found\n");
            return EXIT_FAILURE;
        }
    }

    g_autoptr(MyItem) item2 = DbGet(db, 3);

    if (item2 != item) {
        fprintf(stderr, "Got back different pointer than expected\n");
        return EXIT_FAILURE;
    }

    if (DbPeek(db, 3)) {
        fprintf(stderr, "Item found when it should not have been there\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
