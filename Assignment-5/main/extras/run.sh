#! bin/bash

read outputDir
[ ! -d $outputDir ] && mkdir $outputDir

cd P5
javac P5.java

for file in ../sample_miniRA/*.miniRA
do
    echo "Running $file"
    java P5 < $file > ../$outputDir/$(basename $file .miniRA).s
done

find . -name "*.class" | xargs rm

