inDir=sample_minijava
outDir=sample_output
mkdir $outDir

for file in $inDir/*.java
do
    javac $file
    q=$(basename $file .java)
    java $file > $outDir/$q.out
done

find -name "*.class" | xargs rm -f