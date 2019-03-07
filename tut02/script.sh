#!/bin/bash

echo "Hello world"

if test -d mydir
then
    echo "mydir exists"
fi

for i in a b c d
do
    echo "$i"
done
