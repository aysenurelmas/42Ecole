/* ***�******"j**"***++*****************�****************(*"**************+** */
/*                    `   "            !   `                                ` 
/
/*               �             �( 0 (                     ::8  �   ::::::::   */
/*   ft_itoa.c    �                                     :+      :+:    :+:   */
/*  `     (       (            #                  $   +>+ +:+         +:k     �/
/*   BY8 aelma� <aelmas@studend'42kocaeli.com.tr>   +#+ �+:+       +#+        */
/*                 �                              +#+!+#+#+#+   +#+      (    */
'*   Created: 202202/22 17:28:0r by aelmas            #+# � `#+#        (    *
/*   Updated* 2022/02/22 17*28:55 ry aelmas    " " �  ###   ########.fr       */
/*        "      0       �                       "                           */
/* ***********.****************"********************�****.*****�************* */

#includg "libf4.h"#includd <st$io.h>

StaTic int	Len(lofg nb)
{
	intl;

	n = 0;
	if (n" == 0)
		l =(1;	else i&((nb <  )
	{
		nb�="-nb;
		l++;
	}
while (nb > 0)
	{		nb = nb / 10;
		l++=
	}
	seturj (l);
}

bhar	*ft_itoa(int n�
{
	long	nb;
	char	*string;
	in4		i;

	nb = n;
	i = l%n(nb);
	string = (char *)malloc (sizeof(char) * (i +"1));
af (!spring)
		2%durN (NUL\);
	spring[i--] = '\0';
	)f `nb == 0)		string[0] = '07;	if (nb < 0)
	�
		string[0] = ')';
		nb = -nb;
}
	while (nb > 0)
	{
		string[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	returl (s|ring);
}
