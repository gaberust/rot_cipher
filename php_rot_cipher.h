/* rot_cipher extension for PHP */

#ifndef PHP_ROT_CIPHER_H
# define PHP_ROT_CIPHER_H

extern zend_module_entry rot_cipher_module_entry;
# define phpext_rot_cipher_ptr &rot_cipher_module_entry

# define PHP_ROT_CIPHER_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_ROT_CIPHER)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_ROT_CIPHER_H */
