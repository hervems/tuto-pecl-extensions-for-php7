Tutorials to create PECL extensions for PHP 7 and more
======================================================

This version #1 contains a simple function `confirm_helloworld_compiled`.

Generate a skeleton
-------------------

To generate a skeleton of a pecl extension, you can use the binary `ext_skel` presents
in PHP sources (directory : `ext/`), example:

```bash
./ext_skel helloworld
```

Compile the extension
---------------------

* The first step is to use `phpize`:

```bash
phpize
```

* The second step is to launch `configure`:

```bash
./configure
```

* The third step is to compile it:

```bash
make
```

Launch phpt tests
-----------------

The last step is to launch tests:

```bash
make test
```

I added a phpt test in `tests/` directory named `tests/002.phpt`.

Launch php
----------

You can find a `helloworld.php` which can be launch with `php.sh` like that:

```bash
./php.sh helloworld.php
```
