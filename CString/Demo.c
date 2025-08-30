#include <stdio.h>
#include "CString/CString.h"

void print_string(str string) {
    printf("str(data = \"%s\", length = %lu)", string->data, string->length);
}

void FreeStringArray(str* arr) {
    for (str* p = arr; *p != NULL; p++) {
        DeleteString(*p);
    }
    free(arr);
}

int main(int argc, char const *argv[]) {
    str TestString1 = CreateStringWithData("Hello, World!");
    str TestString2 = CreateStringWithData("What About you!");
    str TestString3 = CreateStringWithData("       ");
    str TestString4 = CreateStringWithData("1234591");
    str TestString5 = CreateString();

    printf("TestString1 - ");
    print_string(TestString1);
    printf("\nTestString2 - ");
    print_string(TestString2);
    printf("\nTestString3 - ");
    print_string(TestString3);
    printf("\nTestString4 - ");
    print_string(TestString4);
    printf("\nTestString5 - ");
    print_string(TestString5);
    printf("\n");

    // Concatenate -- Adds a char* array to string object
    Concatenate(TestString1, TestString2->data);

    // CopyString -- Simply creates a copy of string object and returns it.
    str ConcatenatedString = CopyString(TestString1);
    print_string(ConcatenatedString);
    printf("\n");

    // IsWhiteSpace -- Checks if a string only contains White space character.
    printf("IsWhiteSpace( TestString3 ) - %d\n", IsWhiteSpace(TestString3));
    printf("IsWhiteSpace( TestString1 ) - %d\n", IsWhiteSpace(TestString1));

    // IsAlNum -- Checks if a string only contains Numbers.
    printf("IsAlNum( TestString4 ) - %d\n", IsAlNum(TestString4));
    printf("IsAlNum( TestString1 ) - %d\n", IsAlNum(TestString1));

    // IsNothing -- Checks if a string doesn't contain any data
    printf("IsNothing( TestString5 ) - %d\n", IsNothing(TestString5));
    printf("IsNothing( TestString1 ) - %d\n", IsNothing(TestString1));

    // Find -- Searches and returns the index of a char* inside a string object data if not present returns -1.
    printf("World inside TestString1 - %d\n", Find(TestString1, "World"));
    printf("Alakazam inside TestString1 - %d\n", Find(TestString1, "Alakazam"));

    // Contains -- Uses Find() to check if a string is present inside a string object data (returns a boolean).
    printf("World inside TestString1 - %d\n", Contains(TestString1, "World"));
    printf("Alakazam inside TestString1 - %d\n", Contains(TestString1, "Alakazam"));

    // GetSubString -- Get a string object from original string object which contains a section of data of it.
    str SubString = GetSubString(TestString1, 0, 13);
    print_string(SubString);
    printf("\n");

    // Split -- Splits a string object to an array of char* seperated by a seperator char*
    printf("\nUsage Of Split :\n");

    str* objects = Split(TestString1, " ");
    while (*objects != NULL) {
        print_string(*objects);
        printf("\n");
        objects++;
    }
    FreeStringArray(objects);

    DeleteString(TestString1);
    DeleteString(TestString2);
    DeleteString(TestString3);
    DeleteString(TestString4);
    DeleteString(TestString5);

    return 0;
}
