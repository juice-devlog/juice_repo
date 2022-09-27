#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string    word;
    int arr[26] = { 0, };
    cin >> word;
    for (char c = 'a'; c <= 'z'; c++){
        for (int i = 0; word[i]; i++){
            if (word[i] == c)
                arr[c - 'a']++;
        }
    }
    for (int i = 0; i <= 25; i++) cout << arr[i] << ' ';
}