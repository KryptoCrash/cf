set -e
g++ gen.cpp -o gen
for((i = 1; i<500; ++i)); do
    ./gen $i > ./archive/out$i.txt
done
