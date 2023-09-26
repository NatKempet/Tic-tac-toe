#include <iostream>
#include <string>

using namespace std;

void display(string tic)
{
    for (int i = 1; i < 10; i++)
    {
        cout << tic[i - 1] << "|";
        if (i % 3 == 0)
        {
            cout << endl;
        }
    }
}

bool check(string tic)
{
    string player = "XO";
    for (int i = 0; i < player.size(); i++)
    {
        char c = player[i];
        // horizontal
        if (tic[0] == c && tic[1] == c && tic[2] == c)
        {
            return true;
        }
        if (tic[3] == c && tic[4] == c && tic[5] == c)
        {
            return true;
        }
        if (tic[6] == c && tic[7] == c && tic[8] == c)
        {
            return true;
        }
        // vertical
        if (tic[0] == c && tic[3] == c && tic[6] == c)
        {
            return true;
        }
        if (tic[1] == c && tic[4] == c && tic[7] == c)
        {
            return true;
        }
        if (tic[2] == c && tic[5] == c && tic[8] == c)
        {
            return true;
        }
        // diagonal
        if (tic[0] == c && tic[4] == c && tic[8] == c)
        {
            return true;
        }
        if (tic[2] == c && tic[4] == c && tic[6] == c)
        {
            return true;
        }
    }
}

// bool full(string tic)
// {
//     for (int i = 0; i < tic.size(); i++)
//     {
//         if (tic[i] == ' ')
//         {
//             return false;
//         }
//     }
// }
void ai(string &tic)
{
    if (tic[0] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[1] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[2] == 'O')
    {
        tic[6] = 'X';
        minmax(0);
    }
    if (tic[3] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[4] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[5] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[6] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[7] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
    if (tic[8] == 'O')
    {
        tic[2] = 'X';
        minmax(0);
    }
}
int main()
{
    string tic = "         ";
    int player;
    int turn;

    cout << "would you like to go first or second?(0 = first, 1 = second)" << endl;
    cin >> turn;
    while (!check(tic) && turn == 1)
    {
        ai(tic);
        display(tic);
    }
    while (!check(tic) && turn == 0)
    {
        cout << "please input a space (1-9)" << endl;
        cin >> player;
        if (tic[player] == 'X' || tic[player] == 'O')
        {
            cout << "this space is occupied" << endl;
            continue;
        }
        tic[player - 1] = 'O';
        ai(tic);
        display(tic);
    }
}