#!/bin/bash

writefile=$1
writestr=$2

if [ $# -ne 2 ]
    then
        echo Not enough arguments given
fi

# Make full directory path if it doesn't exist
onlydirectories=$(mkdir -p "$(dirname "$writefile")")

# Make the file
onlyfile=$(basename "$writefile")
touch "$onlyfile" || { echo "Fail"; exit 1; }

# Add writestr to a new file, writefile.
echo "$writestr" > "$writefile" || { echo "Fail"; exit 1; }

echo "Successful write"