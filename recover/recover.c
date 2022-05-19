#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: recover [image ...]\n");
        return 1;
    }

    int cnt = 0;
    char filename[8];
    FILE *file = fopen(argv[1], "r");
    FILE *jpeg = NULL;
    unsigned char buffer[512];
    while (true)
    {
        size_t read = fread(buffer, 1, 512, file); // read file, 512 bits at once
        if (read == 0 && feof(file)) // check if file exits or if we reached the end
        {
            break;
        }
        bool isjpeg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
        if (isjpeg && jpeg != NULL) // checks if we already had a jpeg open
        {
            fclose(jpeg);
            cnt++;
        }
        if (isjpeg) // checks if it fits jpeg criteria
        {
            sprintf(filename, "%03i.jpg", cnt); // makes a new file with formatting for 000-999
            jpeg = fopen(filename, "w"); // opens the newly created file and prepares it for writing
        }
        if (jpeg != NULL) // checks if file is open
        {
            fwrite(&buffer, 1, read, jpeg); // writes to the jpg file
        }
    }
    fclose(jpeg);
    fclose(file);
}
