#include <stdio.h>
#include <stdlib.h>     // for rand() and srand()
#include <time.h>       // for random number generator

// Size of the array NxN - It will be set by user
// It is for passing board array to functions
int ARRAY_SIZE = 0;             

static int energy_level = 20;   // Initial energy level
static int time_counter = 1;    // Initial time

#define TORTOISE '@'    // Tortoise character
#define MULBERRY '*'    // Mulberry character
#define PIT 'O'         // Pit character
#define EMPTY '_'       // Empty character

// Directions - West = 'W' - East = 'E' - North = 'N' - South = 'S'
#define WEST 'W'
#define EAST 'E'
#define NORTH 'N'
#define SOUTH 'S'

#define MOVE 'M'        // Move command
#define EAT 'E'         // Eat command

int tortoise_x = 0;     // Tortoise x coordinate
int tortoise_y = 0;     // Tortoise y coordinate

int mulberry_number = 0;     // Mulberry x coordinate

// Random number generator
static int random_num(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Fill board with specified characters
void fill_board(char board[][ARRAY_SIZE], int size)
{
    // Initialize board with empty character
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            board[i][j] = EMPTY;
        }
    }

    // There is only one TORTOISE
    // MULBERRY is ~15% of the board
    // PIT is ~5% of the board

    // Place tortoise
    tortoise_x = random_num(0, size - 1);
    tortoise_y = random_num(0, size - 1);

    board[tortoise_x][tortoise_y] = TORTOISE;

    // Place MULBERRY
    mulberry_number = size * size * 0.15 + 0.5;  // +0.5 for rounding
    if (mulberry_number < 1)
    {
        mulberry_number = 1;
    }
    for (i = 0; i < mulberry_number; i++)
    {
        int mulberry_x = random_num(0, size - 1);
        int mulberry_y = random_num(0, size - 1);

        if (board[mulberry_x][mulberry_y] == EMPTY)
        {
            board[mulberry_x][mulberry_y] = MULBERRY;
        }
        else
        {
            i--;
        }
    }

    // Place PIT
    int pit_number = size * size * 0.05 + 0.5;  // +0.5 for rounding
    if (pit_number < 1)
    {
        pit_number = 1;
    }
    for (i = 0; i < pit_number; i++)
    {
        int pit_x = random_num(0, size - 1);
        int pit_y = random_num(0, size - 1);

        if (board[pit_x][pit_y] == EMPTY)
        {
            board[pit_x][pit_y] = PIT;
        }
        else
        {
            i--;
        }
    }
}

