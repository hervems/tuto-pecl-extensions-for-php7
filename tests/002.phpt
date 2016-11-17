--TEST--
Check if confirm_helloworld_compiled function is ok
--SKIPIF--
<?php if (!extension_loaded("helloworld")) print "skip"; ?>
--FILE--
<?php
echo confirm_helloworld_compiled("helloworld");
?>
--EXPECT--
Congratulations! You have successfully modified ext/helloworld/config.m4. Module helloworld is now compiled into PHP.
