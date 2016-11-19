/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Hervé Seignole (herve.seignole@gmail.com)                    |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "zend_exceptions.h"
#include "php_helloworld.h"

#define PHP_HELLOWORLD_CLASSNAME "Helloworld"

zend_class_entry* helloworld_class_entry;

static const zend_function_entry helloworld_class_functions[] = {
	PHP_ME(Helloworld, getVersion, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	{NULL, NULL, NULL}
};

/* add constants of class */
static void add_class_constants(zend_class_entry *ce) {
	zend_declare_class_constant_long(ce, ZEND_STRL("MY_CONSTANT"), 140 TSRMLS_CC);
	zend_declare_class_constant_stringl(ce, "MY_CONSTANT_STRING", 18, "string", 6 TSRMLS_CC);
}

/* {{{ proto string Helloworld::getVersion()
*/
PHP_METHOD(Helloworld, getVersion)
{
	RETURN_STRING(PHP_HELLOWORLD_VERSION);
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(helloworld)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, PHP_HELLOWORLD_CLASSNAME, helloworld_class_functions);
    helloworld_class_entry = zend_register_internal_class(&ce);

	add_class_constants(helloworld_class_entry);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(helloworld)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(helloworld)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "helloworld support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ helloworld_module_entry
 */
zend_module_entry helloworld_module_entry = {
    STANDARD_MODULE_HEADER,
    "helloworld",
    NULL,
    PHP_MINIT(helloworld),
    PHP_MSHUTDOWN(helloworld),
    NULL,
    NULL,
    PHP_MINFO(helloworld),
    PHP_HELLOWORLD_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELLOWORLD
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(helloworld)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
