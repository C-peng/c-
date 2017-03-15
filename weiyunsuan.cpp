/*世界上有10种人，一种懂二进制，一种不懂。那么你知道两个int32整数m和n的二进制表达，有多少个位(bit)不同么？  
输入例子: 
1999 2299 
 
输出例子: 
7 
*/  
#include<stdio.h>  
int countBitDiff(int m, int n)   
{  
    int data=1;  
    int a,b;  
    int count=0;  
    for(int i=0;i<31;i++)  
    {  
        a=m&data;  //进行与操作得到最后一位
        b=n&data;  
        if(a!=b)  
        {  
            count++;             
        }  
        m=m>>1;  //进行移位操作  向左移一位  只要移31次
        n=n>>1;  
    }  
  return count;   
}  
void main()  
{  
    printf("-->%d\n",countBitDiff(1999,2299));  
}  
