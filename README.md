Google Summer of Code 2024 Coding exercise
==========================================

### Goal: Implement a library that serves a database

Your task is to provide the missing implementation for functions and structures
in `db.c`. The basic usage might look like this:

```
  g_autoptr(Db) db = DbNew(item_free, item_get_id, NULL);
  MyItem *item = g_new(MyItem, 1);
  size_t i = 0;

  item->id = 3;

  DbInsert(db, item);

  g_autoptr(MyItem) item2 = DbGet(db, 3);
```

Take a look at `db_test_1.c`, `db_test_2.c` or `db_test_3.c` for more examples.

### Steps:

The design of `_Db` structure is completely up to you, just like algorithms
used. You can introduce new internal functions or macros you want. You can use
standard C library and GLib. If you allocate any memory, do not forget to free
it once no longer needed.

Please make sure your code passes tests. You can run test suite by:

```
  meson test -C _build/
```

_Note: Replace `_build` with your build directory._

Feel free to ask any questions.

