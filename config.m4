dnl $Id$
dnl config.m4 for extension helloworld

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(helloworld, for helloworld support,
dnl Make sure that the comment is aligned:
dnl [  --with-helloworld             Include helloworld support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(helloworld, whether to enable helloworld support, [  --enable-helloworld           Enable helloworld support])

if test "$PHP_HELLOWORLD" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-helloworld -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/helloworld.h"  # you most likely want to change this
  dnl if test -r $PHP_HELLOWORLD/$SEARCH_FOR; then # path given as parameter
  dnl   HELLOWORLD_DIR=$PHP_HELLOWORLD
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for helloworld files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HELLOWORLD_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HELLOWORLD_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the helloworld distribution])
  dnl fi

  dnl # --with-helloworld -> add include path
  dnl PHP_ADD_INCLUDE($HELLOWORLD_DIR/include)

  dnl # --with-helloworld -> check for lib and symbol presence
  dnl LIBNAME=helloworld # you may want to change this
  dnl LIBSYMBOL=helloworld # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HELLOWORLD_DIR/$PHP_LIBDIR, HELLOWORLD_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HELLOWORLDLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong helloworld lib version or lib not found])
  dnl ],[
  dnl   -L$HELLOWORLD_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HELLOWORLD_SHARED_LIBADD)

  PHP_NEW_EXTENSION(helloworld, helloworld.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
