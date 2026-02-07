#!/bin/bash

target=$1

./ft_ls -lRa "$target" > a 2>&1
LC_ALL=C ls -lRa "$target" > b 2>&1

diff -y a b > diff_result

rm -f a b
