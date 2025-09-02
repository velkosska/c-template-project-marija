// Inspect this code. Will it print "1 and 1", or "1 and 0"?
#include<stdio.h>
#include<stdlib.h>
int f(int* value){
   *value = 1;
   return *value;
}

int g(int* value){
   return *value;
}

int main(){
    int value = 0;
    printf("%d and %d\n", f(&value), g(&value));
    return EXIT_SUCCESS;
}



















// Answer: Never rely on the order of evaluation of function arguments in C, as it is unspecified.
//  The compiler will choose one arbitrarily depending on the context.
// In order to avoid this undefined behavior, we must write functions that do not have side effects.