/* rot_cipher extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_rot_cipher.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void rot_cipher_test1()
 */
PHP_FUNCTION(rot_cipher_test)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "rot_cipher");
}
/* }}} */

static void rotate(const char* text, size_t len, long key, char* dest) {
    for (int i = 0; i < len; i++) {
        dest[i] = (char)((long) text[i] + key);
    }
}

/* {{{ string rot( [ string $text, long $key ] )
 */
PHP_FUNCTION(rot)
{
	char *text = "World";
	size_t text_len;

	long key;

	char result[3000] = {0};

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(text, text_len)
		Z_PARAM_LONG(key)
	ZEND_PARSE_PARAMETERS_END();

    rotate(text, text_len, key, result);

	RETURN_STR(strpprintf(0, "%s", result));
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(rot_cipher)
{
#if defined(ZTS) && defined(COMPILE_DL_ROT_CIPHER)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(rot_cipher)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "rot_cipher support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_rot_cipher_test, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_rot, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ rot_cipher_functions[]
 */
static const zend_function_entry rot_cipher_functions[] = {
	PHP_FE(rot_cipher_test,		arginfo_rot_cipher_test)
	PHP_FE(rot,		arginfo_rot)
	PHP_FE_END
};
/* }}} */

/* {{{ rot_cipher_module_entry
 */
zend_module_entry rot_cipher_module_entry = {
	STANDARD_MODULE_HEADER,
	"rot_cipher",					/* Extension name */
	rot_cipher_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(rot_cipher),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(rot_cipher),			/* PHP_MINFO - Module info */
	PHP_ROT_CIPHER_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ROT_CIPHER
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(rot_cipher)
#endif
