/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:53:35 by ogoman            #+#    #+#             */
/*   Updated: 2024/05/02 15:01:45 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	size_t i;
	i = 0;
	if (new_size <= old_size)
	{
		return ptr;
	}
	void *new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return NULL;
	}

	while (i < old_size)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return new_ptr;
}