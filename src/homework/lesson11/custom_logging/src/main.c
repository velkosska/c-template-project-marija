#include "logger.h"

int main() {
    performTask(consoleLogger);
    performTask(fileLogger);
    return 0;
}
