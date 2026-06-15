/*
Name : Sehan Madusha
student ID : 106223861
Name of the C file: 106223861_A_Qn3.cpp

Assignment 2 question 3
This program generates an array of 800 bars with random colors and heights 
drawing them as vertical bars, and allows the user to sort them using either bubble sort(sort 1) or selection sort(sort 2)
user can sort by clicking on sort buttons
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "splashkit.h"
#define SIZE 800
using namespace std;

//struct
struct sample{
    int value;
    color clr;
};

color get_color(int num){
    float hue;
    hue = static_cast<float>(num)/screen_height();
    return hsb_color(hue,0.7,0.8);

}

//sort 1 method bubble sort
void BubbleSort(sample data[]){
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (data[j].value > data[j + 1].value)
            {
                int temp = data[j].value;
                data[j].value = data[j + 1].value;
                data[j + 1].value = temp;
            }
        }
    }

}

//sort 2 selection sort
void SelectionSort(sample data[]){
    for(int i = 0; i < SIZE - 1; i++){
        int min_pos = i;

        //finding largest value
        for(int j = i + 1; j < SIZE; j++)
            if(data[j].value < data[min_pos].value){
                min_pos = j;
            }

        //swapping the value
        if(min_pos != i){
            int temp = data[i].value;
            data[i].value = data[min_pos].value;
            data[min_pos].value = temp;
        }
    }

}


void fill_array(sample data[]){
    int i;
    for(i=0; i < SIZE; i++ ){
        data[i].value = rand() % screen_height()-100;
        data[i].clr = get_color(data[i].value);
    }

}

void draw_bar(sample data[]){
    int i;
    float x, y;
    float rect_width = 1;
    for(i=0 ; i < SIZE; i++){
        x = rect_width * i ;
        y = screen_height() - data[i].value;
        fill_rectangle(data[i].clr, x, y, rect_width, data[i].value);
    }

}

//detecting button clicks
bool clicked_button(float x, float y, float w, float h){
    return mouse_clicked(LEFT_BUTTON) &&
        mouse_x() >= x && mouse_x() <= x + w &&
        mouse_y() >= y && mouse_y() <= y + h;
}

//drawing three buttons and red separation line
void DrawButton(){

    //draw button
    fill_rectangle(COLOR_GREEN, 10, 10, 120, 30);
    draw_text("Draw Bars", COLOR_BLACK, 25, 17);

    //sort 1 button
    fill_rectangle(COLOR_GREEN, 140, 10, 120, 30);
    draw_text("Sort 1", COLOR_BLACK, 175, 17);

    //sort 2 button
    fill_rectangle(COLOR_GREEN, 270, 10, 120, 30);
    draw_text("Sort 2", COLOR_BLACK, 305, 17);

    //red line
    fill_rectangle(COLOR_RED, 0, 87, 800, 5);
}

int main(){
    sample data[SIZE];
    open_window("Array rectangles", 800, 700);
    srand(time(NULL));
    fill_array(data);

    while(not quit_requested()){

        process_events();

        //if draw button is clicked, draw random bar selection
        if(clicked_button(10, 10, 120, 30)){
            clear_screen(COLOR_WHITE);
            fill_array(data);
        }

        //if sort 1 button is clicked, draws bubblt sort bar
        if(clicked_button(140, 10, 120, 30)){
            fill_array(data);
            clear_screen(COLOR_WHITE);
            BubbleSort(data);
        }

        //if sort 2 button is clicked, draw selection sort bar
        if(clicked_button(270, 10, 120, 30)){
            fill_array(data);
            clear_screen(COLOR_WHITE);
            SelectionSort(data);
        }
        DrawButton();
        draw_bar(data);
        refresh_screen(60);
    }
    return 0;
}