#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ifstream file ("data.txt");
	string line;
	if(file.is_open()){
		while(getline(file,line)){
		cout<<line<<endl;
	}
	file.close();
	}else{
		cout<<"file tidak bisa dibuka";
	}
	return 0;	
}

