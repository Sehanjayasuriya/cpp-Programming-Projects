#include "splashkit.h"
#include <string>

using namespace std;

// Constants to define layout made it global so it can be common to the whole code
const int ICON_SIZE = 60;
const int MARGIN = 25;
const int START_X_POS = 60;
const int START_Y_POS = 60;
const int DRAW_BTN_X = 60; 
const int DRAW_BTN_Y = 520; 
const int DRAW_BTN_WIDTH = 140;  
const int DRAW_BTN_HEIGHT = 40; 

// Function declaration
void render_interface()
{
    color border_color = COLOR_BLACK;

    // Drawing the shapes
    draw_rectangle(border_color, START_X_POS, START_Y_POS, ICON_SIZE, ICON_SIZE); // Square
    draw_rectangle(border_color, START_X_POS + ICON_SIZE + MARGIN, START_Y_POS, ICON_SIZE * 2, ICON_SIZE); // Rectangle
    draw_circle(border_color, START_X_POS + ICON_SIZE * 3 + MARGIN * 2 + 30, START_Y_POS + 30, 30); // Circle
    int triangle_x_pos = START_X_POS + ICON_SIZE * 4 + MARGIN * 3;
    draw_triangle(border_color, triangle_x_pos + ICON_SIZE / 2, START_Y_POS, triangle_x_pos, START_Y_POS + ICON_SIZE, triangle_x_pos + ICON_SIZE, START_Y_POS + ICON_SIZE); // Triangle

    // Drawing color selection
    int color_start_y = START_Y_POS + ICON_SIZE + MARGIN * 2;
    fill_rectangle(COLOR_BLUE, START_X_POS, color_start_y, ICON_SIZE, ICON_SIZE); // Blue
    fill_rectangle(COLOR_RED, START_X_POS + ICON_SIZE + MARGIN, color_start_y, ICON_SIZE, ICON_SIZE); // Red
    fill_rectangle(COLOR_BLACK, START_X_POS + ICON_SIZE * 2 + MARGIN * 2, color_start_y, ICON_SIZE, ICON_SIZE); // Black
    fill_rectangle(COLOR_GREEN, START_X_POS + ICON_SIZE * 3 + MARGIN * 3, color_start_y, ICON_SIZE, ICON_SIZE); // Green

    // Click to draw button
    draw_rectangle(border_color, DRAW_BTN_X, DRAW_BTN_Y, DRAW_BTN_WIDTH, DRAW_BTN_HEIGHT);
    draw_text("Click to draw", border_color, DRAW_BTN_X + 10, DRAW_BTN_Y + 10);
}

bool check_click(int x, int y, int width, int height)
{
    bool is_x_in_range = mouse_x() >= x && mouse_x() <= x + width;
    bool is_y_in_range = mouse_y() >= y && mouse_y() <= y + height;
    return is_x_in_range && is_y_in_range;
}

// Drawing the selected shape
void display_selected_shape(const string &shape_type, const string &color_choice)
{
    color chosen_color;
    if (color_choice == "Red") chosen_color = COLOR_RED;
    else if (color_choice == "Blue") chosen_color = COLOR_BLUE;
    else if (color_choice == "Green") chosen_color = COLOR_GREEN;
    else if (color_choice == "Black") chosen_color = COLOR_BLACK;
    else chosen_color = COLOR_WHITE; 

    // Defining the final shape layout
    const int FINAL_SHAPE_X = 400; 
    const int FINAL_SHAPE_Y = 300; 
    const int SHAPE_DIMENSION = 150;
    const int HALF_DIMENSION = SHAPE_DIMENSION / 2;

    if (shape_type == "Square")
    {
        fill_rectangle(chosen_color, FINAL_SHAPE_X - HALF_DIMENSION, FINAL_SHAPE_Y - HALF_DIMENSION, SHAPE_DIMENSION, SHAPE_DIMENSION);
    }
    else if (shape_type == "Rectangle")
    {
        fill_rectangle(chosen_color, FINAL_SHAPE_X - SHAPE_DIMENSION, FINAL_SHAPE_Y - HALF_DIMENSION, SHAPE_DIMENSION * 2, SHAPE_DIMENSION);
    }
    else if (shape_type == "Circle")
    {
        fill_circle(chosen_color, FINAL_SHAPE_X, FINAL_SHAPE_Y, HALF_DIMENSION);
    }
    else if (shape_type == "Triangle")
    {
        fill_triangle(chosen_color, FINAL_SHAPE_X, FINAL_SHAPE_Y - HALF_DIMENSION,
                      FINAL_SHAPE_X - HALF_DIMENSION, FINAL_SHAPE_Y + HALF_DIMENSION,
                      FINAL_SHAPE_X + HALF_DIMENSION, FINAL_SHAPE_Y + HALF_DIMENSION);
    }
}

int main()
{
    string shape_selected = "";
    string color_selected = "";
    bool is_ready_to_draw = false; 

    open_window("Draw Shape", 800, 600); 

    while (not quit_requested())
    {
        process_events();

        if (mouse_clicked(LEFT_BUTTON))
        {
            if (!is_ready_to_draw)
            {
                // Shape selection
                if (check_click(START_X_POS, START_Y_POS, ICON_SIZE, ICON_SIZE)) shape_selected = "Square";
                else if (check_click(START_X_POS + ICON_SIZE + MARGIN, START_Y_POS, ICON_SIZE * 2, ICON_SIZE)) shape_selected = "Rectangle";
                else if (check_click(START_X_POS + ICON_SIZE * 3 + MARGIN * 2, START_Y_POS, ICON_SIZE, ICON_SIZE)) shape_selected = "Circle";
                else if (check_click(START_X_POS + ICON_SIZE * 4 + MARGIN * 3, START_Y_POS, ICON_SIZE, ICON_SIZE)) shape_selected = "Triangle";

                // Color selection
                int color_pos_y = START_Y_POS + ICON_SIZE + MARGIN * 2;
                if (check_click(START_X_POS, color_pos_y, ICON_SIZE, ICON_SIZE)) color_selected = "Blue";
                else if (check_click(START_X_POS + ICON_SIZE + MARGIN, color_pos_y, ICON_SIZE, ICON_SIZE)) color_selected = "Red";
                else if (check_click(START_X_POS + ICON_SIZE * 2 + MARGIN * 2, color_pos_y, ICON_SIZE, ICON_SIZE)) color_selected = "Black";
                else if (check_click(START_X_POS + ICON_SIZE * 3 + MARGIN * 3, color_pos_y, ICON_SIZE, ICON_SIZE)) color_selected = "Green";

                // Draw button
                if (check_click(DRAW_BTN_X, DRAW_BTN_Y, DRAW_BTN_WIDTH, DRAW_BTN_HEIGHT))
                {
                    if (!shape_selected.empty() && !color_selected.empty())
                    {
                        is_ready_to_draw = true; 
                    }
                }
            }
        }

        clear_screen(COLOR_WHITE);

        if (not is_ready_to_draw)
        {
            render_interface();
            draw_text("Shape: " + shape_selected, COLOR_BLACK, START_X_POS + 400, START_Y_POS + MARGIN);
            draw_text("Color: " + color_selected, COLOR_BLACK, START_X_POS + 400, START_Y_POS + ICON_SIZE + MARGIN * 3);
        }
        
        else 
        {
            display_selected_shape(shape_selected, color_selected);
        }

        refresh_screen(60);
    }

    return 0;
}