// Print board
void print_board(char board[][ARRAY_SIZE], int size)
{
    // Print board
    printf("Time = %d, Energy Level : %d\n", time_counter, energy_level);
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move(char board[][ARRAY_SIZE], int size, int direction)
{
    if (direction == WEST)
    {
        if (tortoise_y == 0)
        {
            printf("Tortoise can not move to the west\n");
            time_counter++;
            return;
        }
        else if (board[tortoise_x][tortoise_y - 1] == MULBERRY)
        {
            printf("Tortoise can not move to the west\n");
            time_counter++;
            return;
        }
        else
        {
            board[tortoise_x][tortoise_y] = EMPTY;
            tortoise_y--;
        }
    }
    else if (direction == EAST)
    {
        if (tortoise_y == size - 1)
        {
            printf("Tortoise can not move to the east\n");
            time_counter++;
            return;
        }
        else if (board[tortoise_x][tortoise_y + 1] == MULBERRY)
        {
            printf("Tortoise can not move to the east\n");
            time_counter++;
            return;
        }
        else
        {
            board[tortoise_x][tortoise_y] = EMPTY;
            tortoise_y++;
        }
    }
    else if (direction == NORTH)
    {
        if (tortoise_x == 0)
        {
            printf("Tortoise can not move to the north\n");
            time_counter++;
            return;
        }
        else if (board[tortoise_x - 1][tortoise_y] == MULBERRY)
        {
            printf("Tortoise can not move to the north\n");
            time_counter++;
            return;
        }
        else
        {
            board[tortoise_x][tortoise_y] = EMPTY;
            tortoise_x--;
        }
    }
    else if (direction == SOUTH)
    {
        if (tortoise_x == size - 1)
        {
            printf("Tortoise can not move to the south\n");
            time_counter++;
            return;
        }
        else if (board[tortoise_x + 1][tortoise_y] == MULBERRY)
        {
            printf("Tortoise can not move to the south\n");
            time_counter++;
            return;
        }
        else
        {
            board[tortoise_x][tortoise_y] = EMPTY;
            tortoise_x++;
        }
    }
    // If there is a pit, set energy level to 0 and return
    if (board[tortoise_x][tortoise_y] == PIT)
    {
        energy_level = 0;
        time_counter++;
        return;
    }

    // Move tortoise
    board[tortoise_x][tortoise_y] = TORTOISE;

    // Decrease energy level
    energy_level--;

    // Increase time
    time_counter++;
}

void eat(char board[][ARRAY_SIZE], int size, int direction)
{
    // If there is a mulberry in the specified direction, eat it, increase energy level and decrease mulberry number
    // set the mulberry to empty
    if (direction == WEST)
    {
        if (tortoise_y == 0)
        {
            printf("Tortoise can not eat to the west\n");
            return;
        }
        else
        {
            if (board[tortoise_x][tortoise_y - 1] == MULBERRY)
            {
                board[tortoise_x][tortoise_y - 1] = EMPTY;
            }
            else
            {
                printf("There is no mulberry to the west\n");
                return;
            }
        }
    }
    else if (direction == EAST)
    {
        if (tortoise_y == size - 1)
        {
            printf("Tortoise can not eat to the east\n");
            return;
        }
        else
        {
            if (board[tortoise_x][tortoise_y + 1] == MULBERRY)
            {
                board[tortoise_x][tortoise_y + 1] = EMPTY;
            }
            else
            {
                printf("There is no mulberry to the east\n");
                return;
            }
        }
    }
    else if (direction == NORTH)
    {
        if (tortoise_x == 0)
        {
            printf("Tortoise can not eat to the north\n");
            return;
        }
        else
        {
            if (board[tortoise_x - 1][tortoise_y] == MULBERRY)
            {
                board[tortoise_x - 1][tortoise_y] = EMPTY;
            }
            else
            {
                printf("There is no mulberry to the north\n");
                return;
            }
        }
    }

    energy_level += 20;
    mulberry_number--;
    time_counter++;
}

// Game logic
void game(char board[][ARRAY_SIZE], int size)
{
    printf("------------------------------------\n");
    printf("\nInstructions:\n");
    printf("Commands are as follows: \n");
    printf("M: Move\n");
    printf("E: Eat\n\n");

    printf("Directions are as follows: \n");
    printf("W: Move West\n");
    printf("E: Move East\n");
    printf("N: Move North\n");
    printf("S: Move South \n");

    printf("usage: <Command> <Direction> \n");
    printf("------------------------------------\n");
    while(1)
    {
        // Print board
        printf("\n");
        print_board(board, size);

        // Check energy level
        if (energy_level <= 0)
        {
            printf("\nEnergy Level is: %d\n", energy_level);
            printf("Tortoise is dead\n");
            printf("YOU LOST :-(\n");
            printf("THE GAME IS OVER\n");
            break;
        }

        // Check mulberry number
        if (mulberry_number == 0)
        {
            printf("\nCONGRAGULATIONS, YOU WON :-)\n");
            break;
        }

        // Get direction
        char command, direction;
        printf("\nPlease enter an action: ");
        scanf(" %c", &command);
        scanf(" %c", &direction);

        if (!(command == MOVE || command == EAT))
        {
            printf("Invalid command\n");
            continue;
        }

        if (!(direction == WEST || direction == EAST || direction == NORTH || direction == SOUTH))
        {
            printf("Invalid direction\n");
            continue;
        }

        // Move tortoise
        if (command == MOVE)
        {
            move(board, size, direction);
        }
        else
        {
            eat(board, size, direction);
        }

        printf("\n====================================\n");
    }
}

int main()
{
    // Seed random number generator
    srand(time(NULL));  

    
    printf("Welcome to Tortoise Game\n\n");

    int size;
    printf("Please specify the size of the board: ");
    scanf("%d", &size);
    if (size > 50 || size < 2)
    {
        // Size 50 will not set to the screen and size 1 will not be able to place the tortoise, mulberry and pit
        printf("The size of the board cannot be greater than 50 or less than 2\n");
        return 1;
    }
    ARRAY_SIZE = size;
    // Create board
    char board[size][size];

    // Fill board
    fill_board(board, size);

    // Game
    game(board, size);
    printf("\n====================================\n");
    return 0;
}