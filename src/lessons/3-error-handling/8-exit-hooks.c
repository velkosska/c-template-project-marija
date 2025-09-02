  #include <stdio.h>
  #include <stdlib.h>

  void goodbye_message() {
    printf("------- Thanks for using this program -------\n");
  }

  void cleanup2() {
    printf("Cleanup 2\n");
  }

  int main() {
    atexit(goodbye_message);
    atexit(cleanup2);
    // Do something
    printf("Exiting program\n");
    return EXIT_SUCCESS;
  }