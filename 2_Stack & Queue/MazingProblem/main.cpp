//
//  main.cpp
//  MazingProblem
//
//  Created by 高昊 on 2019/10/20.
//  Copyright © 2019年 高昊. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
using namespace std;

struct coor{
    int x;
    int y;
};
coor findNext(vector<vector<int>>,coor);

int main(int argc, const char * argv[]) {
    srand( time(NULL) );
    //srand(6);
    
    //產生迷宮
    cout<<"產生15*15的maze:"<<endl;
    vector<vector<int>> maze;
    for(int i=0;i<15;i++)
    {
        vector<int> temp;
        for(int j=0;j<15;j++)
        {
            int x = rand();
            temp.push_back(x%2);
        }
        maze.push_back(temp);
    }
    //設置出入口
    maze[0][1]=2;//起點:(0,1)
    maze[14][13]=2;//終點:(14,13)
    
    //印出迷宮
    for(int i=0;i<maze.size();i++)
    {
        for(int j=0;j<maze[i].size();j++)
        {
            cout<<maze[i][j]<<",";
        }cout<<endl;
    }
    
    //宣告stack
    bool flag=true;//true:有路 ; false:沒有錄
    vector<coor> stack;
    coor cur;cur.x=0;cur.y=1;
    //findNext(maze,cur);
    coor last;
    while(cur.x!=14 || cur.y!=13)
    {
        maze[cur.x][cur.y]=3;
        stack.push_back(cur);
        //coor last=cur;
        cur=findNext(maze,cur);
        if(cur.x==-1&&cur.y==-1)
        {
            //cout<<"往後退"<<endl;
            last=stack.back();
            maze[last.x][last.y]=4;
            stack.pop_back();
            cur=stack.back();
            stack.pop_back();
        }
        if(stack.size()==0)
        {
            flag=false;
            break;
        }
        //cout<<cur.x<<","<<cur.y<<endl;
    }
    
    if(flag)
    {
        cout<<"有路"<<endl;
    }
    else{
        cout<<"沒有路"<<endl;
    }
    //印出迷宮
    maze[0][1]=2;
    for(int i=0;i<maze.size();i++)
    {
        for(int j=0;j<maze[i].size();j++)
        {
           if(maze[i][j]!=3&&maze[i][j]!=2)
           {
                cout<<"*"<<",";
           }
           else
                cout<<maze[i][j]<<",";
        }cout<<endl;
    }
    
    return 0;
}

coor findNext(vector<vector<int>> map,coor cur_pos)
{
    //找出周圍
     coor next;
    //cout<<"找下一步"<<endl;
     int next_x[8]={0,1,1,1,0,-1,-1,-1};
     int next_y[8]={1,1,0,-1,-1,-1,0,1};
     for(int i=0;i<8;i++)
     {
        next.x=next_x[i]+cur_pos.x;
        next.y=next_y[i]+cur_pos.y;
        if(next.x<0||next.x>=15||next.y<0||next.y>=15)
        {
            continue;
        }
        if(map[next.x][next.y]==0||map[next.x][next.y]==2)
        {
         //cout<<next.x<<","<<next.y<<endl;
         return next;
        }
     }
    next.x=-1;next.y=-1;//代表沒路
    //cout<<next.x<<","<<next.y<<endl;
    return next;
}
