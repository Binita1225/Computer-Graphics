#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};
bool inside(Point p, Point win_min, Point win_max) {
    return (p.x >= win_min.x && p.x <= win_max.x && p.y >= win_min.y && p.y <= win_max.y);
}
Point intersection(Point p1, Point p2, Point win_min, Point win_max) {
    Point intersect;
    if (p2.y - p1.y == 0) {
        intersect.y = p1.y;
        intersect.x = win_min.x;
    } else if (p2.x - p1.x == 0) {
        intersect.x = p1.x;
        intersect.y = win_min.y;
    } else {
        float m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        if (p1.x == p2.x) {
            intersect.x = p1.x;
            intersect.y = win_min.y;
        } else if (p1.y == p2.y) {
            intersect.y = p1.y;
            intersect.x = win_min.x;
        } else {
            if (m < 0) {
                if (p1.y < win_min.y) {
                    intersect.y = win_min.y;
                    intersect.x = p1.x - ((p1.y - win_min.y) / m);
                } else {
                    intersect.y = p1.y - m * (p1.x - win_min.x);
                    intersect.x = win_min.x;
                }
            } else {
                if (p1.y > win_max.y) {
                    intersect.y = win_max.y;
                    intersect.x = p1.x - ((p1.y - win_max.y) / m);
                } else {
                    intersect.y = p1.y - m * (p1.x - win_max.x);
                    intersect.x = win_max.x;
                }
            }
        }
    }
    return intersect;
}
vector<Point> sutherlandHodgman(vector<Point> polygon, Point win_min, Point win_max) {
    vector<Point> clippedPolygon;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int k = (i + 1) % n;
        if (inside(polygon[i], win_min, win_max)) {
            if (!inside(polygon[k], win_min, win_max)) {
                clippedPolygon.push_back(intersection(polygon[i], polygon[k], win_min, win_max));
            }
            clippedPolygon.push_back(polygon[k]);
        } else if (inside(polygon[k], win_min, win_max)) {
            clippedPolygon.push_back(intersection(polygon[i], polygon[k], win_min, win_max));
        }
    }
    return clippedPolygon;
}
void displayPolygon(vector<Point> polygon) {
    for (int i = 0; i < polygon.size(); i++) {
        cout << "(" << polygon[i].x << ", " << polygon[i].y << ") ";
    }
    cout << endl;
}
int main() {
    int n;
    vector<Point> polygon, clippedPolygon;
    Point win_min, win_max;

    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    cout << "Enter the vertices of the polygon (x y):" << endl;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        polygon.push_back(p);
    }

    cout << "Enter the minimum coordinates of the clipping window (x y): ";
    cin >> win_min.x >> win_min.y;
    cout << "Enter the maximum coordinates of the clipping window (x y): ";
    cin >> win_max.x >> win_max.y;

    clippedPolygon = sutherlandHodgman(polygon, win_min, win_max);

    cout << "Clipped polygon:" << endl;
    displayPolygon(clippedPolygon);

    return 0;
}

