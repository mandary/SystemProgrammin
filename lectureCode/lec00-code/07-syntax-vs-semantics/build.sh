#!/bin/bash

echo -e "\ngcc -E unless.c >unless.preprocessed.c"
gcc -E unless.c >unless.preprocessed.c

echo -e "\ngcc unless.preprocessed.c"
gcc unless.preprocessed.c
