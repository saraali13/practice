#!/bin/bash
counter=1
while [ $counter -le 5 ]
do
    echo "Count: $counter"
    ((counter++))   # Increment counter
done
