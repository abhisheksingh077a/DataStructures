#include <iostream>

class Darray
{
    private:
        int* m_array;
        int m_length;
        int m_point;

    public:
    // constructor
        Darray(int length): m_length(length)
        {
            m_point = 0;
            m_array = new int [m_length];
            std::cout << "\n Initialising array with 0 !" << "\n";
            for(int ii = 0; ii < m_length; ii ++)
                m_array[ii] = 0;
        }

    // member function
        void print()
        {
            std::cout << "\n Array: [ ";
            for(int ii = 0; ii < m_length; ii ++)
            {
                if(m_array[ii]== 0)
                    break;
                std::cout <<  m_array[ii] << " ";
            }
            std::cout << "]\n";
        }
    //member function
        void clear()
        {
            delete [] m_array;
            m_array = nullptr;
        }
    // member function
        int* resize(int newlength)
        {
            if(newlength <= 0)
            {
                std::cout << "\n Clearing array !";
                clear();
                return m_array;
            }
            if(newlength == m_length)
                return m_array;

            else
            {
                int* new_array = new int [newlength];

                for(int ii = 0; ii < m_length; ii ++)
                    new_array[ii] = m_array[ii];

                m_length = newlength;
                delete [] m_array;
                m_array = new_array;
                return m_array; 
            } 
        }
// member function
        void insertAt(int index, int value)
        {
            m_array[index] = value;
        }
// member function

        void append(int num)
        {
            if(m_point < m_length)
            {
                m_array[m_point] = num;
                ++ m_point;
            }
            else
            {
                resize(m_length + 5);
                m_array[m_point] = num;
                ++ m_point;
            }
        }
// member function 
        void reverse()
        {
            for(int ii = 0; ii < m_point / 2; ii ++)
            {
                int temp = m_array[ii];
                m_array[ii] = m_array[m_point - ii - 1];
                m_array[m_point - ii - 1] = temp;
            }
        }
    // destructor
        ~Darray()
        {
            delete [] m_array;
            m_array = nullptr;
        }
        int getMpoint() { return m_point; }

        int getLength () { return m_length; }

};

int main()
{
    Darray arr1(5);
    arr1.print();
    std::cout << arr1.getMpoint() << "  " << arr1.getLength() << "\n";

for(int ii = 1; ii <= 6; ii ++)
{   
    arr1.append(ii);
    arr1.print();
    std::cout <<"\n m_point: " << arr1.getMpoint() << "    m_length: " << arr1.getLength() << "\n";
}  
arr1.reverse();
arr1.print();
arr1.resize(50);
arr1.print();
std::cout <<"\n m_point: " << arr1.getMpoint() << "    m_length: " << arr1.getLength() << "\n";
    return 0;
}
