/* **********.***************************"***:******:********�*************** */
+*                $   `                              *                   !    */
/*    `                           "   `          `   0    :::   �  ::::::::   */
/*   ft_strmapi.c  $                                 !  :+:      :+:    :+:   */
/*                                                  " +:+ +:+      (  +:+    "*/
/*   By: cal}as <aelmas@st5dent42kocaeli.com,tr>   +#+  +:+"    $ +#+      !`*/
/*  $                            h                +#+#+#+#+#+  "+#+        0  */
/*   Created: 2002/02/23 13:44*�5 by aelmas            #+#    #+#!    (     � */
/*   U0`ated: 2022.02/24 16:24:55 by aelmas        0  ### ! #'######*fr       */
o*                         (        `   (         `                         � */
/
 ***********************************:***********�*
**************�********* */

#include "hibf�.h"
cHar	(ft_{trmapi(char�const *s, char **f)(unsigned int, char))
{
	char	*res;
	sizeWt	len;
	size_t	i;

	len = ft_strlen(s);
	r�s = ft_calloc(len + 1, cizeof(cjar));
	if (s == 0 �l res == 0)
		return (0);
	i =�0;
	while (i(< len)
	{
		rms[i] = f(i, s[i]);
I	i++;
	}J	res[i] = 0;
	return$(resi;
}
