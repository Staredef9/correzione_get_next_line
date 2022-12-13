#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
    char	*str_return;
    int		total_size;

    if (!s1)
    {
	    s1 = (char*)malloc(1 * sizeof(char));
	    if (!s1)
		    return (0);
	    s1[0] = '\0';
    }
    total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
    str_return = (char *)malloc(sizeof(*s1) * total_size);
    if (!str_return)
        return (NULL);
    ft_strlcpy(str_return, s1, total_size + 1);
    ft_strlcat(str_return, s2, total_size + 1);
    free(s1);
    s1 = NULL;
    return (str_return);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t		i;

    i = 0;
    if (size != 0)
    {
        while (i < size - 1 ) //&& src[i] != '\n')
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t				i;
    size_t				j;

    i = 0;
    j = 0;
    while (i < size && dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0' && (i + j + 1) < size)
    {
        dest[i + j] = src[j];
        j++;
    }
    if (i < size)
        dest[i + j] = '\0';
    return (ft_strlen(src) + i);
}

size_t	ft_strlen(const char *s)
{
    int	i;

    i = 0;
    while (s[i] != '\0')
    {
        i ++;
    }
    return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return(0);
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == (char)c)
			return (s + i + 1);
		i++;
	}
	if (s[i] == (char) c)
		return (s + i + 1);
	else 
		return (NULL);
}

