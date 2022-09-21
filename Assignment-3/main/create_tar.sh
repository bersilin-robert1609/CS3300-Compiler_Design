cd CS20B013_P2/
find . -name "*.class" | xargs rm -f
rm -r sample_minijava 
rm run.sh
cd ..
tar -cvzf CS20B013_P1.tar.gz CS20B013_P1
bash copy_testing.sh