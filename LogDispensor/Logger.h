#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX_MESSAGE 1024

enum Level{ DEBUG, MESSAGE, WARNING, ERROR, PASS };

extern enum Level __PRINT_LEVEL__;
extern bool __CREATE_FILE__;
extern bool __PRINT_TIME__;
extern char* __LOGFILE_PATH__;

static const char* RED    = "\x1B[31m";
static const char* BLUE   = "\x1B[34m";
static const char* GREEN  = "\x1B[32m";
static const char* ORANGE = "\x1B[38;5;214m";
static const char* YELLOW = "\x1B[33m";
static const char* RESET  = "\x1B[0m";

void Debug(char* string);  // BLUE
void Message(char* string);  // ORANGE
void Warning(char* string);  // YELLOW
void Error(char* string);  // RED
void Pass(char* string);  // GREEN
void Log(char* COLOR, char* string);  // This will reset the color
void ULog(char* COLOR, char* string); // This will not reset the color

void SetPrintLevel(enum Level level);
void SetCreateFile(bool createFile);
void SetPrintTime(bool printTime);
void SetLogfilePath(const char* logfilePath);

#endif