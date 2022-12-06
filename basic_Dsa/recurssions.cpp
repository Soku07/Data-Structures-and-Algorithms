#include<iostream>
using namespace std;
int factorial(long int n)

{   static int i = 1;
     if(0<=n<=1 )
    {   cout<<"In this f for one last time!!"<<i<<endl;
        i +=1;
        return 1;
    }
    cout<<"idhar mai "<<i<<" bar aya hu"<<endl;
    i +=1;
    return n * factorial(n-1);

}
int main()
{   
    int n;
    cout<<"Enter n : "<<endl;
    cin>>n;
    cout<<"Factorial of "<<n<<" is :"<<factorial(n)<<endl;;
    return 0;
}