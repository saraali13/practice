#!/bin/bash
read -p "Enter your age: " age

if [ $age -ge 18 ]; then #elif [condition]; then 
    echo "You are an adult."
else
    echo "You are a minor."
fi
