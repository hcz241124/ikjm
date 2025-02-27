#ifndef HCZ_IKJM_CAPI_VERSION_H
#define HCZ_IKJM_CAPI_VERSION_H

#include <stdint.h>

#include "hcz/ikjm/capi/api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ikjm_version_s {
    int8_t major;
    int8_t minor;
    int8_t patch;
    char release_version;
    int8_t build;
} ikjm_version_t;

/**
 * @brief Return library version info
 * 
 * @return int64_t hexversion
 */
IKJM4C_API int64_t ikjm4c_hexversion();

/**
 * @brief Get version description
 * 
 * @return const char* version description
 */
 IKJM4C_API const char* ikjm4c_version();

/**
 * @brief Get version data
 * 
 * @param version_info [OUT]
 * 
 * @code {.c}
 * ikjm_version_t version_info;
 * ikjm4c_version_info(&version_info);
 * printf("libikjm4c version .major=%d", version_info.major);
 * @endcode
 * 
 */
IKJM4C_API void ikjm4c_version_info(ikjm_version_t* version_info);

#ifdef __cplusplus
}
#endif

#endif // HCZ_IKJM_CAPI_VERSION_H