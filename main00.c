/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:24:24 by rlozano           #+#    #+#             */
/*   Updated: 2019/10/17 12:24:31 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	main()
{
	char src[] = "cosa";
	char src2[] = "casa";
	int		r;
	r = ft_strcmp(src, src2);
	printf("%d", r);
}
