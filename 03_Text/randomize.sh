#!/bin/bash

DELAY=0
if [[ $# -ne 0 ]]
then
    DELAY=$1
fi

row=0
col=0
text_w_coord=()

while IFS= read -r line
do
    for i in $line
    do
        str="$line"
        substr="$i"
        prefix=${str%%$substr*}
        index=${#prefix}
        col=$index

        if [[ $i != " " ]]
        then
            text_w_coord+="$row $col $i\n"
        fi
    done
    col=0
    row=$((row + 1))
done

all_lines=$row
res_text=$(echo -e "$text_w_coord" | shuf)
tput clear

echo -e "$res_text" | while read row col word
do
    if [[ ${#row} && ${#col} > 0 ]]
    then 
        tput cup $row $col
        tput setaf $((($RANDOM) % 7 + 50))
        echo $word
        sleep $DELAY
    fi  
done

tput cup $all_lines 0