#include <iostream>
#include <vector>
#include<bits/stdc++.h>
const int SIZE=256;
using namespace std;
struct DP
{
private:
    string name;
    int price;
    int profit;
public:
   DP(){}
   DP(string n,int p,int pro)
   {
       name=n;
       price=p;
       profit=pro;
   }
   string getName()
   {
       return name;
   }
   int getPrice()
   {
       return price;
   }
   int getProfit()
   {
       return profit;
   }
};
vector<struct DP>dp;
void AddToVector(struct DP d)
{
    dp.push_back(d);
}
bool compare(struct DP first,struct DP second)
{
    return (first.getPrice()<second.getPrice());
}
void sorts()
{
    sort(dp.begin(),dp.end(),compare);
}
void print()
{
    sorts();
    for(int i=0;i<dp.size();i++)
    {
        cout<<"name : "<<dp[i].getName()<<endl;
        cout<<"price : "<<dp[i].getPrice()<<endl;
        cout<<"profit : "<<dp[i].getProfit()<<endl;
    }
}


int add(int row,int col)
{
  int arr[row+1][col+1];
    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            if(i==0||j==0)
            {
                arr[i][j]=0;
            }
            else
            {
                if(j>=dp[i-1].getPrice())
                {
                    arr[i][j]=dp[i-1].getProfit();
                    if(j-dp[i-1].getPrice()>0)
                    {
                        arr[i][j]=dp[i-1].getProfit()+arr[i-1][j-dp[i-1].getPrice()];
                        arr[i][j]=max(arr[i][j],arr[i-1][j]);

                    }
                    if(j-dp[i-1].getPrice()==0)
                    {
                        arr[i][j]=max(arr[i-1][j],arr[i][j]);
                    }
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
    }
    //printArr(arr,row,col);
    return arr[row][col];
}

void printArr(int arr[][SIZE],int row,int col)
{
    for(int i=0;i<=col;i++)
    {
        cout<<i<<"  ";
    }
    cout<<endl;
    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    int number,price,profit;
    int p;
    string name;
    cout<<"enter the number of values you want to enter : ";
    cin>>number;
    for(int i=0;i<number;i++)
    {
        cout<<"Enter the name : ";
        cin>>name;
        cout<<"Enter the price : ";
        cin>>price;
        cout<<"Enter the profit : ";
        cin>>profit;
        struct DP p(name,price,profit);
        AddToVector(p);
    }
    cout<<"Enter your maximum money : ";
    cin>>p;
    cout<<"the value is : "<<add(dp.size(),p)<<endl;
    return 0;
}
