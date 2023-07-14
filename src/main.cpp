#include <iostream>
#include <string.h>
#include <time.h>
#include "../include/InsertionSort.h"
#include "../include/MergeSort.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            if (argc == 5)
            {
                if (isdigit(argv[3][strlen(argv[3]) - 1]))
                {
                    cout << "Command 3\n";
                }
                else
                {
                    cout << "Command 1\n";
                }
            }
            else if (argc == 6)
            {
                cout << "Command 2\n";
            }
        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            if (argc == 5)
            {
                cout << "Command 4\n";
            }
            else if (argc == 6)
            {
                cout << "Command 5\n";
            }
        }
    } 
    else {
        int n = 50;
        int* a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 1000;
        }

        MergeSort array(a, n);
        array.display();
        array.sortWithComparison();
        cout << array.getComparison() << endl;
        array.display();
        delete[] a;
    }
    return 0;
}