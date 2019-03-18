echo "working at `pwd`"
cwd=`pwd`
gcc "${cwd}/main.cpp"

for f in `find ${cwd} -name "*.in"`
do
    fname="${f##*/}"
    fname="${f%.*}"
    echo $fname
    cat $f|./a.out>"$fname.out"
done
