--TEST--
Check if Helloworld::MY_CONSTANT is ok.
--SKIPIF--
<?php if (!extension_loaded("helloworld")) print "skip"; ?>
--FILE--
<?php
echo Helloworld::MY_CONSTANT;
?>
--EXPECT--
140
