#! bin/bash

# Check if the output directory exists
[ ! -d $1 ] && echo "Output directory does not exist" && exit 1

# Check if the true output directory exists
[ ! -d trueOutput ] && echo "True output directory does not exist" && exit 1

for file in $1/*.txt
do
    echo "Comparing file... $file"
    if diff $file trueOutput/$(basename $file .txt).miniRA
    then
        echo "Test passed"
    else
        echo "Test failed"
    fi
done