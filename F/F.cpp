#include <bits/stdc++.h>

using namespace std;
struct point {
    double x;
    double y;
};
struct circle {
    double x;
    double y;
    double r;
    circle() {}
    circle(double x, double y, double r): x(x), y(y), r(r) {}
};
circle b_md(vector<point> R) {
    if (R.size() == 0) {
        return circle(0, 0, -1);
    } else if (R.size() == 1) {
        return circle(R[0].x, R[0].y, 0);
    } else if (R.size() == 2) {
        return circle((R[0].x+R[1].x)/2.0,
                      (R[0].y+R[1].y)/2.0,
                      hypot(R[0].x-R[1].x, R[0].y-R[1].y)/2.0);
    } else {
        double D = (R[0].x - R[2].x)*(R[1].y - R[2].y) - (R[1].x - R[2].x)*(R[0].y - R[2].y);
        double p0 = (((R[0].x - R[2].x)*(R[0].x + R[2].x) + (R[0].y - R[2].y)*(R[0].y + R[2].y)) / 2 * (R[1].y - R[2].y) - ((R[1].x - R[2].x)*(R[1].x + R[2].x) + (R[1].y - R[2].y)*(R[1].y + R[2].y)) / 2 * (R[0].y - R[2].y))/D;
        double p1 = (((R[1].x - R[2].x)*(R[1].x + R[2].x) + (R[1].y - R[2].y)*(R[1].y + R[2].y)) / 2 * (R[0].x - R[2].x) - ((R[0].x - R[2].x)*(R[0].x + R[2].x) + (R[0].y - R[2].y)*(R[0].y + R[2].y)) / 2 * (R[1].x - R[2].x))/D;
        return circle(p0, p1, hypot(R[0].x - p0, R[0].y - p1));
    }
}
circle b_minidisk(vector<point>& P, int i, vector<point> R) {
    if (i == P.size() || R.size() == 3) {
        return b_md(R);
    } else {
        circle D = b_minidisk(P, i+1, R);
        if (hypot(P[i].x-D.x, P[i].y-D.y) > D.r) {
            R.push_back(P[i]);
            D = b_minidisk(P, i+1, R);
        }
        return D;
    }
}
circle minidisk(vector<point> P) {
    random_shuffle(P.begin(), P.end());
    return b_minidisk(P, 0, vector<point>());
}

int main() {
    int n,m; cin >> n >> m;
    int N; cin >> N; 
    vector<point> v;
    for (int i = 0; i < N; i++) {
        double x, y; cin >> x >> y;
        point p; p.x = x; p.y = y;
        v.push_back(p);
    }

    int d; cin >> d;

    while(d--){
        int f; cin >> f;
        vector<point> ad;
        for(int i=0;i<f;i++){
            int id; cin >> id;
            ad.push_back(v[--id]);
        }
        circle c = minidisk(ad);
        cout << fixed << setprecision(9) << c.r << endl;
    }
    return 0;
}

