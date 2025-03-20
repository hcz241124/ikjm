#ifndef LIFE_HCZ_IKJM4C_VERSION_H_
#define LIFE_HCZ_IKJM4C_VERSION_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hcz_version_s {
    uint16_t major;
    uint16_t minor;
    uint16_t patch;
    char release_version;
    uint8_t build;
} hcz_version_t, HVersion, *PHVersion;

typedef int32_t hcz_hexversion_t;

#ifdef __cplusplus
}
#endif

#endif // LIFE_HCZ_IKJM4C_VERSION_H_