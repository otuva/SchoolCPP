/*
 * Onur Alp
 * Akin
 * 200709011
 * Faculty of Engineering
 * Computer Engineering
 * CEN-104-50-50 | Object Oriented Programming
 * 2020-2021 Summer Term
 * Project 1
 * Ahmet COŞKUNÇAY
 */

//Library Declarations
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

//Function Prototypes
void TakePlayerNumber(int&);

void Swap(int*, int*);

void RandomizeArray(int[], int);

void CreateCards(int[][15], int);

void AssignCards(int[][15], int[][15], int);

void DrawNumbers(int[], int);

void PrintCards(int[][15], int);

bool CheckForCinko(int[][15], int, int, int, int[]);

void CheckNumbers(const int[], int[][15], int, int, int[]);

void AddSetPoints(int[], int[], int);

void InitializePoints(int[], int);

void DeclareWinner(int[], int);

//main Function
int main() {
    int tombalaCards[10][15], playerNum=0, drawnNumbers[90];

    // creating base cards
    CreateCards(tombalaCards, 10);

    TakePlayerNumber(playerNum);

    int points[playerNum];
    int finalPoints[playerNum];
    InitializePoints(points, playerNum);
    InitializePoints(finalPoints, playerNum);

    int playerCards[playerNum][15];
    AssignCards(tombalaCards, playerCards, playerNum);

    DrawNumbers(drawnNumbers, 90);

    CheckNumbers(drawnNumbers, playerCards, 90, playerNum, points);

    AddSetPoints(points, finalPoints, playerNum);

    for (int i=0; i<2; ++i) {
        CreateCards(tombalaCards, 10);
        AssignCards(tombalaCards, playerCards, playerNum);
        DrawNumbers(drawnNumbers, 90);
        CheckNumbers(drawnNumbers, playerCards, 90, playerNum, points);
        AddSetPoints(points, finalPoints, playerNum);
    }

    DeclareWinner(finalPoints, playerNum);

    return 0;
}

//Function Definitions
void TakePlayerNumber(int &player) {
    //If not in range [2,5] it'll keep asking
    while (player<2 || player > 5) {
        cout << "Number of Players (min:2, max:5): ";
        cin >> player;
    }
}

void Swap(int *a, int *b) {
    //simple swap
    int temp = *a;
    *a = *b;
    *b = temp;
}

void RandomizeArray(int arr[], int n) {
    // Using a different seed value so that
    // code won't get same result each call
    srand(time(nullptr)+rand()%256);

    // Starting from the last element and swap one by one.
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);

        // Swap arr[i] with the element at random index
        Swap(&arr[i], &arr[j]);
    }
}

void CreateCards(int arr[][15], int N) {
    // using tab to format one line below
    cout << "   Loading Tombala Cards...\n\n";
    int range = 90, i;
    int numbers[range];

    //initialize numbers
    for (i=0; i<range; ++i) {
        numbers[i] = i+1;
    }

    //assign cards
    for (i=0; i<N; ++i) {
        cout << "Card number " << i << ": ";
        //randomize each iteration for maximum randomness
        RandomizeArray(numbers, 90);
        for (int j=0; j<15; ++j) {
            arr[i][j] = numbers[j];
            cout << setw(3) << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void AssignCards(int allCards[][15], int playerCards[][15], int players) {
    // initialize array
    int cardsIndex[10], i;
    for (i=0; i<10; ++i) {
        cardsIndex[i] = i;
    }

    RandomizeArray(cardsIndex, 10);

    cout << "Card numbers selected for players:" << endl;

    for (i=0; i<players; ++i) {
        cout << cardsIndex[i] << ' ';
    }
    cout << "\n\n";

    // after randomized index.
    // update playing cards
    for (i=0; i<players; ++i){
        cout << "Player " << i << "’s Tombala Card:";
        for (int j=0; j<15; ++j) {
            playerCards[i][j] = allCards[cardsIndex[i]][j];
            cout << setw(3) << playerCards[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void DrawNumbers(int arr[], int N) {
    cout << "Numbers Drawn:" << endl;

    //initialize array
    int i;
    for (i=0; i<N; ++i) {
        arr[i] = i+1;
    }

    RandomizeArray(arr, N);

    for (i=0; i<N; ++i) {
        if (i%10==0 && i!=0) {
            cout << '\n';
        }
        cout << setw(3) << arr[i] << ' ';
    }

    cout << "\n\n";
}

void PrintCards(int cards[][15], int players) {
    for (int i=0; i<players; i++) {
        for (int j=0; j<15; ++j) {
            cout << setw(3) << cards[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool CheckForCinko(int cards[][15], int hit, int player, int totalPlayers, int status[]) {

    bool isDone = false;

    if (hit == 5 && status[player] == 0) {
        status[player] += 5;
        cout << "Winner of the first “Cinko” is Player " << player << endl;
        PrintCards(cards, totalPlayers);
    }
    else if (hit == 10 && status[player] == 5) {
        status[player] += 10;
        cout << "Winner of the second “Cinko” is Player " << player << endl;
        PrintCards(cards, totalPlayers);
    }
    else if (hit == 15 && status[player] == 15) {
        status[player] += 15;
        cout << "Winner of the Tombala is Player " << player << endl;
        PrintCards(cards, totalPlayers);
        isDone = true;
    }

    return isDone;
}

void CheckNumbers(const int allNumbers[], int allPlayerCards[][15], int numberSize, int players, int points[]) {
    int hitNumber;
    // all numbers
    for (int i=0; i<numberSize; i++) {
        // all cards
        for (int j=0; j<players; ++j) {
            hitNumber=0;
            // all numbers on one card
            for (int k=0; k<15; ++k) {
                // if current number hits one update to -1
                if (allNumbers[i] == allPlayerCards[j][k]) {
                    allPlayerCards[j][k] = -1;
                }
                // while parsing thru
                // keep track of -1 to check for cinko
                if (allPlayerCards[j][k] == -1) {
                    hitNumber += 1;
                    if (hitNumber%5==0 && hitNumber!=0) {
                        // if it's tombala then finish the current set.
                        if (CheckForCinko(allPlayerCards, hitNumber, j, players, points)){
                            return;
                        }
                    }
                }
            }
        }
    }
}

void AddSetPoints(int currentSet[], int final[], int N) {
    for (int i=0; i<N; ++i) {
        final[i] += currentSet[i];
        currentSet[i] = 0;
    }
}

void InitializePoints(int p[], int N) {
    for (int i=0; i<N; ++i) {
        p[i] = 0;
    }
}

void DeclareWinner(int p[], int N) {
    int max = p[0];
    int winner = 0;

    // I'm not considering draw
    // because there was no indication to consider that.
    for (int i=0; i<N; ++i) {
        cout << "Player " << i << ": " << p[i] << " points." << endl;
        if (p[i] > max) {
            max = p[i];
            winner = i;
        }
    }

    cout << "The winner is player " << winner << endl;
}
