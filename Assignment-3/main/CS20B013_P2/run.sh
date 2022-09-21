read outputDirectory
mkdir $outputDirectory

cd P2
javac P2.java

outputDir="../$outputDirectory"

for file in ../sample_minijava/*.java
do
    java P2 < $file > $outputDir/$(basename $file .java).txt
done

find -name "*.class" | xargs rm -f