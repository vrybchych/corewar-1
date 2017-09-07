/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:30:27 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/09/07 13:38:36 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void		x_sti(t_player *player, unsigned char *arena)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	arg3;
	int				tmp;

	player->pc = (player->pc + 1) % MEM_SIZE;
	arg1 = ft_get_n_bytes(arena, player->pc, 1);
	if (arg1 < 1 || arg1 > REG_NUMBER)
		return ;
	arg1 = palyer->rgstrs[arg1 - 1];
	player->pc = (player->pc + 1) % MEM_SIZE;
	if (arena[player->pc] == 84) // T_REG | T_REG | T_REG
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg2 < 1 || arg2 > REG_NUMBER)
			return ;
		arg2 = palyer->rgstrs[arg2 - 1];
		arg3 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg3 < 1 || arg3 > REG_NUMBER)
			return ;
		arg3 = palyer->rgstrs[arg3 - 1];
	}
	else if (arena[player->pc] == 88) // T_REG | T_REG | T_DIR
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg2 < 1 || arg2 > REG_NUMBER)
			return ;
		arg2 = palyer->rgstrs[arg2 - 1];
		arg3 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else if (arena[player->pc] == 100) // T_REG | T_DIR | T_REG
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 1) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 2) % MEM_SIZE;
		if (arg3 < 1 || arg3 > REG_NUMBER)
			return ;
		arg3 = palyer->rgstrs[arg3 - 1];
	}
	else if (arena[player->pc] == 104) // T_REG | T_DIR | T_DIR
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else if (arena[player->pc] == 116) // T_REG | T_IND | T_REG
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
        tmp = player->pc - 3 + (int)arg2;
        arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 1);
		player->pc = (player->pc + 1) % MEM_SIZE;
		if (arg3 < 1 || arg3 > REG_NUMBER)
			return ;
		arg3 = palyer->rgstrs[arg3 - 1];
	}
	else if (arena[player->pc] == 120) // T_REG | T_IND | T_DIR
	{
		arg2 = ft_get_n_bytes(arena, player->pc, 2);
		arg2 = ft_get_n_bytes(arena, player->pc, 2) % IDX_MOD;
        tmp = player->pc - 3 + (int)arg2;
        arg2 = ft_get_n_bytes(arena, ft_addr(tmp), 4);
		player->pc = (player->pc + 2) % MEM_SIZE;
		arg3 = ft_get_n_bytes(arena, player->pc, 2);
		player->pc = (player->pc + 2) % MEM_SIZE;
	}
	else 
		return ;
	arena[(arg2+ arg3) % MEM_SIZE] = arg1;
}
