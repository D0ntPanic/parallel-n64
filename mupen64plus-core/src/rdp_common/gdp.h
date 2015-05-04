#ifndef _RDP_COMMON_GDP_H
#define _RDP_COMMON_GDP_H

#include <stdint.h>

/* Useful macros for decoding GBI command's parameters */

#ifndef _SHIFTL
#define _SHIFTL( v, s, w )  (((uint32_t)v & ((0x01 << w) - 1)) << s)
#endif

#ifndef _SHIFTR
#define _SHIFTR( v, s, w )  (((uint32_t)v >> s) & ((0x01 << w) - 1))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   uint32_t total;
   int32_t r, g, b, a, l;
} gdp_color;

struct gdp_global
{
   int32_t primitive_lod_frac;
   gdp_color prim_color;
   gdp_color env_color;
};

void gdp_set_prim_color(uint32_t w0, uint32_t w1);

extern struct gdp_global g_gdp;

#ifdef __cplusplus
}
#endif

#endif
