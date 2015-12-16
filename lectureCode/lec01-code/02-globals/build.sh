#!/bin/bash

gcc -Wall -O0 main.c func.c
gcc -O0 -S main.c func.c

