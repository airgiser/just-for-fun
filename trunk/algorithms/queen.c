/*!
 * \brief A demo about recursion.
 */
#include <stdio.h>

#define NUM 8
#define DG_NUM (NUM * 2) - 1
static char Queen[NUM][NUM];
static char colflag[NUM];
static char diagonal[DG_NUM];
static char rdiagonal[DG_NUM];
static int status_num = 0;

void output()
{
    int col = 0;
    int row = 0;
    
    printf("Status %d: \n", ++status_num);

    for(col = 0; col < NUM; col++)
    {
        for(row = 0; row < NUM; row++)
        {
            printf("%c ", Queen[col][row]);
        }
        printf("\n");
    }
}

void dispose(int line)
{
    int col = 0;
    
    for(col = 0; col < NUM; col++)
    {
        // esurience 
        if(colflag[col] == 0 &&
                diagonal[line + NUM - col - 1] == 0 &&
                rdiagonal[line + col] == 0)
        {
            Queen[line][col] = '@';
            colflag[col] = 1;
            diagonal[line + NUM - col - 1] = 1;
            rdiagonal[line + col] = 1;

            if(line < NUM - 1)
            {
                // recursion
                dispose(line + 1);
            }
            else
            {
                output();
            }

            // back track.
            Queen[line][col] = '*';
            colflag[col] = 0;
            diagonal[line + NUM - col - 1] = 0;
            rdiagonal[line + col] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    int col = 0;
    int line = 0;

    // Initialize
    for(col = 0; col < NUM; col++)
    {
        colflag[col] = 0;
        for(line = 0; line < NUM; line++)
        {
            Queen[col][line] = '*';
        }
    }
    for(line = 0; line < DG_NUM; line++)
    {
       diagonal[line] = rdiagonal[line] = 0;
    } 
    
    //
    dispose(0);

    return 0;
}
