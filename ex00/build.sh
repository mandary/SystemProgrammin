#!/bin/bash

# build executables from true.c and false.c

gcc -Wall -std=c11 -g -o true true.c

gcc -Wall -std=c11 -g -o false false.c
