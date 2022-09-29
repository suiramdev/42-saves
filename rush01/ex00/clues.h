/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:42:50 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 22:52:43 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLUES_H
# define CLUES_H

int	verify_clues(int *clues, int grid_size);
int	*get_clues(char *arg, int grid_size);

#endif
