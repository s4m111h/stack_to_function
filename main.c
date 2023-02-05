#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

char code[] = {0x48, 0xc7, 0xc0, 0x01, 0x00, 0x00, 0x00,
               0xc2, 0x00, 0x00};

int main(int argc, char **argv)
{
    void *buf;
    buf = mmap(0, sizeof(code),
               PROT_READ | PROT_WRITE | PROT_EXEC,
               MAP_PRIVATE | MAP_ANON,
               -1, 0);
    memcpy(buf, code, sizeof(code));
    __builtin___clear_cache(buf, buf + sizeof(code) - 1);


    printf("%d\n", ((int (*)(void))buf)());

    return 0;
}
