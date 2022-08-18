#!bin/bash/

read outputDir
 
make test.exe
cd ..
mkdir $outputDir

i=0
for file in ./Inputs/*.java
do
    ./main/test.exe < $file > $outputDir/"$i".java
    i=$((i+1))
done
