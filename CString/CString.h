#ifndef STRINGS_H_
#define STRINGS_H_

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct String_type {
    char* data;
    uint32_t length;
} String;

typedef String* str;

str CreateString();
str CreateStringWithData(char* data);
int32_t Find(str string, char* substr);
str GetSubString(str string, uint32_t start_index, uint32_t last_index);
bool Contains(str string, char* substr);
bool IsWhiteSpace(str string);
bool IsAlNum(str string);
bool IsAscii(str string);
bool IsNothing(str string);
void ConvertLowerCase(str string);
void ConvertUpperCase(str string);
str* Split(str string, char* substr);
void Concatenate(str string, char* adder);
void ConcatenateChar(str string, char adder);
str CopyString(str string);
void DeleteString(str string);

// MORE FUNCTIONS
bool Equals(str string, char* equSTR);  // INCOMPLETE

// CONVERSION FUNCTIONS (CURRENTLY INCOMPLETE)
char* DTS();  // Double to String
char* ITS();  // Integer to String
char* FTS();  // Float to String

#endif