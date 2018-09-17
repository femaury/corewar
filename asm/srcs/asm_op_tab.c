/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:45:44 by femaury           #+#    #+#             */
/*   Updated: 2018/09/17 20:11:40 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op_tab	g_op_tab[17] = {
	{ "live", 0x01, 1, {T_DIR, 0, 0}, 4, 0 },
	{ "ld", 0x02, 2, {T_DIR | T_IND, T_REG, 0}, 4, 1 },
	{ "st", 0x03, 2, {T_REG, T_REG | T_IND, 0}, 0, 1 },
	{ "add", 0x04, 3, {T_REG, T_REG, T_REG}, 0, 1 },
	{ "sub", 0x05, 3, {T_REG, T_REG, T_REG}, 0, 1 },
	{ "and", 0x06, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1 },
	{ "or", 0x07, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1 },
	{ "xor", 0x08, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1 },
	{ "zjmp", 0x09, 1, {T_DIR, 0, 0}, 2, 0 },
	{ "ldi", 0x0a, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1 },
	{ "sti", 0x0b, 3, {T_REG, T_REG | T_IND | T_DIR, T_DIR | T_REG}, 2, 1 },
	{ "fork", 0x0c, 1, {T_DIR, 0, 0}, 2, 0 },
	{ "lld", 0x0d, 2, {T_IND | T_DIR, T_REG, 0}, 4, 1 },
	{ "lldi", 0x0e, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1 },
	{ "lfork", 0x0f, 1, {T_DIR, 0, 0}, 2, 0 },
	{ "aff", 0x10, 1, {T_REG, 0, 0}, 0, 1 },
	{ "\0", 0x00, 0, {0, 0, 0}, 0, 0 }
};
