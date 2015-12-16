#!/bin/bash

echo -e "\ngcc main.c func.c"
if gcc main.c func.c; then
  echo Compile and link \(main.c func.c\) success!
else
  echo Compile and link \(main.c func.c\) failure!
fi
