#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return (1);
    }
    else
    {
        BYTE buffer[BLOCK_SIZE];
        FILE *file = fopen(argv[1], "r");
        int jpeg_num = -1;
        char file_name[8];
        FILE *recovered_img_p = NULL;
        if (!file)
        {
            printf("Invalid input\n");
            return (1);
        }
        while (fread(buffer, sizeof(BYTE)*BLOCK_SIZE, 1, file) == 1) // read 512 bytes into buffer per time till the end of the file
        {
            // if start of new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
            {
                if ((buffer[3] & 0xf0) == 0xe0)
                {
                    // if not first jpeg and file already exists
                    if (recovered_img_p)
                    {
                        fclose(recovered_img_p);
                    }
                    jpeg_num++;
                    sprintf(file_name, "%03i.jpg", jpeg_num);
                    recovered_img_p = fopen(file_name, "w");
                }
            }
            if (recovered_img_p) // if already found jpeg - keep writing to it
            {
                fwrite(buffer, sizeof(BYTE)*BLOCK_SIZE, 1, recovered_img_p);
            }
        }
        if (recovered_img_p)
        {
            fclose(recovered_img_p);
        }

        if (file)
        {
            fclose(file);
        }
    }
    return (0);
}