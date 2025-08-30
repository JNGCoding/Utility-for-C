#include "CString.h"

// FUNCTIONS
char getSmallChar(char c) {
    return (c >= 65 && c <= 90) ? c + 32 : c;
}

char getBigChar(char c) {
    return (c >= 97 && c <= 122) ? c - 32 : c;
}

// TYPE
str CreateString() {
    str result = (str) calloc(1, sizeof(String));
    result->length = 0;
    result->data = (char*) calloc(1, sizeof(char));
    result->data[0] = '\0';

    if (!result || !result->data) {
        fprintf(stderr, "Error: Failed allocation of string.");
        DeleteString(result);
        return NULL;
    }

    return result;
}

str CreateStringWithData(char* _data) {
    str result = (str) calloc(1, sizeof(String));
    result->length = strlen(_data);
    result->data = strdup(_data);

    if (!result || !result->data) {
        fprintf(stderr, "Error: Failed allocation of string.");
        DeleteString(result);
        return NULL;
    }

    return result;
}

int32_t Find(str string, char* substr) {
    for (size_t i = 0; i < string->length; i++) {
        if (string->data[i] == substr[0]) {
            bool flag = true;
            for (size_t j = i; j - i < strlen(substr) && j < string->length; j++) {
                if (string->data[j] != substr[j - i]) {
                   flag = false;
                   break;
                }
            }
            if (flag) { return i; }
        }
    }

    return -1;
}

str GetSubString(str string, uint32_t start_index, uint32_t last_index) {
    str result = (str) calloc(1, sizeof(String));
    result->length = last_index - start_index + 1;
    result->data = (char*) calloc(result->length, sizeof(char));

    for (size_t i = start_index; i < last_index; i++) {
        result->data[i] = string->data[i];
    }
    result->data[last_index] = '\0';

    if (!result || !result->data) {
        fprintf(stderr, "Error: Failed allocation of string.");
        DeleteString(result);
        return NULL;
    }

    return result;
}

bool Contains(str string, char* substr) {
    return Find(string, substr) != -1;
}

bool IsWhiteSpace(str string) {
    for (size_t i = 0; i < string->length; i++) {
        if (string->data[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool IsAlNum(str string) {
    for (size_t i = 0; i < string->length; i++) {
        if (string->data[i] < '0' || string->data[i] > '9') {
            return false;
        }
    }
    return true;
}

bool IsAscii(str string) {
    for (size_t i = 0; i < string->length; i++) {
        if ((unsigned char)string->data[i] > 127) {
            return false;
        }
    }
    return true;
}

bool IsNothing(str string) {
    return string->length == 0;
}

void ConvertLowerCase(str string) {
    for (size_t i = 0; i < string->length; i++) { string->data[i] = getSmallChar(string->data[i]); }
}

void ConvertUpperCase(str string) {
    for (size_t i = 0; i < string->length; i++) { string->data[i] = getBigChar(string->data[i]); }
}

str* Split(str string, char* substr) {
    if (!string || !substr || strlen(substr) == 0) return NULL;

    size_t substr_len = strlen(substr);
    size_t count = 0;
    size_t last_index = 0;

    for (size_t i = 0; i <= string->length - substr_len; ) {
        if (strncmp(&string->data[i], substr, substr_len) == 0) {
            count++;
            i += substr_len;
        } else {
            i++;
        }
    }

    str* result = (str*)calloc(count + 2, sizeof(str));
    if (!result) {
        fprintf(stderr, "Error: Failed to allocate memory.");
        return NULL;
    }

    size_t res_idx = 0;
    for (size_t i = 0; i <= string->length; ) {
        if (i <= string->length - substr_len && strncmp(&string->data[i], substr, substr_len) == 0) {
            size_t seg_len = i - last_index;
            str seg = (str)calloc(1, sizeof(String));
            seg->length = seg_len;
            seg->data = (char*)calloc(seg_len + 1, sizeof(char));
            strncpy(seg->data, &string->data[last_index], seg_len);
            seg->data[seg_len] = '\0';
            result[res_idx++] = seg;
            i += substr_len;
            last_index = i;
        } else {
            i++;
        }
    }

    if (last_index <= string->length) {
        size_t seg_len = string->length - last_index;
        str seg = (str)calloc(1, sizeof(String));
        seg->length = seg_len;
        seg->data = (char*)calloc(seg_len + 1, sizeof(char));
        strncpy(seg->data, &string->data[last_index], seg_len);
        seg->data[seg_len] = '\0';
        result[res_idx++] = seg;
    }
    result[res_idx] = NULL; // Terminating the str* with a NULL.

    return result;
}

void Concatenate(str string, char* adder) {
    size_t adder_len = strlen(adder);
    string->data = (char*) realloc(string->data, sizeof(char) * (string->length + adder_len + 1));

    if (!string->data) {
        fprintf(stderr, "Error: Failed re-allocation of resultant string data.");
        return;
    }

    string->length += adder_len;
    strcat(string->data, adder);
}

void ConcatenateChar(str string, char adder) {
    char temp[2] = {adder, '\0'};
    Concatenate(string, temp);
}

str CopyString(str string) {
    str result = (str) calloc(1, sizeof(String));
    result->data = strdup(string->data);
    result->length = string->length;

    if (!result || !result->data) {
        fprintf(stderr, "Error: Failed Allocation of resultant string or resultant string data.");
        DeleteString(result);
        return NULL;
    }

    return result;
}

void DeleteString(str string) {
    free(string->data);
    free(string);
}
