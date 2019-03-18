echo "working at `pwd`"
cwd=`pwd`
gcc $1

for f in `find ${cwd} -name "*.in"`
do
    fname="${f##*/}"
    fname="${f%.*}"
    echo $fname
    cat $f|./a.out>"$fname.out"
done
