#include "life/hcz/ikjm4c/ris/version.h"

#include <stdio.h>
#include <string.h>

#ifndef MAX_PATH
#define MAX_PATH 0xFF
#endif // MAX_PATH

ris_version_t s_ris_version = {
    .major = 0, .minor = 1, .patch = 0, .release_version = 0xA, .build = 1};

IKJM4C_INNER const char *_ikjm4c_get_build_time() {
  return __DATE__ " " __TIME__;
}

IKJM4C_INNER const char *
_ris_get_release_version(char release_version) {
  if (release_version == 0xA) {
    return "Alpha";
  } else if (release_version == 0xB) {
    return "Beta";
  } else if (release_version == 0xF) {
    return "Release";
  } else {
    return "Unknown";
  }
}

hcz_hexversion_t ris_hexversion() {
  hcz_hexversion_t hexversion = (hcz_hexversion_t)(s_ris_version.major) << 24;
  hexversion += (s_ris_version.minor << 16);
  hexversion += (s_ris_version.patch << 8);
  hexversion += (s_ris_version.release_version << 4);
  hexversion += s_ris_version.build;
  return hexversion;
}

const char *ris_version() {
  static char s_version[MAX_PATH] = "\0";
  if (s_version[0] == '\0') {
    memset(s_version, '\0', MAX_PATH);
    sprintf(s_version,
            "libikjm4c(%d.%d.%d-%x%d) build %s .major=%d .minor=%d .patch=%d "
            ".release=%s .build=%d",
            s_ris_version.major, s_ris_version.minor,
            s_ris_version.patch, s_ris_version.release_version,
            s_ris_version.build, _ikjm4c_get_build_time(),
            s_ris_version.major, s_ris_version.minor,
            s_ris_version.patch,
            _ris_get_release_version(s_ris_version.release_version),
            s_ris_version.build);
  }
  return s_version;
}

void ris_version_info(ris_version_t *version_info) {
  *version_info = s_ris_version;
}

const char* ris_sem_ver() {
  static char s_version[MAX_PATH] = "\0";
  if (s_version[0] == '\0') {
    memset(s_version, '\0', MAX_PATH);
    sprintf(s_version,
            "%d.%d.%d-%s+%d",
            s_ris_version.major, s_ris_version.minor,
            s_ris_version.patch, 
            _ris_get_release_version(s_ris_version.release_version),
            s_ris_version.build);
  }
  return s_version;
}
