clear && gcc -Wall -Wextra -Werror src/error_message/* src/map/* src/parsing/* src/display/* libft/libft.a && valgrind --leak-check=full ./a.out < map_test/map4
