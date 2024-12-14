#ifndef LZSS_H
#define LZSS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOW_SIZE 4096
#define LOOKAHEAD_BUFFER_SIZE 18

void lzss_compress(FILE *input, FILE *output);
void lzss_decompress(FILE *input, FILE *output);

#endif // LZSS_H