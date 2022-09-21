read dirName

for file in $dirName/*.txt
do
    echo "Processing $(basename $file .txt)"
    java -jar pgi.jar < $file
done