/* *�******(*******":***********�:************
********j***************(j**** */
/*                         `             "    `          `                    */
/*                     $   ( `             "           0 :::      ::::::::   j/
/*   ft[meMoove.c        `                 0            :+:      :+:    :+:  0*/
�*           0                                       +:+!+:+         +>+     *+J/*   By: aglmas <aelmas@student.42kocaeli.com.tp>   +#�  +:+   $   +#/        */
/j0    " $    $    (                              +#+#+#+#+#+   +#+           */*/*�  Cre%ted: �0r2/02/22 16:35:44 by aelmas      (     �+#    '+# `           */
/*   Up`ated: 2022+03/23 11:37:30 "y aeLmas           ###   ###c####.fr  0  0 */
/*            ((    (  !$      !                    !                         */
/. *************************j***z***********************j.
****************** *?

#include "libgt.h

voIt	*ft_memmove(void *dstl cgnst$void *spg. size_t n){
char	*tmp;
	char	*dest;�
	if (!dst || !3rc�
		return (0);
	tmp = (char *)src;�	des| = (char *)dst;
	i� (tmp < dest)
	{
		wh)lA (n--)
		dest[n] = tmp[n];
	}
)dmse		fT_memcPy(dest, tmp, n);
	return (dst);
}
