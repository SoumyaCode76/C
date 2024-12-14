#include "lzss.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[2], "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[3], "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        lzss_compress(input, output);
    } else if (strcmp(argv[1], "decompress") == 0) {
        lzss_decompress(input, output);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}