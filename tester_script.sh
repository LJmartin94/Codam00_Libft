echo "\033[0;32m Directory structure: This dir should contain the script, a dir with libft (Libft) and a dir with the tests (Tests) \033[0m"
rm -rf output
touch output
echo "Checking norminette"
cd Libft && norminette | cat -e | grep "Error" >> ../output
cd ..
rm -rf compilation_info
touch compilation_info
echo "Compiling"
cd Libft && make | cat -e >> ../compilation_info && cd ..
echo "Cleaning up"
cd Libft && make fclean | cat -e >> ../compilation_info && cd ..