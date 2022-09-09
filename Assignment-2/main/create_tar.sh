cd current/
find . -name "*.class" | xargs rm
rm -r sample_minijava
rm run.sh
cd ..
tar -cvzf CS20B013_P1.tar.gz current