#include <iostream>
#include <vector>
#include <map>
#include <math.h>

#define BIT_SUM 64

using namespace std;


int main() 
{
	int caseN;
	int numN; //ÿ������������������� 
	long long temp;	 //Ҫ������Χ  
	long long rest = 0;
	vector<long long> bitCount(BIT_SUM); 
	vector<long long> rts;
	vector<vector<long long>> res
	long long rt;	
	while( cin>>numN )  //EOF ���� ctr + z
	{		
		for(int i = 0; i < numN;i++)
		{ 
			cin>>temp;
		}	
		//bitCount�����õ����ִ���Ϊһ������
		rt = 0;	
		for(int k = 0; k < bitCount.size(); ++k)
		{
			if( bitCount[k] % 3 == 1)
			{
				rt = rt + pow(2,k);
			}
			//�������0
			bitCount[k] = 0; 
		}
		rts.push_back(rt);	 		 		
	}
	
	for(int i = 0; i < rts.size(); ++i)
	{
		cout <<rts[i] <<endl;
	}
}
