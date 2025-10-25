#ifndef ADVANCED_LOGGER_H
#define ADVANCED_LOGGER_H

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef void (*Logger)(const char *, LogLevel);

void coloredTimestampedConsoleLogger(const char *message, LogLevel level);
void performTask(Logger logger);

#endif
