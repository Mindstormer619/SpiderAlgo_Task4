#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <ctype.h>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

int prec(char op) {
	switch(op) {
		case '+':	return 1;
					break;
		case '-':	return 1;
					break;
		case '*':	return 2;
					break;
		case '/':	return 2;
					break;
		case '^':	return 3;
					break;
	}
}

float evalAns(float a, float b, char c) {
	switch(c)
	{
		case '+':	return a+b;
					break;
		case '-':	return a-b;
					break;
		case '*':	return a*b;
					break;
		case '/':	return a/b;
					break;
		case '^':	return pow(a,b);
					break;
	}

}

int main() {
	string infix;
	string postfix="";
	string num="";
	stack<char> opStack;
	cout<<"Enter the input string\nNo values other than numbers, +, -, /, *, ^\nParantheses not allowed\n";
	getline(cin,infix);
	
	//int num = 0;
	for (int i=0; i<infix.size(); i++) {
		if (isdigit(infix.at(i))) {
			num += infix.at(i);
		}
		else {
			postfix += num;
			postfix += " ";
			num = "";
			while(!(opStack.empty()) && prec(opStack.top()) >= prec(infix.at(i)) ) {
				postfix += opStack.top();
				opStack.pop();
			}
			opStack.push(infix.at(i));
		}
	}
	
	postfix += num;
	postfix += " ";
	while(!(opStack.empty())) {
		postfix += opStack.top();
		opStack.pop();
	}
	
	stack<float> evalStack;
	string readstr="";
	for (int i=0; i<postfix.size(); i++) {
		if(isdigit(postfix.at(i))) {
			readstr += postfix.at(i);
		}
		else if(postfix.at(i)==' ') {
			const char *c = readstr.c_str();
			float pushVal = (float) atoi(c);
			readstr="";
			evalStack.push(pushVal);
		}
		else { //is operator
			float temp2 = evalStack.top();
			evalStack.pop();
			float temp1 = evalStack.top();
			evalStack.pop();
			float ans = evalAns(temp1, temp2, postfix.at(i) );
			evalStack.push(ans);
		}
	}
	cout<<"Answer: "<<evalStack.top()<<endl;
	return 0;
}
