#include <iostream>
using namespace std;

//function prototype
int get_quantity();
int get_product_code();
double calculate_product_cost(int,int);

int main(){
    int product_code, quantity;
    double total_cost = 0.0;
    int total_product = 0;

    while (true){
        product_code = get_product_code();

        //if product code -1 exit condition
        if (product_code == -1){
            break;
        }

        //get quantity and calculated cost
        quantity=get_quantity();
        double cost = calculate_product_cost(product_code,quantity);

        //check for invalid product code
        if(cost == -1){
            cout << "Error... Invalid Product Code, please enter the code again" << endl;
        }
        else{
            cout << "Total - $" << cost << endl;
            total_cost += cost; //total_cost = total_cost + cost
            total_product += quantity; // total_product = total_product + cost
        }
    }

    //display invoices
    cout << "\nInvoice" << endl;
    cout << "Total Number of Products: " << total_product << endl;
    cout << "Total Invoice Amount: $" << total_cost << endl;

    return 0;
}


//To get product code from user 
int get_product_code(){
    int product_code;
    cout << "product code : ";
    cin >> product_code;

    return product_code;
}

//To get quantity from user
int get_quantity(){
    int quantity;
    cout << "Quantity : ";
    cin >> quantity;

    //check for negative quantity
    while (quantity <= 0){
        cout << "Invalid quantity, please enter the quantity again: ";
        cin >> quantity;
    }
    return quantity;
}

//calculating the cost for each product
double calculate_product_cost(int product_code, int quantity){
    double cost = 0.0;

    switch (product_code){
        case 1: cost = 3.25 * quantity; //bread
            break;

        case 2: cost = 1.75 * quantity; //milk
            break;

        case 3: cost = 7.85 * quantity; //toilet roll
            break;
        
        case 4: cost = 0.35 * quantity; // banana
            break;
        
        default: cost = -1; //end of entry
            break;

    } 
    return cost;
}