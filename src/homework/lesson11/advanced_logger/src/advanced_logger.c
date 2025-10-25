#include <stdio.h>
#include <time.h>
#include "advanced_logger.h"

static const char *levelToColor(LogLevel level) {
    switch (level) {
        case DEBUG: return "\033[36m";
        case INFO: return "\033[32m";
        case WARNING: return "\033[33m";
        case ERROR: return "\033[31m";
        default: return "\033[0m";
    }
}

static const char *levelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void coloredTimestampedConsoleLogger(const char *message, LogLevel level) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char buffer[20];
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("%s[%s] [%s] %s\033[0m\n", levelToColor(level), buffer, levelToString(level), message);
}

void performTask(Logger logger) {
    logger("Task started", INFO);
    logger("Processing data", DEBUG);
    logger("Minor issue encountered", WARNING);
    logger("Task completed", INFO);
}
