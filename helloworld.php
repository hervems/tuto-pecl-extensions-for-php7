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

$module = 'helloworld';

$functions = get_extension_funcs($module);

echo 'Functions available in the test extension:', $br, "\n";

foreach($functions as $func) {
    echo $func, $br, "\n";
}

echo $br, "\n";

$function = 'confirm_' . $module . '_compiled';

if (extension_loaded($module)) {
	$str = $function($module);
} else {
	$str = 'Module '.$module.' is not compiled into PHP';
}

echo $str, "\n";
