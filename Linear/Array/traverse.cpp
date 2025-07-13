#include <vector>
#include <iostream>
using namespace std;

template <typename T>

class Array
{

public:
    vector<T> v1;

    Array(const vector<T> &vec = {}) : v1(vec) {};

public:
    Array &traverse()
    {
        cout << "Elements in vector v1[" << v1.size() << "] are: [";
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i];
            if (i < v1.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        return *this;
    }

    Array &insertion(T &item, int index = -1)
    {
        vector<T> temp;
        if (index - 1 < 0 || index - 1 > v1.size())
        {
            cout << "Invalid index. Inserting at the end." << endl;
            v1.push_back(item);
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                temp.push_back(v1[i]);
            }
            temp.push_back(item);
            for (int i = index - 1; i < v1.size(); i++)
            {
                temp.push_back(v1[i]);
            }
            v1 = temp;
        }
        return *this;
    }

    Array &insertion(vector<T> &items, int index = -1)
    {
        if (index - 1 < 0 || index - 1 > v1.size())
        {
            cout << "Invalid index. Inserting at the end." << endl;
            v1.insert(v1.end(), items.begin(), items.end());
        }
        else
        {
            vector<T> temp;
            for (int i = 0; i < index - 1; i++)
            {
                temp.push_back(v1[i]);
            }
            temp.insert(temp.end(), items.begin(), items.end());
            for (int i = index - 1; i < v1.size(); i++)
            {
                temp.push_back(v1[i]);
            }
            v1 = temp;
        }
        return *this;
    }
};

int main()
{
    Array<int> array({1, 2, 3, 4, 5});
    int option;

    do
    {
        cout << "Enter the option to perform following task: " << endl;
        cout << "1: traversing" << endl;
        cout << "2: insertion" << endl;
        cout << "0: exit" << endl;
        cout << "Your choice: ";
        cin >> option;

        switch (option)
        {
        case 0:
        {
            cout << "Exiting..." << endl;
            break;
        }
        case 1:
        {
            array.traverse();
            break;
        }
        case 2:
        {
            cout << "Enter the number of elements to insert: ";
            int n;
            cin >> n;
            if (n == 1)
            {
                int number;
                cout << "Enter the number to insert: ";
                cin >> number;

                cout << "Do you want to insert at a specific index? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    int index;
                    cout << "Enter the index to insert at: ";
                    cin >> index;
                    array.insertion(number, index).traverse();
                }
                else
                {
                    array.insertion(number).traverse();
                }
            }
            else
            {
                vector<int> numbers(n);

                cout << "Enter the numbers to insert: ";
                for (int i = 0; i < n; i++)
                {
                    cin >> numbers[i];
                }
                cout<<endl;

                cout << "Do you want to insert at a specific index? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    int index;
                    cout << "Enter the index to insert at: ";
                    cin >> index;
                    array.insertion(numbers, index).traverse();
                }
                else
                {
                    array.insertion(numbers).traverse();
                }
            }
            break;
        }

        default:
            break;
        }
    } while (option != 0);

    return 0;
}