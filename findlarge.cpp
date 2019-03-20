#include<iostream>
using namespace std;
int arr[10]={10,20,30,40,50,600,70,80,90,100};
int large=arr[0];

int findlarge(int arr[],int loc)
{
    if(arr[loc]>large)
    {
        large=arr[loc];
    }
    if(loc==9)
        return large;
    else
        findlarge(arr,loc+1);
}

int main()
{
    cout<<"findlarge = "<<findlarge(arr,1);
}
