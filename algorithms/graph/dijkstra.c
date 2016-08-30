#include <stdio.h>

const int MAXINT = 32767;
const int MAXNUM = 10;
int dist[MAXNUM];   // 记录每个点到起点的最短距离
int pre[MAXNUM];    // 记录每个点的前驱
int A[MAXNUM][MAXNUM]; // 保存每个边的权重

void dijkstra(int v0)
{
    bool visited[MAXNUM];
    int n = MAXNUM;

    for (int i = 1; i <= n; i++) {
        dist[i] = A[v0][i];
        visited[i] = false;                 // 初始都未用过该点
        
        if (dist[i] != MAXINT) {
            pre[i] = v0;
        } else {
            pre[i] = -1;
        }
    }

    visited[v0] = true;
    dist[v0] = 0;

    for (int i = 2; i <= n; i++) {
        int min = MAXINT;
        int u = v0;                  // 找出当前未使用的点j的dist[j]最小值
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                u = j;            // u保存当前邻接点中距离最小的点的号码 
                min = dest[j];
            }
        }
        visited[u] = true;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && A[u][j] < MAXNUM) {
                if (dist[u] + A[u][j] < dist[j]) {   //在通过新加入的u点路径找到离v0点更短的路径
                    dist[j] = dist[u] + A[u][j];    //更新dist
                    pre[j] = u;                     //记录前驱顶点
                }
            }
        }
    }
}

