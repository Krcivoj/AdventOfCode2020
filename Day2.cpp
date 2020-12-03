#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int find_all(string s, char a){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==a)cnt++;
    }
    return cnt;
}

int task1(string input){
    ifstream f(input);
    char x;
    string s;
    int min, max, i,cnt=0;
    while(f>>min){
        f.ignore();
        f>>max;
        f.ignore();
        f>>x;
        f.ignore(2);
        f>>s;
        i=find_all(s,x);
        if(min<=i && i<=max)cnt++;
    }
    return cnt;
}

int task2(string input){
    ifstream f(input);
    char x;
    string s;
    int min, max, cnt=0;
    while(f>>min){
        f.ignore();
        f>>max;
        f.ignore();
        f>>x;
        f.ignore(2);
        f>>s;
        if(s[min-1]==x){
            if(s[max-1]!=x)cnt++;
        }
        else if(s[max-1]==x)cnt++;
    }
    return cnt;
}

int main(){
    int a=task1("Day2Input.txt");
    cout<<"Task1= "<<a<<endl;
    int b=task2("Day2Input.txt");
    cout<<"\nTask2= "<<b<<endl;

return 0;
}
