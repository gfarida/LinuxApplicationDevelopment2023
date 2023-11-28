TESTS_ENVIRONMENT = CK_VERBOSITY=$(CK_VERBOSITY)
TESTS = buf_clear_test buf_grow_test buf_pop_test buf_push_test
check_PROGRAMS = buf_clear_test buf_grow_test buf_pop_test buf_push_test

AM_CFLAGS = -I$(top_builddir)/src
LDADD = $(top_builddir)/src/libbuf.la