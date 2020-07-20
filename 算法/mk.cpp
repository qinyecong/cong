#include <iostream>  
#include <cstring>  
using namespace std;  
  
int main()  
{  
    int n;  
    cin>>n;  
    int price[10]={0,5,10,15,20,25,30,35,40,45};  
    int *r=new int [n+1]; 
  
    for(int a = 0; a<= n; ++a)  
        r[a] = 0;  //初始化
  
    for(int i = 1; i <= n; ++i)//规模长度为i  
    {  
        int q = INT_MIN;  
        for(int j = 1; j <= i; ++j)//计算规模为i的最大收益  
        {  
            if(q < (price[j] + r[i-j]))//因为i>i-j，所以当计算r[i]时，r[i-j]已经解决，可以直接用  
                q = (price[j] + r[i-j]);  //迭代q；
        }  
        r[i] = q;  //找出i这个位置的最优解；
    }  
    cout<<r[n];  //最后是n这个位置，就是n米长的木头的最大价值。

}