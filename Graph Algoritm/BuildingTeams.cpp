// soal bebas uva 10004
// ac
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> adj[100001];
bool isvisit[100001];
int color[100001];
bool biparted;
int main()
{
    int n;
    scanf("%d", &n);
        int  y;
        scanf("%d", &y);
        biparted = true;
        for (int j = 1; j <= n; j++)
        {
            color[j] = 2;
            adj[j].clear();
        }
        for (int j = 0; j < y; j++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int j = 1; j <= n; j++)
        {
            if (color[j] == 2)
            {
                
                queue<int> aq;
                aq.push(j);

                color[j] = 0;

                while (!aq.empty() && biparted)
                {
                    int fr = aq.front();
                    aq.pop();
                    for (int z = 0; z < adj[fr].size(); z++)
                    {
                        int sec = adj[fr][z];

                        if (color[sec] == 2)
                        {
                            color[sec] = 1 - color[fr];
                            aq.push(sec);
                        }
                        else if (color[sec] == color[fr])
                        {
                            biparted = false;
                            break;
                        }
                    }
                }
            }
        }
        if (biparted)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ",color[i]+1);
            }
            
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    
}