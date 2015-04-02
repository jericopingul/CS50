#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    
    // get right user input
    do {
        printf("height: ");
        n = GetInt();
    } while (n < 0 || n > 23);
    
    // hashes and spaces to be printed
    int hashes, spaces;
    
    for(int i = 0; i < n; i++)
    {
        hashes = i + 2;
        spaces = n + 1 - hashes;
        
        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        
        for(int j = 0; j < hashes; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
