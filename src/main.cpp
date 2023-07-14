#include <iostream>
#include <string.h>
#include <time.h>
#include "../include/InsertionSort.h"
#include "../include/MergeSort.h"
#include "../external/doctest.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 4)
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
    } else {
        doctest::Context context;

        // !!! THIS IS JUST AN EXAMPLE SHOWING HOW DEFAULTS/OVERRIDES ARE SET !!!

        // defaults
        context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in their name
        context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
        context.setOption("order-by", "name");            // sort the test cases by their name

        context.applyCommandLine(argc, argv);

        // overrides
        context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

        int res = context.run(); // run

        if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
            return res;          // propagate the result of the tests

        int client_stuff_return_code = 0;
        // your program - if the testing framework is integrated in your production code

        return res + client_stuff_return_code; // the result from doctest is propagated here as well
    }
}