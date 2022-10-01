inDir=sample_minijava_2
outDir=sample_output_2
mkdir $outDir

for file in $inDir/*.java
do
    javac $file
    q=$(basename $file .java)
    java $file > $outDir/$q.out
done

find -name "*.class" | xargs rm -f