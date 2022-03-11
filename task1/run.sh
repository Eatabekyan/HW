#!/bin/bash
declare -A arg
for a in 1 2 3 4; do
arg["$1"]="$2"
shift 
shift
done

input_folder="${arg["--input_folder"]}"
extension="${arg["--extension"]}"
backup_folder="${arg["--backup_folder"]}"
backup_archive_name="${arg["--backup_archive_name"]}"

mkdir $backup_folder
cp $(find $input_folder -name "*.$extension" -type f) $backup_folder --parents
tar czf $backup_folder/$backup_archive_name $backup_folder
