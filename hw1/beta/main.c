#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) {  /* power of two? */
        // return MMMM;       
        return (sz + mask) & ~mask;
    }
    return (((sz + mask) / alignment) * alignment);
}


int main() {
    static int align = 4;
    int i;
    for (i = 120; i<130; i++) {
        printf("align_up(%d, %d) = %d\n", i, align, align_up(i, align));
    }

    return 0;
}