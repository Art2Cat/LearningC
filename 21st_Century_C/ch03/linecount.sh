#!/bin/bash

lines=`grep '[;)}]' *.c | wc -l`

files=`ls *.c | wc -l`

echo files=$files and lines=$lines

echo lines/file = $(($lines/$files))

bc << ---
scale=3
$lines/$files
---

