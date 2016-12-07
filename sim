#!/bin/bash


page_size=$1
window_size=$2
process=$3

# stackoverflow 'how do i test if a variable is a number in bash'


# check if we have 3 arguments, also we should check if the third argument is valid as well
if [ "$process" ]; then
	
	# too many arguments
	if [ "$4" ]; then
		echo "Too many arguments"
		exit
	# checks if both page size and window size are numbers
	elif ! [[ $page_size =~ ^[0-9]+$ ]] ; then 
		echo "Both page_size(!) and window_size must be numbers"
		exit
	elif ! [[ $window_size =~ ^[0-9]+$ ]] ; then
		echo "Both page_size and window_size(!) must be numbers"
		exit
	fi

# not enought arguments 
else
	echo "3 arguments needed"
	exit
fi

# command line arguments are valid if we get here

# the process
make clean
make $process

./$process
# runs the simulator which takes in the process name as the argument
# is this what we want?

#./simulator $process
