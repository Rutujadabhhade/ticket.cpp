#include<iostream>
using namespace std;

#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void addJob(int job) {
    if(rear == SIZE - 1) {
        cout << "Queue is full\n";
        return;
    }

    if(front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = job;
    cout << "Job added: " << job << endl;
}

void deleteJob() {
    if(front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Deleted job: " << queue[front] << endl;
    front++;
}

void displayJob() {
    if(front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Jobs in queue: ";
    for(int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, job;

    do {
        cout << "\n1. Add job\n";
        cout << "2. Delete job\n";
        cout << "3. Display jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter job number: ";
                cin >> job;
                addJob(job);
                break;

            case 2:
                deleteJob();
                break;

            case 3:
                displayJob();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 4);

    return 0;
}
