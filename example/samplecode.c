#include <stdio.h>
#include <stdlib.h> // for EXIT_SUCCESS

#include "hcz/ikjm/capi/version.h"

int main(int argc, char* argv[])
{
    printf("hcz.life.ikjm4c version: %s\n", ikjm4c_version());

    int64_t hexversion = ikjm4c_hexversion();
    printf("hcz.life.ikjm4c hexversion=%08llx\n", hexversion);
    
    ikjm_version_t version_info;
    ikjm4c_version_info(&version_info);
    printf("libikjm4c version .major=%d\n", version_info.major);
    return EXIT_SUCCESS;
}
