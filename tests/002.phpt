--TEST--
Check if Helloworld __construct method is ok
--SKIPIF--
<?php if (!extension_loaded("helloworld")) print "skip"; ?>
--FILE--
<?php
$class = new Helloworld();
?>
--EXPECT--
Helloworld::__construct
