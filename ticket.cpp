#include <iostream>
using namespace std;

class Node {
public:
    int seat;
    Node* prev;
    Node* next;

    Node(int s) {
        seat = s;
        prev = NULL;
        next = NULL;
    }
};

class Cinemax {
    Node* head[10]; 

public:
    Cinemax() { 
        for (int i = 0; i < 10; i++) { 
            head[i] = NULL;
            Node* last = NULL;
            for (int j = 1; j <= 7; j++) { 
                Node* newnode = new Node(j);
                if (head[i] == NULL)
                    head[i] = newnode;
                else {
                    last->next = newnode;
                    newnode->prev = last;
                }
                last = newnode;
            }
        }
    }

    void display() {
        cout << "\nAvailable seats:\n";
        for (int i = 0; i < 10; i++) {
            cout << "Row " << i + 1 << ": ";
            Node* temp = head[i];
            if (temp == NULL)
                cout << "No seats available";
            else {
                while (temp != NULL) {
                    cout << temp->seat << " ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
    void bookSeat() {
        int row, seat;
        cout << "Enter row (1-10): ";
        cin >> row;
        cout << "Enter seat no (1-7): ";
        cin >> seat;
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid row or seat number.\n";
            return;
        }
        Node* temp = head[row - 1];
        while (temp != NULL && temp->seat != seat)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Seat already booked or invalid.\n";
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head[row - 1] = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Seat booked successfully!\n";
    }
};

int main() {
    Cinemax c;
    int choice;

    do {
        cout << "\n---- CINEMAX TICKET BOOKING ----\n";
        cout << "1. Show available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            c.display();
            break;
        case 2:
            c.bookSeat();
            break;
        case 3:
            cout << "Thank you for using Cinemax system!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
