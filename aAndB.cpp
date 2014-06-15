#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void evalIt ( string inp ) {
	/*
		set start and end to inp's start and end
		while start != lastelem and end != beginelem and start!= end?
	*/
	int start, mid, end;
	start = 0;
	end = inp.size() - 1;
	mid = (start + end)/2;
	while (start<end) {
		mid = (start+end)/2;
		if(inp.at(mid) == 'a') {
			if(inp.at(mid+1)=='b') {
				//case where a at mid and b at midnext
				cout<<"m = "<<mid+1<<endl;
				cout<<"n = "<<inp.size() - (mid+1)<<endl;
				return;
			}
			//a at mid, but b not next
			start = mid+1;
			continue;
		}
		else if(inp.at(mid) == 'b') {
			if(inp.at(mid-1)=='a') {
				//case where b at mid and a at midprev
				cout<<"m = "<<mid<<endl;
				cout<<"n = "<<inp.size() - mid<<endl;
				return;
			}
			//b at mid, but a not prev
			end = mid-1;
			continue;
		}
	}
	//either all a's or all b's
	if(inp.at(0)=='a') {
		cout<<"m = "<<inp.size()<<endl;
		cout<<"n = 0\n";
	}
	else {
		cout<<"m = 0\n";
		cout<<"n = "<<inp.size()<<endl;
	}
}

int main() {
	string inp;
	getline(cin, inp);
	evalIt(inp);
	return 0;
}
