#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

struct printJob {
	int timestamp;
	int pNumber;
	string jobName;
	bool urgent;
	int duration;
};

int main() {
	printJob tempJob;
	string input = "";
	vector<printJob> jobList;
	int t = 0;
	//int lastTime = -1;
	int jobsExecd = 0;
	//introductory cout statements
	while(true) {
		cout<<"Enter timestamp: ";
		getline(cin, input);
		stringstream myStream(input);
		myStream>>tempJob.timestamp;
		if(tempJob.timestamp<0) {
			break;
		}
		cout<<"Enter number of pages: ";
		getline(cin,input);
		stringstream myStream1(input);
		myStream1>>tempJob.pNumber;
		cout<<"Enter Job Name: ";
		getline(cin,input);
		tempJob.jobName = input;
		cout<<"Enter 1 for urgent: ";
		getline(cin,input);
		stringstream myStream2(input);
		int status;
		myStream2>>status;
		tempJob.urgent = (status==1)?true:false;
		cout<<"Enter time for printing: ";
		getline(cin,input);
		stringstream myStream3(input);
		myStream3>>tempJob.duration;
		cout<<"Entered:\n"
			<<"\t"<<tempJob.timestamp<<endl
			<<"\t"<<tempJob.jobName<<endl
			<<"\t"<<tempJob.pNumber<<endl
			<<"\t"<<tempJob.urgent<<endl
			<<"\t"<<tempJob.duration<<endl;
		jobList.push_back(tempJob);
	}
	vector<printJob*> incomp;
	int lIndex=0;
	while (jobsExecd < jobList.size()) {
		int uIndex = -1;
		int nIndex = -1;
		int uMinTime = INT_MAX;
		int nMinTime = INT_MAX;
		int i = lIndex;
		while(i<jobList.size() && jobList.at(i).timestamp <= t) {
			incomp.push_back(&(jobList.at(i)));
			i++;
		}
		lIndex = i;
		for(int j=0; j<incomp.size(); j++) {
			printJob *p = incomp.at(j);
			if (p->urgent) {
				if (t + p->duration > p->timestamp +5) { //refund time!
					p->urgent = false;
					cout<<"Refund "<<p->jobName<<"\tPages: "<<p->pNumber<<endl;
					if(p->duration < nMinTime) {
						nMinTime = p->duration;
						nIndex = j;
					}
				}
				else { //legit urgent, right now
					if(p->duration < uMinTime) {
						uMinTime = p->duration;
						uIndex = j;
					}
				}
			}
			else { //anyway normal
				if(p->duration < nMinTime) {
					nMinTime = p->duration;
					nIndex = j;
				}
			}
			p = NULL;
		}
		if (uIndex>-1) {
			printJob *p = incomp.at(uIndex);
			cout<<"Print: "<<p->jobName<<" of pages: "<< p->pNumber <<" at time "<< (t+p->duration)<<endl;
			t = t + p->duration;
			jobsExecd++;
			p = NULL;
			incomp.erase(incomp.begin()+uIndex);
			continue;
		}
		else if(nIndex>-1) {
			printJob *p = incomp.at(nIndex);
			cout<<"Print: "<<p->jobName<<" of pages: "<<(p->pNumber)<<" at time "<< (t+p->duration)<<endl;
			t = t + p->duration;
			jobsExecd++;
			p = NULL;
			incomp.erase(incomp.begin()+nIndex);
			continue;
		}
		if (incomp.empty()) t++; //no jobs at this time, just increment dis
	}
	return 0;
}
