#include "memory_copy.h"

static void reverse_array(void * pArr, unsigned int start, unsigned int end);

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

static void reverse_array(void * pArr, unsigned int start, unsigned int end)
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