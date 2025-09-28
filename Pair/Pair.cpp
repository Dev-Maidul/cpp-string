#include <bits/stdc++.h>
using namespace std;

int main() {
	pair<int,string> student;
	vector<pair<int,string>>allStudents;
	int n;
	cin>>n;
	int roll;
	string name;
	for(int i=0; i<n; i++)
	{
	    cin>>roll>>name;
	    student=make_pair(roll,name);
	    allStudents.push_back(student);
	}
	// pair sort 
	sort(allStudents.begin(),allStudents.end());
	cout<<"Sorted by Roll\n";
	for(auto curStudent: allStudents)
	{
	    cout<<"Roll: "<<curStudent.first<<" Name: "<<curStudent.second<<endl;
	}

}
