--TEST--
rot_cipher_test() Basic test
--SKIPIF--
<?php
if (!extension_loaded('rot_cipher')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = rot_cipher_test();

var_dump($ret);
?>
--EXPECT--
The extension rot_cipher is loaded and working!
NULL
