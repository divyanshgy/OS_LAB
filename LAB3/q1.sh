#!/bin/bash
if [ ! -e "$1" ]; then
	echo "the file '$1' does not exist"
	exit 1
fi
if [ -d "$1" ]; then
	echo "'$1' is a directory"
elif [ -f "$1" ]; then
	echo "'$1' is a file"
else 
	echo "'$1' is neither a file nor directory"
fi
