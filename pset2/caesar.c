#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        printf("Enter command line argumemnt!\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]); // secret key

        int c;  // ciphertext
        
        string s = GetString(); // user input
        

        for(int j = 0, n = strlen(s); j < n; j++)
        {
            if(s[j] == ' ')
            {
                printf(" ");
            }
            else if(islower(s[j])) // lower case letters
            {
                c = ((s[j] + k) % 97) % 26 + 97;
                printf("%c", c);
            }
            else if(isupper(s[j])) // upper case letters
            {
                c = ((s[j] + k) % 65) % 26 + 65;
                printf("%c", c);
            }
            else // others
                printf("%c", s[j]);
        }
            
        printf("\n");
        return 0;
    }
}
