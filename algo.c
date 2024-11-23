#include "algo.h"

void lzss_compress(FILE *input, FILE *output) {
    unsigned char window[WINDOW_SIZE];
    unsigned char lookahead[LOOKAHEAD_BUFFER_SIZE];
    int window_pos = 0;
    int lookahead_pos = 0;
    int i, j, k, match_length, match_pos;

    memset(window, ' ', WINDOW_SIZE);

    while (1) {
        lookahead_pos = 0;
        while (lookahead_pos < LOOKAHEAD_BUFFER_SIZE && (lookahead[lookahead_pos] = fgetc(input)) != EOF) {
            lookahead_pos++;
        }

        if (lookahead_pos == 0) {
            break;
        }

        match_length = 0;
        match_pos = 0;

        for (i = 0; i < WINDOW_SIZE; i++) {
            for (j = 0; j < lookahead_pos; j++) {
                if (window[(window_pos + i) % WINDOW_SIZE] != lookahead[j]) {
                    break;
                }
            }

            if (j > match_length) {
                match_length = j;
                match_pos = i;
            }
        }

        if (match_length > 2) {
            fputc(1, output);
            fputc(match_pos >> 4, output);
            fputc(((match_pos & 0xF) << 4) | (match_length - 3), output);
        } else {
            match_length = 1;
            fputc(0, output);
            fputc(lookahead[0], output);
        }

        for (k = 0; k < match_length; k++) {
            window[window_pos] = lookahead[k];
            window_pos = (window_pos + 1) % WINDOW_SIZE;
        }
    }
}

void lzss_decompress(FILE *input, FILE *output) {
    unsigned char window[WINDOW_SIZE];
    int window_pos = 0;
    int i, j, k, flag, match_pos, match_length;

    memset(window, ' ', WINDOW_SIZE);

    while ((flag = fgetc(input)) != EOF) {
        if (flag == 1) {
            match_pos = (fgetc(input) << 4) | (fgetc(input) >> 4);
            match_length = (fgetc(input) & 0xF) + 3;

            for (i = 0; i < match_length; i++) {
                fputc(window[(window_pos + match_pos + i) % WINDOW_SIZE], output);
                window[window_pos] = window[(window_pos + match_pos + i) % WINDOW_SIZE];
                window_pos = (window_pos + 1) % WINDOW_SIZE;
            }
        } else {
            unsigned char c = fgetc(input);
            fputc(c, output);
            window[window_pos] = c;
            window_pos = (window_pos + 1) % WINDOW_SIZE;
        }
    }
}