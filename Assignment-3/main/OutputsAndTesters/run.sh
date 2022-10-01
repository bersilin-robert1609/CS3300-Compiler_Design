read outputDirectory
mkdir $outputDirectory

cd P2
javac P2.java

outputDir="../$outputDirectory"

for file in ../sample_minijava/*.java
do
    echo "Running $(basename $file .java)"
    q=$(basename $file .java)
    java P2 < $file > $outputDir/"$q.txt"
    java -jar ../pgi.jar < $outputDir/"$q.txt" > ../foutput/"$q.txt"
done

find -name "*.class" | xargs rm -f

cd ..
bash compare_output.sh