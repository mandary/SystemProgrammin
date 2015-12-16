#!/bin/bash

gcc -S func.c

gcc -S -O3 func.c -o func.s-optimized
