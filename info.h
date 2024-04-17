#ifndef INFO_H_
#define INFO_H_
#endif
#include <stdint.h>
typedef void (*FuncPtr)(unsigned char**, uint32_t, uint32_t);
FuncPtr PrintAndSelectOperations();
FuncPtr SelectOperations(uint8_t);
FuncPtr PrintFilters();
FuncPtr Filters(uint8_t);