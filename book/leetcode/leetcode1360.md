## Intuition

计算两个日期间隔的时间。

----

体力活。闰年比较麻烦。

## Solution

```cpp
class Solution {
public:
    bool isLeap(int year) {
        if (year % 100 == 0) return year % 400 == 0;

        return year % 4 == 0;
    }

    int countLeap(int year1, int year2) {
        int cnt = 0;
        for (int i = year1; i < year2; i++) {
            cnt += isLeap(i) ? 1 : 0;
        }
        return cnt;
    }

    int countDayOfYear(int year, int month, int day) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> leapDays = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return isLeap(year)
            ? accumulate(leapDays.begin(), leapDays.begin() + month, 0) + day
            : accumulate(days.begin(), days.begin() + month, 0) + day;
    }

    int daysBetweenDates(string date1, string date2) {
        int res = 0;

        if (date1 > date2) swap(date1, date2);

        int year1 = stoi(date1.substr(0, 4));
        int year2 = stoi(date2.substr(0, 4));
        res += (year2 - year1) * 365 + countLeap(year1, year2);

        return res - countDayOfYear(year1, stoi(date1.substr(5, 2)), stoi(date1.substr(8, 2)))
                  + countDayOfYear(year2, stoi(date2.substr(5, 2)), stoi(date2.substr(8, 2)));

    }
};
```