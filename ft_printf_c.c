#include "ft_printftests.h"

void category_c()
{
	int outcome;
	int ft_outcome;
	int file_outcome;
	int len_outcome;
	int test_count;

	outcome = 0;
	ft_outcome = 0;
	file_outcome = 0;
	len_outcome = 0;
	test_count = 0;

	fclose(fopen("error_log.txt", "w"));
	printf("-------------------\n");
	printf("|   category c    |\n");
	printf("-------------------\n");
	test_count++;
	freopen("ft_temp.txt", "w", stdout); 
	ft_outcome = ft_printf("lol %c", '1'); 
	freopen("temp.txt", "w", stdout);
	outcome = printf("lolc %c", '1');
	freopen("/dev/tty", "w", stdout);
	file_outcome = compare_files(test_count);
	len_outcome = compare_length(test_count, ft_outcome, outcome);
	printf("test %d: ", test_count);
	if(ft_outcome != outcome || file_outcome != 0) 
		printf("FAIL\n");
	else
		printf("OK\n");
	printf("-------------------\n");

	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
