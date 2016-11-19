--TEST--
Check if Helloworld printHelloWorld method is ok
--SKIPIF--
<?php if (!extension_loaded("helloworld")) print "skip"; ?>
--FILE--
<?php
$class = new Helloworld();
$class->printYourFirstAndLastName(['firstname' => 'Jules', 'lastname' => 'Verne']);
?>
--EXPECT--
Helloworld::__construct
Your name is Jules Verne
