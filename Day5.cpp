#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<iterator>

using namespace std;

vector<string> load(string input){
    ifstream f(input);
    vector<string> v;
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return v;
    }
    string s;
    while(f>>s){
        v.push_back(s);
    }
    return v;
}

int seatId(string s){
    int lr=0, ur=127;
    for(int i=0;i<7;i++){
        if(s[i]=='F')ur=(lr+ur)/2;
        if(s[i]=='B')lr=(lr+ur)/2+1;
    }
    int lc=0, uc=7;
    for(int i=7;i<10;i++){
        if(s[i]=='L')uc=(lc+uc)/2;
        if(s[i]=='R')lc=(lc+uc)/2+1;
    }
    return 8*lr+lc;
}

int task1(vector<string> v){
    int max=-1,a;
    for(auto x: v){
        a=seatId(x);
        if(a>max)max=a;
    }
    return max;
}

int task2(vector<string> v){
    list<int> l;
    for(auto x: v)
        l.push_back(seatId(x));
    l.sort();
    list<int>::iterator it1,it2;
    for(it1=l.begin();it1!=l.end();it1++){
        it2=it1;
        advance(it2,1);
        if(*it1+2==*it2)return *it1+1;
    }
    return -1;
}

int main(){
    string input="../../Day5Input.txt";
    vector<string> v=load(input);
    int a= task1(v);
    cout<<"Task1= "<<a<<endl;
    int b= task2(v);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}