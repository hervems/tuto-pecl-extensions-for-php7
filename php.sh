#!/bin/bash

php -c php.ini -d extension_dir=./modules/ $*
