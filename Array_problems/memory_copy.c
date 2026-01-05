#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int memory_copy(void * dst, const void * src, unsigned int length);

void reverse_array(void * pArr, unsigned int start, unsigned int end);

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
    printf("Source array after memory copy:\n");
    for(int i = 0; i < src_size; i++)
    {
        printf("Xsrc[%d] = %d\n", i, Xsrc[i]);
    }
    printf("Destination array after memory copy:\n");
    for(int i = 0; i < dst_size; i++)
    {
        printf("Xdst[%d] = %d\n", i, Xdst[i]);
    }
    return 0;
}

int memory_copy(void * dst, const void * src, unsigned int length)
{
    int count = 0;
    if(src == NULL || dst == NULL)
    {
        count = -1;
    }
    else if(src == dst)
    {
        count = 0;
    }
    else if(length == 0)
    {
        count = 0;
    }
    else
    {
        unsigned char * pSrc = (unsigned char *)src;
        unsigned char * pDst = (unsigned char *)dst;
        unsigned int address_difference = (pDst > pSrc) ? (pDst - pSrc) : (pSrc - pDst);
        if(address_difference > length)
        {
            for(int i = 0; i < length; i++)
            {
                pDst[i] = pSrc[i];
                count++;
            }
        }
        else
        {
            for(int i = length - address_difference, j = 0; i < length; i++, j++)
            {
                if(pDst < pSrc)
                {
                    pDst[j] = pSrc[i];
                }
                else
                {
                    pDst[i] = pSrc[j];                    
                }
                count++;
            }
            /* Reverse the destination array */
            if(pDst < pSrc)
            {
                reverse_array((void *)pDst, 0, address_difference - 1);
                reverse_array((void *)pDst, address_difference, length - 1);
                reverse_array((void *)pDst, 0, length - 1);   
            }
            else
            {
                reverse_array((void *)pDst, 0, length - address_difference - 1);
                reverse_array((void *)pDst, length - address_difference, length - 1);
                reverse_array((void *)pDst, 0, length - 1);                
            }
        }
    }
    return count;    
}

void reverse_array(void * pArr, unsigned int start, unsigned int end)
{
    char * X = (char *)pArr;
    unsigned int mid = (end - start) / 2;
    for(int i = 0; i <= mid; i++)
    {
        if(X[start + i] != X[end - i])
        {
            X[start + i] = X[start + i] ^ X[end - i];
            X[end - i] = X[start + i] ^ X[end - i];
            X[start + i] = X[start + i] ^ X[end - i];
        }
    }
}
