#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    unsigned int src_size = 5, dst_size = 10;
    int diff = -3;
    int * Xsrc = (int *)calloc(src_size, sizeof(int));
    int * Xdst = (int *)calloc(dst_size, sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < src_size; i++)
    {
        Xsrc[i] = rand() % 10;
    }
    printf("Source array before memory copy:\n");
    for(int i = 0; i < src_size; i++)
    {
        printf("Xsrc[%d] = %d\n", i, Xsrc[i]);
    }
    Xdst = Xsrc + diff;
    int bytes_copied = memory_copy((void *)Xdst, (const void *)Xsrc, dst_size * sizeof(Xdst[0]));
    char * s = (bytes_copied >= 0) ? "Number of bytes copied: " : "Error: Memory copy failed: ";    
    printf("%s %d\n", s, bytes_copied);
/*     printf("Source array after memory copy:\n");
    for(int i = 0; i < src_size; i++)
    {
        printf("Xsrc[%d] = %d\n", i, Xsrc[i]);
    } */
    printf("Destination array after memory copy:\n");
    for(int i = 0; i < dst_size; i++)
    {
        printf("Xdst[%d] = %d\n", i, Xdst[i]);
    }
    return 0;
}
