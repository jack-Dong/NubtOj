#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int caseN;
	cin>>caseN; //�õ������������� 
	vector<int> nums;
	vector<int> rtTemp;
	vector< vector<int> > rt;
	int numN;
	int temp;
	for(int i = 0; i < caseN;i++)
	{
		cin>>numN;//�õ����������������� 
		for(int j = 0; j < numN;j++)
		{
			cin>>temp;
			nums.push_back(temp);
		}
		
		//��ð�������ֵ
		int max = nums[0]; 
		for(int k = 1; k < nums.size();k++)
		{
			if( nums[k] > max )
			{
				max = nums[k];
			}			
		}
		rtTemp.push_back(max);
		//��ð��������ֵ
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
	//����� 
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

