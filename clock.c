#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec ts;
    char buff[50];
    struct tm ltime;

    while (1)
    {
        timespec_get(&ts, TIME_UTC);
        localtime_s(&ltime, &ts.tv_sec);
        strftime(buff, sizeof buff, "%F W%V-%u UTC%z      %T", &ltime);
        printf("%s.%09ld\r", buff, ts.tv_nsec);
    }
}