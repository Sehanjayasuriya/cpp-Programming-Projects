#include <stdlib.h>
#include <time.h>
#include "splashkit.h"

void draw_star(int clr_value, double x, double y, int width, int height){
    color clr;
    //declare other variables as in task 3.2

    switch(clr_value){
        //write different case to select different colours according to the clr_value
        case 0: clr = COLOR_RED;
        break;

        case 1: clr = COLOR_GREEN;
        break;

        case 2: clr = COLOR_BLUE;
        break;

        case 3: clr = COLOR_YELLOW;
        break;

    }    
    double x2 = x+width;
    double y2= y+height;
    double left_x=x-width;
    double mid_y=y+height/2;
    double mid_x=x+width/2;
    double right_x=x2+width;
    double top_y=y-height;
    double bottom_y=y2+height;

    fill_rectangle(clr,x,y,width,height);

    fill_triangle(clr,x,y2,left_x,mid_y,x,y);
    fill_triangle(clr,x,y,mid_x,top_y,x2,y);
    fill_triangle(clr,x2,y,right_x,mid_y,x2,y2);
    fill_triangle(clr,x2,y2,mid_x,bottom_y,x,y2);//here give the commands to create the star
}

int main(){

    open_window("shape", 800, 600);
    clear_screen(COLOR_WHITE);
    srand(time(NULL));

    int row=1, column ;
    double x = 100, y = 100;

    while(row<=10)
    {
        column = 1;
        while(column <= row){
            draw_star(rand()%4, x,y,10, 10); //call draw_star function to draw the stars
            x+=50; //update the x-position here
            column++;
        }
        row++;
        x=100; //reset the x position so that the next row starts at the same position
        y+=50; //update the y position here to go to the next row

    }
    refresh_screen(60);
    delay(50000);
    return 0;

}