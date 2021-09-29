#!/bin/zsh
if [ $# -gt 2 ]; then
    echo wrong number of args
    exit 1
fi

problemname="problems/$1"
echo $problemname
if [ -e $problemname ]; then
    echo "$problemname is already exist"
else
    mkdir -p $problemname
fi

if [ $# = 2 ]; then
    diff=($2)
else
    diff=("a" "b" "c" "d" "e" "f")
fi

for d in ${diff[@]}; do
    if [ -e $problemname/$d.cpp ]; then
        echo "$problemname/$d.cpp is already exist"
    else
        cp template.cpp $problemname/$d.cpp
        echo "$problemname/$d make"
    fi
done

for d in ${diff[@]}; do
    code "$problemname/$d.cpp"
done
