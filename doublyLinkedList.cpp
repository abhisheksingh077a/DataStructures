#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node *prev;
    string name;
    Node *next;
};

class Dlist
{
private:
    Node *head = nullptr; // pointer which represents whole list

public: // access modifiers

///////////////////////////// constructors
    Dlist(string name)
    {
        head = createNode(name);
    }
    Dlist() { } // default constructor

///////////////////////// member functions

    Node* createNode(string name)
    {
        Node *newnode = new Node;
        newnode->prev = nullptr;
        newnode->name = name;
        newnode->next = nullptr;
    return newnode;
    }

    void printList()
    {
        Node *current = head;
        if(current == nullptr)
            cout << "\n List is empty!";
        while(current != nullptr)
        {
            cout << current->name << " -- " ;
            current = current->next;
        }
        cout << "\n";
    }

    void push(string name)
    {
        Node *current = head;
        head = createNode(name);
        if(current != nullptr)
        {
        head->next = current;
        current->prev = head;
        }
    }

    string pop()
    {
        string name;
        Node *current = head;
        if(head != nullptr)
        {
        head = head->next;
        name = current->name;
        delete current;
        }
        else 
        {
            cout << "\n List is empty cant pop!";
            name = "";
        }
    return name;
    }

    string removeTail()
    {
        string name;
        Node* current = head;
        if(current != nullptr)
        {
        while(current->next != nullptr)
            current = current->next;
        name = current->name;
        current->prev->next = nullptr;
        delete current;
        }
        else 
        {
            cout << "\n List is empty cant remove tail !";
            name = "";
        }
    return name;
    }

    void enQueue(string name)
    {
        Node *current = head;
        if(current != nullptr)
        {
        while(current->next != nullptr)
            current = current->next;
        Node *newnode = createNode(name);
        current->next = newnode;
        newnode->prev = current;
        }
        else 
        {
            head = createNode(name);
        }
    }


    void clearList() // to delete all elements in the list
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

    Node* __search(string name)
    {
        if(head != nullptr)
        {
        Node *current = head;
        while(current-> name != name)
        {
            current = current->next;
            if(current == nullptr)
                return nullptr;
        }
        return current;
        }
        else
        {
            cout << "\n List is empty";
            return nullptr;
        }
    }

    void search(string name)
    {
        if(__search(name) != nullptr)
            cout << "\nName " << name << " exists in the list ! \n";
        else
            cout << "\nName " << name << " does'nt exist in the list ! \n";
    }

    void deleteName(string name)
    {
        Node* current = __search(name);
        if(current == nullptr)
            cout << "\nName not found in the list";
        
        else
        {
            if(current->prev == nullptr)
                pop();
            else if(current->next == nullptr)
                removeTail();
            else
            {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            cout << "\nDeleting name: " << current->name << endl;
            delete current;   
            }
        }

    }

    ~Dlist() // destructor of class
    {
        cout << "\n\nCalling destructor to cleanup memory !";
        clearList();
    }
};


int main()
{
string name;
int num;
Dlist dl_names;
while(1)
{
    cout << "\n 1:push, 2:enqueue, 3:search_name, 4:clear_list, 5:pop, 6:print_list, 7:delete_name, 8:remove tail\n";
    cout << "\nEnter your choice: ";
    cin >> num;
    switch(num)
    {
        case 1: // push
            cout << "\nEnter name to insert at head: ";
            cin >> name;
            dl_names.push(name);
            break;
        case 2: // enqueue
            cout << "\nEnter name to insert at tail: ";
            cin >> name;
            dl_names.enQueue(name);
            break;
        case 3: //search name
            cout << "\nEnter name to search in list: ";
            cin >> name;
            dl_names.search(name);
            break;
        case 4: // clear list
            dl_names.clearList();
            break;
        case 5: // pop
            cout << "\n Poping name: " << dl_names.pop();
            break;
        case 6: // print whole list
            dl_names.printList();
            break;
        case 7: // delete name
            cout << "\nEnter name to delete from list: ";
            cin >> name;
            dl_names.deleteName(name);
            break;
        case 8: // remove tail
            dl_names.removeTail();
            break;
        default:
            cout << "\n No work going out !" ;
            return 0;
    }
cout << string( 15, '\n' );
}
    return 0;
}
