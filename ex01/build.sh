#!/bin/bash

# build true and false executables from main.c

gcc -g -Wall -std=c11 -D TRUE=0 main.c -o true

gcc -g -Wall -std=c11 -D TRUE=1 main.c -o false
