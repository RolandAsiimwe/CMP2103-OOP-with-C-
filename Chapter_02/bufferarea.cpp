#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Point class to represent a 2D coordinate
class Point {
public:
    double x, y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    // Calculate distance from this point to another point
    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

// Buffer class to manage buffered regions
class Buffer {
private:
    Point center;
    vector<double> bufferSizes;  // Buffer radii
    vector<vector<Point>> pointsInBuffer;  // Points contained in each buffer
    
public:
    Buffer(Point center) : center(center) {}
    
    // Add buffer sizes (radii)
    void addBufferSize(double radius) {
        bufferSizes.push_back(radius);
        pointsInBuffer.push_back(vector<Point>());
    }
    
    // Check which buffer contains a given point
    void checkPoint(const Point& p) {
        double dist = center.distanceTo(p);
        
        for (int i = 0; i < bufferSizes.size(); i++) {
            if (dist <= bufferSizes[i]) {
                pointsInBuffer[i].push_back(p);
            }
        }
    }
    
    // Display results
    void displayResults() {
        cout << fixed << setprecision(2);
        cout << "\n=== Buffer Analysis Results ===\n";
        cout << "Center Point: (" << center.x << ", " << center.y << ")\n\n";
        
        for (int i = 0; i < bufferSizes.size(); i++) {
            cout << "Buffer " << (i + 1) << " (Radius: " << bufferSizes[i] << " units)\n";
            cout << "Points contained: " << pointsInBuffer[i].size() << "\n";
            
            for (const Point& p : pointsInBuffer[i]) {
                double dist = center.distanceTo(p);
                cout << "  - (" << p.x << ", " << p.y << ") at distance " << dist << "\n";
            }
            cout << "\n";
        }
    }
};

int main() {
    // Define center point
    Point center(0, 0);
    
    // Create buffer object with center
    Buffer buffer(center);
    
    // Define buffer sizes (radii)
    buffer.addBufferSize(5);     // 5 units buffer
    buffer.addBufferSize(10);    // 10 units buffer
    buffer.addBufferSize(15);    // 15 units buffer
    
    // Define test points
    vector<Point> testPoints = {
        Point(3, 4),      // Distance: 5 (on boundary of buffer 1)
        Point(6, 8),      // Distance: 10 (on boundary of buffer 2)
        Point(9, 12),     // Distance: 15 (on boundary of buffer 3)
        Point(2, 2),      // Distance: 2.83 (inside buffer 1)
        Point(7, 7),      // Distance: 9.90 (inside buffer 2)
        Point(12, 9),     // Distance: 15 (on boundary of buffer 3)
        Point(20, 20)     // Distance: 28.28 (outside all buffers)
    };
    
    // Check each point against buffers
    cout << "Processing " << testPoints.size() << " points...\n";
    for (const Point& p : testPoints) {
        buffer.checkPoint(p);
    }
    
    // Display results
    buffer.displayResults();
    
    return 0;
}