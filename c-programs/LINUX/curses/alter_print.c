/* this program is laternative to printf and scanf by using files
1- printing to console
2- printinfg on console that is present in  stream buffer
3- taking form console and pring again on console

*/

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
fprintf(stdout,"this is text\n");
char * stream="my name is linux",*ipstream=malloc(10);
fputs(stream,stdout);


fgets(ipstream,10,stdin);

fputs(ipstream,stdout);
}

