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
    PHP_ME(Helloworld, __construct, NULL, ZEND_ACC_CTOR | ZEND_ACC_PUBLIC)
    PHP_ME(Helloworld, printYourFirstAndLastName, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

/* {{{ proto Helloworld Helloworld::__construct()
   Public constructor
*/
PHP_METHOD(Helloworld, __construct)
{
    php_printf("Helloworld::__construct\n");
}
/* }}} */

/* {{{ proto boolean Helloworld::printYourFirstAndLastName(array names)
*/
PHP_METHOD(Helloworld, printYourFirstAndLastName)
{
    zval *object, *z_args, *zv_firstname, *zv_lastname;
    HashTable *hash;
    int arg_count;

    /* For Oa see: zend_parse_arg_impl in zend_API.c (O: object, a: array) */
    if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "Oa",
        &object, helloworld_class_entry, &z_args) == FAILURE) {
        RETURN_FALSE;
    }

    /* Grab our array */
    hash = Z_ARRVAL_P(z_args);

    /* We don't need to do anything if there aren't 2 keys */
    if ((arg_count = zend_hash_num_elements(hash)) != 2) {
        zend_throw_exception(zend_ce_exception, "Invalid number of arguments!", 0 TSRMLS_CC);
    }

    if ((zv_firstname = zend_hash_str_find(hash, "firstname", sizeof("firstname") - 1)) == NULL) {
        zend_throw_exception(zend_ce_exception, "firstname key not found!", 0 TSRMLS_CC);
    }

    if ((zv_lastname = zend_hash_str_find(hash, "lastname", sizeof("lastname") - 1)) == NULL) {
        zend_throw_exception(zend_ce_exception, "lastname key not found!", 0 TSRMLS_CC);
    }

    php_printf("Your name is ");
    PHPWRITE(ZSTR_VAL(zv_firstname->value.str), ZSTR_LEN(zv_firstname->value.str));
    php_printf(" ");
    PHPWRITE(ZSTR_VAL(zv_lastname->value.str), ZSTR_LEN(zv_lastname->value.str));
    php_printf("\n");
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(helloworld)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, PHP_HELLOWORLD_CLASSNAME, helloworld_class_functions);
    helloworld_class_entry = zend_register_internal_class(&ce);

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
