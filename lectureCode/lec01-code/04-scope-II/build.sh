#!/bin/bash

if gcc -Wall -O0 main.c func.c; then
    gcc -O0 -S main.c func.c
fi




