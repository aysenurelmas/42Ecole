char	*ft_strcat(char *dest, char *src)
{
	int	j;
	int	i;

	j = 0;
	while (dest[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
