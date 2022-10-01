original=sample_output

for file in foutput/*.txt
do
    q=$(basename $file .txt)
    if diff $file $original/"$q.out"
    then
        echo "$q Test Passed"
    else
        echo "$q Test failed"
    fi
done