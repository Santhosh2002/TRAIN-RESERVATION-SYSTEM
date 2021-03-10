#include<stdio.h>
int main(int argc, char const *argv[])
{
    FILE *ptr;
    ptr = fopen("seatoccupied.txt","r+");
    char str[3];
    printf("THERE ARE TOTAL 30 SEATS\nBELOW LISTED ARE THE OCCUPIED SEAT");
    while(fgets(str,3,ptr)!= NULL)
    {
    
    printf("%s",str);
    }
    fclose(ptr);
    return 0;
}
