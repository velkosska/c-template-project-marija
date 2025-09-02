  #include <stdio.h>
  #include <stdlib.h>

  int factorial(int n) {
      if (n < 0) {
          fprintf(stderr, "Error: n must be non-negative\n");
          return -1; // Error
      }
      if (n == 0) return 1;
      return n * factorial(n - 1);
  }

  int main() {
      int n = 5;
      int result = factorial(n);
      printf("factorial(%d) = %d\n", n, result);
      return EXIT_SUCCESS;
  }