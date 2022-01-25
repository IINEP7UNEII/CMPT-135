// evenwins7.cpp

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// global variables


struct Gamestate {
    int marbles_in_middle;
    int human_marbles;
    int computer_marbles;
    int totalGames;
    int humanWins;
    int computerWins;

    Gamestate()
    {
        marbles_in_middle = -1;
        human_marbles = -1;
        computer_marbles = -1;
        totalGames = 0;
        humanWins = 0;
        computerWins = 0;
    }
};

enum class Player {
    human,
    computer
};

Player whose_turn;

void welcome_screen() {
    cout << "+-----------------------+\n"
         << "| Welcome to Even Wins! |\n"
         << "+-----------------------+\n";
    cout << "Even Wins is a two-person game. You start with\n";
    cout << "27 marbles in the middle of the table.\n";
    cout << "\n";
    cout << "Players alternate taking marbles from the middle.\n";
    cout << "A player can take 1 to 4 marbles on their turn, and\n";
    cout << "turns cannot be skipped. The game ends when there are\n";
    cout << "no marbles left, and the winner is the one with an even\n";
    cout << "number of marbles.";
    cout << "\n";
}

string marbles_str(int n) {
    if (n == 1) return "1 marble";
    return to_string(n) + " marbles";
}

void choose_first_player() {
   for (;;) {
        cout << "\nDo you want to play first? (y/n) --> ";
        string ans;
        cin >> ans;
        if (ans == "y") {
            whose_turn = Player::human;
            return;
        } else if (ans == "n") {
            whose_turn = Player::computer;
            return;
        } else {
            cout << "\nPlease enter 'y' if you want to play first,\n";
            cout << "or 'n' if you want to play second.\n";
        }
    }
} // choose_first_player

void next_player() {
    whose_turn = (whose_turn == Player::human) ? Player::computer : Player::human;
}

void print_board(Gamestate & game) {
    cout << "\n";
    cout << " marbles in the middle: " << game.marbles_in_middle
         << " " << string(game.marbles_in_middle, '*') << "\n";
    cout << "    # marbles you have: " << game.human_marbles << "\n";
    cout << "# marbles computer has: " << game.computer_marbles << "\n";
    cout <<  "\n";
}

// returns true if s is an int, and false otherwise
// https://www.cplusplus.com/reference/string/stoi/
bool is_int(const string& s) {
    try {
        stoi(s); // throws an invalid_argument exception if conversion fails
        return true;
    } catch (...) {
        return false;
    }
}

void human_turn(Gamestate & game) {
    // get number in range 1 to min(4, marbles_in_middle)
    int max_choice = min(4, game.marbles_in_middle);
    cout << "It's your turn!\n";
    for(;;) {
        cout << "Marbles to take? (1 - " << max_choice << ") --> ";
        string s;
        cin >> s;
        if (!is_int(s)) {
            cout << "\n  Please enter a whole number from 1 to " << max_choice
                 << "\n";
            continue;
        }

        // convert s to an int so it can be compared
        int n = stoi(s);
        if (n < 1) {
            cout << "\n  You must take at least 1 marble\n";
            continue;
        }
        if (n > max_choice) {
            cout << "\n  You can take at most " << marbles_str(max_choice)
                 << "\n";
            continue;
        }

        cout << "\nOkay, taking " << marbles_str(n) << " ...\n";
        game.marbles_in_middle -= n;
        game.human_marbles += n;

        return;
    } // for
} // human_turn

//Computer will take an even number of marbles (2 or 4) if the marbles left in the middle is odd
//if there are an even number of marbles in the middle, then the computer will take an odd number
//The strategy is not perfect because the player could still dictate the number of marbles they collect (odd or even)
void computer_turn(Gamestate & game) {
    cout << "It's the computer's turn ...\n";
    int max_choice = min(4, game.marbles_in_middle);

    int n = 0;

    if (game.marbles_in_middle % 2 == 0) //if even number of marbles in the middle
    {
        if (max_choice >= 3)
        {
            n = 3;
        }
        else
        {
            n = 1;
        }
    }
    else //if odd number of marbles in the middle
    {
        if (max_choice == 4)
        {
            n = 4;
        }
        else
        {
            n = 2;
        }
    }

    cout << "Computer takes " << marbles_str(n) << " ...\n";
    game.marbles_in_middle -= n;
    game.computer_marbles += n;
}

string randTaunt(){
    string taunt1 = "The computer wins: tremble before it's mighty brain!";
    string taunt2 = "OWNAGE!";
    string taunt3 = "Better luck next time!";
    string taunt4 = "CPU > Brain";
    string taunt5 = "Wombo Combo! Get rekt!";
    
    int randomTaunt = 0;
    randomTaunt = rand() % 5 + 1;

    switch (randomTaunt)
    {
        case 1:
        {
            return taunt1;
            break;
        }
        case 2:
        {
            return taunt2;
            break;
        }
        case 3:
        {
            return taunt3;
            break;
        }
        case 4:
        {
            return taunt4;
            break;
        }
        case 5:
        {
            return taunt5;
            break;
        }
    }
    return "Error in randomTaunt()";
}

void game_over(Gamestate & game) {
    cout << "\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
         << "!! All the marbles are taken: Game Over !!\n"
         << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
    print_board(game);
    if (game.human_marbles % 2 == 0) {
        ++game.humanWins;
        cout << "You are the winner! Congratulations!\n";
    } else {
        cout << randTaunt() << '\n';
        ++game.computerWins;
    }
}

void play_game(Gamestate & game) {
    // initialize the game state
    game.marbles_in_middle = 27;
    game.human_marbles = 0;
    game.computer_marbles = 0;
    print_board(game);

    for (;;) {
        if (game.marbles_in_middle == 0) {
            ++game.totalGames;
            game_over(game);
            return;
        } else if (whose_turn == Player::human) {
            human_turn(game);
            print_board(game);
            next_player();
        } else if (whose_turn == Player::computer) {
            computer_turn(game);
            print_board(game);
            next_player();
        }
    } // for
} // play_game

int main() {
    srand(time(NULL));

    welcome_screen();

    Gamestate game;

    for(;;) {
        choose_first_player();
        play_game(game);

        cout << "\nStatistics"
             << "\n----------"
             << "\ntotal games: " << game.totalGames
             << "\nhuman wins: " << game.humanWins
             << "\ncomputer wins: " << game.computerWins;

        // ask if the user if they want to play again
        cout << "\n\nWould you like to play again? (y/n) --> ";
        string again;
        cin >> again;
        if (again == "y") {
            cout << "\nOk, let's play again ...\n";
        } else {
            cout << "\nOk, thanks for playing ... goodbye!\n";
            return 0;
        }
    } // for
} // main
