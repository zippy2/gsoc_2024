#include "db.h"

struct MyItem {
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
    struct MyItem *my_item = item;

    return my_item->id;
}

int
main(int argc G_GNUC_UNUSED,
     char **argv G_GNUC_UNUSED)
{
    g_autoptr(Db) db = DbNew(item_free, item_get_id, NULL);
    struct MyItem *item = g_new(struct MyItem, 1);

    item->id = 3;

    DbInsert(db, item);

    return EXIT_SUCCESS;
}
