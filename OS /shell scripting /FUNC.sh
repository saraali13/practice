#!/bin/bash
greet() {
    echo "Hello, $1!"
}
greet "Sara"   # Output: Hello, Sara!

#multiple var
info() {
    echo "Name: $1"
    echo "Age: $2"
    echo "City: $3"
}

info "Ali" 22 "Karachi"


#variable passing

greet() {
    name=$1
    echo "Hello, $name!"
}

user="Alice"
greet "$user"


#Func with Return Value
add() {
    sum=$(( $1 + $2 ))
    echo $sum
}

result=$(add 5 7)
echo "Result is $result"
