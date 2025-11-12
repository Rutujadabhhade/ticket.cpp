#include<iostream>
using namespace std;

void bubblesort(float arr[],int n){
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            float temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
}

void selectionsort(float arr[],int n){
for(int i=0;i<n-1;i++){
    int minindex=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minindex]){
            minindex=j;
        }
    }

            float temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
}
}

            void display(float arr[],int n){
            cout<<"five score:";
            int count=(n<5)?n:5;
            for(int i=n-1;i>=n-5 && i>=0;i--){
            cout<<arr[i]<<"%";
            }
            cout<<endl;
        }

            int main(){
                int n,choice;
                cout<<"enter no of the students";
                cin>>n;

                float percentage[n];
                cout<<"enter percentage of"<<n<<"students:\n";
                for(int i=0;i<n;i++){
                cin>>percentage[i];
            }
            cout<<"\n menu:\n1.sort using the bubble sort\n2.sort using the selction sort\n";
            cout<<"enter you choice";
            cin>>choice;
            switch(choice){
                case 1:
                bubblesort(percentage,n);
                cout<<"\nsorted percentage(bubble sort)";
                for(int i=0;i<n;i++){
                cout<<percentage[i]<<"";
                display(percentage,n);
                break;
                }
                case 2:
                selectionsort(percentage,n);
                cout<<"\nsorted percentage(selection sort)";
                for(int i=0;i<n;i++){
                cout<<percentage[i]<<"";
                display(percentage,n);
                break;
            
            }
                default:
                cout<<"invalid choice";
        }
        return 0;
    }

            
       