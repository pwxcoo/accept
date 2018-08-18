#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 110;
const double eps = 1e-8;
int n, stack[maxn];
struct point
{
    double x, y;
} p[maxn];

double dis(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double Cross_left(point a, point b, point c)
{
    return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
}
bool cmp(point a, point b) 
{
    double x = Cross_left(a, b, p[0]);
    if (x > 0)    return true;
    else if (fabs(x) <= eps && (dis(b, p[0]) >= dis(a, p[0])))  return true;
    else   return false;
}

double Graham()
{
    int i, k = 0, top = 2;
    point pmin = p[0];
    for (i = 1; i < n; i++)
    {
        if (p[i].y < pmin.y || (p[i].y - pmin.y <= eps && p[i].x < pmin.x))
        {
            pmin = p[i], k = i;  
        }
    }
    swap(p[0], p[k]);
    sort(p + 1, p + n, cmp);
    for (i = 0; i < 3; i++) stack[i] = i;

    for (i = 3; i < n; i++)
    {
        while (Cross_left(p[stack[top - 1]], p[stack[top]], p[i]) <= 0)
        {
            top--;
            if (top == 0)  break;
        }
        stack[++top] = i;
    }
    double cir = 0; top++;
    for (i = 0; i < top; i++)
        cir += dis(p[stack[i]], p[stack[(i + 1) % top]]);

    return cir;

}
int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        if (n == 1)  printf("0.00\n");
        else if (n == 2) printf("%.2lf\n", dis(p[0], p[1]));
        else
            printf("%.2lf\n", Graham());
    }
}
