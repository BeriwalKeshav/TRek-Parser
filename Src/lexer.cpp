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
#include "lexer.hpp"
FILE *fp2;

bool isAlphabet(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

bool isNum(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

/*
isDelimiter(): Checks whether the passed character is a delimiter or not
Parameters:	character c
Returns:	if c is a delimiter true; otherwise false
*/
bool isDelimiter(char c) {
	if (c == ' ' || c == '\n' || c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '>' || c == '<' || c == '\t')
		return true;
	else if (c == ',' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
		return true;
	return false;
}
/*
printDelimiter(): Prints the passed delimiter in proper format
Parameters:	character c
Returns:	if c is a delimiter true; otherwise false
*/
bool printDelimiter(char c) {
	if (c == '+') {
		printf("%-50s", "tk_plus_operator");
		fputs("tk_plus_operator + ", fp2);
	}
	else if (c == '-') {
		printf("%-50s", "tk_minus_operator");
		fputs("tk_minus_operator - ", fp2);

	}
	else if (c == '*') {
		printf("%-50s", "tk_mul_operator");
		fputs("tk_mul_operator * ", fp2);
	}
	else if (c == '/') {
		printf("%-50s", "tk_div_operator");
		fputs("tk_div_operator / ", fp2);
	}
	else if (c == '=') {
		printf("%-50s", "tk_assignment_operator");
		fputs("tk_assignment_operator = ", fp2);
	}
	else if (c == '>') {
		printf("%-50s", "tk_gt_operator");
		fputs("tk_gt_operator > ", fp2);
	}
	else if (c == '<') {
		printf("%-50s", "tk_lt_operator");
		fputs("tk_lt_operator < ", fp2);
	}
	else if (c == ',') {
		printf("%-50s", "tk_comma_operator");
		fputs("tk_comma_operator , ", fp2);
	}
	else if (c == ';') {
		printf("%-50s", "tk_semicol_operator");
		fputs("tk_semicol_operator ; ", fp2);
	}
	else if (c == '(') {
		printf("%-50s", "tk_lparen_operator");
		fputs("tk_lparen_operator ( ", fp2);
	}
	else if (c == ')') {
		printf("%-50s", "tk_rparen_operator");
		fputs("tk_rparen_operator ) ", fp2);
	}
	else if (c == '[') {
		printf("%-50s", "tk_lsquarebracket_operator");
		fputs("tk_lsquarebracket_operator [ ", fp2);
	}
	else if (c == ']') {
		printf("%-50s", "tk_rsquarebracket_operator");
		fputs("tk_rsquarebracket_operator ] ", fp2);
	}
	else if (c == '{') {
		printf("%-50s", "tk_lcurlybracket_operator");
		fputs("tk_lcurlybracket_operator { ", fp2);
	}
	else if (c == '}') {
		printf("%-50s", "tk_rcurlybracket_operator");
		fputs("tk_rcurlybracket_operator } ", fp2);
	}
	else
		return false;
	printf(", string %-40c", c);
	return true;

}

/*
isCmpOperator(): Checks whether the 2 passed character constitute a comparison operator or not
Parameters:	character first, character c
Returns:	if c+first is either of {==,<=,>=} true; otherwise false
*/
bool isCmpOperator(char first, char c) {
	if (c == '=') {
		if (first == '<') {
			printf("%-50s", "tk_lteq_operator");
			fputs("tk_lteq_operator <= ", fp2);
		}
		else if (first == '>') {
			printf("%-50s", "tk_gteq_operator");
			fputs("tk_gteq_operator >= ", fp2);
		}
		else if (first == '=') {
			printf("%-50s", "tk_equal_operator");
			fputs("tk_equal_operator == ", fp2);
		}
	}
	else
		return false;
	printf(", string %c%-39c", first, c);
	return true;
}

/*
isKeyword(): checks whether the passed string is a keyword(prespecified) or not
Parameters:	character pointer str
Returns:	if str is a keyword true; otherwise false
*/
bool isKeyword(char* str) {
	if (!strcmp(str, "main")) {
		printf("%-50s", "tk_main");
		fputs("tk_main main ", fp2);
	}
	else if (!strcmp(str, "void")) {
		printf("%-50s", "tk_void_keyword");
		fputs("tk_void_keyword void ", fp2);
	}
	else if (!strcmp(str, "int")) {
		printf("%-50s", "tk_int_keyword");
		fputs("tk_int_keyword int ", fp2);
	}
	else if (!strcmp(str, "float")) {
		printf("%-50s", "tk_float_keyword");
		fputs("tk_float_keyword float ", fp2);
	}
	else if (!strcmp(str, "string")) {
		printf("%-50s", "tk_string_keyword");
		fputs("tk_string_keyword string ", fp2);
	}
	else if (!strcmp(str, "input")) {
		printf("%-50s", "tk_input_keyword");
		fputs("tk_input_keyword input ", fp2);
	}
	else if (!strcmp(str, "output")) {
		printf("%-50s", "tk_output_keyword");
		fputs("tk_output_keyword output ", fp2);
	}
	else if (!strcmp(str, "read")) {
		printf("%-50s", "tk_read_keyword");
		fputs("tk_read_keyword read ", fp2);
	}
	else if (!strcmp(str, "write")) {
		printf("%-50s", "tk_write");
		fputs("tk_write write ", fp2);
	}
	else if (!strcmp(str, "for")) {
		printf("%-50s", "tk_for_keyword");
		fputs("tk_for_keyword for ", fp2);
	}
	else if (!strcmp(str, "if")) {
		printf("%-50s", "tk_if_keyword");
		fputs("tk_if_keyword if ", fp2);
	}
	else if (!strcmp(str, "else")) {
		printf("%-50s", "tk_else_keyword");
		fputs("tk_else_keyword else ", fp2);
	}
	else if (!strcmp(str, "return")) {
		printf("%-50s", "tk_return_keyword");
		fputs("tk_return_keyword return ", fp2);
	}
	else if (!strcmp(str, "parameter")) {
		printf("%-50s", "tk_parameter");
		fputs("tk_parameter parameter ", fp2);
	}
	else if (!strcmp(str, "and")) {
		printf("%-50s", "tk_and");
		fputs("tk_and and ", fp2);
	}
	else if (!strcmp(str, "or")) {
		printf("%-50s", "tk_or");
		fputs("tk_or or ", fp2);
	}
	else
		return false;
	printf(", string %-40s", str);
	return true;
}

/*
isInteger(): checks whether the passed string is an integer literal or not
Parameters:	character pointer str
Returns:	if str is a integer literal true; otherwise false
*/
bool isInteger(char *str) {
	int i, len = strlen(str);

	if (len == 0)
		return false;
	for (i = 0; i < len; ++i) {
		int val = str[i]; //ASCII 0-9 is 48-57
		if (val < 48 || val > 57) //NaN
			return false;
	}
	if (str[0] != '0') {
		fputs("tk_int_literal ", fp2);
		fputs(str, fp2);
		fputs(" ", fp2);
		printf("%-50s", "tk_int_literal");
		printf(", string %-40s", str);
	}
	return true;
}

/*
isFloat(): checks whether the passed string is an float literal or not
Parameters:	character pointer str
Returns:	if str is a float literal true; otherwise false
*/
bool isFloat(char *str) {
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return false;

	for (i = 0; i < len; i++) {
		int val = str[i]; //ASCII 0-9 is 48-57
		if (str[i] == '.')
			if (!hasDecimal)
				hasDecimal = true;
			else
				return false;
		else if (val < 48 || val > 57) //NaN
			return false;

	}
	if (hasDecimal) {
		fputs("tk_float_literal ", fp2);
		fputs(str, fp2);
		fputs(" ", fp2);
		printf("%-50s", "tk_float_literal");
		printf(", string %-40s", str);
	}
	return (hasDecimal);
}

/*
isIdentifier(): checks whether the passed string is an identifier(corresponding to the regex) or not
Parameters:	character pointer str
Returns:	if str is an identifier true; otherwise false
*/
bool isIdentifier(char *str) {
	int i, len = strlen(str);
	if (isAlphabet(str[0])) { // first char is alphabet
		for (i = 1; i < len; i++) {
			if (!(isAlphabet(str[i]) || str[i] == '\\' || str[i] == '.' || isNum(str[i])))
				return false; //if none of the above conditions match, it is not IDENT
		}
		fputs("tk_ident ", fp2);
		fputs(str, fp2);
		fputs(" ", fp2);
		printf("%-50s", "tk_ident");
		printf(", string %-40s", str);
		return true;
	}
	else if (str[0] == '_') {
		for (i = 1; i < len; i++) {
			if (!(isAlphabet(str[i]) || str[i] == '\\' || str[i] == '.' || isNum(str[i])))
				return false; //if none of the above conditions match, it is not IDENT
		}
		fputs("tk_funid ", fp2);
		fputs(str, fp2);
		fputs(" ", fp2);
		printf("%-50s", "tk_funid");
		printf(", string %-40s", str);
		return true;

	}
	else {
		return false;
	}

}

/*
isFloat(): checks whether the passed string is an string literal(enclosed in double quotes) or not
Parameters:	character pointer str
Returns:	if str is a string literal true; otherwise false
*/
bool isStringLiteral(char *str) {
	int i, len = strlen(str);
	if (str[0] == '\"') {
		return true;
	}
	return false;
}

/*
isComment(): checks whether the passed string is an comment(begins with #) or not
Parameters:	character pointer str
Returns:	if str is a comment true; otherwise false
*/
bool isComment(char *str) {
	if (str[0] == '#') {
		return true;
	}
	return false;
}

/*
subString(): Generates substring from the passed string from left to right position
Parameters:
	character pointer str,
	integer left(start point of the substring)
	integer right(ending point of the substring)
Returns:
	character pointer subStr(the generated substring)
*/
char* subString(char* str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));


	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

/*
parse(): main parsing functions, reads the input token by token and determines category of the token
Parameters:
	character pointer str (input line)
	integer line (line number)
*/
void parse(char *str, int line) {
	int left = 0, right = 0;
	int len = strlen(str);

	while (right <= len && left <= right) {
		if (isDelimiter(str[right]) == false) {
			right++;
		}
		if (isDelimiter(str[right]) == true && left == right) {
			int check = 1;
			if (str[right] == '<' || str[right] == '>' || str[right] == '=') {
				char first = str[right];
				if (right < len && isCmpOperator(first, str[right + 1]) == true) {
					printf(", line number %d\n", line);
					fprintf(fp2, "%d", line);
					fputs(" ", fp2);
					right++;
					check = 0;
				}
			}
			if (check && printDelimiter(str[right])) {
				printf(", line number %d\n", line);
				fprintf(fp2, "%d", line);
				fputs(" ", fp2);
			}

			right++;
			left = right;
		}
		else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);
			// printf("%lu\n", strlen(subStr));
			// printf("%d\n", subStr[0]);
			// printf("%-50s","\nExtracted substring is %s\n",subStr);

			int println = 0; //whether to print line no or not


			if (isKeyword(subStr) == true) {
				// printf("Hello");
				println = 1;
			}

			else if (isInteger(subStr) == true) {
				if (subStr[0] == '0') {
					int k = 0;
					while (subStr[k] == '0') {
						fputs("tk_int_literal 0 ", fp2);
						printf("%-50s", "tk_int_literal");
						printf(", string %-40s", "0");
						printf(", line number %d\n", line);
						fprintf(fp2, "%d", line);
						fputs(" ", fp2);
						k++;

					}

					if (strlen(subStr) > 1) {
						fputs("tk_int_literal ",  fp2);
						fputs(subString(str, left + k, right - 1), fp2);
						fputs(" ", fp2);
						printf("%-50s", "tk_int_literal");
						printf(", string %-40s", subString(str, left + k, right - 1));
						println = 1;
					}
				}
				else {
					println = 1;
				}
			}

			else if (isFloat(subStr) == true) {
				println = 1;
			}

			else if (isIdentifier(subStr) == true) {
				println = 1;
			}

			else if (isStringLiteral(subStr) == true) {
				int i = left + 1;
				while (i <= len && str[i] != '\"') {
					i++;
				}
				if (i == len + 1) {
					fputs("ERROR ", fp2);
					fputs(subStr, fp2);
					fputs(" ", fp2);
					printf("%-50s", "ERROR");
					printf(", string %-40s", subStr);
				}
				else {
					fputs("tk_string_literal ",  fp2);
					fputs(subString(str, left, i), fp2);
					fputs(" ", fp2);
					printf("%-50s", "tk_string_literal");
					printf(", string %-40s", subString(str, left, i));
				}
				right = i + 1;
				println = 1;
			}
			else if (isComment(subStr) == true) {
				//printf("%-50s","COMMENT");
				//printf(", string %-40s",subString(str,left,len-2));
				//printf(", line number %d\n",line);
				break; //whole line is a comment at this point
			}

			else if (strlen(subStr) > 0 && subStr[0] != ' ' && subStr[0] != '\t') {
				//resolving errors like 4abc & 5.12abc
				// printf("%s", subStr);
				int i = 0, tleft = left , extra = 0;
				int newlen = right - left;
				bool hasDecimal = false;
				while (i < newlen) {
					if (isNum(subStr[i]) || (subStr[i] == '.') ) {
						while (i < newlen && (isNum(subStr[i])) || (subStr[i] == '.' && !(hasDecimal)) ) {
							if (subStr[i] == '.') {
								hasDecimal = true;
							}
							i++;
						}
						if (hasDecimal) { //float
							if (i - 1 - extra != 0) {
								fputs("tk_float_literal ",  fp2);
								fputs(subString(str, left, left + i - 1 - extra), fp2);
								fputs(" ", fp2);
								printf("%-50s", "tk_float_literal");
								printf(", string %-40s", subString(str, left, left + i - 1 - extra));
								hasDecimal = false;
							}
							else {
								fputs("ERROR ", fp2);
								fputs(subString(str, left, left), fp2);
								fputs(" ", fp2);
								printf("%-50s", "ERROR");
								printf(", string %-40s", subString(str, left, left));
							}

						}
						else { //int
							fputs("tk_int_literal ", fp2);
							fputs(subString(str, left, left + i - 1 - extra), fp2);
							fputs(" ", fp2);
							printf("%-50s", "tk_int_literal");
							printf(", string %-40s", subString(str, left, left + i - 1 - extra));
						}
						printf(", line number %d\n", line);
						fprintf(fp2, "%d", line);
						fputs(" ", fp2);
					}
					else if (isAlphabet(subStr[i]) || subStr[i] == '_') {
						if (subStr[i] == '_') {
							i++;
						}
						while (i < newlen && (isAlphabet(subStr[i]) || isNum(subStr[i]) || subStr[i] == '.')) {
							i++;
						}
						if (isKeyword(subString(str, left, left + i - 1 - extra))) {

							printf(", line number %d\n", line);
							fprintf(fp2, "%d", line);
							fputs(" ", fp2);
						}
						else if (isIdentifier(subString(str, left, left + i - 1 - extra))) {
							// printf("%-50s", "TK_IDENT");
							// printf(", string %-40s", subString(str, left, left + i - 1 - extra));
							printf(", line number %d\n", line);
							fprintf(fp2, "%d", line);
							fputs(" ", fp2);
						}
					}

					else {
						fputs("ERROR ",  fp2);
						fputs(subString(str, left, left), fp2);
						fputs(" ", fp2);
						printf("%-50s", "ERROR");
						printf(", string %-40s", subString(str, left, left));
						printf(", line number %d\n", line);
						fprintf(fp2, "%d", line);
						fputs(" ", fp2);
						// println=1;
						i++;
					}
					left = tleft + i;
					extra = i;
					// i++;
				}
			}

			if (println) {
				printf(", line number %d\n", line);
				fprintf(fp2, "%d", line);
				fputs(" ", fp2);
			}
			println = 0;
			left = right;
		}
	}
	return;
}

void lexer() {
	FILE *fp;
	// printf("Welcome To TreK lexer!\n");
	printf("Enter the input file name\n");
	char filename[1000];
	scanf("%s", filename);
	fp = fopen(filename, "r");

	fp2 = fopen("../Output/Loutput.txt", "w");
	if (fp == NULL) {
		printf("Supplied file failed to open.\n");
		exit(0);
	}

	char buff[200];
	int line = 1;
	while (fgets (buff, 200, fp) != NULL) {
		// printf("%-50s","buffer passed is %s\n\n",buff);
		parse(buff, line);
		line++;
	}
	fclose(fp);
	fclose(fp2);
}
