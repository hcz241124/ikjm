#include "hcz/ikjm/capi/version.h"

#include <stdio.h>

#ifndef MAX_PATH
#define MAX_PATH 0xFF
#endif // MAX_PATH

ikjm_version_t s_ikjm4c_version = {
    .major = 0, .minor = 1, .patch = 0, .release_version = 0xA, .build = 1};

__attribute__((visibility("hidden"))) const char *_ikjm4c_get_build_time() {
  return __DATE__ " " __TIME__;
}

__attribute__((visibility("hidden"))) const char *
_ikjm4c_get_release_version(char release_version) {
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

int64_t ikjm4c_hexversion() {
  int64_t hexversion = s_ikjm4c_version.major << 24;
  hexversion += (s_ikjm4c_version.minor << 16);
  hexversion += (s_ikjm4c_version.patch << 8);
  hexversion += s_ikjm4c_version.build;
  return hexversion;
}

const char *ikjm4c_version() {
  static char s_version[MAX_PATH] = "\0";
  if (s_version[0] == '\0') {
    sprintf(s_version,
            "libikjm4c(%d.%d.%d-%x%d) build %s .major=%d .minor=%d .patch=%d "
            ".release=%s .build=%d",
            s_ikjm4c_version.major, s_ikjm4c_version.minor,
            s_ikjm4c_version.patch, s_ikjm4c_version.release_version,
            s_ikjm4c_version.build, _ikjm4c_get_build_time(),
            s_ikjm4c_version.major, s_ikjm4c_version.minor,
            s_ikjm4c_version.patch,
            _ikjm4c_get_release_version(s_ikjm4c_version.release_version),
            s_ikjm4c_version.build);
  }
  return s_version;
}

void ikjm4c_version_info(ikjm_version_t *version_info) {
  *version_info = s_ikjm4c_version;
}
