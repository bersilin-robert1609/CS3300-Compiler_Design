cd RollNo_P1/P1/
javac P1.java
cd ..
cd ..
#read folderName
#mkdir $folderName
cd RollNo_P1/P1/

for file in ../../sample_minijava/*.java
do
    echo "---------------------------"
    echo Running "$(basename $file)"
    #java P1 < $file > ../../$folderName/$(basename $file).txt
    java P1 < $file
done
echo "---------------------------"