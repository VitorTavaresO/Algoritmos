#include <stdio.h>
void convertSegToHour(int totalSeconds, int *hour, int *min, int *sec)
{
    *hour = totalSeconds / 3600;
    *min = (totalSeconds % 3600) / 60;
    *sec = (totalSeconds % 3600) % 60;
}

int main()
{
    int totalSeconds, hour, min, sec;
    printf("Digite o total de segundos: ");
    scanf("%d", &totalSeconds);
    convertSegToHour(totalSeconds, &hour, &min, &sec);
    printf("%d:%d:%d", hour, min, sec);
    return 0;
}