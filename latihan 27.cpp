#include <iostream>
#include <string>

using namespace std;
int main(){
	string str1="STMIK";
	string str2="PENUSA";
	
	//concatenation
	string result =str1+" "+str2;
	cout <<"concatenated:"<<result<<std::endl;
  	
	//length
	size_t length=result.length();
	cout<<"length:"<<length<<endl;

	//substring
	string sub=result.substr(6,6);
	cout<<"substring:"<<sub<<endl;

	//find
	size_t pos=result.find("PENUSA");
	cout<<"position of'PENUSA':"<<pos<<endl;
	
	//replace
	result.replace(0,5,"HI");
	cout<<"replaced:"<<result<<endl;

	return 0;
	
	
	
}
