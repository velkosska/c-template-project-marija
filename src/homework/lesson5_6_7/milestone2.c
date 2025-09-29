#include <stdio.h>
int main(){
int a = 1;
int b = 2;
printf("Address of a: %p\n", (void*)&a);
printf("Address of b: %p\n", (void*)&b);
printf("Distance between a and b: %ld bytes\n", (char*)&b - (char*)&a);
return 0;
}

/** 1. An int is 4 bytes. Two ints will be placed next to each other in memory so the distance 
 * will be 4 bytes.
 * 2. A double is 8 bytes. Two doubles will be placed next to each other in memory so the distance
 * will be 8 bytes.
 * 3. A char is 1 byte. Two chars will be placed next to each other in memory so the distance
 * will be 1 byte.
 * Int then a double will have a distance of 8 bytes because of padding added to align the double.
 * Double then an int will have a distance of 4 bytes because the int can fit in the padding after the double.
 */