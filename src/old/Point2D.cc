#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

// Hàm so sánh tùy chỉnh
bool comparePoints(const Point& a, const Point& b) {
    if (a.x == b.x) {
        return a.y > b.y;  // Sắp xếp giảm dần theo y nếu x bằng nhau
    }
    return a.x < b.x;  // Sắp xếp tăng dần theo x nếu khác nhau
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Point> points(N);

    // Nhập toạ độ các điểm
    for (int i = 0; i < N; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    // Sắp xếp các điểm sử dụng hàm so sánh tùy chỉnh
    std::sort(points.begin(), points.end(), comparePoints);

    // In ra các điểm sau khi đã sắp xếp
    for (const Point& point : points) {
        std::cout << point.x << " " << point.y << std::endl;
    }

    return 0;
}
