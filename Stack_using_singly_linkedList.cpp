#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string name;
    Node *next;
};


class Slist
{
    private:
        Node *head;
    
    public:
        Slist()
        { 
            head = nullptr;
        }

        Slist(string name)
        {
            head = createNode(name);
        }

        string pop() /// popping head from stack
        {
            string name;
            if(head == nullptr)
            {
                cout << "\nList is empty! unable to pop";
                name = "";
            }
            else
            {
                name = head->name;
                Node *current = head;
                head = head->next;
                delete current;
            }
        return name;
        }

        void push(string name)
        {
            Node *current = head;
            head = createNode(name);
            head->next = current;
        }

        Node* createNode(string name)
        {
            Node *newnode = new Node;
            newnode->name = name;
            newnode->next = nullptr;
        return newnode;
        }

        void clearStack()
        {
            Node *current = head;
            while(head != nullptr)
            {
                head = head->next;
                delete current;
                current = head;
            }
        }

        void searchName(string name)
        {
            Node *current = head;
            bool found = 0;
            if(current == nullptr)
                found = 0;
            else
            while(current != nullptr)
            {
                if(current->name == name)
                {
                    cout << "Name exists in the stack!";
                    found = 1;
                    break;
                }
                else
                    current = current->next;
            }
            if(!found)
                cout <<"\nName not found in the Stack !";
        }

        void printStack()
        {
            Node *current = head;
            if(current == nullptr)
                cout << "\nList is empty !";
            else
            while(current != nullptr)
            {
                cout << current->name << " -- ";
                current = current->next;
            }
        }
        ~Slist()
        {
            cout << "\nCalling Stack destructor !";
            clearStack();
        }
};



int main()
{
    string name;
    cout << "\nEnter a name to start the stack: ";
    cin >> name;
    Slist s1(name);
    int choice;
    while(1)
    {
        cout <<"\n1:Push, 2:Pop, 3:search_name, 4: print stack, 5: exit";
        cout << "\nchoice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "\nEnter a name to push in stack : ";
                cin >> name;
                s1.push(name);
                break;
            case 2:
                cout <<"\nPopping Name: "<< s1.pop();
                break;
            case 3:
                cout << "\nEnter a name to search in stack: ";
                cin >> name;
                s1.searchName(name);
                break;
            case 4:
                s1.printStack();
                break;
            case 5:
                return 0;
            default:
                cout << "\nEnter a valid choice";
                return 0;
        }
    }

}
