int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' && str[i] > 'Z')
			|| (str[i] < 'A' || str[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}
