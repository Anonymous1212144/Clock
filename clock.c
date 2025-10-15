#include <stdio.h>
#include <time.h>

int main()
{
    const char *format = "%F W%V-%u UTC%z     %T.000000000\r";
    struct timespec ts;
    char buff[50];
    char *b;

    while (1)
    {
        timespec_get(&ts, TIME_UTC);
        strftime(buff, sizeof buff, format, localtime(&ts.tv_sec));
        b = buff + 47;
        do
            *(b--) = '0' + ts.tv_nsec % 10;
        while (ts.tv_nsec /= 10);
        fputs(buff, stdout);
    }
}