#include <stdio.h>
#include "logger.h"

static const char *levelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void consoleLogger(const char *message, LogLevel level) {
    printf("[%s] %s\n", levelToString(level), message);
}

void fileLogger(const char *message, LogLevel level) {
    FILE *f = fopen("log.txt", "a");
    if (!f) return;
    fprintf(f, "[%s] %s\n", levelToString(level), message);
    fclose(f);
}

void performTask(Logger logger) {
    logger("Task started", INFO);
    logger("Task completed", INFO);
}
