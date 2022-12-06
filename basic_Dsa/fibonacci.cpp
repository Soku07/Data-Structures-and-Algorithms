// #include<iostream>
// using namespace std;
// int fibonacci(int);
// int main()
// {   int num;
//     cout<<"Enter a number : ";
//     cin>>num;
//     cout<<"The value of at "<<num<<" is : "<<fibonacci(num);
//     return 0;
// }

// int fibonacci(int n)
// {
//     if(n<2)
//     {
//         return 1;
//     }
//     return fibonacci(n-2) + fibonacci(n-1);
// }

// fibonacci without recurssion - 
#include<iostream>
using namespace std;
int main()
{
    int first_num = 1, second_num = 1,num, sum;
    cout<<"Enter a number : ";
    cin>>num;
    for(int i = 2;i < num; i++)
    {
        sum = first_num + second_num;
        first_num = second_num;
        second_num = sum;   
    }
    cout<<"The value at "<<num<<" is : "<<sum;
    return 0;

}