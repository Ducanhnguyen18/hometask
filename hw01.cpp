#include<iostream>
using namespace std;

double function(double dum)
{

double result;
result = 2.54 * dum;
return result;
}

int main()
{
double dum;
double finaly;
cout<<"Enter counter duym"<<endl;
cin>>dum;
finaly = function(dum);

cout << "santimetrs" << finaly << endl;
return 0;
}