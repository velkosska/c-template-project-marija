#include <assert.h>
#include <stddef.h>

#define Type double
int main(void){
    Type a;
    size_t addr = (size_t)&a;
    assert(addr % sizeof(Type) == 0);
}

/*C compilers must place objects at addresses meeting that type’s alignment,
 which is at least their size.
 Thus &a is guaranteed to be suitably aligned; the modulo test on sizeof(Type) succeeds.*/