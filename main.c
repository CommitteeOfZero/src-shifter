// This work is licensed under the terms of the MIT license.  
// To obtain a copy, see <https://opensource.org/licenses/MIT>.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("usage: src-shifter <in-file>.src\n");
        return 0;
    }

    size_t len = strlen(argv[1]) + sizeof(".out");
    char  *out = malloc(len);

    strcpy(out, argv[1]);
    strcat(out, ".out");

    FILE *fin  = fopen(argv[1], "rb");
    FILE *fout = fopen(out,     "wb");

    // to encrypt or decrypt, xor all bytes by 0x64
    for(int c; (c = fgetc(fin)) != EOF; fputc(c ^ 0x64, fout));

    printf("wrote to %s\n", out);
    return 0;
}
