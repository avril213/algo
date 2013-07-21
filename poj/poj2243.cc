// POJ.cpp : Defines the entry point for the console application.
//
// 2013.7.20 SJM
// 写BFS的总结：
// 1.用一个表格存储是否已访问该节点，用一个表格（二维数组）存储到该节点所需最小步数
// 2.将初始化二维数组与bfs的实现分离，main中应该非常简洁明了
// 3.stl中queue的使用需要注意，queue.front()是取队列前端的节点，而pop只负责删除前端节点，push从后端插入节点

#include <iostream>
#include <queue>
using namespace std;

typedef struct point{
     int x;
     int y;
}point;

bool isVisited[9][9];
int board[9][9];
int moves[][2] = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};

void init()
{
     for(int i = 0; i < 9; i++)
          for(int j = 0; j < 9; j++)
          {
               isVisited[i][j] = 0;
               board[i][j] = 0;
          }
}

bool isValidMove(int x, int y)
{
     return (x > 0)&&(x <9)&&(y > 0)&&(y < 9);
}

int bfs(point start, point end)
{
     queue<point> qu;
     qu.push(start);
     while(!qu.empty())
     {
          point temp = qu.front();   // why? : qu.pop() just pop out , not get the top element
          point tempPost;
          qu.pop(); //~
          for(int i = 0; i < 8; i++)
          {
               int xpost = temp.x + moves[i][0];
               int ypost = temp.y + moves[i][1];
               if(isValidMove(xpost,ypost) && !isVisited[xpost][ypost])
               {
                    board[xpost][ypost] = board[temp.x][temp.y] + 1;
                    if(xpost == end.x && ypost == end.y)
                         return board[xpost][ypost];
                    tempPost.x = xpost;
                    tempPost.y = ypost;
                    qu.push(tempPost);
                    isVisited[xpost][ypost] = 1;
               }
          }
     }
     return 0;
}

int main()
{
     char sx,sy, ex, ey;
     point sp, ep;
     int moveNum;
     while(cin>>sx>>sy>>ex>>ey)
     {
          init();
          sp.x = sx - 'a' + 1;
          sp.y = sy - '0';
          ep.x = ex -'a' + 1;
          ep.y = ey - '0';
          if(sx == ex && sy == ey)
          {
               moveNum = 0;
          }
          else
          {
               moveNum = bfs(sp, ep);
          }
         
          cout<<"To get from "<<sx<<sy<<" to "<<ex<<ey<<" takes "<<moveNum<<" knight moves."<<endl;
     }
     return 0;
}

