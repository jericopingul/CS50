/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 
 #include <stdio.h>
 #include <stdint.h>
 
 const int BLOCK_SIZE = 512;
 
 int main(int argc, char *agrv[])
 {
    FILE *file;
    
    if ((file = fopen("card.raw", "r")) == NULL)
    {
        printf("Error opening the file \"ecard.raw\"...");
        return 1;
    }
    
    // size block
    uint8_t buffer[512];
    
    int jpeg = 0;
    FILE *fw = NULL;
    
    // iterate over file contents
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // checking first 4 bytes, as these must be jpeg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // if file is open close it
            if (fw != NULL)
                fclose(fw);
            
            char filename[8];
            sprintf(filename, "%03d.jpg", jpeg);
                
            // write to new jpeg file
            fw = fopen(filename, "w"); 
                
            jpeg++;
        }
        
        if (fw != NULL)
            fwrite(buffer, BLOCK_SIZE, 1, fw);
    }
    
    if (fw != NULL)
        fclose(fw);
    
    fclose(file);
 
    return 0;
 } 
