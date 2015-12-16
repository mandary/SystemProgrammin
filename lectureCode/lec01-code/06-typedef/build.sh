#!/bin/bash

if gcc -Wall -g main.c; then
    gcc -S main.c
fi

