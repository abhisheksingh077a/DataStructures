#include <iostream>
#include <string>

struct Node
{
    std::string name;
    Node* next;
};

class SList
{
    private:
        Node* m_head;
        Node* m_temp;

    public:
// constructor for list
        SList(): m_head(nullptr), m_temp(nullptr)
        {

        }

// printing list by member function
        void print()
        {
            if(m_head == nullptr)
                std::cout << "\n No element in the list !\n";

            else
            {
                std::cout << "\n Printing list !\n";
                m_temp = m_head;
                do
                {
                    std::cout << "\n Name: "<< m_temp->name << "\n";
                    std::cout << "\t\t |";
                    m_temp = m_temp->next;
                }
                while(m_temp != nullptr);
            }
        }

// adding node by member function
        void append(std::string name)
        {
            std::cout << "\n Appending name: " << name << "\n";
            if(m_head == nullptr)
            {
                m_head = new Node;
                m_head->name = name;
                m_head->next = nullptr;
            }
            else
            {
                m_temp = m_head;
                while(m_temp->next != nullptr)
                    m_temp = m_temp->next;
                Node* newNode = new Node;
                newNode->name = name;
                newNode->next = nullptr;

                m_temp->next = newNode;
            }
        }
//member function for clearing the list
        void clearList()
        {
         std::cout << "\n Deleting whole list ! \n";
         if(m_head != nullptr)
         {   
            m_temp = m_head;
            Node* trav = m_head->next;
            do
            {
                delete m_temp;
                m_temp = trav;
                if(trav != nullptr)
                    trav = trav->next;
            }
            while(m_temp != nullptr);
            m_head = nullptr;
         }
         else
            std::cout << "\n There is nothing to delete in list, it is empty\n";
        }
//member function to add a head
        void addHead(std::string name)
        {
            std::cout << "\n Adding name in begining: " << name << "\n";
            m_temp = new Node;
            m_temp->name = name;
            m_temp->next = m_head;
            m_head = m_temp;
        }
//member function to delete a name
        int deleteName(std:: string name)
        {
            if(m_head == nullptr)
            {
                std::cout << "\n No element in the list";
                return 0;
            }
            if(m_head->next == nullptr || m_head->name == name)
            {
                if(m_head->name == name)
                {
                    m_temp = m_head->next;
                    std::cout << "\n Deleting: " << name;
                    delete m_head;
                    m_head = m_temp;
                }
                else
                    std::cout << "\n Name asked to delete not found.\n";
                    
            }
            else
            {
                Node* trav;
                m_temp = m_head;
                trav = m_temp->next;
                do
                {
                    if(trav->name == name)
                    {                
                        std::cout << "\n Deleting: " << name;
                        trav = trav->next;
                        delete m_temp->next;
                        m_temp->next = trav;    
                        return 0;
                    }
                    else
                    {
                        if(trav != nullptr)
                          trav = trav->next;
                        m_temp = m_temp->next;
                    }

                }
                while(trav != nullptr);

            std::cout << "\n Name not found in the list. \n";
        
            }
        return 0;
        }

// destructor for class
        ~SList()
        {
            if(m_head != nullptr)
            {
                std::cout << "\n Calling Destructor !";   
                clearList();
            }
        }


};

void printMenu()
{
    std::cout << "\n  1: append name \n";
    std::cout << "\n  2: add name in begining \n";
    std::cout << "\n  3: delete name \n";
    std::cout << "\n  4: print list \n";
    std::cout << "\n  5: delete list \n";
    std::cout << "\n  6: print menu \n";
    std::cout << "\n  7: exit \n";
}

int main()
{
  SList names;
  printMenu();
while(1)
{  
   int choice;
   std::cout << "\n\n\n\n\t\t Enter choice: ";
   std::cin >> choice;
   std::string name;
    switch(choice)
    {
        case 1:  
            std::cout << "\n Enter name to add: ";
            std::cin >> name;
            names.append(name);
            break;
        case 2:
            std::cout << "\n Enter name to add: ";
            std::cin >> name;
            names.addHead(name);
            break;
        case 3:
            std::cout << "\n Enter name to delete: ";
            std::cin >> name;
            names.deleteName(name);
            break;
        case 4:
            names.print();
            break;
        case 5:
            names.clearList();
            break;
        case 6:
            printMenu();
            break;
        default:
            std::cout << "\n You have not choosen any work to do !";
            return 0;
    }
}
  return 0;
}
