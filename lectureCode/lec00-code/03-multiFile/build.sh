#!/bin/bash

echo -e "\ngcc -S main.c func.c"
if gcc -S main.c func.c; then
  echo Compile success!
  ls *.s
else
  echo Compile failure!
fi

echo -e "\n gcc main.c"
if gcc main.c; then
  echo Compile and link \(main.c\) success!
else
  echo Compile and link \(main.c\) failure!
fi

echo -e "\ngcc main.c func.c"
if gcc main.c func.c; then
  echo Compile and link \(main.c func.c\) success!
else
  echo Compile and link \(main.c func.c\) failure!
fi
