#John Parkhurst
#9.20.21
#Basic executable check then execute the program
if test -e $1
then
    gcc $1 -o ans
    echo "Compiled"
else
    echo "Invalid argument list. Proper usage: script01 <path to source file> m1 [m2 [m3 [...]]]"
    exit 2
fi
#gcc prog01.c -o ans

./ans 36
./ans 494
./ans 13
./ans 3 -5
./ans 55 5
./ans 36 6
./ans 7 49
./ans dan 3
./ans 
./ans 3 dan
./ans -5 -5
./ans -5 3
echo "Complete"