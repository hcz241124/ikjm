#ifndef LIFE_HCZ_IKJM4C_RIS_VERSION_H_
#define LIFE_HCZ_IKJM4C_RIS_VERSION_H_

#include "life/hcz/ikjm4c/types.h"
#include "life/hcz/ikjm4c/api.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef hcz_version_t ris_version_t;

IKJM4C_API hcz_hexversion_t ris_hexversion();

IKJM4C_API const char* ris_version();

IKJM4C_API void ris_version_info(hcz_version_t* version_info);

IKJM4C_API const char* ris_sem_ver();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIFE_HCZ_IKJM4C_RIS_VERSION_H_