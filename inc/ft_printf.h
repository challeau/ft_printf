/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:02:28 by challeau          #+#    #+#             */
/*   Updated: 2020/04/29 16:38:35 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# define BUFF_SZ 256
# define CONVS "cspdiuxX%"

typedef struct	s_flags
{
	int align;
	int width;
	int prec;
}				t_flags;

int				ft_printf(const char *format, ...);

char			*ft_init_buff(void);
void			ft_flush_buff(char *buff, int *char_count);
int				ft_fill_buff(char **buff, char *to_add, int *char_count);

int				ft_conv_handler(const char **f, va_list args, char **buff,
						int *c_count);
int				c_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				s_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				p_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				d_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				i_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				u_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				l_x_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				u_x_conv(va_list args, t_flags flg, char **buff, int *c_count);
int				pct_conv(va_list args, t_flags flg, char **buff, int *c_count);

t_flags			ft_flg_handler(const char **f, va_list args);
int				f_align(const char **format);
int				f_width(const char **format, va_list args);
int				f_prec(const char **format, va_list args);

char			*ft_add_spaces(char *src, int to_add_len, int align);
char			*ft_add_zeros(char *src, int to_add_len);
void			ft_bzero(char *str, size_t n);
char			*ft_char_to_str(char c);
char			*ft_dec_to_base(bool cap, unsigned long num,
					unsigned int base_len);
int				ft_intlen(long num);
char			*ft_itoa(int n);
void			ft_memdel(void *ptr);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_realloc(char *src, size_t new_sz);
char			*ft_strcat(char *dst, char *src);
int				ft_strchr_index(char *str, char to_find);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strlen(const char *str);
void			ft_strlowcase(char *str);
void			ft_strrev(char *str);
char			*ft_utoa(unsigned int num);

#endif
