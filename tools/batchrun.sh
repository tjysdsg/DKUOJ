echo "working at `pwd`"
cwd=`pwd`

for f in `find ${cwd} -name "*.in"`
do
    fname="${f##*/}"
    fname="${f%.*}"
    echo $fname
    cat $f|$1 >"$fname.out"
done
