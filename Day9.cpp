#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
 

vector<long int> load(string input){
    fstream f(input);
    vector<long int> v;
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return v;
    }
    long int x;
    while (f>>x)
    {
        v.push_back(x);
    }
    return v;
}

bool valid(vector<long int> v, int preamble,int n){
    for(int i=n-preamble; i<n; i++){
        for(int j=i+1; j<n;j++){
            if(v[i]+v[j]==v[n])return true; 
        }
    }
    return false;
}

long int task1(vector<long int> v, int preamble){
    for(int i=preamble; i<v.size(); i++){
        if(!valid(v,preamble,i))return v[i];
    }
    return -1;
}

long int subsum(vector<long int> v, int i, int j){
    long int x=0;
    while(i<=j){
        x+=v[i];
        i++;
    }
    return x;
}

long int task2(vector<long int> v, long int x){
    int i,j;
    for(i=0;i<v.size();i++){
        for( j=i+1;j<v.size();j++){
            if(subsum(v,i,j)==x)break;;
        }
        if(j<v.size())break;
    }
    long int m=v[i],M=v[j];
    while(i<=j){
        if(v[i]<m)m=v[i];
        if(v[i]>M)M=v[i];
        i++;
    }
    return m+M;
}

int main(){
    //string input="../../Day9Test.txt";
    string input="../../Day9Input.txt";
    vector<long int> v=load(input);
    long int a= task1(v,25);
    cout<<"Task1= "<<a<<endl;
    long int b= task2(v,a);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}