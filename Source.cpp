#include <stdio.h>

double G_TMP;

char G_TMP_STR[16];
bool Idont[10];

char *decToBinary(unsigned short n) 
{ 
    // Size of an integer is assumed to be 16 bits 
    for (int i = 15; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            G_TMP_STR[i] = 49;
        else
            G_TMP_STR[i] = 48;
    } 
    return G_TMP_STR;
}

int main()
{
    decToBinary(8);
    for(int i = 15; i >= 0; i--)
    {
        printf("%c", G_TMP_STR[i]);
    }
    return 0; 
}
