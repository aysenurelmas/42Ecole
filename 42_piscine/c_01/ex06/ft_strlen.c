#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
