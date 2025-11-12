#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node* next;
    Node(int p, string n) {
        prn = p;
        name = n;
        next = NULL;
    }
};

class PinnacleClub {
    Node* head;
public:
    PinnacleClub() {
        head = NULL;
    }

    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
        cout << "President added.\n";
    }

    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == NULL) {
            head = newNode;
            cout << "Secretary added as first member.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        cout << "Secretary added.\n";
    }

    void addMember(int prn, string name) {
        if (head == NULL) {
            cout << "Add President first!\n";
            return;
        }
        Node* newNode = new Node(prn, name);
        Node* temp = head;
        while (temp->next != NULL && temp->next->next != NULL)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Member added.\n";
    }

    void deleteMember(int prn) {
        if (head == NULL) {
            cout << "No members to delete.\n";
            return;
        }

        if (head->prn == prn) {
            cout << "President cannot be deleted directly.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Member not found.\n";
            return;
        }

        if (temp->next == NULL) {
            cout << "Secretary cannot be deleted directly.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Member deleted.\n";
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "No members in club.\n";
            return;
        }
        cout << "\n--- Pinnacle Club Members ---\n";
        cout << "PRN\tName\n";
        while (temp != NULL) {
            cout << temp->prn << "\t" << temp->name << endl;
            temp = temp->next;
        }
    }

    void countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "\nTotal members in club: " << count << endl;
    }
};

int main() {
    PinnacleClub club;
    int choice, prn;
    string name;

    do {
        cout << "\n1. Add President";
        cout << "\n2. Add Member";
        cout << "\n3. Add Secretary";
        cout << "\n4. Display Members";
        cout << "\n5. Count Members";
        cout << "\n6. Delete Member";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN and Name of President: ";
            cin >> prn >> name;
            club.addPresident(prn, name);
            break;
        case 2:
            cout << "Enter PRN and Name of Member: ";
            cin >> prn >> name;
            club.addMember(prn, name);
            break;
        case 3:
            cout << "Enter PRN and Name of Secretary: ";
            cin >> prn >> name;
            club.addSecretary(prn, name);
            break;
        case 4:
            club.display();
            break;
        case 5:
            club.countMembers();
            break;
        case 6:
            cout << "Enter PRN of member to delete: ";
            cin >> prn;
            club.deleteMember(prn);
            break;
        case 7:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
