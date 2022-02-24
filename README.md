#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
vector<int>vec;

int counter;
cout«"Enter counter numbers"«endl;
cin»counter;

vec.resize(counter);

for (int i=0;i<vec.size(); i++)
{
cout « "Enter number" « endl;
cin » vec[i];

}

reverse(vec.begin(), vec.end());

for (int i=0;i<vec.size(); i++)
{
cout«vec[i]«endl;

}
return 0;
