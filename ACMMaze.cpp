#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int start;
    int levels;
    int root;

    vector<int> path;

    cin >> levels;
    cin >> start;

    for (int i=0; i<=levels; i++) {
        root += pow(2,i);
    }
    if (root % 2 == 1)
        root --;
    root /= 2;
    path.push_back(root);
    levels--;
    while (root != start) {
        if (root > start) {
            root -= pow(2, levels);
            path.push_back(root);
        }
        else if (root < start) {
            root += pow(2, levels);
            path.push_back(root);
        }
        levels--;
    }
    for (auto x = path.rbegin(); x != path.rend(); x++) {
        cout << *x << " ";
    }
    cout << endl;
}


// That's what Bob would do! :D
