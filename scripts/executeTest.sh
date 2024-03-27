#!/bin/bash
if [ -z "$1" ]; then
    echo "Usage: scripts/executeTest.sh <test_name>"
    exit 1
fi

TEST_FOLDER="tests/$1"
if [ ! -d "$TEST_FOLDER" ]; then
    echo "Test $1 does not exist"
    exit 1
fi

cd $TEST_FOLDER

echo "Running test $1"
./main
