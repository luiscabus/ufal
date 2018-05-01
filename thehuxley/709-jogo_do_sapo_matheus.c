#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>
#include    <math.h>

int walk(int table[], int positions[], int players, int track)
{
    if(track == players)
    {
        return 0;
    }

    int pos = positions[track];

    printf("%d\n", pos);
    //printf("%d\n", table[pos]);

    walk(table, positions, players, track + 1);
}

int roll(int table[], int positions[], int size, int players, int rounds, int current_round, int player_track)
{
    int ratio;

    if(current_round == rounds)
    {
        walk(table, positions, players, 0);
        return 0;
    }

    //printf(" ultimo array = %d\n", table[size - 1]);
    int n;
    scanf ( "%d", &n);
    int jump = positions[player_track] + n;


    if( jump >= size - 1 )
    {
        ratio = jump / size;

        if(ratio > 1)
        {
            jump = jump - (ratio * size);
        }
        else
        {
            jump = jump - size;
        }
    }

    jump = jump + table[jump];

    if( jump >= size - 1 )
    {
        ratio = jump / size;

        if( ratio > 1 )
        {
            jump = jump - (size * ratio);
        }
        else
        {
            jump = jump - size;
        }
    }
    else if( jump < 0 )
    {
        ratio = (jump * -1) / size;

        if( ratio > 1 )
        {
            jump = ((size * ratio)+ 1) + jump;
        }
        else
        {
            jump = size + jump;
        }
    }

    //printf(" player %d, rodada %d, POS = %d\n", player_track , current_round, jump);

    positions[player_track] = jump;

    if(player_track == players - 1)
    {
        roll(table, positions, size, players, rounds, current_round + 1, 0);
    }
    else
    {
        roll(table, positions, size, players, rounds, current_round , player_track + 1);
    }

}

void init(int table[], int positions[], int players, int track)
{
    if(track == players)
    {
        return ;
    }

    positions[track] = 0;
    //printf(" %d initial position = %d\n", track, positions[track]);

    init(table, positions, players, track + 1);
}

void read(int array[], int size, int current)
{
    if(current == size)
    {
        return ;
    }

    scanf( "%d", &array[current] );
    read(array, size, current + 1);
    }               /* ----------  end of function read---------- */

    int main()
    {
        int size, players, rounds;
        scanf ( "%d %d %d", &size, &players, &rounds );

        int table[size];
        int positions[players];

        read(table, size, 0);
        init(table, positions, players, 0);
        roll(table, positions, size, players, rounds, 0, 0);

        return 0;
}               /* ----------  end of function main  ---------- */