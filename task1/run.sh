#!/bin/bash

while [ -n "$1" ]
do
case $1 in
	--input_folder) inputf=$2;;
	--extension) ext=$2;;
	--backup_folder) bup_f=$2;;
	--backup_archive_name) bupf_arc=$2;;
	esac
shift
done



mkdir $bup_f



for item in $(find $inputf -type f -name "*.$ext")
do
	cp --backup=numbered $item $bup_f
done



tar -czpf $bupf_arc $bup_f

echo "done"

