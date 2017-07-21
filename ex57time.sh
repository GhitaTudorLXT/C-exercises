#!/bin/bash

declare -i exectimes=$1
declare -i tte=$exectimes
ftime=0
stime=0
extime=0

while [ $tte -gt 0 ]
do
	./ex57 ex57.in 1000 >> times
	tte=$tte-1
done

while read buffer
do
	sbuff=$buffer
	match=$(expr match "$sbuff" "Fast")
	if [ $match -eq "4" ]
	then
		extime=$(cut -c7-14 <<< $sbuff)
		forstr="scale=6;$ftime + $extime"
		ftime=$(bc <<< $forstr)
	fi

	match=$(expr match "$sbuff" "Slow")
	if [ $match -eq "4" ]
	then
		extime=$(cut -c7-14 <<< $sbuff)
		forstr="scale=6;$stime + $extime"
		stime=$(bc <<< $forstr)
	fi
done < times


forstr="scale=6;$ftime/$exectimes"
echo "Average fast time: $(bc <<< $forstr)"

forstr="scale=6;$stime/$exectimes"
echo "Average slow time: $(bc <<< $forstr)"

rm times
