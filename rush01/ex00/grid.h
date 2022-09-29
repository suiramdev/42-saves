/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:56 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 22:52:52 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

int		**init_grid(int grid_size);
void	complete_tallest(int **grid, int *clues, int i);
void	complete_suit(int **grid, int *clues, int i);
void	first_grid(int grid_size, int **grid, int *clues);

#endif
