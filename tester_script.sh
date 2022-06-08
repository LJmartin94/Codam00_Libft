#!/bin/sh
echo "\033[0;32m Directory structure: This dir should contain the script, a dir with libft (Libft) and a dir with the tests (Tests) \033[0m"
rm -rf output
touch output

echo "Checking norminette"
echo "\nNorminette: " >> output
cd Libft 
norminette | cat -e | grep "Error" >> ../output
cd ..

echo "Checking norminette+"
echo "\nNorminette+: " >> output
cd Libft 
curl -sL bit.ly/qnorm | bash | grep -B 1 "Error" >> ../output
cd ..

echo "Compiling"
rm -rf compilation_info
touch compilation_info
cd Libft 
make | cat -e >> ../compilation_info
echo "\nRelinking: " >> ../output
make | cat -e >> ../output
echo "\nBonus Relinking: " >> ../output
make bonus | cat -e >> ../compilation_info
make | cat -e >> ../output
make bonus | cat -e >> ../output
cd ..

echo "Copying libft to test dir"
cd Libft
make >> ../compilation_info
make bonus >> ../compilation_info
cp libft.a ../Tests >> ../compilation_info
cp libft.h ../Tests >> ../compilation_info
if test -f "../Tests/libft.a"; then
    echo "\033[0;32mlibft.a exists.\033[0m"
else
    echo "\033[0;31mlibft.a FAILED! \033[0m"
fi
if test -f "../Tests/libft.h"; then
    echo "\033[0;32mlibft.h exists.\033[0m"
else
    echo "\033[0;31mlibft.h FAILED! \033[0m"
fi
cd ..

echo "Running my Ugly Tester"
echo "\nUgly Tester: " >> output
cd Tests
gcc -w -o ugly libft.a uglyLibftTester.c
./ugly | cat -e >> ../output
rm ugly
cd ..

echo "Running Boris' tests"
cd Tests
cp libft.a Boris\ Libft\ Test/
cp libft.h Boris\ Libft\ Test/
cd Boris\ Libft\ Test/
echo "\nBoris -  " >> ../../output
gcc -o Boris libft.a libtest.c
./Boris
gcc -o Boris libft.a lib_bonustest.c
./Boris
# gcc -o Boris libft.a lib_cleartest.c
# ./Boris
# gcc -o Boris libft.a lib_deltest.c
# ./Boris
rm -rf libft.a libft.h Boris
cd ../..

echo "Running Warmachine"
echo "\nWarmachine: " >> output
cd Tests
cd Warmachine
./grademe.sh
cat -e deepthought >> ../../output
cd ../..

echo "Cleaning up"
cd Libft 
make fclean | cat -e >> ../compilation_info 
cd ..
cd Tests
rm -rf libft.a libft.h
cd ..
open output