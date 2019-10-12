#include <iostream>
#include <string>
using namespace std;

struct Node
{
    Node *prev;
    string name;
    Node *next;
};

class Queue
{
    private:
        Node *head = nullptr;
        Node *tail = nullptr;

    public:
        Queue() { }

        Queue(string name)
        {
            head = tail = createNode(name);
        }

        Node* createNode(string name)
        {
            Node* newnode = new Node;
            newnode->prev = nullptr;
            newnode->name = name;
            newnode->next = nullptr;
        return newnode;
        }

        void enQueue(string name)
        {
            if(tail != nullptr)
            {
            Node* newnode = createNode(name);
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
            }
            else
                head = tail = createNode(name);
        
        cout << "\nQueue after enqueueing !\n";
        printQueue();
        }

        string deQueue()
        {
            string name = "";
            if(head != nullptr)
            {
                name = head->name;
                if(head->next != nullptr)
                { 
                    head = head->next;
                    delete head->prev;
                }
                else
                {
                    delete head;
                    head = nullptr;
                    tail = nullptr;   
                }
            }
            else
                cout << "\n List is empty";
        return name;
        }

        void printQueue()
        {
            if(head == nullptr)
                cout << "\n Queue is empty";
            else
            {
                Node *current = head;
                while(current != nullptr)
                {
                    cout << current->name << " -- ";
                    current = current->next;
                }
            cout << "\n";
            }
        }        

};


int main()
{
    string name;
    cout << "\nEnter the first name to start queue: ";
    cin >> name;
    Queue q1(name);
    
    int choice;
    while(1)
    {
        cout << "\n\n1:enqueue, 2:dequeue, 3:exit \n";
        cin >> choice;
        switch(choice)
        {
            case 1: // enqueue 
                cout << "\nEnter name to enque in queue: ";
                cin >> name;
                q1.enQueue(name);
                break;
            case 2:
                cout << "\nDequeued name: " << q1.deQueue();
                cout << "\nQueue after dequeueing !\n";
                q1.printQueue();
                break;
            case 3:
                return 0;
            default:
                cout << "\nSelect a valid choice !";
        }
    }
return 0;
}
