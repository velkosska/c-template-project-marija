  #include <stdio.h>
  #include <stdlib.h>

  unsigned int operate(float x){
    return (unsigned int)(x * 2);
  }

  unsigned int safe_operate(float x){
    if (x < 0) {
      fprintf(stderr, "Error: x must be non-negative\n");
      exit(EXIT_FAILURE);
    }
    return operate(x);
  }

  void apply_and_print(float x, unsigned int (*func)(float)){
    int result = func(x);
    printf("Result: %d\n", result);
    fflush(stdout);
  }

  int main() {
    apply_and_print(-3.5, operate);
    apply_and_print(3.5, safe_operate);
    apply_and_print(-3.5, safe_operate); // This will terminate the program
    return 0;
  }