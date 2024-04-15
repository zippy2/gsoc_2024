project('db', 'c',
  version: '0.0.1',
  default_options: [
    'c_std=gnu89',
    'warning_level=2',
    'werror=true',
  ],
)

deps = [
  dependency('glib-2.0'),
]

cc_flags = [
  '-Wall',
  '-O0',
]

db_lib = static_library(
  'db_lib',
  [ 'db.c' ],
  dependencies: [ deps ],
)

test_1_bin = executable(
  'db_test_1',
  [ 'db_test_1.c' ],
  dependencies: [ deps ],
  link_whole: [ db_lib ],
)

test_2_bin = executable(
  'db_test_2',
  [ 'db_test_2.c' ],
  dependencies: [ deps ],
  link_whole: [ db_lib ],
)

test_3_bin = executable(
  'db_test_3',
  [ 'db_test_3.c' ],
  dependencies: [ deps ],
  link_whole: [ db_lib ],
)

test('test_1', test_1_bin)
test('test_2', test_2_bin)
test('test_3', test_3_bin)
