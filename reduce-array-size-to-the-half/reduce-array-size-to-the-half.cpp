 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> counts;
    for (int value : arr) {
        counts[value] = 0;
    }
    for (int value : arr) {
        counts[value] = counts[value] + 1;
    }

    vector<pair< int, int>> value_and_count;
    for (auto it : counts) {
        value_and_count.push_back({it.second, it.first});
    }

    sort(value_and_count.begin(), value_and_count.end(), std::greater<>());
    int num_remove = 0;
    int number_removed_value = 0;
    for (pair<int, int> it : value_and_count) {
        num_remove += it.first;
        number_removed_value++;
        if (num_remove >= arr.size() / 2) {
            return  number_removed_value;
        }
    }
    return arr.size();


}
int main()
{
 
    vector<int> numbers = { 3,3,3,3,5,5,5,2,2,7 };
    cout << minSetSize(numbers) << endl;
} 