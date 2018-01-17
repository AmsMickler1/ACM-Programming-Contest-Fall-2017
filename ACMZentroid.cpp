#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
}Body;

typedef struct {
    vector<Body> bodies;
    int d = 0;
    Body centroid;
}Cluster;

int main() {
    Body zentrum;
    vector<Cluster> clusters;
    int numC;
    int numB;
    int sumx = 0;
    int sumy = 0;

    cin >> numC;
    for (int i=0; i<numC; i++) {
        cin >> numB;
        Cluster c;
        sumx = 0;
        sumy = 0;
        for (int j=0; j<numB; j++) {
            Body b;
            cin >> b.x >> b.y;
            sumx += b.x;
            sumy += b.y;
            if (b.x%2 == 0 && b.y%2 == 0)
                c.d++;
            c.bodies.push_back(b);

        }
        c.centroid.x = sumx/numB;
        c.centroid.y = sumy/numB;
        if (c.d % 2 == 1) {
            c.centroid.x /= c.d;
            c.centroid.y /= c.d;
        }
        clusters.push_back(c);
    }
    sumx = 0;
    sumy = 0;
    for (int i=0;i<numC;i++) {
        sumx += clusters[i].centroid.x;
        sumy += clusters[i].centroid.y;
    }

    zentrum.x = sumx/numC;
    zentrum.y = sumy/numC;

    cout << "(" << zentrum.x << "," << zentrum.y << ")" << endl;

}

// THATS WHAT BOB WOULD DO! :)
