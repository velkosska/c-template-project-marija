#include <stdlib.h>

int main() {
  char const *const path_name [[deprecated]] = "some/path/to/file";
  // path_name = "some_string";
  // path_name[0] = 's';
  return EXIT_SUCCESS;
}
