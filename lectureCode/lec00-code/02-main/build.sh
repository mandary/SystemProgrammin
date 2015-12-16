#!/bin/bash

if gcc -S main.c; then
  echo Unoptimized compile success!
else
  echo Unoptimized compile failure!
fi

read
less main.s

echo Try to build...
if gcc main.c; then
  echo Compile and link success!
else
  echo Compile and link failure!
fi
