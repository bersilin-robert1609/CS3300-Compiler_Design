#!bin/bash

read dirName

[ ! -d $dirName ] && mkdir $dirName

cd P4
javac P4.java

for file in ../sample_microIR/*.microIR
do
    echo "Testing file... $file"
    java P4 < $file > ../$dirName/$(basename $file .microIR).txt
done

find . -name "*.class" | xargs rm -f

cd ..

bash compareOutput.sh $dirName