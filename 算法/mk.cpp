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
        r[a] = 0;  //��ʼ��
  
    for(int i = 1; i <= n; ++i)//��ģ����Ϊi  
    {  
        int q = INT_MIN;  
        for(int j = 1; j <= i; ++j)//�����ģΪi���������  
        {  
            if(q < (price[j] + r[i-j]))//��Ϊi>i-j�����Ե�����r[i]ʱ��r[i-j]�Ѿ����������ֱ����  
                q = (price[j] + r[i-j]);  //����q��
        }  
        r[i] = q;  //�ҳ�i���λ�õ����Ž⣻
    }  
    cout<<r[n];  //�����n���λ�ã�����n�׳���ľͷ������ֵ��

}