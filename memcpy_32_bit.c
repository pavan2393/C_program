//Memcpy for 32bit aligned
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void memCpy8(uint8_t* pDst, uint8_t* pSrc, int n)
{
    while(n > 0)
    {
        *pDst++ = *pSrc++;
         n--;
    }
}

void myMemCp(void* dst, const void* src, int numBytes)
{
    if(numBytes == 0)
        return;


    uint8_t* pDst = (uint8_t*)dst;
    uint8_t* pSrc = (uint8_t*)src;
    uint32_t shiftl = 0, shiftr = 0;

    if(numBytes < 4)
    {
        memCpy8(pDst, pSrc, numBytes);
        return;
    }

    uint32_t uaSrc = 4 - ((uint32_t)pSrc & 0x03);
    uint32_t uaDst = 4 - ((uint32_t)pDst & 0x03);

    memCpy8(pDst, pSrc, uaDst);

    uint32_t* pSrcWord;
    uint32_t* pDstWord;
    uint32_t dif;

    pDstWord = (uint32_t*)(pDst + uaDst);
    if(uaSrc <= uaDst)
    {
        pSrcWord = (uint32_t*)(pSrc + uaSrc);
        dif = uaDst - uaSrc;
        if(dif == 1)
        {
            shiftr = 8;
            shiftl = 24;
        }
        else if(dif == 3)
        {
            shiftr = 24;
            shiftl = 8;
        }

    }
    else
    {
        pSrcWord = (uint32_t*)(pSrc + uaSrc - 4);
        dif = uaSrc - uaDst;
        if(dif == 3)
        {
            shiftr = 8;
            shiftl = 24;
        }
        else if(dif == 1)
        {
            shiftr = 24;
            shiftl = 8;
        }
    }
    
    if(dif == 2)
    {
        shiftr = 16;
        shiftl = 16;
    }

    uint32_t remLen = numBytes - uaDst;
    uint32_t numWords = remLen >> 2;
    uint32_t tail = remLen & 0x03;
    
    
    uint32_t srcWord1 = *pSrcWord++;
    uint32_t srcWord2;
    uint32_t numWordsCpy = numWords;

    // Copy all full words
    while(numWords > 0)
    {
         srcWord2 = *pSrcWord++;
         if(dif != 0)
            *pDstWord++ = (srcWord1 >> shiftr) | (srcWord2 << shiftl);
         else
            *pDstWord++ = srcWord1;
         srcWord1 = srcWord2;
         numWords--;
    }

    if(tail == 0)
        return;

    uint32_t numCopied = uaDst + (numWordsCpy << 2);

    pSrc = pSrc + numCopied;
    pDst = pDst + numCopied;

    memCpy8(pDst, pSrc, tail);
}


int main()
{
    uint8_t src[100];
    uint8_t *pSrc = &src;
    
    while(((uint32_t)pSrc & 0x03) != 0)
    {
         pSrc++;
    }
    

    uint8_t dst[100];
    uint8_t* pDst = &dst;

    while(((uint32_t)pDst & 0x03) != 0)
    {
         pDst++;
    }
    pSrc = pSrc;
    pDst += 0;

    int i;
    int val = 1;

    for(i = 0; i < 12; i++)
    {
        pSrc[i] = val;
        val++;
    }
    

    myMemCp(pDst, pSrc, 12);

    for(i = 0; i < 12; i++)
    {
        printf("Dst[%d] : %x\n", i, (uint32_t)pDst[i]); 
    }

}


