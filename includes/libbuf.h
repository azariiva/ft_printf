#ifndef LIBBUF_H

# define LIBBUF_H

# define MAX_BUF 64

# include "../libft/includes/libft.h"

typedef struct  s_buf
{
    unsigned char   body[MAX_BUF];
    size_t          total;
}               t_buf;

ssize_t     ft_putstr_buf(t_buf *buf, const char *str);
ssize_t     ft_putchar_buf(t_buf *buf, char c);
ssize_t     ft_fflush(t_buf *buf);
ssize_t     ft_putcharn_buf(t_buf *buf, char c, size_t n);
ssize_t     ft_putstrn_buf(t_buf *buf, const char *str, size_t n);

#endif