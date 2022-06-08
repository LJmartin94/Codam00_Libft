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
cd ..

echo "Cleaning up"
cd Libft 
make fclean | cat -e >> ../compilation_info 
cd ..
cd Tests
rm -rf libft.a libft.h
cd ..
open output