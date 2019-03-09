#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		string hex,bin,oct;
		cin>>hex;
		for(int i=0;i<hex.length();i++){
			switch(hex[i]){
				case '0':bin+="0000";break;
				case '1':bin+="0001";break;
				case '2':bin+="0010";break;
				case '3':bin+="0011";break;
				case '4':bin+="0100";break;
				case '5':bin+="0101";break;
				case '6':bin+="0110";break;
				case '7':bin+="0111";break;
				case '8':bin+="1000";break;
				case '9':bin+="1001";break;
				case 'A':bin+="1010";break;
				case 'B':bin+="1011";break;
				case 'C':bin+="1100";break;
				case 'D':bin+="1101";break;
				case 'E':bin+="1110";break;
				case 'F':bin+="1111";break;
			}
		}
		int ct=0,l=bin.length();
		while(bin[ct]=='0'){
			bin=bin.substr(1,l-1);
			l=bin.length();
		}
		int flag=0;
		string s;
		for(int i=0;i<l;){
			if(flag==0&&l%3!=0){
				s=bin.substr(i,l%3);
				flag=1;
				i+=l%3;
			}else{
				s=bin.substr(i,3);
				i+=3;
			}
			int temp=0,op=1;
			for(int i=s.length()-1;i>=0;i--){
				temp+=(s[i]=='0'?0:1)*op;
				op*=2;
			}
			switch(temp){
				case 0:oct+="0";break;
				case 1:oct+="1";break;
				case 2:oct+="2";break;
				case 3:oct+="3";break;
				case 4:oct+="4";break;
				case 5:oct+="5";break;
				case 6:oct+="6";break;
				case 7:oct+="7";break;
			}
		}
		cout<<oct<<endl;
	}		
	return 0;
}
