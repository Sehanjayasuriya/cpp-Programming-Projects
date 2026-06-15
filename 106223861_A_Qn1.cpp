/*
Name: Sehan Madusha
Student ID: 106223861
Name of the C file: 106223861_A_Qn1.cpp

Asiignment 2 question 1
This program checks if a credit card number is valid by using a checksum calculation mathod
it takes input digits from the useer, and then runs it through the luhn algorithm,
and check whether the final digit matches the calculated checksum. if the checksum matches
to the last digit the credit card number user entered is valid.
*/
#include <iostream>
using namespace std;

//function prototype
int calc_sum1(int*, int);
int calc_sum2(int*, int);
bool calculate_check_sum(int*, int);


int main(){
    int array[20];
    int size = 0;
    int num;

    // getting the user inputs until user enters -1 or Array is full
    cout << "Enter credit card number : ";
    for (int i = 0; i < 20; i++) {
        cin >> num;
        if (num == -1) break;
        array[size] = num;
        size++;

    }
    cout << endl << endl;

    // Displaying the credit card number as an output
    cout << "Credit card number is: ";
    for (int i = 0; i < size; i++) {
        cout << array[i];
    }
    cout << endl;

    calculate_check_sum(array, size);


    return 0;
}

//calculating sum1
int calc_sum1(int* array, int size){
    int sum1=0;
    int store[20]; // to store values used in sum1 for display
    int count = 0;

    //the loop start from second last digit, move from right to left, get every second digit 
    for(int i= size - 2; i >= 0; i-= 2){
        store[count++] = array[i]; //assigning array[i] (array[18]) value to store[count++] (store[1]) value and save save it for later display

        int DoubleDigit = array[i] * 2;
        if(DoubleDigit >= 10){
            sum1 += DoubleDigit - 9; // subtract 9 instead of summing the two digits 
            // ex: 7 + 7 = 14 --> 1 + 4 = 5 --> 14(double digit) - 9 = 5 
        }
        else{
            sum1 += DoubleDigit;
        }
    }

    cout << "Numbers for sum1 are: ";
    for(int i = count - 1; i >= 0; i--){
        cout << store[i] << " ";
    }
    cout << endl;
    cout << "sum 1 is " << sum1 << endl;
    return sum1; 
}

//calculating sum2
int calc_sum2(int* array, int size){
    int sum2 = 0;
    int store[20];
    int count = 0;

    //the loop start from third last digit, move from right to left, get every second digit 
    for(int i = size - 3; i >= 0; i-= 2){
        store[count++] = array[i];
        sum2 += array[i];
    }

    cout << "Numbers for sum2 are: ";
    for(int i = count - 1; i >= 0; i--){
        cout << store[i] << " ";
    }
    cout << endl;
    cout << "Sum 2 is " << sum2 << endl;
    return sum2;

}

// To calculate check sum and validate the card number
bool calculate_check_sum(int *array, int size){

    int sum1 = calc_sum1(array, size);
    int sum2 = calc_sum2(array, size);

    int total_sum = sum1 + sum2;
    int check_sum = (total_sum * 9) % 10;

    cout << "Check sum is " << check_sum << endl;
    cout << "Last digit on credit card is " << array[size - 1] << endl;

    //checkin whether the checksum is equal to last digit of the credit card number
    if(check_sum == array[size - 1]){
        cout << "Check sum " << check_sum << " and the last digit " << array[size - 1] << " are the same: Valid credit card number" << endl;
        return true;
    }
    else{
        cout << "Check sum " << check_sum << " and the last digit " << array[size - 1] << " are not the same: Invalid credit card number" << endl;
        return false;
    }
}




