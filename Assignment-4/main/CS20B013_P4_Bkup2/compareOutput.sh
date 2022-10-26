#! bin/bash

# Check if the output directory exists
[ ! -d $1 ] && echo "Output directory does not exist" && exit 1

# Check if the true output directory exists
[ ! -d trueOutput ] && echo "True output directory does not exist" && exit 1

mkdir temp

totCount=0
passCount=0

for file in $1/*.txt
do
    totCount=$((totCount+1))
    echo "Comparing file... $file"
    java -jar kgi.jar < $file > ./temp/$(basename $file .txt).txt
    if diff ./temp/$(basename $file .txt).txt trueOutput/$(basename $file .txt).txt
    then
        echo "Test passed"
        passCount=$((passCount+1))
    else
        echo "Test failed"
    fi
done

echo "Total tests passed: $passCount/$totCount"