#include <stdio.h>
#include <stdlib.h>

char answer[9][9] = {
    {32,32,32,32,32,32,32,32,32},
    {32,32,32,32,'1','2',32,'2','1'},
    {32,32,32,32,'1','2','5','2','1'},
    {32,32,32,32,32,32,32,32,32},
    {32,32,'5',32,'1','1','1','1','1'},
    {32,32,'3',32,'0','1','1','1','0'},
    {32,32,'1',32,'0','0','1','0','0'},
    {32,32,'3',32,'0','1','1','1','0'},
    {32,32,'5',32,'1','1','1','1','1'}};

char user[9][9] = {
    {32,32,32,32,32,32,32,32,32},
    {32,32,32,32,'1','2',32,'2','1'},
    {32,32,32,32,'1','2','5','2','1'},
    {32,32,32,32,32,32,32,32,32},
    {32,32,'5',32,'*','*','*','*','*'},
    {32,32,'3',32,'*','*','*','*','*'},
    {32,32,'1',32,'*','*','*','*','*'},
    {32,32,'3',32,'*','*','*','*','*'},
    {32,32,'5',32,'*','*','*','*','*'}};

void map(char user[9][9], char answer[9][9]);
void K_O(int i, int j);
void K_X(int i, int j);
int Coordinates_check(int i, int j);

int count = 17;
int life = 3;

int main()
{
    while(1)
    {
        map(user,answer);
        break;
    }
    return 0;
}

void map(char user[9][9], char answer[9][9])
{
    int i,j,a,b;
    char k;

    for(a=0;a<9;a++){
        for(b=0;b<9;b++){
            printf("%2c", user[a][b]);}
            printf("\n");
    }

    printf("\n");

    while(1)
    {
        while(1)
            {
                int re;
                while(1)
                {
                    printf("enter 'x'coordinate(1~5) : ");
                    scanf("%d",&i);
                    getchar();
                    if(i<1 || i>5)
                    printf("the 'x' coordinate value is invalid\n\n");
                    else
                        break;
                }

                while(1)
                {
                    printf("enter 'y'coordinate(1~5) : ");
                    scanf("%d", &j);
                    getchar();
                    if(j<1 || j>5)
                        printf("the 'y' coordinate balue is invalid\n\n");
                        else
                            break;
                }

                re = Coordinates_check(i,j);
                if(re == 0)
                    break;
            }
            
            while(1)
            {
                printf("enter o or x: ");
                scanf("%c", &k);
                getchar();

                if(k == 'o')
                {
                    i+=3; j+=3;
                    system("clear"); printf("\n");
                    K_O(i,j);
                    break;
                }
                else if(k == 'x')
                {
                    i+=3; j+=3;
                    system("clear"); printf("\n");
                    K_X(i,j);
                    break;
                }
                else
                {
                    printf(" invalid input!\n\n");
                }
            }

            if(count <=0)
            {
                printf("congratulation\n");
                break;
            }
            if(life <=0)
            {
                printf("game over\n");
                break;
            }
    }
}

void K_O(int i, int j)
{
    int l;
    while(1)
    {
        if(answer[i][j] == '1')
        {
            user[i][j] = 'o';
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    printf("%2c",user[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("the o,x was correct\n\n");
            count -=1;
            break;
        }
        else
        {
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    printf("%2c",user[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            life -=1;
            printf("the o,x input was incorrect.\n\n");
            break;
        }
    }
}

void K_X(int i, int j)
{
    int l;
    while(1)
    {
        if(answer[i][j] == '1')
        {
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    printf("%2c",user[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            life -= 1;
            printf("the o,x input was incorrect\n\n");
            break;
        }
        else
        {
            user[i][j] = 'x';
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    printf("%2c", user[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            printf("the o,x input was correct\n\n");
            break;
        }
    }
}

int Coordinates_check(int i, int j)
{
    i+=3; j+=3;
    if(user[i][j] == '*')
        return 0;
        else if(user[i][j] == '0' || user[i][j] == 'x')
        {
            printf("the coordinate already entered \n\n");
            return 1;
        }
}
