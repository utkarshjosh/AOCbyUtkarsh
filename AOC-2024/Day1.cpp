//.............Utkarsh-Codes.................

#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> list1,list2;

	 ifstream myfile;
   myfile.open("inputs/day1.txt");
  if (myfile.is_open())
  {
  	string line;
    while (!myfile.eof())
    {
    	getline(myfile, line);
	 	stringstream ins(line);
	 	int num1,num2;
	 	ins>>	num1>>num2;
	 	list1.push_back(num1);
	 	list2.push_back(num2);
    }
   }

   /// STARTS	
   sort(list1.begin(), list1.end());
   sort(list2.begin(),list2.end());
   long long ans = 0;
   for(int i=0;i<list1.size();i++){
   		ans += abs(list2[i]-list1[i]);
   }
   cout<<"Part1	distance sum -- >"<<ans<<endl;

   /// PART 2
   unordered_map<int,int> freq;
   for(int i : list2){
   	freq[i] ++;
   }
   long long ans2 =0;
   for(int i=0;i<list1.size();i++){
   	ans2 += list1[i]* freq[list1[i]];
   }
   cout<<"Ans Part2 ---> "<<ans2<<endl;
	return 0;
}					