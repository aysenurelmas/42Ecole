#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(src);
	str = (char *)malloc((i + 1) * sizeof(char));
	j = 0;
	if (str != NULL)
	{
		while (j < i && src[j] != '\0')
		{
			str[j] = src[j];
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
