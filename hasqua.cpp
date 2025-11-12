#include <iostream>
using namespace std;

#define SIZE 10

long phone[SIZE];
string name[SIZE];

int hashFunc(long k) {
    return k % SIZE;
}

void insertData(string n, long p) {
    int i = hashFunc(p), j = 0;
    while (phone[(i + j * j) % SIZE] != 0)
        j++;
    int pos = (i + j * j) % SIZE;
    phone[pos] = p;
    name[pos] = n;
    cout << "Inserted at " << pos << endl;
}

void searchData(long p) {
    int i = hashFunc(p), j = 0;
    while (phone[(i + j * j) % SIZE] != 0) {
        int pos = (i + j * j) % SIZE;
        if (phone[pos] == p) {
            cout << "Found: " << name[pos] << " - " << phone[pos] << endl;
            return;
        }
        j++;
        if (j == SIZE) break;
    }
    cout << "Not found\n";
}

void display() {
    cout << "\nIndex\tName\tPhone\n";
    for (int i = 0; i < SIZE; i++) {
        if (phone[i] != 0)
            cout << i << "\t" << name[i] << "\t" << phone[i] << endl;
        else
            cout << i << "\t---\t---\n";
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) phone[i] = 0;
    int ch; string n; long p;

    do {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter name and phone: ";
            cin >> n >> p;
            insertData(n, p);
        }
        else if (ch == 2) {
            cout << "Enter phone: ";
            cin >> p;
            searchData(p);
        }
        else if (ch == 3)
            display();
    } while (ch != 4);

    return 0;
}
