#include<iostream>
#include <fstream>
#include<set>
#include<string>
#include <iterator>

using namespace std;

void task1(string input){
    multiset<int> s;
    ifstream f(input);
    int x;
    while(f>>x)
    {
        s.insert(x);
    }
    multiset<int>::iterator it;
    for(it=s.begin();it!=s.end();++it){
        if(s.find(2020-*it)!=s.end()){
            if((*it)+(2020-*it)==2020){
                cout<<"OK\n";
                cout<<*it<<'+'<<2020-*it<<'='<<(*it)+(2020-*it)<<endl;
                cout<<*it<<'*'<<2020-*it<<'='<<(*it)*(2020-*it);
                break;
            }
            else cout<<"NOT OK\n";
        }
    }
}

void task2(string input){
    multiset<int> s;
    ifstream f(input);
    int x;
    while(f>>x)
    {
        s.insert(x);
    }
    multiset<int>::iterator it1, it2;
    for(it1=s.begin();it1!=s.end();++it1){
            it2=it1;
        for( advance(it2,1);it2!=s.end();++it2){
            if(s.find(2020-((*it1)+(*it2)))!=s.end()){
               if((*it1)+(*it2)+(2020-((*it1)+(*it2)))==2020){
                    cout<<"OK\n";
                    cout<<*it1<<'+'<<*it2<<'+'<<2020-((*it1)+(*it2))<<'='<<(*it1)+(*it2)+(2020-((*it1)+(*it2)))<<endl;
                    cout<<*it1<<'*'<<*it2<<'*'<<2020-((*it1)+(*it2))<<'='<<(*it1)*(*it2)*(2020-((*it1)+(*it2)));
                    return;
               }
                else cout<<"NOT OK\n";
            }
        }
    }
}

int main(){
    string input="Day1Input.txt";
    task1(input);
    cout<<endl<<endl;
    task2(input);
    cout<<endl<<endl;
    return 0;
}
