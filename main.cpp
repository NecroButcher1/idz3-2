#include <iostream>
#include <cstdlib>
#include "queue.h"
#include "merge.h"
using namespace std;
void menu();
int main()
{
    queue<int> current;
    int check(0),value;
    while(check!=5){
        menu();
        cin>>check;
        while((!cin)||(check<1)||(check>5)){
            system("cls");
            cin.clear();
            cin.ignore(32767,'\n');
            menu();
            cin>>check;
        }
        if(check==1){
            system("cls");
            current.doEmpty();
            int size(0);
            cout<<"press size :";
            cin>>size;
            while((!cin)||(size<1)){
                system("cls");
                cin.clear();
                cin.ignore(32767,'\n');
                cout<<"press size :";
                cin>>size;
            }
            for(size_t i=0;i<size;i++){
                system("cls");
                cout<<"press"<<i<<" :";
                cin>>value;
                while(!cin){
                    system("cls");
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"press"<<i<<" :";
                    cin>>value;
                }
                current.push(value);
            }
            check=0;
        }
        if(check==2){
            system("cls");
            current.doEmpty();
            int size(0);
            cout<<"press size :";
            cin>>size;
            while((!cin)||(size<1)){
                system("cls");
                cin.clear();
                cin.ignore(32767,'\n');
                cout<<"press size :";
                cin>>size;
            }
            for(size_t i=0;i<size;i++){
                value=rand()%200-100;
                current.push(value);
            }
            check=0;
        }
        if(check==3){
            system("cls");
            if(current.empty())cout<<"queue is empty"<<endl;
            else{
                queue<int> buff(current);
                while(!buff.empty()){
                    buff.pop(value);
                    cout<<value<<" ";
                }
                cout<<endl;
            }
            check=0;
        }
        if(check==4){
            unsigned out=merge(current);
            if(out==1)cout<<"queue is empty"<<endl;
            else cout<<"sort"<<endl;
            check=0;
        }
    }
    return 0;
}
void menu(){
    cout<<"1.fill from keyboard"<<endl<<"2.fill random"<<endl<<"3.see queue"<<endl<<"4.merge"<<endl<<"5.exit"<<endl;
}
