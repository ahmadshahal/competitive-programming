#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b)
{
    // if (a.second < b.second)
    //     return true;
    // else
    //     return false;

    return (a.second < b.second); // MUST BE LIKE THIS
}

int main()
{
    int n = 10;
    int arr[n] = {3, 1, 2, 4, 5, 6, 7, 8, 9, 0};
    vector<int> vec = {3, 1, 2, 4, 5, 6, 7, 8, 9, 0};
    vector<pair<int, int>> vecOfPairs;

    vecOfPairs.push_back(make_pair(3, 4));
    vecOfPairs.push_back(make_pair(8, 8));
    vecOfPairs.push_back(make_pair(1, 7));
    vecOfPairs.push_back(make_pair(0, 2));


    // Sorting in Ascending order
    sort(arr, arr + n);
    sort(vec.begin(), vec.end());
    sort(vecOfPairs.begin(), vecOfPairs.end());               // Depending on First
    sort(vecOfPairs.begin(), vecOfPairs.end(), sortBySecond); // Depending on Second


    // Sorting in Decending order
    sort(arr, arr + n, greater<int>());
    sort(vec.rbegin(), vec.rend());
    sort(vecOfPairs.rbegin(), vecOfPairs.rend());               // Depending on First
    sort(vecOfPairs.rbegin(), vecOfPairs.rend(), sortBySecond); // Depending on Second

}