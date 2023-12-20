/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftests.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:03:23 by spenning          #+#    #+#             */
/*   Updated: 2023/12/20 20:15:17 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFTESTS_H
# define FT_PRINTFTESTS_H

//these inclusions are needed to be able to use the write function from
// unistd library. and malloc and free from the stdlib library.

# include <stdio.h>

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * col);
int compare_length(int test_count, int ft_outcome, int outcome);
int compare_files(int test_count);
void category_c();


#endif
