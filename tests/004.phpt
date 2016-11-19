--TEST--
Check if Helloworld::getVersion static method is ok.
--SKIPIF--
<?php if (!extension_loaded("helloworld")) print "skip"; ?>
--FILE--
<?php
echo Helloworld::getVersion();
?>
--EXPECT--
0.1.0
