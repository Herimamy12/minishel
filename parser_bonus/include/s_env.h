/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako <nirirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:41 by nirirako          #+#    #+#             */
/*   Updated: 2024/10/12 08:22:41 by nirirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ENV_H
# define S_ENV_H
# include <stdlib.h>
# include "libft.h"

typedef struct s_env_lst
{
	int					index;
	char				*name;
	char				*value;
	struct s_env_lst	*next;
}	t_env;

t_env	*new_env(char *var_name, char *var_value, int index);
t_env	*new_env_lst(char **env);
t_env	*last_env(t_env *env);
void	insert_2_env_lst(char *var_name, char *var_value, int index,
			t_env **env);
void	destroy_env(t_env *env);
void	remove_from_env_lst(char *var_name, t_env **env);
void	destroy_env_lst(t_env *env);
char	*get_env_var_value(t_env *env, char *var_name);
void	print_env(t_env *env);
t_list	*env_2_lst(t_env *env);
int		set_env_var(char *var_name, char *new_value, t_env *env, int index);
t_env	*dup_env_lst(t_env *env_lst);
void	swap_env_lst_items(t_env *env1, t_env *env2);
void	sort_env_lst(t_env *env);
void	update_env_var(char *var_name, char *new_value, t_env **env, int index);
int		does_env_var_exist(char *var_name, t_env *env);
#endif
