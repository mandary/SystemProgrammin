#!/bin/bash

gcc --std=c11 -Wall -g main.c

# print the addresses of main and globalInt

objdump -t a.out | grep -w main | grep text
objdump -t a.out | grep -w globalInt
