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

echo "Running unit tester"
cd Tests
cd iKOLEtest
echo "\nUnit test: " >> ../../output
make fclean >> ../../compilation_info
cd ../../Libft
make bonus >> ../../compilation_info
cd ../Tests/iKOLEtest
make >> ../../compilation_info
./run_test
cat -e result.log >> ../../output
cd ../..

echo "Running happytramp"
cd Tests
cd happytramp
echo "\nhappytramp: " >> ../../output
make >> ../../compilation_info
./test >> ../../output
cd ../..

echo "Running Warmachine"
echo "\nWarmachine: " >> output
cd Tests
cd Warmachine
./grademe.sh
cat -e deepthought >> ../../output
cd ../..

echo "Running Boris' tests"
cd Tests
cp libft.a Boris\ Libft\ Test/
cp libft.h Boris\ Libft\ Test/
cd Boris\ Libft\ Test/
echo "\nBoris -  " >> ../../output
gcc -o Boris libft.a libtest.c
./Boris
cd ../../Libft
make bonus >> ../../compilation_info
cp libft.a ../Tests/Boris\ Libft\ Test/
cp libft.h ../Tests/Boris\ Libft\ Test/
cd ../Tests/Boris\ Libft\ Test/
gcc -o Boris libft.a lib_bonustest.c
./Boris
# gcc -o Boris libft.a lib_cleartest.c
# ./Boris
# gcc -o Boris libft.a lib_deltest.c
# ./Boris
rm -rf libft.a libft.h Boris
cd ../..

echo "\nRunning Destructor (just FYI)"
cd Tests
cd destructor2
./run.sh ../../Libft
cd ../..

echo "\nNote: stan's tests in ./Tests/stan are not used as they require criterion to run. 
This is too time consuming during a regular eval, but feel free to experiment with them!"

echo "\nCleaning up"
cd Libft 
make fclean | cat -e >> ../compilation_info 
cd ..
cd Tests
rm -rf libft.a libft.h
cd ..

rm -rf output_diff
touch output_diff
diff expected_output output >> output_diff
open output_diff