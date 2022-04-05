#include "stdafx.h"
#include "iostream"
#include <string.h>
#include <string>
#include <stack>
using namespace std;

bool opening_symbol(string Str) {
	if ((Str == "(") || (Str == "(*") || (Str == "{") || (Str == "[") || (Str == "<"))
		return true;
	else
		return false;

};
bool closing_symbol(string Str) {
	if ((Str == ")") || (Str == "*)") || (Str == "}") || (Str == "]") || (Str == ">"))
		return true;
	else
		return false;

};
bool Check_two_symbols(string S1, string S2) {
	if (S1 == "(" && S2 == ")")
		return true;
	if (S1 == "(*" && S2 == "*)")
		return true;
	if (S1 == "{" && S2 == "}")
		return true;
	if (S1 == "<" && S2 == ">")
		return true;
	if (S1 == "[" && S2 == "]")
		return true;
	return false;
}




int main()
{
	int i, check;
	bool flag;
	stack <string> Stack;
	string Str, check_str;
	while (std::getline(std::cin, Str)) {
		flag = false;
		check = 0;
		for (i = 0; i < Str.size(); i++) {
			check_str = "";
			if (Str[i] == '(' &&  i != Str.size() - 1 && Str[i + 1] == '*') {
				check_str = "(*";
				i++;
			}
			else {
				if (Str[i] == '*' &&  i != Str.size() - 1 && Str[i + 1] == ')') {
					check_str = "*)";
					i++;
				}
				else
					check_str = Str[i];
			}
			////////////////////////////////////////////
			check++;
			if (opening_symbol(check_str))
				Stack.push(check_str);
			else {
				if (closing_symbol(check_str)) {
					if (Stack.empty() == true) {
						cout << "NO " << check << endl;
						flag = true;
						break;
					}
					if (Check_two_symbols(Stack.top(), check_str) == false) {
						cout << "NO " << check << endl;
						flag = true;
						break;
					}
					Stack.pop();
				}
			}
		}
		if (Stack.empty() && flag == false)
			cout << "YES" << endl;
		else
			if (flag == false)
				cout << "NO " << check + 1 << endl;

	}

	return 0;
}

