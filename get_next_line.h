#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_exist(char *orig, int car);
char	*ft_free(char **aux);
char	*ft_read_buf(int fd, char *storg);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_concat(char *s1, char *s2);
char	*clean_storage(char *storage);
char	*new_line(char *storage);

#endif
