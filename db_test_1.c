#include "db.h"


int
main(int argc G_GNUC_UNUSED,
     char **argv G_GNUC_UNUSED)
{
    /* None of the functions should be called when there is no data */
    g_autoptr(Db) db = DbNew(NULL, NULL, NULL);

    return EXIT_SUCCESS;
}
