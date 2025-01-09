#include <iostream>
#include <cmath>
#define m_PI 3.14

using namespace std;

struct Point
{
    double x;
    double y;
};

int main()
{
    Point A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    int radius = ceil(sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y)));

    //  area of the actual land
    int actual_area = ceil(m_PI * pow((radius), 2));
    //  area of the fenced land
    int fenced_area = ceil(m_PI * pow(ceil(sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y))), 2));

    if (fenced_area < actual_area)
    {
        cout << "Krishna " << (actual_area - fenced_area) * 20 << endl;
    }
    else if (fenced_area > actual_area)
    {
        int extra_area = fenced_area - actual_area;
        int square_area = pow(ceil(sqrt(extra_area)), 2);
        int compensation_area = square_area - extra_area;

        cout << "actual_area: " << actual_area << endl;
        cout << "fenced_area: " << fenced_area << endl;
        cout << "extra_area: " << extra_area << endl;
        cout << "square_area: " << square_area << endl;
        cout << "compensation_area: " << compensation_area << endl;

        if (compensation_area < 0)
        {
            cout << "Shiva " << abs(compensation_area) * 20;
        }
        else
        {
            cout << "Krishna " << (compensation_area) * 20;
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
