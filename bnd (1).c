#include <stdio.h>

int solveSudoku(int sudoku[9][9], int row, int col)
{
    if(row<9 && col<9)
    {
        if(sudoku[row][col])//if the box is not 0 
        {
            if(col-8) return solveSudoku(sudoku, row, col+1);
            else if(row-8) return solveSudoku(sudoku, row+1, 0);
            else return 1;
        }
        else
        {
            for(int i=1; i<10;i++)//if box is 0, assign a number and check if it works
            {
                if(check(sudoku, row, col, i))
                {
                    sudoku[row][col] = i;
                    if(col-8)
                    {
                        if(solveSudoku(sudoku, row, col +1)) return 1;
                        else sudoku[row][col] = 0;
                    }
                    else if(row-8)
                    {
                        if(solveSudoku(sudoku, row+1, 0)) return 1;
                        else sudoku[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}
int check(int sudoku[9][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    for(int i=0; i<9; ++i)
    {
        if (sudoku[row][i] == num) return 0;
        if (sudoku[i][col] == num) return 0;
        if (sudoku[rowStart +i%3][colStart +i/3] == num) return 0;
    }
    return 1;
}
int main()
{
int sudoku[9][9];
for(int i=0;i<9;i++)
 for(int j=0;j<9;j++)scanf("%d ",&sudoku[i][j]);
    if(solveSudoku(sudoku, 0, 0))
    {
        for(int i=0; i<9;i++)
        {
            for(int j=0; j<9;j++) printf("%d ", sudoku[i][j]);//accept the initial unsolved sudoku with 0 as blank boxes
            printf("\n");
        }
    }
    else printf("NO SOLUTION\n");
return 0;
}
