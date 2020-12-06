#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>

using namespace std;


vector<vector<string>> load(string input){
    ifstream f(input);
    vector<string> v;
    vector<vector<string>> vv;
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return vv;
    }
    string s;
    while(!f.eof()){
        getline(f,s);
        if(s.empty()){
            vv.push_back(v);
            v.clear();
        }
        else v.push_back(s);
    }
    vv.push_back(v);
    return vv;
}

int task1(vector<vector<string>>vv){
    set<char> sc;
    int cnt=0;
    for(auto v: vv){
        sc.clear();
        for(auto s: v){
            for(char c: s){
                sc.insert(c);
            }
        }
        cnt+=sc.size();
    }
    return cnt;
}

int task2(vector<vector<string>>vv){
    set<char> sc;
    int cnt=0;
    for(auto v: vv){   
        string first=v[0];
        for(char c: first){
            bool flag=true;
            for(auto s: v){
                if(s.find(c)==string::npos){
                    flag=false;
                    break;
                }  
            }
            if(flag)cnt++;
        }
    }
    return cnt;
}


int main(){
    string input="../../Day6Input.txt";
    vector<vector<string>>v=load(input);
    int a= task1(v);
    cout<<"Task1= "<<a<<endl;
    int b= task2(v);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}