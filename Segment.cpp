// Segment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Segment {
    double x1;
    double y1;
    double x2;
    double y2;
};


double LengthOfCoveredSegment(Segment segmentA, Segment segmentB) {
    double coveredLength;
    double lengthA;
    double lengthB;
    if (segmentA.x1 == segmentA.x2 == segmentB.x1 == segmentB.x2) {
        if ((segmentA.y1 >= segmentB.y1 && segmentA.y1 <= segmentB.y2) || (segmentB.y2 >= segmentA.y1 && segmentB.y2 <= segmentA.y2)) {

            coveredLength = segmentB.y2 - segmentA.y1;
            return coveredLength;
        }if ((segmentB.x1 >= segmentA.y1 && segmentB.y1 <= segmentA.y2) || (segmentA.y2 >= segmentB.y1 && segmentA.y2 <= segmentB.y2)) {

            coveredLength = segmentA.y2 - segmentB.y1;
            return coveredLength;
        }
        else {
            return 0;
        }
    } if (segmentA.y1 == segmentA.y2 == segmentB.y1 == segmentB.y2) {
        if ((segmentA.x1 >= segmentB.x1 && segmentA.x1 <= segmentB.x2) || (segmentB.x2 >= segmentA.x1 && segmentB.x2 <= segmentA.x2)) {

            coveredLength = segmentB.x2 - segmentA.x1;
            return coveredLength;
        }if ((segmentB.x1 >= segmentA.x1 && segmentB.x1 <= segmentA.x2) || (segmentA.x2 >= segmentB.x1 && segmentA.x2 <= segmentB.x2)) {

            coveredLength = segmentA.x2 - segmentB.x1;
            return coveredLength;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int main()
{
    Segment segmentA;
    cout << "Please input coordinates of Segment A" << endl;
    cin >> segmentA.x1;
    cin >> segmentA.y1;
    cin >> segmentA.x2;
    cin >> segmentA.y2;
    Segment segmentB;
    cout << "Please input coordinates of Segment B" << endl;
    cin >> segmentB.x1;
    cin >> segmentB.y1;
    cin >> segmentB.x2;
    cin >> segmentB.y2;
    cout << LengthOfCoveredSegment(segmentA, segmentB);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
