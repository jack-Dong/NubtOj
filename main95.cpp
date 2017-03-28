#include <iostream>
#include <string> 
#include <vector> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <bitset>

#define Debug 0 

using namespace std;

int main() 
{
	if( Debug )
	{
		freopen("95in.txt","r",stdin); 
	}
	
	int caseN;
	cin >> caseN;
	for( int i = 0; i < caseN; ++i)
	{
		unsigned int num;
		cin >> num;
		bitset<32> b(num);
		string bits = b.to_string();
		//去掉前面的0
	
		int  index =  bits.find('1');
		string rt;
		rt.insert(0,bits,index,bits.size() - index );
		cout << rt <<endl;
	}
	
	return 0;
}
