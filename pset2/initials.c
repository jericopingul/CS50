#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    
    bool printL = true;    // print letter
    
    for(int i = 0, n = strlen(name); i < n; i++)
    {          
        if(printL)
        {
            printf("%c", toupper(name[i]));
            printL = false;
        }   
        
        // if space is character
        if(name[i] == ' ')
            printL = true;
    }
    printf("\n");
}
