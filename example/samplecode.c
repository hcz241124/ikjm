#include <stdio.h>
#include <stdlib.h> // for EXIT_SUCCESS

#include "life/hcz/ikjm4c/ris/version.h"
#include "life/hcz/ikjm4c/types.h"

int main(int argc, char* argv[])
{
    printf("%s\n", ris_version());
    printf("life.hcz.ikjm4c.ris SemVer%s\n", ris_sem_ver());

    int64_t hexversion = ris_hexversion();
    printf("life.hcz.ikjm4c.ris hexversion=%08llx\n", hexversion);
    
    hcz_version_t version_info;
    ris_version_info(&version_info);
    printf("life.hcz.ikjm4c.ris version .major=%d\n", version_info.major);
    return EXIT_SUCCESS;
}
