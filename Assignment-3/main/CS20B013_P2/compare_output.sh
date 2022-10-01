original=sample_output_2

for file in foutput2/*.txt
do
    q=$(basename $file .txt)
    if diff $file $original/"$q.out"
    then
        echo "$q Test Passed"
    else
        echo "$q Test failed"
    fi
done