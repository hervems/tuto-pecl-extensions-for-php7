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
#include "php_helloworld.h"

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_helloworld_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_helloworld_compiled)
{
	char *arg = NULL;
	size_t arg_len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "helloworld", arg);

	RETURN_STR(strg);
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(helloworld)
{
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

/* {{{ helloworld_functions[]
 *
 * Every user visible function must have an entry in helloworld_functions[].
 */
const zend_function_entry helloworld_functions[] = {
	PHP_FE(confirm_helloworld_compiled,	NULL)	/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in helloworld_functions[] */
};
/* }}} */

/* {{{ helloworld_module_entry
 */
zend_module_entry helloworld_module_entry = {
	STANDARD_MODULE_HEADER,
	"helloworld",
	helloworld_functions,
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
