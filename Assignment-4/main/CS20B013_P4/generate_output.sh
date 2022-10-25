#! bin/bash

mkdir trueOutput

for file in sample_microIR/*.microIR
do
    echo "Testing file... $file"
    java -jar kgi.jar < $file > trueOutput/$(basename $file .microIR).miniRA
done