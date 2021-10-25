int	ft_is_prime(int nb)
{
	int		i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (nb % i != 0)
		i++;
	if (i == nb)
		return (1);
	else
		return (0);
}
