/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:15:18 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/25 16:47:49 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	int	tmp;

	tmp = n;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > 0)
	{
		(*(unsigned char *)dest) = (*(unsigned char *)src);
		src++;
		dest++;
		n--;
	}
	dest -= tmp;
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (ptr == NULL)
		return (ptr = malloc (size));
	tmp = malloc (size);
	ft_memcpy (tmp, ptr, size);
	free(ptr);
	ptr = malloc (size);
	ft_memcpy (ptr, tmp, size);
	return (ptr);
}
