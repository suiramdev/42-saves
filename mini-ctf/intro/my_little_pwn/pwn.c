#include <stdlib.h>
#include <stdio.h>

int main()
{
    int auth = 0;
    char buff[32];

    setbuf(stdout, NULL);

    puts("Ok now try to hack me.");
    gets(buff);
    if (auth != 0)
        system("cat flag.txt");
    else
        puts("Try again. Bye.");
}