#!/bin/sh
echo "\033[0;32m Directory structure: This dir should contain the script, a dir with libft (Libft) and a dir with the tests (Tests) \033[0m"
rm -rf output
touch output
echo "Checking norminette"
echo "Norminette: " >> output
cd Libft && norminette | cat -e | grep "Error" >> ../output
cd ..
echo "Checking norminette+"
echo "Norminette+: " >> output
cd Libft 
curl -sL bit.ly/qnorm | bash | grep -B 1 "Error" >> ../output
cd ..
rm -rf compilation_info
touch compilation_info
echo "Compiling"
cd Libft && make | cat -e >> ../compilation_info && cd ..
echo "Relinking: " >> output
cd Libft
make | cat -e >> ../output
echo "Bonus Relinking: " >> ../output
make bonus | cat -e >> ../compilation_info
make bonus | cat -e >> ../output
cd ..
echo "Cleaning up"
cd Libft && make fclean | cat -e >> ../compilation_info && cd ..
open output