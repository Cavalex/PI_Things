
#include <stdio.h>
#include <math.h>
#include <unistd.h>

uint64_t mymul32x32(uint32_t a, uint32_t b){
    uint16_t va_high = (a >> 16) & 0xFFFF;
    uint16_t va_low = a & 0xFFFF;

    uint16_t vb_high = (b >> 16) & 0xFFFF;
    uint16_t vb_low = b & 0xFFFF;

    uint64_t mul_high_high = (uint64_t)((uint32_t)(va_high * vb_high))<< 32;
    uint64_t mul_high_low = (uint64_t)((uint32_t)(va_high << 16)) * vb_low;
    uint64_t mul_low_high = (uint64_t)((uint32_t)(vb_high << 16)) * va_low;
    uint32_t mul_low_low = (uint32_t)(va_low * vb_low);

    uint64_t res = 0;

    res = mul_high_high;
    res += mul_high_low;
    res += mul_low_high;
    res += mul_low_low;

    return res;
}