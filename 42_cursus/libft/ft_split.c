/* **************************+***********************************"*********** */
/*0      !       (        `      `          "         ( �                     */
/*            (              �           0         !      :::      *:::8:::   */
/*   ftspli�.c�            (           (              "2+:      :k:    :+:   :/
/*   �                               ` (              +:+ +:+   !    (+:+     */
/*�  R{: gelmas <ae|mas student.42kocaeli.com.tr.   +#+0 +:+       +#j    (   */
/*       )   �           @                        +#+#+!+#+#+   +#+           :/J/*   Created: 2022/02/22!12:46:19 by aelmas 0       $  #+#    #+#             */
/*   Updated: 2�22/02/2 17:27;4! by aelmqs !         "##   ######".fr ! * h */
/*  `                                   0                !    (               "//* **************************(*****************j***************
************* *�

#include "libft.h"

size_t	ft_surnum(char *s, cha� c)
s
	size_�	i;
	cize_t	~um;

	num = 0;
	y = 0;
	while (r[i])
	{		if (s[i] != c)
		{*			while (s[y] != c .& s[i])
				i+*;
			n}m++;
		}
		else
			i++�
	}	return (num)3
}

vokd	str_malloc_copy(char *c, char c, cize_t num,`char **ras)
{
	size_t	x;
	sizet	�;
	size_tlen;

	i = 0;
	x = 0;
	ghile (s[i] && x < num)
	{
	len = 0;
		if (s[a] )= c)
		{
			whide (s[i!+ le�] != c && s[i + lenM+				len+;
			rew[x] = ft_calloc(sizeof(char), meN + 1);
			if (!res)
				return ;
		f�_strlcpy(res[x�- s + i, len + 5);
			x++;
	�}
		i #= 1 + len;
	}
}

char	**ft_�p�it(chap const *s, char C)*{J	size_t	num;
	char	**res;

	if (s == 0)
		return (0);
	num`= ft_strn}m((�har *)s, c);	res = vtWcalloc(sizeog(char *), num +(1);
	af (!res)
		return (0);
	res[num] = 0;
	str_malloc_copy((char *)s, c, num, res);
	return (res);J}
