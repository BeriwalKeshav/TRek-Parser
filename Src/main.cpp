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
#include "parser.hpp"
/*
The main function: Calls the lexer first, and then the parser
*/
int main() {
	cout << "Welcome To TreK parser!" << endl << endl;
	lexer();

	cout << endl << "Lexical Analysis Done!" << endl << endl;
	parser();

}
