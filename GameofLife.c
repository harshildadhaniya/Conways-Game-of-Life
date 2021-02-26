#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int neighbours(char* input_arr, int row, int col, int max_row, int max_col){
    int nei_bours = 0;

    for(int r = row-1; r <= row+1; r++){
        for(int c = col-1; c <= col+1; c++){
            /*Go to surrounding cells of a location (r,c) except at (r,c) */    
            if ((r >= 0) && (r < max_row) && (c >= 0) && (c < max_col) && !((r == row) && (c == col))){
                if ((input_arr[r*max_row+c] == '0') || (input_arr[r*max_row+c] == 'D')){

                    nei_bours++;

                }
            }

        }
    }

    return nei_bours;
}

void step(char* input, int n, int m){
    /*Input is encoded as an 1D array of size n*m */

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            /* Calculate the neighbours of the current cell */

            int neighb = neighbours(input, i, j, n, m);

            /* Apply the rules of the game of life */
            /* Less than 2 or greater than 4 neighbours correspond to under and overpopulation aka dead cell */
            /* 3 neighbours of a dead cell is reproduction aka birth of a cell */

            if ((input[i*n+j] == '0') && ((neighb < 2) || (neighb >= 4))){
                input[i*n+j] = 'D';
            }
            else if ((input[i*n+j] == '_') && (neighb == 3)){
                input[i*n+j] = 'B'; 
            }

        }
    }

    /* The current array is encoded with 'B', 'D', '0', and '_'. */
    /* This needs to be simplified to only '0' and '_'. */

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            if (input[i*n+j] == 'B'){
                input[i*n+j] = '0';
            }
            else if (input[i*n+j] == 'D'){
                input[i*n+j] = '_';
            }

        }
    }

}

void print(char* input, int n, int m){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            printf("%c", input[i*n+j]);
        }

        printf("\n");
    }
}

void life(char* input, int n, int m){
    /* Check validity of the input */

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            if ((input[i*n+j] != '0') && (input[i*n+j] != '_')){
                printf("Invalid input.\n");
                printf("Unrecognized characters. Enter '0 for alive and '_' for dead cells.");
                return;
            }
        }
    }

    /* After being validated, display the beginning of the game */
    printf("You entered:\n");
    print(input, n, m);

    /* Once the input is validated, move forward with the game */

    int quit = 0;
    char c;

    printf("Press <Enter> to continue or type <Q> to quit: ");
    c = getchar();
    printf("\n");

    while(!quit){
        if (c == '\n'){
            step(input, n, m);
            print(input, n, m);
            printf("Press <Enter> to continue or type <Q> to quit: ");
            c = getchar();
        }
        else if(c == 'Q'){
                    quit = 1;
                }
        else{
            printf("Invalid input, type something else: ");
            if (c != '\n'){
                /* Flush buffer */
                while(getchar() != '\n'){
                    /* Do nothing */
                }
            }

            c = getchar();
        }
    }

}

int main(){

    char A[25] = {
        '_', '_', '_', '_', '_',
        '_', '_', '0', '_', '_',
        '_', '_', '0', '_', '_',
        '_', '_', '0', '_', '_',
        '_', '_', '_', '_', '_',
    };

    
    life(A, 5, 5);
    printf("Hope you had fun!!\n");
    printf("Thank you for playing\n");
    printf("\n");

    int option_val;

    printf("Would you like to continue with one more pattern?\n");
    printf("Press <1> for Yes and <0> for No: ");
    scanf("%d", &option_val);

    if (option_val == 0){
        return 1;
    }

    option_val = 0;

    char B[16] = {
        '_', '_', '_', '_',
        '_', '0', '0', '0',
        '0', '0', '0', '_',
        '_', '_', '_', '_',
    };

    life(B, 4, 4);
    printf("Hope you had fun!!\n");
    printf("Thank you for playing\n");
    printf("\n");

    printf("Would you like to continue with one more pattern?\n");
    printf("Press <1> for Yes and <0> for No: ");
    scanf("%d", &option_val);

    if (option_val == 0){
        return 1;
    }

    option_val = 0;


    char C[25] = {
        '_', '_', '_', '_', '_',
        '_', '0', '0', '0', '_',
        '_', '_', '0', '_', '_',
        '_', '_', '0', '_', '_',
        '_', '_', '_', '_', '_',
    };

    life(C, 5, 5);
    printf("Hope you had fun!!\n");
    printf("Thank you for playing\n");
    printf("\n");

    return 1;

}
