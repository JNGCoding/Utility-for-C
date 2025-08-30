#include "Logger.h"

enum Level __PRINT_LEVEL__ = DEBUG;
bool __CREATE_FILE__ = false;
bool __PRINT_TIME__ = false;
char* __LOGFILE_PATH__ = "Log.txt";

void getFormattedTime(char *buffer, size_t bufferSize) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, bufferSize,"%H:%M:%S|", timeinfo);
}

void Debug(char* string) {
    if (__PRINT_LEVEL__ <= DEBUG) {
        char text[MAX_MESSAGE];
        char time[15] = {'\0'};
        if (__PRINT_TIME__) { getFormattedTime(time, 15); }

        sprintf(text, "%sDEBUG: %s\n", time, string);
        printf("%s%s%s", BLUE, text, RESET);

        if (__CREATE_FILE__) {
            FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
            if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
            fprintf(ptr, text);
            fclose(ptr);
        }
    }
}  // BLUE

void Message(char* string) {
    if (__PRINT_LEVEL__ <= MESSAGE) {
        char text[MAX_MESSAGE];
        char time[15] = {'\0'};
        if (__PRINT_TIME__) { getFormattedTime(time, 15); }

        sprintf(text, "%sMESSAGE: %s\n", time, string);
        printf("%s%s%s", ORANGE, text, RESET);

        if (__CREATE_FILE__) {
            FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
            if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
            fprintf(ptr, text);
            fclose(ptr);
        }
    }
}  // ORANGE

void Warning(char* string) {
    if (__PRINT_LEVEL__ <= WARNING) {
        char text[MAX_MESSAGE];
        char time[15] = {'\0'};
        if (__PRINT_TIME__) { getFormattedTime(time, 15); }

        sprintf(text, "%sWARNING: %s\n", time, string);
        printf("%s%s%s", YELLOW, text, RESET);

        if (__CREATE_FILE__) {
            FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
            if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
            fprintf(ptr, text);
            fclose(ptr);
        }
    }
}  // YELLOW

void Error(char* string) {
    if (__PRINT_LEVEL__ <= ERROR) {
        char text[MAX_MESSAGE];
        char time[15] = {'\0'};
        if (__PRINT_TIME__) { getFormattedTime(time, 15); }

        sprintf(text, "%sERROR: %s\n", time, string);
        printf("%s%s%s", RED, text, RESET);

        if (__CREATE_FILE__) {
            FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
            if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
            fprintf(ptr, text);
            fclose(ptr);
        }
    }
}  // RED

void Pass(char* string) {
    if (__PRINT_LEVEL__ <= PASS) {
        char text[MAX_MESSAGE];
        char time[15] = {'\0'};
        if (__PRINT_TIME__) { getFormattedTime(time, 15); }

        sprintf(text, "%sPASS: %s\n", time, string);
        printf("%s%s%s", GREEN, text, RESET);

        if (__CREATE_FILE__) {
            FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
            if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
            fprintf(ptr, text);
            fclose(ptr);
        }
    }
}  // GREEN

void Log(char* COLOR, char* string) {
    char text[MAX_MESSAGE];
    char time[15] = {'\0'};
    if (__PRINT_TIME__) { getFormattedTime(time, 15); }

    sprintf(text, "%sLOG: %s\n", time, string);
    printf("%s%s%s", COLOR, text, RESET);

    if (__CREATE_FILE__) {
        FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
        if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
        fprintf(ptr, text);
        fclose(ptr);
    }
}  // This will reset the color

void ULog(char* COLOR, char* string) {
    char text[MAX_MESSAGE];
    char time[15] = {'\0'};
    if (__PRINT_TIME__) { getFormattedTime(time, 15); }

    sprintf(text, "%sULOG: %s\n", time, string);
    printf("%s%s%s", COLOR, text);

    if (__CREATE_FILE__) {
        FILE* ptr = fopen(__LOGFILE_PATH__, "a+");
        if (!ptr) { fprintf(stderr, "Error: Log File failed to open."); return; }
        fprintf(ptr, text);
        fclose(ptr);
    }
} // This will not reset the color

void SetPrintLevel(enum Level level) {
    __PRINT_LEVEL__ = level;
}

void SetCreateFile(bool createFile) {
    __CREATE_FILE__ = createFile;
}

void SetPrintTime(bool printTime) {
    __PRINT_TIME__ = printTime;
}

void SetLogfilePath(const char* logfilePath) {
    __LOGFILE_PATH__ = (char*) logfilePath;
}