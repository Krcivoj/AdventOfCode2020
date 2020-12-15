#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<utility>
#include<stdlib.h>

using namespace std;

vector<pair<char,int>> load(string input){
    vector<pair<char,int>> v;
    fstream f(input);
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return v;
    }
    char c;
    int n;
    while(f>>c){
        f>>n;
        v.push_back(pair(c,n));
    }
    return v;
}

int task1(vector<pair<char,int>> v){
    int x=0, y=0, z=0;
    for(auto p: v){
        if(p.first=='L')z=(z+4-p.second/90)%4;
        if(p.first=='R')z=(z+p.second/90)%4;

        if(p.first=='F'){
            if(z==0)p.first='E';
            else if(z==1)p.first='S';
            else if(z==2)p.first='W';
            else if(z==3)p.first='N';
        }

        if(p.first=='N')x+=p.second;
        if(p.first=='S')x-=p.second;
        if(p.first=='E')y+=p.second;
        if(p.first=='W')y-=p.second;
    }
    return abs(x)+abs(y);
}

int task2(vector<pair<char,int>> v){
    int wx=1, wy=10, z=0, sx=0, sy=0;
    for(auto p: v){
        if(p.first=='L')z=(z+4-p.second/90)%4;
        if(p.first=='R')z=(z+(p.second/90))%4;

        if(z==1){
            swap(wx,wy);
            wx=-wx;
        }
        if(z==2){
            wx=-wx;
            wy=-wy;
        }
        if(z==3){
            swap(wx,wy);
            wy=-wy;
        }
        z=0;

        if(p.first=='F'){
            sx+=wx*p.second;
            sy+=wy*p.second;
        }

        if(p.first=='N')wx+=p.second;
        if(p.first=='S')wx-=p.second;
        if(p.first=='E')wy+=p.second;
        if(p.first=='W')wy-=p.second;
    }
    return abs(sx)+abs(sy);
}

int main(){
    string test="../../Day12Test.txt";
    string input="../../Day12Input.txt";
    vector<pair<char,int>> t=load(test);
    vector<pair<char,int>> i=load(input);
    cout<<"task1 test ";
    if(task1(t)==25){
        cout<<"OK \nTask1= ";
        int a= task1(i);
        cout<<a<<endl<<endl;
    }
    else cout<<"NO  value= "<<task1(t)<<endl;

    cout<<"Task2 test ";
    if(task2(t)==286){
        cout<<"OK \nTask2= ";
        int a= task2(i);
        cout<<a<<endl;
    }
    else cout<<"NO  value= "<<task2(t)<<endl;
    return 0;
}