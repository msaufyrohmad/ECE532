#include<iostream>
using namespace std;
int arr[10]={10,20,30,40,50,60,70,80,90,100};
int largest=arr[0];

int large(int arr[],int size)
{
    if(arr[size]>largest)
        largest=arr[size];
    if(size==9)
        return largest;
    else
        large(arr,size+1);
}

void print(int arr[],int loc)
{
    cout<<arr[loc]<<" "<<endl;
    if(loc == 10)
        return;
    else
        print(arr,loc+1);
}

int fac(int n)
{
    if(n<=1)return 1;
    else return n*fac(n-1);
}

int gcd(int x,int y)
{
    if(x%y==0)
        return y;
    else
    {
        x=gcd(y,x%y);
        return x;
    }
}

int fib(int n)
{
    if(n<=1)return n;
    else return fib(n-1)+fib(n-2);
}

int arraysum(int arr[],int loc)
{
    if(loc==9)
        return arr[9];
    else
        return arr[loc]+arraysum(arr,loc+1);
}

int main()
{
    int arr[10]={10,20,30,40,50,60,70,80,90,100};
    cout<<"recursive functions"<<endl;
    cout<<"1 for print 0-10"<<endl;
    cout<<"2 for factorial "<<endl;
    cout<<"3 for gcd "<<endl;
    cout<<"4 for fibonacci series"<<endl;
    cout<<"5 for array sum "<<endl;
    cout<<"6 for find largest "<<endl;
    int sel;
    cin>>sel;
    cout<<"sel "<<sel<<endl;
   switch (sel)
    {
        case 1:
                print(arr,0);
                break;
        case 2:
                cout<<fac(5)<<endl;
                break;
        case 3:
                cout<<gcd(32,24)<<endl;
                break;
        case 4:
                cout<<fib(6)<<endl;
                break;
        case 5:
                cout<<arraysum(arr,0)<<endl;
                break;
        case 6:
                cout<<large(arr,1)<<endl;
                break;
        default:
                cout<<"Not in selection"<<endl;
                break;
    }


}
