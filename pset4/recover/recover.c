#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, " Could not open %s.\n", argv[1]);
        return 1;
    }
    
    char filename[8];
    int countRecovered = 0;
    FILE *output = NULL;
    BYTE buffer[BLOCK_SIZE];
    
    //Read blocks of 512 BYTES until end of file 
    while (fread(&buffer, sizeof(BYTE), BLOCK_SIZE, inptr))
    {
        //IF is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // If there is an open file close it to star writing a new one
            if (output != NULL)
            {
                fclose(output);
            }
            //Get the name of the file
            sprintf(filename, "%03i.jpg", countRecovered);
            //Open output file
            output = fopen(filename, "w");
            //Add one to countRecovered so the file names increase by one
            countRecovered ++;
            // If output is not NULL the write the block in it
            if (output != NULL)
            {
                fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, output);
            }
        }
        else
        {
            //If it is not a new JPEG and there is an output file then write the block in it
            if (output != NULL)
            {
                fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, output);
            }
        }
    }
    
    //Clos both files
    fclose(output);
    fclose(inptr);
}