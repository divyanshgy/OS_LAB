#!/bin/bash
#sed -i '2~2d' $1
sed 'n;d' "$1"
