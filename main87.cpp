#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std; 

//字符串切割 
vector<string> split(string src, string ch)
{
    vector<string> rt;
    size_t last = 0;
    size_t index = src.find_first_of(ch,last);
    while(index != string::npos)
    {
        rt.push_back( src.substr(last,index - last) );
        last = index + 1;
        index = src.find_first_of(ch,last);
    }
    //没找到就把全部字符串放进去
    if(index - last > 0)
    {
        rt.push_back(src.substr(last,index-last));
    }

    return rt;
}

//判断是否是闰年
bool jugleLeapYear(int year)
{
	if( year % 100 == 0 )//整百年 
	{
		if( year % 400 == 0 )
		{
			return true;
		}
	}else//非整百年 
	{
		if( year % 4 == 0 )
		{
			return true;
		}
	}
	return false;
} 

int main() 
{
	int caseN;
	int days[2][12] = {31,28,31,30,31,30,31,31,30,31,30,31,
					   31,29,31,30,31,30,31,31,30,31,30,31,};
	vector<int> rts;
	string temp;
	cin >> caseN;
	for( int i = 0; i < caseN; ++i)
	{
		cin>>temp;
		//解析成整数
		vector<string> strTemp = split(temp,":");
		int year = atoi( strTemp[0].c_str() );
		int month = atoi( strTemp[1].c_str() );
		int day = atoi( strTemp[2].c_str() );
	    //cout << year <<" "<<month <<" "<<day<<endl;
	    
	    //判断是否是闰年 
	    bool isLeapYear = jugleLeapYear(year);
	    int sum = 0;
	    for(int j = 0;j < month - 1; ++j)
	    {
	    	sum += days[isLeapYear][j];
		}
		sum+=day;
		rts.push_back(sum);
	}
	
	//输出答案 
	for(int i= 0; i < rts.size();++i)
	{
		cout<<rts[i]<<endl;
	}
	
	return 0;
}
