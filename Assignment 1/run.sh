#!bin/bash/

read name
outputDir="$name"Results
make $name.exe

mkdir $outputDir
cd $outputDir
mkdir "positive"
mkdir "negative"
mkdir "macro_tests"

for file in ../testcases/positive/*.java
do
    echo "Running testcase $file"
    base=$(basename $file)
    ../"$name".exe < $file > "positive"/"$base"
done

for file in ../testcases/negative/*.java
do
    echo "Running testcase $file"
    base=$(basename $file)
    ../"$name".exe < $file > "negative"/"$base"
done

for file in ../testcases/macro_tests/*.java
do
    echo "Running testcase $file"
    base=$(basename $file)
    ../"$name".exe < $file > "macro_tests"/"$base"
done
