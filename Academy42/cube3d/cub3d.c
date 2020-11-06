/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:37:02 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/06 12:07:05 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int argc, char **argv)
{
    t_map param;
    
    ft_readmap(argv[1], &param);
    init_raycasting(&param);
    return(0);
}