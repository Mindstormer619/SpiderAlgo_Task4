#include <iostream>
#include <conio.h>
#include <deque>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	deque<string> q;
	string s;
	for (int i=0; i<100; ++i) {
		getline(cin,s);
		/*
			s is input
			must check for existence, if exist, delete
			push the current thing in back
			if >20, pop the top
		*/
		if(q.empty()) {
			//doesn't exist for sure
			q.push_back(s);
			continue;
		}
		//size is more
		if (q.back() == s) { //last element is the same
			continue;
		}
		
		for (int j=0; j<q.size()-1; j++) {
			if ( q.at(j) == s ) {
				q.erase(q.begin()+j);
				break;
			}
		}
		
		if (q.size()==20) {
			cout<<"Popping "<<q.at(0)<<"\n";
			q.pop_front();
		}
		q.push_back(s);
	}
	return EXIT_SUCCESS;
}
