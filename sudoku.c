#include<raylib.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int board[9][9]={0};
    int clueR[9];
    int clueC[9];
    int r1,r2;
    int row=0,col=0,flag=0,clflag=0;
    int count=0;
    srand(time(NULL));
    
    for(int i=0;i<9;i++)
        
    {
        for(int j=0;j<9;j++)
        {
            if(count<9)
            {   
                r1=rand()%9;
                r2=rand()%9;
                if(board[r1][r2]==0) 
                {
                board[r1][r2]=count+1; 
                clueR[count]=r1;
                clueC[count]=r2;
                count++;
                }
            }
        }
    }
    
    InitWindow(820,820,"Sudoku");
    SetTargetFPS(30); 
    
    while(!WindowShouldClose())
    {
     
     if(IsKeyPressed(KEY_RIGHT)) row++;
     if(IsKeyPressed(KEY_LEFT))  row--;
     if(IsKeyPressed(KEY_UP))    col--;
     if(IsKeyPressed(KEY_DOWN))  col++;
     
     if(row>=9) row=8;
     if(col>=9) col=8;
     if(row<=0) row=0;
     if(col<=0) col=0;     
     
     flag=0;
     clflag=0;
                
      int key = GetKeyPressed();
      
      for(int i=0;i<9;i++)
      {
          if(row==clueR[i] && col==clueC[i]) {clflag=1;break;}
      }
      
      if(clflag==0)
      {          
      if (key >= KEY_ONE && key <= KEY_NINE) {
      board[row][col] = key - 48;
      }
      
      else if (key == KEY_ZERO) {
      board[row][col] = 0;
      }
      }
      

     for(int i=0;i<9;i++)
      {
          if(board[i][col]==board[row][col] && row!=i && board[i][col]>0) {flag=1;break;}
      }
      
      for(int i=0;i<9;i++)
      {
          if(board[row][i]==board[row][col] && col!=i && board[row][i]>0) {flag=1;break;}
      }
      
      for(int i=(row/3)*3;i<(row/3)*3+3;i++)
      {
          for(int j=(col/3)*3;j<(col/3)*3+3;j++)
          {
              if(i!=row && j!=col && board[i][j]>0)
              {
                  if(board[i][j]==board[row][col]) {flag=1;break;}
              }
          }
      }
        
        
     BeginDrawing();
     ClearBackground(BLACK);
     for(int i=0;i<9;i++)
     {
     for(int j=0;j<9;j++)
     {  
        DrawRectangle(10+90*i,10+90*j,80,80,BEIGE);
     }
     }
     
     for(int i=0;i<9;i++)
     {  
        DrawRectangle(10+90*clueR[i],10+90*clueC[i],80,80,SKYBLUE);
     }
              
     
     if(flag==0) DrawRectangle(10+row*90,10+col*90,80,80,YELLOW);
     if(flag==1) DrawRectangle(10+row*90,10+col*90,80,80,RED); 
     if(clflag==1) DrawRectangle(10+row*90,10+col*90,80,80,GREEN); 
      
      for(int i=0;i<9;i++)
     {
     for(int j=0;j<9;j++)
     {  
      if(board[i][j]>0)  DrawText(TextFormat("%d",board[i][j]),30+90*i,30+90*j,50,BLACK);
     }
     }
    
     DrawLineEx({275,0},{275,820},15.0,BLACK);
     DrawLineEx({545,0},{545,820},15.0,BLACK);
     DrawLineEx({0,275},{820,275},15.0,BLACK);
     DrawLineEx({0,545},{820,545},15.0,BLACK);
    
    EndDrawing();
    }
    
}