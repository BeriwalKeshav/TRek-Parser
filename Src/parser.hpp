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
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdio.h>
#include <sstream>
#include<map>
#include<deque>
#include<fstream>
#include<iomanip>
#include<queue>
using namespace std;
void PrintStack(stack<string>& s, int i, string& output1);
void PrintInput(deque<pair<pair<string, string>, int> >& tokens, int i, string& output2);
void InsertRule(vector<string>&r, stack<string>&s);
void parser();