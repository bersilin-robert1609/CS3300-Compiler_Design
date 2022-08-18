#!bin/bash/

read outputDir
read name
make $name.exe
cd ..
mkdir $outputDir

i=0
for file in ./Inputs/*.java
do
    ./main/"$name".exe < $file > $outputDir/"$i".java
    i=$((i+1))
done
