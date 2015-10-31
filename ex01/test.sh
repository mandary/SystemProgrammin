#!/bin/bash

# test true and false executables to see if they 
# return the correct result

if ./true; then
    echo Success
else
    echo Failure
fi


if ! ./false; then
	echo Success
else
	echo Failure
fi