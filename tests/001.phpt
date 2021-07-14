--TEST--
Check if rot_cipher is loaded
--SKIPIF--
<?php
if (!extension_loaded('rot_cipher')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "rot_cipher" is available';
?>
--EXPECT--
The extension "rot_cipher" is available
