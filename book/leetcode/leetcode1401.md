## Intuition

矩阵和圆是否有重叠（overlap）

----

计算圆心到矩阵边的最短距离。可以分成两种情况，一种是直接计算到边的，一种是计算到顶点的。


## Solution

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // case1: minimum = 'edge of rectangle' to 'center of circle'
        int distance;
        if (x_center >= x1 && x_center <= x2) {
            return y_center >= y1 - radius && y_center <= y2 + radius;
        }
        if (y_center >= y1 && y_center <= y2) {
            return x_center >= x1 - radius && x_center <= x2 + radius;
        }

        // case2: minimun = 'vertex of rectangle' to 'center of circle'
        int d1 = calc2point(x_center, y_center, x1, y1);
        int d2 = calc2point(x_center, y_center, x2, y2);
        int d3 = calc2point(x_center, y_center, x1, y2);
        int d4 = calc2point(x_center, y_center, x2, y1);

        distance = min(d1, min(d2, min(d3, d4)));
        return distance <= radius * radius;

    }

    int calc2point(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};
```

时间复杂度：$$O(1)$$