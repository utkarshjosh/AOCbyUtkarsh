//.............Utkarsh-Codes.................

#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<int> v){
	if(v.size()==0)return false;
	if(v.size()<2) return true;
	 bool isPositive = (v[1]-v[0])>0;
	for(int i=1;i<v.size();i++){
		int g = v[i]-v[i-1];
		if(abs(g)==0 || abs(g)>3)return false;
		if((isPositive && g<0) || (!isPositive && g>0))return false; 
		
	}cout<<"safe"<<endl;
	return true;
}
bool isSafe2(vector<int> v){
	if(v.size()==0)return false;
	if(v.size()<2) return true;
	for(int i=0;i<v.size();i++){
		vector<int> remain = v;
		 remain.erase(remain.begin() + i);
		 if (isSafe(remain)) {
            return true; // Safe after removing this level
        }
	}
	return false;
}
	

int main(){
	int safeCount = 0;
	int safeCount2 =0;
	int notSafe= 0;
	int notSafe2= 0;

	ifstream myfile;
	myfile.open("inputs/day2.txt");
	if (myfile.is_open())
	{
  		string line;
    	while (!myfile.eof())
    	{
    		getline(myfile, line);
    		vector<int> v1;
	 		stringstream ins(line);
	 		int i;
	 		
	 		while ( ins >> i )
			{	v1.push_back(i);	}
			if(isSafe(v1))
				{
					
					safeCount ++;
					safeCount2++;

				}
			else{
				for(int a: v1)cout<<a<<" ";
					cout<<endl;
				notSafe++;
				if(isSafe2(v1)){
					safeCount2++;
				}
				else{
					notSafe2++;
				}
			}
			

		}
   }
   cout<<" safeCount"<< safeCount<<endl;
   cout<<" notSafe"<<notSafe<<endl;
      cout<<" safeCount2--"<< safeCount2<<endl;
   cout<<" notSafe2--"<<notSafe2<<endl;
	return 0;
}
