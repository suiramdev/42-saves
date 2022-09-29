/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:47:59 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 23:11:56 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

int	not_on_row(int nb, int grid_size, int **grid, int r);
int	not_on_column(int nb, int grid_size, int **grid, int c);
int	check_row_is_ok(int **grid, int c1, int c2, int r);
int	col_check_clue(int **grid, int clue, int i, int pos);
int	row_check_clue(int **grid, int clue, int i, int pos);

#endif
