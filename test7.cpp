#include <cstdlib>
#include <iostream>
using namespace std;




int main7() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int x = 0;
    int i = 0, j = 0;
    while (i < s1.size() && j < s1.size()) {

        if (s2[j] == s1[i]) {
            x++;
            j++;
            i++;
        }
        else if (j>0 && s2[j] == '*') {
            while (s2[j - 1] == s1[i]) {
                x++;
                i++;
            }
            j++;
        }
        else {
            break;
        }


    }
    cout << x;
    return 0;


}