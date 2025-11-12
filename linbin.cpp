#include<iostream>
using namespace std;

int linearsearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarysearch(int arr[], int n, int key){
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int choice;
    int key, n;

    cout << "Enter the number who attended training: ";
    cin >> n;

    int roll[n];
    cout << "Enter roll numbers:\n";
    for(int i = 0; i < n; i++)
        cin >> roll[i];

    do {
        cout << "\n---- MENU ----";
        cout << "\n1. Linear Search (random order)";
        cout << "\n2. Binary Search (sorted order)";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){

        case 1: {
            cout << "Enter roll number to search: ";
            cin >> key;
            int pos = linearsearch(roll, n, key);
            if(pos != -1)
                cout << "Student with roll no " << key << " attended training\n";
            else
                cout << "Student with roll no " << key << " DID NOT attend training\n";
            break;
        }
        case 2: {
            
            for(int i = 0; i < n - 1; i++){
                for(int j = 0; j < n - i - 1; j++){
                    if(roll[j] > roll[j + 1]){
                        int temp = roll[j];
                        roll[j] = roll[j + 1];
                        roll[j + 1] = temp;
                    }
                }
            }

            cout << "Sorted roll numbers: ";
            for(int i = 0; i < n; i++)
                cout << roll[i] << " ";
            cout << "\nEnter roll number to search: ";
            cin >> key;
            int pos = binarysearch(roll, n, key);
            if(pos != -1)
                cout << "Student with roll no " << key << " attended training\n";
            else
                cout << "Student with roll no " << key << " DID NOT attend training\n";
            break;
        }
        case 3:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice";
        }
    } while(choice != 3);

    return 0;
}
