#include <iostream>
using namespace std;

#define SIZE 10

long phone[SIZE];
string name[SIZE];

int h1(long k) { return k % SIZE; }
int h2(long k) { return 7 - (k % 7); }

void insertData(string n, long p) {
    int i = h1(p);
    int step = h2(p);
    while (phone[i] != 0)
        i = (i + step) % SIZE;
    phone[i] = p;
    name[i] = n;
    cout << "Inserted at " << i << endl;
}

void searchData(long p) {
    int i = h1(p), step = h2(p), start = i;
    while (phone[i] != 0) {
        if (phone[i] == p) {
            cout << "Found: " << name[i] << " - " << phone[i] << endl;
            return;
        }
        i = (i + step) % SIZE;
        if (i == start) break;
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
