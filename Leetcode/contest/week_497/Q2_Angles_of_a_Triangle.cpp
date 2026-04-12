#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double findAngle(double a, double b, double c) {
        double anglec = (a * a + b * b - c * c) / (2 * a * b);
        anglec = max(-1.0, min(1.0, anglec));

        return acos(anglec) * 180.0 / M_PI;
    }
    vector<double> internalAngles(vector<int> &sides) {
        sort(sides.begin(), sides.end());

        double hyp = sides[2];
        double base = sides[0];
        double per = sides[1];

        if (base + per <= hyp) {
            return {};
        }
        vector<double> ans;

        double angle1 = findAngle(base, per, hyp);
        double angle2 = findAngle(base, hyp, per);

        double angle3 = 180 - (angle1 + angle2);

        ans.push_back(angle1);
        ans.push_back(angle2);
        ans.push_back(angle3);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
