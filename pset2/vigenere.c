#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Enter command line argumemnt!\n");
        return 1;
    }
    else
    {
        string k = argv[1]; // key
        int kLen = strlen(k);
        int c;  // ciphertext
        int kVal; // k value to be added
        int j = 0;
        
        // check if valid key
        for(int i = 0; i < kLen; i++)
            if(!isalpha(k[i % kLen]))
            {
                printf("Invalid key!\n");
                return 1;
            }
               
        string s = GetString(); // user input
        

        for(int i = 0, n = strlen(s); i < n; i++)
        {
            if(isupper(k[j % kLen]) && s[i] >= 65)   // upper case
            {
                kVal = k[j % kLen] - 65;
                j++;
            }
            else if(islower(k[j % kLen]) && s[i] >= 65)    // lower case
            {
                kVal = k[j % kLen] - 97;
                j++; 
            }
                   
            if(s[i] == ' ')
            {
                printf(" ");
            }
            else if(islower(s[i])) // lower case letters
            {
                c = ((s[i] + kVal) % 97) % 26 + 97;
                printf("%c", c);
            }
            else if(isupper(s[i])) // upper case letters
            {
                c = ((s[i] + kVal) % 65) % 26 + 65;
                printf("%c", c);
            }
            else // others
                printf("%c", s[i]);
        }
            
        printf("\n");
        return 0;
    }
}
