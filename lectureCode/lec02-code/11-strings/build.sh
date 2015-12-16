#!/bin/bash

# -D_GNU_SOURCE for strdup()
gcc --std=c11 -D_GNU_SOURCE -Wall -g main.c

