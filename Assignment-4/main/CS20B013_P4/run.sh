#!bin/bash

read dirName
mkdir $dirName

cd P4
javac P4.java

for file in ../sample_microIR/*.microIR
do
    echo "Testing $file"
    java P4 < $file > ../$dirName/$(basename $file .microIR).txt
done

find . -name "*.class" | xargs rm -f