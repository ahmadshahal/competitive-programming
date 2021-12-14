#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;




// How to implement Stress Testing:

void STRESS_TEST()
{
    int n;
    int arr[1006];
    while(true)
    {
        n = rand() % 10 + 2; // Change the constraints of the Random number
        cout << "{";
        for(int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10; // Change the constraints of the Array members
            cout << arr[i];
            if(i != n - 1)
                cout << ", ";
        }
        cout << "}" << endl;
        if(/* First Algorithm(arr, n) */ == /* maxPairwiseAlternative(arr, n) */)
            cout << "OK" << endl;
        else
        {
            cout << "Wrong Answer: " << /* First Algorithm(arr, n) */<< " : " 
            << /* maxPairwiseAlternative(arr, n) */ << endl;
            system("pause");
            break;
        }
    }
}

int main()
{
    STRESS_TEST();
}
