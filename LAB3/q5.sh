#!/bin/bash
extension=$1
folder=$2
result=`find . -maxdepth 1 -name *$extension`
mkdir $folder
for i in $result
do
	mv $i $folder
done
