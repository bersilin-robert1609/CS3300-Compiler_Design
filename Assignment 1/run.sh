#!bin/bash/

read outputDir
 
make test.exe

mkdir $outputDir

i=0
for file in ./Inputs/*.java
do
    ./test.exe < $file > $outputDir/"$i".java
    i=$((i+1))
done
