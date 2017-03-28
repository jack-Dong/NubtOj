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
		freopen("96in.txt","r",stdin); 
	}
	
	int caseN;
	cin >> caseN;
	for( int i = 0; i < caseN; ++i)
	{
		int sz,k;
		cin >> sz >> k;
		vector<unsigned long> mT(sz,0);
		vector<	vector<unsigned long> > A(sz,mT);
		vector<vector<unsigned long> > B(sz,mT);
		vector<vector<unsigned long> > rt(sz,mT);
		
		//读入矩阵
		for(int m = 0; m < sz; ++m )
		{
			for(int n = 0; n < sz; ++n)
			{
				int d;
				cin >> d;
				A[m][n] = d;
				B[m][n] = d;
			   rt[m][n] = d;				
			}	
		}
		
		//矩阵相乘
		for(int j = 0; j < k - 1; ++j) //考虑 一次幂的情况 
		{
			for( int m = 0; m < sz;++m)
			{
				for(int n = 0; n < sz; ++n)
				{
					int sum = 0;
					for(int c = 0; c < sz; ++c)
					{
						sum += A[m][c] * B[c][n];
					}
					rt[m][n] = sum;  
				}
			}
			//乘法循环  把rt 复制给  A
			for( int m = 0; m < sz;++m)
			{
				for(int n = 0; n < sz; ++n)
				{
					A[m][n] = rt[m][n];  
				}
			}		 
			
		}		
		//输出矩阵
		for( int m = 0; m < sz; ++m )
		{
			for(int n = 0; n < sz; ++n)
			{
				cout << rt[m][n];
				if( n != sz - 1 )
				{
					cout <<" ";	
				}	
			}
			cout << endl;	
		} 
	}
	return 0;
}
