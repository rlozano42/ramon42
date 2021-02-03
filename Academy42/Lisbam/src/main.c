#include <stdio.h>

 extern char *ft_strdup(const char *str);


 int main ()
 {
     char * s1 = "";
//     char *s2  = "hola mundo";

     printf("%s", ft_strdup(s1));
 }