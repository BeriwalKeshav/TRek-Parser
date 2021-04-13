/*
Compilers Assignment Phase 2
LANGUAGE NAME: TReK
Group No. 10 (G10)

Members:
1. Kshitij Verma		2017B1A71145H
2. Keshav Beriwal		2017B4A71301H
3. Thejas Sasikumar		2017B4A70614H
4. Rohan Maheshwari		2017B4A70965H

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<ctype.h>
using namespace std;
bool isAlphabet(char c);
bool isNum(char c);
bool isDelimiter(char c);
bool printDelimiter(char c) ;
bool isCmpOperator(char first, char c);
bool isKeyword(char* str);
bool isInteger(char *str);
bool isFloat(char *str);
bool isIdentifier(char *str);
bool isStringLiteral(char *str) ;
bool isComment(char *str);
char* subString(char* str, int left, int right);
void parse(char *str, int line);
void lexer();