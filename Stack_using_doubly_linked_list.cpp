#include <iostream>
#include <string>
using namespace std;

struct Node
{
    Node *prev;
    string name;
    Node *next;
};

class Stack
{
    private:
        Node* head;

    public:
        Stack() { }

        Stack(string name)
        {
            head = createNode(name);
        }

        Node* createNode(string name)
        {
            Node* newnode = new Node;
            newnode->prev = nullptr;
            newnode->name = name;
            newnode->next = nullptr;
        return newnode;
        }

        void push(string name)
        {
            if(head == nullptr)
                head = createNode(name);
            else
            {
                Node* newnode = createNode(name);
                head->prev = newnode;
                newnode->next = head;
                head = newnode;
            }
        }

        string pop()
        {
            string name = "";
            if(head == nullptr)
                return name;
            else
            {
                name = head->name;
                if(head->next != nullptr)
                {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
                }
                else
                {
                    delete head;
                    head = nullptr;
                }
            return name;
            }
        }

        void printStack()
        {
            Node *current = head;
            cout << endl;
            while(current != nullptr)
            {
                cout << current->name << " -- ";
                current = current->next;
            }
        }

        void clearStack()
        {
            if(head != nullptr)
            {
                while(head->next != nullptr)
                {
                    head = head->next;
                    delete head->prev;
                }
            delete head;
            head = nullptr;
            }
        }

        ~Stack()
        {
            cout << "\nCalling  destructor !";
            clearStack();
        }
};

int main()
{
    string name;
    cout << "\nEnter a name to start Stack: ";
    cin >> name;
    Stack s1(name);
    int choice;
    while(1)
    {
        cout << "\n1:push, 2:pop, 3:exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: //push
                cout << "\nEnter the name to push into stack: ";
                cin >> name;
                s1.push(name);
                s1.printStack();
                break;
            case 2: // pop
                cout << "\nPoping the name from stack: " << s1.pop();
                s1.printStack();
                break;
            case 3: // exit
                return 0;
            default:
                cout << "\nEnter a valid choice !";
        }

    }

return 0;
}
