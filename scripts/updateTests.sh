#!/bin/bash
for test in tests/*; do
    if [ -d "$test" ]; then
        cp main $test
    fi
done
