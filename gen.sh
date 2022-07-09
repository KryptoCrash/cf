set -e
g++ $1.cpp -o $1
g++ gen.cpp -o gen
g++ $1bad.cpp -o $1bad
for((i = 1; ; ++i)); do
    ./gen $i > s.in
    ./$1 < s.in > myAnswer
    ./$1bad < s.in > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat s.in
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer