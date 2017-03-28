#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int caseN;
	cin>>caseN; //得到测试用例个数 
	vector<int> nums;
	vector<int> rtTemp;
	vector< vector<int> > rt;
	int numN;
	int temp;
	for(int i = 0; i < caseN;i++)
	{
		cin>>numN;//得到单个测试用例个数 
		for(int j = 0; j < numN;j++)
		{
			cin>>temp;
			nums.push_back(temp);
		}
		
		//用冒泡求最大值
		int max = nums[0]; 
		for(int k = 1; k < nums.size();k++)
		{
			if( nums[k] > max )
			{
				max = nums[k];
			}			
		}
		rtTemp.push_back(max);
		//用冒泡求次最大值
		int maxScend = nums[0];
		for(int k = 1; k < nums.size();k++)
		{
			if( nums[k] > maxScend && nums[k] != max )
			{
				maxScend = nums[k];
			}			
		}
		rtTemp.push_back(maxScend);
		rt.push_back(rtTemp);
		
		rtTemp.clear();
		nums.clear();
	}
	//输出答案 
	for(int i = 0; i < caseN;i++)
	{
		for(int j = 0; j < rt[0].size();j++)
		{
			cout<<rt[i][j];
			if(j != rt[0].size() - 1 )
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}	
}

