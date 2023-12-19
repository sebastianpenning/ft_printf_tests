/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printftests.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 12:54:09 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/19 18:45:18 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * col)
{
    char ch1, ch2;

    *line = 1;
    *col  = 0;

    do
    {
        // Input character from both files
        ch1 = fgetc(fPtr1);
        ch2 = fgetc(fPtr2);
        
        // Increment line 
        if (ch1 == '\n')
        {
            *line += 1;
            *col = 0;
        }

        // If characters are not same then return -1
        if (ch1 != ch2)
            return -1;

        *col  += 1;

    } while (ch1 != EOF && ch2 != EOF);
    /* If both files have reached end */
    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}

int compare_length(int test_count, int ft_outcome, int outcome)
{
	if(ft_outcome != outcome)
	{
	printf("Length is not equal. Check error_log.txt\n");
	freopen("error_log.txt", "a+", stdout);
	printf("Length error\n");
	printf("test: %d\n", test_count);
	printf("ft_print len: %d\n", ft_outcome);
	printf("print len: %d\n", outcome);
	printf("---------\n");
	freopen("/dev/tty", "w", stdout);
	}
	return(ft_outcome - outcome);
}

int compare_files(int test_count)
{
	int diff;
	int line, col;
	char s;
	FILE * fPtr1; 
    FILE * fPtr2;
	fPtr1 = fopen("ft_temp.txt", "r");
    fPtr2 = fopen("temp.txt", "r");
	s = '0';

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr1 == NULL || fPtr2 == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        return(-1);
    }
    /* Call function to compare file */
    diff = compareFile(fPtr1, fPtr2, &line, &col);

	rewind(fPtr1);
	rewind(fPtr2);
    if (diff != 0)
    {
        printf("Files are not equal. Check error_log.txt\n");
		freopen("error_log.txt", "a+", stdout);
		printf("---------\n");
		printf("File not equal error\n");
		printf("test: %d\n", test_count);
        printf("Line: %d, col: %d\n", line, col);
		printf("ft_printf\n");
		while((s=fgetc(fPtr1))!=EOF) 
		{
      		printf("%c",s);
   		}
		printf("\nprintf\n");
		while((s=fgetc(fPtr2))!=EOF) 
		{
      		printf("%c",s);
   		}
		printf("\n");
		printf("---------\n");
		freopen("/dev/tty", "w", stdout);
    }
    /* Finally close files to release resources */
    fclose(fPtr1);
    fclose(fPtr2);

    return 0;
}

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


int main ()
{
	// int rtr;

	// rtr = 0;
	// // char test[10] = "lolol";
	// printf("\n");
	// printf("My printf: \n");
	// // rtr = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 
	// 			// 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,   'C', "0", 0, 0 ,0 ,0, 42, 0);
	// rtr = ft_printf(" %p %p ", NULL, NULL);
	// printf("num: %d\n", rtr);

	// printf("\n");
	// printf("org printf: \n");
	// // rtr = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// rtr = printf(" %p %p ", NULL, NULL);
	// printf("num: %d\n", rtr);
	// // ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% ", 'A', "42", 42, 42 ,42 , 42, 42);
	// printf("\n");
	// // ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42);
	// // printf("\n-------------------\n");
	// // printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%", 'A', "42", 42, 42 ,42 , 42, 42);
	// // printf("\n");
	// // printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42);
	category_c();
}


lol