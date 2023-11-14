AC_PREREQ([2.69])
AC_INIT([program], [0.00], [])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CONFIG_SRCDIR([src/program.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([locale.h])
AC_CHECK_HEADER([string.h])
AC_CHECK_HEADER([libgen.h])
AC_CHECK_HEADER([libintl.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT