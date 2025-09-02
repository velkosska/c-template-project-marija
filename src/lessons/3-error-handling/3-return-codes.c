  #include <stdio.h>
  #include <stdlib.h>

  void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
      fprintf(stderr, "Error: Could not open file %s\n", filename);
      return;
    }
    // Do something with the file
    fclose(file);
  }

  int main() {
    process_file("non_existent_file.txt");
    return 0;
  }