#!/bin/bash
echo "Enter the number:"
read input
for((i=2;i<input;i++))
do
	if [ $[ $input % $i ] == 0 ]; then
		echo "Not a prime number"
		exit 1;
	fi
done
echo "Prime number"
exit 0
