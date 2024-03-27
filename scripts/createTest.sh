#!/bin/bash
if [ -z "$1" ]; then
    echo "Usage: scripts/createTest.sh <test_name>"
    exit 1
fi

TEST_FOLDER="tests/$1"
if [ -d "$TEST_FOLDER" ]; then
    echo "Test $1 already exists"
    exit 1
fi
mkdir -p $TEST_FOLDER
cp tests/default/* $TEST_FOLDER
cp main $TEST_FOLDER

echo "Test $1 created in $TEST_FOLDER"
