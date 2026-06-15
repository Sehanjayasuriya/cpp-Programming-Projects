#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function prototype
int roll_dice();
void play_game();

int main(){
    srand(time(NULL)); // to get a different result each time
    play_game(); //calling the function to play
    return 0;   
}

int roll_dice(){
    return rand() % 6+1; //generates a random number between 1 and 6
}

//function declaration
void play_game(){
    int dice_1, dice_2, dice_3, sum, point;

    // first roll
    dice_1=roll_dice();
    dice_2=roll_dice();
    dice_3=roll_dice();

    //gerring the sum of these dice values
    sum= dice_1+ dice_2 + dice_3;
    cout << "player rolled: " << dice_1 << " + " << dice_2 << " + " << dice_3 << " = " << sum << endl;

    if(sum >= 13){
        cout << "Player wins" << endl;
    }
    else if(sum <=6){
        cout << "Player loses" << endl;
    }
    else{
        //if the sum is between 7 and 12 sum = points
        point = sum;
        cout << "Point is " << point << endl;

        //continue rolling until sum >=15
        while(true){
            dice_1=roll_dice();
            dice_2=roll_dice();
            dice_3=roll_dice();

            sum = dice_1 + dice_2 + dice_3;
            cout << "player rolled: " << dice_1 << " + " << dice_2 << " + " << dice_3 << " = " << sum << endl;

            if(sum==point){
                cout << "Player wins " << point << endl;
                break;
            }
            else if(sum >= 15){
                cout << "Player loses" << endl;
                break;
            }

        }
    }
}