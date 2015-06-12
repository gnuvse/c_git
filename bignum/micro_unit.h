/*
 *  MICRO_UNIT is a little test framework for embedded systems, based on C preprocessor
 *  directives. It is designed to be used as a first step to test-driven development.
 *  Framework allows few settings to maintain target platform.
 *  Author: Yunkin Ilya.
 *  License: You can use this code with preserving original content.
 *  Date: December 10th 2013.
 */

#ifndef MICRO_UNIT_H
#define MICRO_UNIT_H

/*
 *  Definition of the way to print C- string.
 *  You can define other function before including this file,
 *  puts, for example.
 */
#ifndef TEST_PRINT_STRING
#define TEST_PRINT_STRING     MICRO_UNIT_TEST_PRINT_STRING
#endif

/*
 *  Definition of the way to print one byte ASCII symbol.
 *  You can define other function before including this file
 *  if you did not redefine TEST_PRINT_STRING macro.
 *  It can be something like putCharToUart.
 */
#ifndef TEST_PRINT_CHAR
#include <stdio.h>
#define TEST_PRINT_CHAR     putchar
#endif

/*
 *  Definition of the way to print digit value.
 *  You can define other function before including this file.
 *  It can be something like putCharToUart.
 */
#ifndef TEST_PRINT_UNSIGNED_DIGIT
#define TEST_PRINT_UNSIGNED_DIGIT     MICRO_UNIT_TEST_PRINT_UNSIGNED
#endif

/*
 *  Definition of data type for failed tests counter.
 *  You can redefine it for maintain number of tests
 *  more than UINT_MAX.
 */
#ifndef TEST_ERROR_COUNT_TYPE
#define TEST_ERROR_COUNT_TYPE   unsigned
#endif

/*
 *  Definition of data type for counter, which will be used to count
 *  array of string length.
 *  You can redefine it if you have any reason to not use <stddef.h>
 *  or if you sure that you don't need so wide range.
 */
#ifndef TEST_COUNT_TYPE
#include <stddef.h>
#define TEST_COUNT_TYPE   size_t
#endif

/*
 *  Definition of architecture dependence  char type size.
 *  You can redefine it, for example to 2 for TMS320F2808,
 *  or to 4 for TMS320C30.
 */
#ifndef SIZE_OF_CHAR_IN_BYTES
#define SIZE_OF_CHAR_IN_BYTES 1
#endif

/*
 *  Default macro for string printing
 */
#define MICRO_UNIT_TEST_PRINT_STRING(string)    \
    do{                                         \
    TEST_COUNT_TYPE i = 0;                      \
    while(string[i])                            \
    {                                           \
    TEST_PRINT_CHAR(string[i]);                 \
    i++;                                        \
    }                                           \
    }while(0)                                   \

/*
 *  Default macro for unsigned digital printing.
 *  It can be used in different platforms for
 *  different unsigned types such as
 *  unsigned long, unsigned char, unsigned short.
 */
#define MICRO_UNIT_TEST_PRINT_UNSIGNED(digit)       \
    do{                                             \
    unsigned i;                                     \
    unsigned nibbleCount = sizeof(digit) * 2 * SIZE_OF_CHAR_IN_BYTES; \
    TEST_PRINT_STRING("0x");                        \
    for(i = 0; i < nibbleCount; i++)                \
    {                                               \
    unsigned shift = (nibbleCount - i - 1) * 4;     \
    TEST_PRINT_CHAR(((digit >> shift) & 0xf) + '0');\
    }                                               \
    }while(0)

#define TEST_SEPARATOR "\r\n------------------------------"

/*
 *  Macro for test initialize.
 *  User should place it in the beginning of test function.
 */
#define INIT_TEST(testTitle) {TEST_ERROR_COUNT_TYPE testsErrorCount = 0; \
    do{                                             \
    TEST_PRINT_STRING(TEST_SEPARATOR);              \
    TEST_PRINT_STRING("\r\n" testTitle);            \
    TEST_PRINT_STRING(TEST_SEPARATOR);              \
    }while(0)                                       \

/*
 *  Macro for test case running.
 *  User should call it with name of test case as argument.
 */
#define RUN_TEST(name)                      \
    do{                                     \
    TEST_PRINT_STRING("\r\n" #name " ");    \
    if (name())                             \
    {                                       \
    TEST_PRINT_STRING("FAIL\r\n");          \
    testsErrorCount++;                      \
    }                                       \
    else                                    \
    TEST_PRINT_STRING("OK \r\n");           \
    }while(0)

/*
 *  Macro for using in return statement in test case routine.
 *  It helps to form correct test case output.
 */
#define MUST_BE_TRUE(condition) (! (condition))


/*
 *  Macro for using in return statement in test case routine.
 *  It helps to form correct test case output.
 */
#define MUST_BE_FALSE(condition) (condition)

/*
 *  Definition of test case return values.
 */
#define TEST_OK         0
#define TEST_FAILED     1

/*
 *  Macro for using INSTEAD of return statement in test case routine.
 *  It helps to form correct test case output if you have a reason
 *  to not using of <string.h>
 */
#define ARRAYS_MUST_BE_EQUAL(array1, array2, size)      \
    do{                                                 \
    TEST_COUNT_TYPE i;                                  \
    for(i = 0; i < size; i++)                           \
    {                                                   \
    if(array1[i] != array2[i])                          \
        return TEST_FAILED;                             \
    }                                                   \
    return TEST_OK;                                     \
    }while(0)

/*
 *  Macro for using INSTEAD of return statement in test case routine.
 *  It helps to form correct test case output if you have a reason
 *  to not using of <string.h>
 */
#define STRINGS_MUST_BE_EQUAL(string1, string2)         \
    do{                                                 \
    TEST_COUNT_TYPE i;                                  \
    for(i = 0;;i++)                                     \
    {                                                   \
    if(string1[i] != string2[i])                        \
        return TEST_FAILED;                             \
    else if (string1[i] == 0)                           \
        return TEST_OK;                                 \
    }                                                   \
    }while(0)

/*
 *  Macro for test procedure finishing.
 *  It outputs the results.
 */
#define FINISH_TEST()                               \
    do{                                             \
    TEST_PRINT_STRING(TEST_SEPARATOR);              \
    if (testsErrorCount == 0)                       \
    {TEST_PRINT_STRING("\r\nTEST OK\r\n");          \
    }else                                           \
    {TEST_PRINT_STRING("\r\nTEST FAILED\r\n");      \
    TEST_PRINT_STRING("\r\nERROR_COUNT:\t");        \
    TEST_PRINT_UNSIGNED_DIGIT(testsErrorCount);     \
    }                                               \
    }while(0);                                      \
    return MUST_BE_TRUE(testsErrorCount == 0);}

#endif /* MICRO_UNIT_H */

