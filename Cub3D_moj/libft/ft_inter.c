/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 07:35:18 by ogoman            #+#    #+#             */
/*   Updated: 2024/07/30 07:35:21 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inter(char *s1, char *s2)
{
	int ascii[256] = {0}; // Assuming ASCII characters. Nado dlja togo, chto bi ogrnichit simvoli v predelah ascii
	while (*s2)
	{
		ascii[(unsigned char)*s2] = 1; // kazdij simvol pod opredelennim indeksom v ascii, poluchaet 1 (p eto 112, znachit index 112 = 1)
		s2++;
	}
	while (*s1)
	{
		if (ascii[(unsigned char)*s1] == 1)
		{
			write(1, s1, 1);
			ascii[(unsigned char)*s1] = 2; // Mark as printed
		}
		s1++;
	}
}

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$