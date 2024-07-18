#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
    int z;
};

// Hàm tráo hoán hai điểm
void swap(Point& a, Point& b) {
    Point temp = a;
    a = b;
    b = temp;
}

// Hàm chia mảng thành hai phần và trả về chỉ số của phần tử chia
int partition(std::vector<Point>& points, int low, int high) {
    Point pivot = points[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (points[j].x < pivot.x ||
            (points[j].x == pivot.x && points[j].y < pivot.y) ||
            (points[j].x == pivot.x && points[j].y == pivot.y &&
             points[j].z > pivot.z)) {
            i++;
            swap(points[i], points[j]);
        }
    }

    swap(points[i + 1], points[high]);
    return i + 1;
}

// Hàm sắp xếp mảng theo thuật toán Quick Sort
void quickSort(std::vector<Point>& points, int low, int high) {
    if (low < high) {
        int pi = partition(points, low, high);
        quickSort(points, low, pi - 1);
        quickSort(points, pi + 1, high);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Point> points(N);

    // Nhập toạ độ các điểm
    for (int i = 0; i < N; ++i) {
        std::cin >> points[i].x >> points[i].y >> points[i].z;
    }

    // Sắp xếp các điểm sử dụng Quick Sort
    quickSort(points, 0, N - 1);

    // In ra các điểm sau khi đã sắp xếp
    for (const Point& point : points) {
        std::cout << point.x << " " << point.y << " " << point.z << "\n";
    }

    return 0;
}
