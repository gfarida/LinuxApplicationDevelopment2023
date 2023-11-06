AC_PREREQ([2.69])
AC_INIT([rhasher], [0.00], [])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CONFIG_SRCDIR([src/rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([rhash is needed])])

# Checks for header files.
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([stdbool.h])
AC_CHECK_HEADER([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE

# Optional clues
AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Enable using readline insted of getline]),
    AC_DEFINE(READLINE,[],[readline])
  )

AC_CONFIG_FILES([Makefile])
AC_OUTPUT