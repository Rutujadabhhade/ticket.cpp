#include<iostream>
using namespace std;
#define SIZE 10

long phone[SIZE];
string name[SIZE];

int hashfun(long num){
    return num % SIZE;
}
void insertdata(string n,long p){
    int i=hashfun(p);
    while(phone[i]!=0)
    i=(i+1)%SIZE;
    name[i]=n;
    phone[i]=p;
}
void searchdata(long p){
    int i=hashfun(p);
    int start=i;
    while(phone[i]!=0){
        if(phone[i]==p){
            cout<<"found:"<<name[i]<<"-"<<phone[i]<<endl;
            return;
        }
        i=(i+1)%SIZE;
        if(i==start)
        break;
    }
    cout<<"not found\n";
}
void display(){
    cout<<"\n.name\n.phone";
    for(int i=0;i<SIZE;i++){
    if(phone[i]!=0)
    cout<<i<<"\t"<<name[i]<<"\t"<<phone[i]<<endl;
    else
    cout<<i<<"\t--\t--\n";
}
}
int main(){
    int ch;
    string n;
    long p;

    for(int i=0;i<SIZE;i++)
    phone[i]=0;
    do{
        cout<<"\n1.insert\n2.search\n3.display\n.4exit\n.enter choice";
        cin>>ch;
        if(ch==1){
            cout<<"enter name and phone";
            cin>>p>>n;
            insertdata(n,p);
        }
        else if(ch==2){
            cout<<"enter the phone";
            cin>>p;
            searchdata(p);
        }
        else if(ch==3)
            display();

        } while(ch!=4);
        return 0;
        }
        

