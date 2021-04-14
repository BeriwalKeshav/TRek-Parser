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
#include "parser.hpp"
ofstream file;
/*
To print the parse tree
*/
void printTree(string node, int level)
{
	for (int i = 0; i < level; i++)
		file << "    ";
	file << node << "\n";
}
/*
Print the stack contents
*/
void PrintStack(stack<string>& s, int i, string& output1)
{
	if (s.empty() || i == 0) {
		return;
	}


	string x = s.top();
	s.pop();
	PrintStack(s, i - 1, output1);
	output1 += x;
	s.push(x);
}
/*
Print the input
*/
void PrintInput(deque<pair<pair<string, string>, int> >& tokens, int i, string& output2) {
	for (auto it : tokens) {
		if (i == 0) {
			break;
		}
		pair<string, string> tl = it.first;

		output2 += "(";
		output2 += tl.first;
		output2 += ",";
		output2 += tl.second;
		output2 += ")";
		i--;
	}
}
/*
Pushing the rule into the stack
*/
void InsertRule(vector<string>&r, stack<string>&s, vector<vector<string> >&parseTree, stack<pair<string, int> >&stack_t, int level) {
	stack<string>temp;
	for (auto it : r) {
		parseTree[level + 1].push_back(it);
		temp.push(it);
	}
	while (!temp.empty()) {
		s.push(temp.top());
		stack_t.push({temp.top(), level + 1});
		temp.pop();

	}
}
/*
The main parser function for checking syntax
*/
void parser() {
	cout << "Time for Synatx Analysis" << endl << endl;
	cout << "For only the Final Result Press 1" << endl;
	cout << "To see the Final Result with stack contents Press 2" << endl;
	cout << "To see the Final Result with Level Order Tree Traversal Press 3" << endl;
	cout << "To see the Final Result with all of the above Press 4" << endl;
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		cout << "Enter the correct Choice" << endl;
		cin >> choice;
	}
	int size = 3;
	if (choice == 2 || choice == 4) {
		cout << endl << "Enter the number of elements that you want see in the stack at once!" << endl;
		cout << "Press 3 for the best view" << endl;
		cin >> size;
	}
	// cout << choice << endl;
	freopen("../Output/Loutput.txt", "r", stdin);
	vector<vector<string> >rules;
	rules = { {"synch"},
		{"OTHERFUNC" , "MAINFUNC"},
		{"tk_main", "tk_lcurlybracket_operator", "STMTS", "tk_rcurlybracket_operator"},
		{"FUNCTION", "OTHERFUNC"},
		{"epsilon"},
		{"tk_funid" , "tk_lcurlybracket_operator", "INPUT_PAR", "OUTPUT_PAR", "tk_semicol_operator", "STMTS", "tk_rcurlybracket_operator" },
		{"tk_input_keyword", "tk_parameter", "tk_lsquarebracket_operator", "PARAMETER_LIST", "tk_rsquarebracket_operator"},
		{"tk_output_keyword", "tk_parameter", "tk_lsquarebracket_operator", "PARAMETER_LIST", "tk_rsquarebracket_operator"},
		{"epsilon"},
		{"DATA_TYPE", "tk_ident", "REMAINING_LIST"},
		{"tk_int_keyword"},
		{"tk_float_keyword"},
		{"tk_string_keyword"},
		{"tk_comma_operator", "PARAMETER_LIST"},
		{"epsilon"},
		{"STMT", "STMTS"},
		{"epsilon"},
		{"DECLSTMT"},
		{"LOOPSTMT"},
		{"ASSIGNSTMT"},
		{"FUNCALSTMT"},
		{"IOSTMT"},
		{"CONDSTMT"},
		{"RETSTMT"},
		{"tk_int_keyword", "tk_ident", "tk_semicol_operator"},
		{"tk_float_keyword" , "tk_ident", "tk_semicol_operator"},
		{"tk_string_keyword" , "tk_ident", "tk_semicol_operator"},
		{"tk_ident" , "tk_assignment_operator", "ARITHEXP", "tk_semicol_operator"},
		{"TERM", "EXPPRIME"},
		{"LOWPOP", "TERM", "EXPPRIME"},
		{"epsilon"},
		{"FACTOR", "TERMPRIME" },
		{"HIGHPOP" , "FACTOR", "TERMPRIME"},
		{"epsilon"},
		{"tk_lparen_operator", "ARITHEXP", "tk_rparen_operator"},
		{"VAR"},
		{"tk_mul_operator"},
		{"tk_div_operator"},
		{"tk_plus_operator"},
		{"tk_minus_operator"},
		{"tk_ident"},
		{"tk_int_literal"},
		{"tk_float_literal"},
		{"tk_string_literal"},
		{"tk_for_keyword", "tk_lparen_operator" , "BOOLEXP" , "tk_rparen_operator" , "tk_lcurlybracket_operator" , "STMTS", "tk_rcurlybracket_operator"},
		{"tk_lparen_operator", "BOOLEXP", "tk_rparen_operator", "LOGOP", "tk_lparen_operator" , "BOOLEXP", "tk_rparen_operator"},
		{"tk_ident", "RELOP", "VAR"},
		{"tk_int_literal", "RELOP", "VAR"},
		{"tk_float_literal", "RELOP", "VAR"},
		{"tk_string_literal", "RELOP", "VAR"},
		{"tk_lt_operator"},
		{"tk_lteq_operator"},
		{"tk_equal_operator"},
		{"tk_gteq_operator"},
		{"tk_gt_operator"},
		{"tk_and"},
		{"tk_or"},
		{"tk_if_keyword" , "BOOLEXP", "tk_lcurlybracket_operator" , "STMTS", "tk_rcurlybracket_operator" , "CONDSTMTPRIME"},
		{"tk_else_keyword", "tk_lcurlybracket_operator", "STMTS" , "tk_rcurlybracket_operator"},
		{"epsilon"},
		{"tk_read_keyword", "tk_lparen_operator", "tk_ident", "tk_rparen_operator" , "tk_semicol_operator"},
		{"tk_write", "tk_lparen_operator" , "VAR" , "tk_rparen_operator" , "tk_semicol_operator"},
		{"OUTPUT_PARAM", "tk_funid", "INPUT_PARAM", "tk_semicol_operator"},
		{"tk_lsquarebracket_operator", "IDLIST", "tk_rsquarebracket_operator", "tk_assignment_operator"},
		{"tk_lsquarebracket_operator", "IDLIST", "tk_rsquarebracket_operator"},
		{"tk_ident", "MOREID"},
		{"tk_comma_operator", "IDLIST"},
		{"epsilon"},
		{"tk_return_keyword" , "OPRESTMT", "tk_semicol_operator"},
		{"tk_lsquarebracket_operator" , "IDLIST", "tk_rsquarebracket_operator"},
		{"epsilon"}
	};
	map<pair<string, string>, int> table;
	table = {{{"PROGRAM", "$"}, 0},
		{{"PROGRAM", "tk_main"}, 1},
		{{"PROGRAM", "tk_funid"}, 1},
		{{"MAINFUNC", "$"}, 0},
		{{"MAINFUNC", "tk_main"}, 2},
		{{"OTHERFUNC", "tk_main"}, 4},
		{{"OTHERFUNC", "tk_funid"}, 3},
		{{"FUNCTION", "tk_main"}, 0},
		{{"FUNCTION", "tk_funid"}, 5},
		{{"INPUT_PAR", "tk_output_keyword"}, 0},
		{{"INPUT_PAR", "tk_main"}, 0},
		{{"INPUT_PAR", "tk_funid"}, 0},
		{{"INPUT_PAR", "tk_semicol_operator"}, 0},
		{{"INPUT_PAR", "tk_input_keyword"}, 6},
		{{"OUTPUT_PAR", "tk_semicol_operator"}, 8},
		{{"OUTPUT_PAR", "tk_output_keyword"}, 7},
		{{"PARAMETER_LIST", "tk_rsquarebracket_operator"}, 0},
		{{"PARAMETER_LIST", "tk_int_keyword"}, 9},
		{{"PARAMETER_LIST", "tk_foat_keyword"}, 9},
		{{"PARAMETER_LIST", "tk_string_keyword"}, 9},
		{{"DATA_TYPE", "tk_ident"}, 0},
		{{"DATA_TYPE", "tk_int_keyword"}, 10},
		{{"DATA_TYPE", "tk_float_keyword"}, 11},
		{{"DATA_TYPE", "tk_string_keyword"}, 12},
		{{"REMAINING_LIST", "tk_rsquarebracket_operator"}, 14},
		{{"REMAINING_LIST", "tk_comma_operator"}, 13},
		{{"STMTS", "tk_rcurlybracket_operator"}, 16},
		{{"STMTS", "tk_int_keyword"}, 15},
		{{"STMTS", "tk_float_keyword"}, 15},
		{{"STMTS", "tk_string_keyword"}, 15},
		{{"STMTS", "tk_for_keyword"}, 15},
		{{"STMTS", "tk_ident"}, 15},
		{{"STMTS", "tk_read_keyword"}, 15},
		{{"STMTS", "tk_write"}, 15},
		{{"STMTS", "tk_if_keyword"}, 15},
		{{"STMTS", "tk_return_keyword"}, 15},
		{{"STMTS", "tk_lsquarebracket_operator"}, 15},
		{{"STMT", "tk_rcurlybracket_operator"}, 0},
		{{"STMT", "tk_int_keyword"}, 17},
		{{"STMT", "tk_float_keyword"}, 17},
		{{"STMT", "tk_string_keyword"}, 17},
		{{"STMT", "tk_for_keyword"}, 18},
		{{"STMT", "tk_ident"}, 19},
		{{"STMT", "tk_read_keyword"}, 21},
		{{"STMT", "tk_write"}, 21},
		{{"STMT", "tk_if_keyword"}, 22},
		{{"STMT", "tk_return_keyword"}, 23},
		{{"STMT", "tk_lsquarebracket_operator"}, 20},
		{{"DECLSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"DECLSTMT", "tk_for_keyword"}, 0},
		{{"DECLSTMT", "tk_ident"}, 0},
		{{"DECLSTMT", "tk_read_keyword"}, 0},
		{{"DECLSTMT", "tk_write"}, 0},
		{{"DECLSTMT", "tk_if_keyword"}, 0},
		{{"DECLSTMT", "tk_return_keyword"}, 0},
		{{"DECLSTMT", "tk_lsquarebracket_operator"}, 0},
		{{"DECLSTMT", "tk_int_keyword"}, 24},
		{{"DECLSTMT", "tk_float_keyword"}, 25},
		{{"DECLSTMT", "tk_string_keyword"}, 26},
		{{"ASSIGNSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"ASSIGNSTMT", "tk_int_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_float_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_string_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_for_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_read_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_write"}, 0},
		{{"ASSIGNSTMT", "tk_if_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_return_keyword"}, 0},
		{{"ASSIGNSTMT", "tk_lsquarebracket_operator"}, 0},
		{{"ASSIGNSTMT", "tk_ident"}, 27},
		{{"ARITHEXP", "tk_semicol_operator"}, 0},
		{{"ARITHEXP", "tk_rparen_operator"}, 0},
		{{"ARITHEXP", "tk_lparen_operator"}, 28},
		{{"ARITHEXP", "tk_ident"}, 28},
		{{"ARITHEXP", "tk_int_literal"}, 28},
		{{"ARITHEXP", "tk_float_literal"}, 28},
		{{"ARITHEXP", "tk_string_literal"}, 28},
		{{"EXPPRIME", "tk_semicol_operator"}, 30},
		{{"EXPPRIME", "tk_rparen_operator"}, 30},
		{{"EXPPRIME", "tk_plus_operator"}, 29},
		{{"EXPPRIME", "tk_minus_operator"}, 29},
		{{"TERM", "tk_semicol_operator"}, 0},
		{{"TERM", "tk_plus_operator"}, 0},
		{{"TERM", "tk_minus_operator"}, 0},
		{{"TERM", "tk_rparen_operator"}, 0},
		{{"TERM", "tk_lparen_operator"}, 31},
		{{"TERM", "tk_ident"}, 31},
		{{"TERM", "tk_int_literal"}, 31},
		{{"TERM", "tk_float_literal"}, 31},
		{{"TERM", "tk_string_literal"}, 31},
		{{"TERMPRIME", "tk_semicol_operator"}, 33},
		{{"TERMPRIME", "tk_plus_operator"}, 33},
		{{"TERMPRIME", "tk_minus_operator"}, 33},
		{{"TERMPRIME", "tk_rparen_operator"}, 33},
		{{"TERMPRIME", "tk_mul_operator"}, 32},
		{{"TERMPRIME", "tk_div_operator"}, 32},
		{{"FACTOR", "tk_semicol_operator"}, 0},
		{{"FACTOR", "tk_plus_operator"}, 0},
		{{"FACTOR", "tk_minus_operator"}, 0},
		{{"FACTOR", "tk_mul_operator"}, 0},
		{{"FACTOR", "tk_div_operator"}, 0},
		{{"FACTOR", "tk_rparen_operator"}, 0},
		{{"FACTOR", "tk_lparen_operator"}, 34},
		{{"FACTOR", "tk_ident"}, 35},
		{{"FACTOR", "tk_int_literal"}, 35},
		{{"FACTOR", "tk_float_literal"}, 35},
		{{"FACTOR", "tk_string_literal"}, 35},
		{{"HIGHPOP", "tk_lparen_operator"}, 0},
		{{"HIGHPOP", "tk_ident"}, 0},
		{{"HIGHPOP", "tk_int_literal"}, 0},
		{{"HIGHPOP", "tk_float_literal"}, 0},
		{{"HIGHPOP", "tk_string_literal"}, 0},
		{{"HIGHPOP", "tk_mul_operator"}, 36},
		{{"HIGHPOP", "tk_div_operator"}, 37},
		{{"LOWPOP", "tk_lparen_operator"}, 0},
		{{"LOWPOP", "tk_ident"}, 0},
		{{"LOWPOP", "tk_int_literal"}, 0},
		{{"LOWPOP", "tk_float_literal"}, 0},
		{{"LOWPOP", "tk_string_literal"}, 0},
		{{"LOWPOP", "tk_plus_operator"}, 38},
		{{"LOWPOP", "tk_minus_operator"}, 39},
		{{"VAR", "tk_semicol_operator"}, 0},
		{{"VAR", "tk_rparen_operator"}, 0},
		{{"VAR", "tk_plus_operator"}, 0},
		{{"VAR", "tk_minus_operator"}, 0},
		{{"VAR", "tk_mul_operator"}, 0},
		{{"VAR", "tk_div_operator"}, 0},
		{{"VAR", "tk_lcurlybracket_operator"}, 0},
		{{"VAR", "tk_ident"}, 40},
		{{"VAR", "tk_int_literal"}, 41},
		{{"VAR", "tk_float_literal"}, 42},
		{{"VAR", "tk_string_literal"}, 43},
		{{"LOOPSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"LOOPSTMT", "tk_int_keyword"}, 0},
		{{"LOOPSTMT", "tk_float_keyword"}, 0},
		{{"LOOPSTMT", "tk_string_keyword"}, 0},
		{{"LOOPSTMT", "tk_ident"}, 0},
		{{"LOOPSTMT", "tk_read_keyword"}, 0},
		{{"LOOPSTMT", "tk_write"}, 0},
		{{"LOOPSTMT", "tk_if_keyword"}, 0},
		{{"LOOPSTMT", "tk_return_keyword"}, 0},
		{{"LOOPSTMT", "tk_lsquarebracket_operator"}, 0},
		{{"LOOPSTMT", "tk_for_keyword"}, 44},
		{{"BOOLEXP", "tk_rparen_operator"}, 0},
		{{"BOOLEXP", "tk_lcurlybracket_operator"}, 0},
		{{"BOOLEXP", "tk_lparen_operator"}, 45},
		{{"BOOLEXP", "tk_ident"}, 46},
		{{"BOOLEXP", "tk_int_literal"}, 47},
		{{"BOOLEXP", "tk_float_literal"}, 48},
		{{"BOOLEXP", "tk_string_literal"}, 49},
		{{"RELOP", "tk_ident"}, 0},
		{{"RELOP", "tk_int_literal"}, 0},
		{{"RELOP", "tk_float_literal"}, 0},
		{{"RELOP", "tk_string_literal"}, 0},
		{{"RELOP", "tk_lt_operator"}, 50},
		{{"RELOP", "tk_lteq_operator"}, 51},
		{{"RELOP", "tk_equal_operator"}, 52},
		{{"RELOP", "tk_gteq_operator"}, 53},
		{{"RELOP", "tk_gt_operator"}, 54},
		{{"LOGOP", "tk_lparen_operator"}, 0},
		{{"LOGOP", "tk_and"}, 55},
		{{"LOGOP", "tk_or"}, 56},
		{{"CONDSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"CONDSTMT", "tk_int_keyword"}, 0},
		{{"CONDSTMT", "tk_float_keyword"}, 0},
		{{"CONDSTMT", "tk_string_keyword"}, 0},
		{{"CONDSTMT", "tk_for_keyword"}, 0},
		{{"CONDSTMT", "tk_ident"}, 0},
		{{"CONDSTMT", "tk_read_keyword"}, 0},
		{{"CONDSTMT", "tk_write"}, 0},
		{{"CONDSTMT", "tk_return_keyword"}, 0},
		{{"CONDSTMT", "tk_lsquarebracket_operator"}, 0},
		{{"CONDSTMT", "tk_if_keyword"}, 57},
		{{"CONDSTMTPRIME", "tk_rcurlybracket_operator"}, 59},
		{{"CONDSTMTPRIME", "tk_int_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_float_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_string_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_for_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_ident"}, 59},
		{{"CONDSTMTPRIME", "tk_read_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_write"}, 59},
		{{"CONDSTMTPRIME", "tk_if_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_return_keyword"}, 59},
		{{"CONDSTMTPRIME", "tk_lsquarebracket_operator"}, 59},
		{{"CONDSTMTPRIME", "tk_else_keyword"}, 58},
		{{"IOSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"IOSTMT", "tk_int_keyword"}, 0},
		{{"IOSTMT", "tk_float_keyword"}, 0},
		{{"IOSTMT", "tk_string_keyword"}, 0},
		{{"IOSTMT", "tk_for_keyword"}, 0},
		{{"IOSTMT", "tk_ident"}, 0},
		{{"IOSTMT", "tk_if_keyword"}, 0},
		{{"IOSTMT", "tk_return_keyword"}, 0},
		{{"IOSTMT", "tk_lsquarebracket_operator"}, 0},
		{{"IOSTMT", "tk_read_keyword"}, 60},
		{{"IOSTMT", "tk_write"}, 61},
		{{"FUNCALSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"FUNCALSTMT", "tk_int_keyword"}, 0},
		{{"FUNCALSTMT", "tk_float_keyword"}, 0},
		{{"FUNCALSTMT", "tk_string_keyword"}, 0},
		{{"FUNCALSTMT", "tk_for_keyword"}, 0},
		{{"FUNCALSTMT", "tk_ident"}, 0},
		{{"FUNCALSTMT", "tk_read_keyword"}, 0},
		{{"FUNCALSTMT", "tk_write"}, 0},
		{{"FUNCALSTMT", "tk_if_keyword"}, 0},
		{{"FUNCALSTMT", "tk_return_keyword"}, 0},
		{{"FUNCALSTMT", "tk_lsquarebracket_operator"}, 62},
		{{"OUTPUT_PARAM", "tk_funid"}, 0},
		{{"OUTPUT_PARAM", "tk_lsquarebracket_operator"}, 63},
		{{"INPUT_PARAM", "tk_semicol_operator"}, 0},
		{{"INPUT_PARAM", "tk_lsquarebracket_operator"}, 64},
		{{"IDLIST", "tk_rsquarebracket_operator"}, 0},
		{{"IDLIST", "tk_ident"}, 65},
		{{"MOREID", "tk_rsquarebracket_operator"}, 67},
		{{"MOREID", "tk_comma_operator"}, 66},
		{{"RETSTMT", "tk_rcurlybracket_operator"}, 0},
		{{"RETSTMT", "tk_int_keyword"}, 0},
		{{"RETSTMT", "tk_float_keyword"}, 0},
		{{"RETSTMT", "tk_string_keyword"}, 0},
		{{"RETSTMT", "tk_for_keyword"}, 0},
		{{"RETSTMT", "tk_ident"}, 0},
		{{"RETSTMT", "tk_read_keyword"}, 0},
		{{"RETSTMT", "tk_write"}, 0},
		{{"RETSTMT", "tk_if_keyword"}, 0},
		{{"RETSTMT", "tk_lsquarebracket_operator"}, 0},
		{{"RETSTMT", "tk_return_keyword"}, 68},
		{{"OPRESTMT", "tk_semicol_operator"}, 70},
		{{"OPRESTMT", "tk_lsquarebracket_operator"}, 69},
	};
	// cout << "Hello" << endl;
	file.open("../Output/ParseTree.txt");

	stack<string> s;
	deque<pair<pair<string, string>, int> > tokens;
	int errline = -1;

	// if (freopen("Loutput.txt", "r", stdin)) {
	// ifstream cin("Loutput.txt");
	while (1) {
		int inflag = 0;
		string a, b;
		int c;
		cin >> a;
		if (a == "ERROR") {
			inflag = 1;
		}
		if (a == "\0") {
			break;
		}
		cin >> b;
		if (b[b.length() - 1] != 34 && b[0] == 34) {
			char ch;
			scanf("%c", &ch);
			while (ch != 34) {
				b.push_back(ch);
				scanf("%c", &ch);
			}
			b.push_back(ch);
		}
		cin >> c;
		if (inflag == 0) {
			tokens.push_back(make_pair(make_pair(a, b), c));
		}


	}
	tokens.push_back(make_pair(make_pair("$", "$"), tokens.back().second + 1));
	fclose(stdin);

	// }



	// freopen("CON", "r", stdin);

	vector<vector<string> > ParseTree(100000);
	ParseTree[0].push_back("PROGRAM");
	stack<pair<string, int> > stack_t;
	stack_t.push({"PROGRAM", 0});
	int flag = 0;
	int flag2 = 0;
	vector<pair<int, string> >lines;
	vector<pair<int, string> >lines2;
	s.push("$");
	s.push("PROGRAM");
	// tree.push("PROGRAM");
	// tree.push("-1");
	if (choice == 2 || choice == 4) {
		cout << "=========================================================================================================================================================================================================\n";
		cout << "Stack(First " << size << " tokens, stack_top=right side)" << "\t\t\t\t\t\tInput(First " << size << " Inputs, starting pointer=left side)\t\t\t\t\tAction\n";
	}
	while (1) {
		if (choice == 2 || choice == 4) {
			cout << "=========================================================================================================================================================================================================\n";
		}

		string output1 = "", output2 = "";

		string stack_top = s.top();
		if (stack_top == "epsilon") {
			if (choice == 2 || choice == 4) {
				PrintStack(s, size, output1);

				printf("%-85s", ("||" + output1 + "||").c_str());

				PrintInput(tokens, size, output2);
				printf("%-85s", ("||" + output2 + "||").c_str());
				cout << "POP epsilon" << endl;

			}
			printTree(stack_t.top().first, stack_t.top().second);
			stack_t.pop();

			s.pop();
			continue;
		}

		pair < pair<string, string>, int> y = tokens.front();
		pair<string, string> token_lexeme = y.first;
		int line = y.second;
		string token = token_lexeme.first;
		string lexeme = token_lexeme.second;

		if (choice == 2 || choice == 4) {

			PrintStack(s, size, output1);

			printf("%-85s", ("||" + output1 + "||").c_str());


			PrintInput(tokens, size, output2);
			printf("%-85s", ("||" + output2 + "||").c_str());


		}




		if (stack_top == token) {
			s.pop();
			tokens.pop_front();
			if (choice == 2 || choice == 4) {
				cout << "POP " << token << endl;

			}
			if (stack_top == "$") {
				flag = 1;
				break;
			}
			printTree(stack_t.top().first, stack_t.top().second);
			stack_t.pop();
		}
		else if (table.count(make_pair(stack_top, token))) {

			string left = stack_t.top().first;
			int level = stack_t.top().second;

			printTree(stack_t.top().first, stack_t.top().second);
			stack_t.pop();
			int rule_no = table[make_pair(stack_top, token)];
			s.pop();
			if (rule_no == 0) {
				if (choice == 2 || choice == 4) {
					cout << "SYNCH POP " << stack_top << " line#" << line << endl;
				}

				lines2.push_back({tokens.front().second, stack_top});
				flag2 = 1;
				continue;
			}
			if (choice == 2 || choice == 4) {
				cout << "Rule " << rule_no << endl;
			}

			InsertRule(rules[rule_no], s, ParseTree, stack_t, level);

		}
		else if (lexeme == "$") {
			errline = line;
			flag2 = 3;
			cout << "The Program is Incomplete!" << endl;
			break;
		}
		else if (stack_top == "$") {
			errline = line;
			flag2 = 2;
			cout << "Some Extra part, not Expecetd!" << endl;
			break;

		}
		else {
			if (choice == 2 || choice == 4) {
				cout << "SKIPING " << lexeme << " in line #" << line << endl;
			}

			lines.push_back({line, lexeme});
			flag2 = 1;
			tokens.pop_front();
		}
	}
	file.close();
	cout << "=========================================================================================================================================================================================================\n";

	if (choice == 3 || choice == 4) {
		cout << "\n\nLevel Order Traversal of the Parse Tree:\n";
		// for (int i = 0; i < 100; i++)
		// {
		// 	if (ParseTree[i].size())
		// 	{
		// 		cout << "Level " << i << " -> ";
		// 		for (auto j : ParseTree[i]) cout << j << " ";
		// 		cout << "\n";
		// 	}
		// }
		cout << "\n\n The Level Order Tree Traversal of the Parse Tree formed is:\n";
		int k = 0;
		for (auto it : ParseTree) {
			if (it.size() == 0) {
				break;
			}
			else {
				cout << "Level " << k++ << " : ";
				for (auto in : it) {
					cout << in << " ";
				}
				cout << endl;
			}
		}
		cout << "=========================================================================================================================================================================================================\n";


	}

	// cout << "=========================================================================================================================================================================================================\n";

	if (flag2 == 1 || flag2 == 2 || flag2 == 3) {
		if (flag2 == 1) {
			cout << endl << "Parsing Process complete, but with errors in the program " << endl;
		}

		for (auto it : lines) {
			cout << endl << "Line " << it.first << ": " << "Error " << it.second << endl;
		}
		for (auto it : lines2) {
			cout << endl << "Line " << it.first << ": " << "missing " << it.second << endl;
		}
		if (flag2 == 2) {
			cout << endl << "line " << errline << " onwards not expected. The Extra part is:" << endl;
			while (tokens.size() != 1) {
				pair<string, string> f = tokens.front().first;
				cout << f.second << endl;
				tokens.pop_front();
			}
		}
		if (flag2 == 3) {
			cout << endl << "The Program is Incomplete! The following Terminals/Non-Terminals are expectd from line " << errline << ":" << endl;
			while (s.size() != 1) {
				cout << s.top() << endl;
				s.pop();
			}
		}
		exit(0);
	}

	else if (flag == 1) {
		cout << endl << "Congratulations, The Program entered is syntactically correct!" << endl;
	}

}
