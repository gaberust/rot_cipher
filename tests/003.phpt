--TEST--
rot() Basic test
--SKIPIF--
<?php
if (!extension_loaded('rot_cipher')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(rot('Lorem ipsum dolor sit amet, consectetur adipiscing elit.', 10));
var_dump(rot('Hello PHP', 3));
?>
--EXPECT--
string(56) "Vy|ow*sz}w*nyvy|*}s~*kwo~6*myx}om~o~|*knszs}msxq*ovs~8"
string(9) "Khoor#SKS"
