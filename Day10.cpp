#include<iostream>
#include<fstream>
#include<set>
#include<string>

using namespace std;

set<int> load(string input){
    fstream f(input);
    set<int> s;
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return s;
    }
    int x;
    while (f>>x)
    {
        s.insert(x);
    }
    return s;
}

int task1(set<int> s){
    s.insert(*(--s.end())+3);//add device's built-in adapter
    int n1=0,n2=0,n3=0;
    int temp=0;
    for(int x: s){
        if(x-temp==1)n1++;
        else if(x-temp==2)n2++;
        else if(x-temp==3)n3++;
        else break;
        temp=x;
    }
    return n1*n3;
}

void ways(set<int>& s, set<int>::iterator it, int b, int& cnt){
    if(it==s.end())return;
    if((*it)-b>3)return;
    b=*it;
    if(++it==s.end()){
        cnt++;
        return;
    }
    ways(s, it, b, cnt);
    if(it==s.end())return;
    ways(s, ++it, b, cnt);
    if(it==s.end())return;
    ways(s, ++it, b, cnt);
}

long long int task2(set<int> s){
    s.insert(0);//charging outle
    set<int> temp;
    int prev=0;
    long long int cnt=1;
    for(int x: s){
        if(x-prev==3){
            int num=0;
            ways(temp,temp.begin(),*temp.begin(),num);
            if(num)cnt*=num;
            temp.clear();
        }
        temp.insert(x);
        prev=x;
    }
    int num=0;
    ways(temp,temp.begin(),*temp.begin(),num);
    if(num)cnt*=num;
    return cnt;

}

int main(){
    //string input="../../Day10Test.txt";
    string input="../../Day10Input.txt";
    set<int> s=load(input);
    int a= task1(s);
    cout<<"Task1= "<<a<<endl;
    long long int b= task2(s);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}