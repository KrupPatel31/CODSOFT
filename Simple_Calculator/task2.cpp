#include <iostream>
using namespace std;

int main()
{
    int n = 1;
    while (n != 2)
    {
    start:
        double a, b;
        int op;
        cout << "--------------------Welcome To My Simple Calculator--------------------" << endl
             << endl;
        cout << "Enter a & b : ";
        cin >> a >> b;
        cout << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> op;
        cout << endl;
        switch (op)
        {
        case 1:
            cout << a + b << endl;
            break;
        case 2:
            cout << a - b << endl;
            break;
        case 3:
            cout << a * b << endl;
            break;
        case 4:
            cout << a / b << endl;
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Operation Not Found" << endl;
            goto start;
        }
        cout << endl
             << "Press 1 for Continue and 2 for Exit" << endl;
        cin >> n;
    }

    return 0;
}