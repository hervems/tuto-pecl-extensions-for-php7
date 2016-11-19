<?php

$br = '<br />';

if (php_sapi_name() == 'cli') {
    $br = '';
}

$extension = 'helloworld.'.PHP_SHLIB_SUFFIX;

if (!file_exists('modules'.DIRECTORY_SEPARATOR.$extension)) {
    exit('Extension "'.$extension.'" not found in modules directory!'.$br."\n");
}

if (!extension_loaded('helloworld')) {
    dl('helloworld.' . PHP_SHLIB_SUFFIX);
}

$extension = new ReflectionExtension('helloworld');
print_r($extension->getClasses());

$class = new ReflectionClass('Helloworld');
$methods = $class->getMethods();
print_r($methods);

echo $br, "\n";
$class = new HelloWorld();
$class->printYourFirstAndLastName(['firstname' => 'Jules', 'lastname' => 'Verne']);
