AC_PREREQ([2.69])
AC_INIT([Number guesser program], [0.0.1], [], [])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([src/program.c])
AC_CONFIG_HEADERS([config.h])
DX_INIT_DOXYGEN([program])

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
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile Doxyfile])
AC_OUTPUT