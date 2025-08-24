/*
USE CONSTRUCTOR DESTRUCTOR
design class: cartitem
attributes : productname, quantity, priceperitem

default custonructor to initialize epty values
parameterized constructer to initialize items hwen added to the car
destructor to print a message like: item remove dfrom the cart

main to allow multiple itemsto be added and deleted

time taken:
*/
#include<iostream>
using namespace std;

int cartcount=0;

class CartItem
{
    public:
    string ProductName;
    int quantity;
    float PricePerItem;

    CartItem()
    {
        //default constructor
       ProductName = "default_product_name";
       quantity = 0;
       PricePerItem = 0.0;
       cartcount = cartcount +1;
       cout<<ProductName<<" was added to the cart. \nItems remaining in cart now are: "<<cartcount<<endl;

    }
    CartItem(string name, int Q, float ppi)
    {
        ProductName = name;
        quantity = Q;
        PricePerItem = ppi;
        cartcount = cartcount +1;
        cout<<ProductName<<" was added to the cart. \nItems remaining in cart now are: "<<cartcount<<endl;
    }

    int display()
    {
        cout<<"The product named: "<<ProductName<<" and having quantity: "<<quantity<<" and has a price of: "<<PricePerItem<<endl;
    }
    ~CartItem()
    {
        cartcount = cartcount -1 ;
        cout<<"The product named "<<ProductName<<" was deleted"<<endl;
        cout<<"Items in cart: "<<cartcount<<endl;
    }

};

int main()
{

    //using the default constructor
    CartItem item1;
    item1.display(); //to verify
    //attributes inputted
    cout<<".\n.\nCustomer check in.\nEnter details of the product...\n";
    cout<<"Enter product name: ";
    cin>>item1.ProductName;
    cout<<"Enter the quantity: ";
    cin>> item1.quantity;
    cout<<"Enter Price Per Item: ";
    cin>>item1.PricePerItem;

    //inputting attributes first
    string name;
    int quantity;
    float price;
    cout<<"Enter a name";
    cin>>name;
    cout<<"Enter quantity: " ;
    cin>>quantity;
    cout<<"Enter price: ";
    cin>>price;
    //parameterized constructor
    CartItem item2(name,quantity,price);
    item2.display();
    
    //destructor called when main ends



}