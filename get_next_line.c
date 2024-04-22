#include "get_next_line.h"

char	*ft_free(char **aux)
{
	free(*aux);
	*aux = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_exist(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*ft_read_buf(int fd, char *storg)
{
	char *buff;
	long int ret;

	ret = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(&storg));
	buff[0] = '\0';
	while ((ret > 0) && (!ft_exist(buff, '\n')))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret > 0)
		{
			buff[ret] = '\0';
			storg = ft_concat(storg, buff);	
		}
	}
	free(buff);
	if (ret == -1)
		return (ft_free(&storg));
	return (storg);
}

char	*get_next_line(int fd)
{
	static char	*storg = NULL;
	char		*res;

	if (fd < 0)
		return (NULL);
	if ((storg && !ft_exist(storg, '\n')) || !storg)
		storg = ft_read_buf(fd, storg);
	if(!storg)
		return (NULL);
	res = ft_substr(storg, 0, (ft_exist(storg, '\n') - storg) + 1);
	if (!res)
		return (ft_free(&storg));
	storg = clean_storage(storg);
	return (res);	
} 
