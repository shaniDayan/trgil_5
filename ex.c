#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* N*N maze. N is the number of rows or number of columns. */
#define N 10

/* Assuming each number has length of am most 10 characters. */
#define MAX_NUMBER_LENGTH 10


/* -------------------------------------------------------- */
unsigned int find_path_length(int valid_tiles[N][N],
                              unsigned int source_row,
                              unsigned int source_col,
                              unsigned int dest_row,
                              unsigned int dest_col);
bool isLegal(int valid_tiles[N][N], unsigned int row, unsigned int col);
bool find_path(int valid_tiles[N][N], unsigned int row, unsigned int col, unsigned int dest_row,
unsigned int dest_col, unsigned int *sum);
/*
unsigned int find_path(int valid_tiles[N][N], unsigned int row, unsigned int col, unsigned int dest_row,
unsigned int dest_col, unsigned int *sum);
*/


int main(){
    int valid_tiles[10][10]={0};
valid_tiles[0][5] = 1;
valid_tiles[1][3] = 1;
valid_tiles[1][4] = 1;
valid_tiles[1][5] = 1;
valid_tiles[1][6] = 1;
valid_tiles[1][7] = 1;
valid_tiles[2][1] = 1;
valid_tiles[2][2] = 1;
valid_tiles[2][3] = 1;
valid_tiles[2][5] = 1;
valid_tiles[3][3] = 1;



valid_tiles[3][5] = 1;
valid_tiles[3][6] = 1;
valid_tiles[3][7] = 1;
valid_tiles[4][3] = 1;
valid_tiles[4][7] = 1;
valid_tiles[4][8] = 1;
valid_tiles[5][1] = 1;
valid_tiles[5][2] = 1;
valid_tiles[5][3] = 1;
valid_tiles[5][5] = 1;
valid_tiles[5][6] = 1;
valid_tiles[5][7] = 1;
valid_tiles[6][1] = 1;
valid_tiles[6][5] = 1;
valid_tiles[6][7] = 1;

valid_tiles[6][8] = 1;
valid_tiles[6][9] = 1;
valid_tiles[7][1] = 1;
valid_tiles[7][2] = 1;
valid_tiles[7][3] = 1;
valid_tiles[7][7] = 1;

valid_tiles[8][1] = 1;
valid_tiles[8][3] = 1;
valid_tiles[8][5] = 1;
valid_tiles[8][6] = 1;
valid_tiles[8][7] = 1;
valid_tiles[8][8] = 1;
valid_tiles[9][1] = 1;
valid_tiles[9][2] = 1;
valid_tiles[9][3] = 1;

valid_tiles[1][8] = 1;
valid_tiles[6][4] = 1;

   unsigned int s = find_path_length(valid_tiles,
                                 1,
                                 8,
                                 6,
                                 4);    
    
    /* Print the returned solution path length. */

    return 0;
}

unsigned int find_path_length(int valid_tiles[N][N],
                              unsigned int source_row,
                              unsigned int source_col,
                              unsigned int dest_row,
                              unsigned int dest_col) {

    unsigned int* sum = 0 ;
    int sum1=0;
  find_path(valid_tiles,source_row, source_col, dest_row,dest_col, sum);
  for(int i=0; i<10;i++){
    for(int j=0;j<10;j++){
        if(valid_tiles[i][j]==-2){
            sum1++;
        }
    }
  }
  printf("sum is  %d\n\n", sum1);
  
   return 0;
}

bool isLegal(int valid_tiles[N][N], unsigned int row, unsigned int col){
   if(row >= 0 && row < N && col >= 0 && col < N && valid_tiles[row][col]==1){
       return true;
   }
  
    return false;
    
}


bool find_path(int valid_tiles[N][N], unsigned int row,
unsigned int col, unsigned int dest_row,
unsigned int dest_col, unsigned int* sum){
    if(valid_tiles[row][col] == 0 ){
        return false;
    } 
    valid_tiles[row][col] = -2;

    if (row == dest_row && col == dest_col){
        printf("we made it \n\n");
         return true; 
    }
    
     if( (isLegal( valid_tiles,row + 1, col)&& find_path(valid_tiles,row+1,col,dest_row,dest_col, sum) !=0) ||
       
        (isLegal(valid_tiles,row - 1, col)&& find_path(valid_tiles,row-1,col,dest_row,dest_col, sum)!=0) ||
     
        (isLegal(valid_tiles,row, col+1)&& find_path(valid_tiles,row,col+1,dest_row,dest_col, sum)!=0) ||
        (isLegal(valid_tiles, row, col-1)&& find_path(valid_tiles,row,col-1,dest_row,dest_col, sum)!=0)){
          return true;
        }
    valid_tiles[row][col] = 1;   
    return 0;
        
 }
