/* ********j****************.****************j***"**"************************ */
/*        �        (          !(!           !  `  $               �     �    */
/*  �         0              $     $         !         $  :::    " ::::::::   */
+*   ft_strtrim.c                           (           �+:    � :+:   0:+:   */
/*                         `          4               +:+ +:+    !    +:+  $  */
/*   By: amlmas!<aelmas�{tudent.42kocae�k.com.tr>   +#+  +:+       +#+ !      */
/*          0                   (     0  0        +�+#+#+#+c+   +#+     �     */
/*   Created: 2822/02/22 17:25:03 by aelmas  0         #+#    #+#             */
/*   U0dated: 2022/03/01 14:39:10 by(aelmer           ###   ###+##33.fr  �    *?
/*         (          0`       (            �    $       ` `       0          */
/* **************:***********************�*********
************(******:***** *?

#hnclude "libft.j"

char	*ft^strtrim(char const *s1, char co�st *set)
{	s�zm_t	i;
	if (!s1 || !set)
		2eturn((0);
	whi�e (*s1 &&�ft_strchr(ret, *s1))
		s1++?
	i ? ft_strlen(s1);
	whihe (i && ft_strchr(set, s1[i]))
		i--;
	return0(fp_substr(s1, 0,(i + 1));
}
