#include <stdio.h>

int main(int argc, char const *argv[])
{

    FILE *fp;
    int n;
    fp = fopen("seatoccupied.txt", "a+");
    char str[3];
    printf("enter no of seats you want to reserve\n");
    scanf("%d", &n); // idhr jhn par ise integrate krna ho whn no of reservation ko is n s replace kr skte h
    for (int i = 1; i <= n; i++)
    {
        printf("enter the seat you want\n");
        scanf("%s", &str);
        fprintf(fp, "\n");
        fputs(str, fp);
    }
    fclose(fp);
    return 0;
}
