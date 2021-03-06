#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>

using namespace std;

class Date{
    /*
        This class is used to create objects of this type to hold birth date of customers
    */

    private:
    int day;
    int month;
    int year;

    public:
    Date(){}

    //setter funtions declaration
    void set_day(int);
    void set_month(int);
    void set_year(int);

    //getter functions declaration
    int get_day();
    int get_month();
    int get_year();

};

//definitions for getter and setter functions of Date class
void Date::set_day(int entered_day){
    day = entered_day;
}
void Date::set_month(int entered_month){
    month = entered_month;
}
void Date::set_year(int entered_year){
    year = entered_year;
}
int Date::get_day(){
    return day;
}
int Date::get_month(){
    return month;
}
int Date::get_year(){
    return year;
}


class Address{

    /*
        This class is used to create objects of this type to hold address of customers
    */

    private:
    string postal_code;
    string city;
    string street;


    public:
    Address(){};
    Address(string postal_code, string city, string street){
        this->postal_code = postal_code;
        this->city = city;
        this->street = street;
    }
    ~Address(){};

    //setter and getter functions declarations
    string get_postal_code();
    string get_city();
    string get_street();

    void set_postal_code(string);
    void set_city(string);
    void set_street(string);
};

//Getter and setter functions definitions of Address Class
string Address::get_postal_code(){
    return postal_code;
}
string Address::get_city(){
    return city;
}
string Address::get_street(){
    return street;
}

void Address::set_postal_code(string postal_code){
    this->postal_code = postal_code;
}
void Address::set_city(string city){
    this->city = city;
}
void Address::set_street(string street){
    this->street = street;
}   

class Motorcycle{

    /*
        Motorcycle class
    */
    
    private:

    //make variable holds the fulll name of the bike 
    string make;

    //reserved boolean flag used to give the bike a status, wether reserved by customers or not
    bool reserved;

    //the id plate used for reservation
    string id_plate;

    public:
    Motorcycle(){}
    Motorcycle(string make, string id_plate){
        this->make = make;
        this->id_plate = id_plate;
        reserved = false;
    }
    ~Motorcycle(){}

    //getter and setter functions declarations
    string get_make();
    string get_id_plate();
    bool is_reserved();

    void set_make(string);
    void reserve();
    void hand_in_bike();

};

// setter and getter functions definitions of class Motorcycle
string Motorcycle::get_make(){
        return make;
    }

bool Motorcycle::is_reserved(){
        return reserved;
    }

void Motorcycle::set_make(string make){
        this->make = make;
    }

void Motorcycle::reserve(){
        reserved = true;
    }

void Motorcycle::hand_in_bike(){
        reserved = false;
    }

string Motorcycle::get_id_plate(){
    return id_plate;
}


class Customer{

    private:
    string first_name;
    string last_name;
    string telephone_number;
    
    char driving_licence; //Holds the driving license type ( A,B, C etc..). 

    //reserved_any flag , used to check if the customer has already reserved a bike ( only one reservation fo the customer)
    bool reserved_any; 

    //Date and Address objects
    Date birth_date;
    Address address;

    public:
    Customer(){}
    Customer(string fn, string ln, string tel, char dl, int day, int month, int year, string postal, string city, string street){
        first_name = fn;
        last_name = ln;
        telephone_number = tel;
        driving_licence = dl;
        birth_date.set_day(day);
        birth_date.set_month(month);
        birth_date.set_year(year);
        address.set_postal_code(postal);
        address.set_city(city);
        address.set_street(street);
        this->reserved_any = false;
    }
    
    //overloading input and output stream objects for customer type 
    friend istream& operator>> (istream& is, Customer& cus);
    friend ostream& operator<< (ostream& os, Customer& cus);

    //Setter and getter functions definitions
    void rent(){
        reserved_any = true;
    }
    void hand_over(){
        reserved_any = false;
    }
    bool get_reservation_status(){
        return reserved_any;
    }

    string get_firstname(){
        return first_name;
    }

    string get_lastname(){
        return last_name;
    }
    char get_license(){
        return driving_licence;
    }
    string get_telephone(){
        return telephone_number;
    }
    Date get_date(){
        return birth_date;
    }
    Address get_address(){
        return address;
    }

};

//overloading input stream for customer objects
istream& operator>> (istream& is, Customer& cus) {

    int dd, mm, yyyy;  //holds user input dd= day of birth, mm= month of birth, yyyy = year of birth
    string postal, city, street;

    cout << endl << "First Name: ";
    is >> cus.first_name;
    cout << endl <<"Last Name: ";
    is >> cus.last_name;
    cout << endl << "Telephone: ";
    is >> cus.telephone_number;
    cout << endl << "Driving license(A, B or C): ";
    is >> cus.driving_licence;
    cout << endl << "Day of birth: ";
    is >> dd;
    cus.birth_date.set_day(dd);
    cout << endl << "Month of birth: ";
    is >> mm;
    cus.birth_date.set_month(mm);
    cout << endl << "Year of birth: ";
    is >> yyyy;
    cus.birth_date.set_year(yyyy);

    cout << endl << "Postal code: ";
    is >> postal;
    cus.address.set_postal_code(postal);

    cout << endl << "City: ";
    is >> city;
    cus.address.set_city(city);

    cout << endl << "Street: ";
    is >> street;
    cus.address.set_street(street);

    cus.hand_over();

    cout<<endl;

    return is;
}

//overloading output stream for customer objects
ostream& operator<< (ostream& os, Customer& cus) {

    os << "Cutomer Name: "<<cus.first_name <<" "<<cus.last_name<<endl;
    os << "Telephone: "<<cus.telephone_number<<endl;
    os << "Driving license: "<<cus.driving_licence<<endl;
    os << "Date of Birth: "<<cus.birth_date.get_day()<<"/"<<cus.birth_date.get_month()<<"/"<<cus.birth_date.get_year()<<endl;
    os << "Postal Code: "<<cus.address.get_postal_code()<<endl;
    os << "City: "<<cus.address.get_city()<<endl;
    os << "Street: "<<cus.address.get_street()<<endl;

    //checking reservation status
    if(cus.get_reservation_status()){
        os << "Has Reservation?: "<<"Yes"<<endl;
    }
    else{
        os << "Has Reservation?: "<<"No"<<endl;
    }
    return os;
}

class Reservation{
    /*
        Reservation class used for reservations for customers and bikes
    */
    public:
    //Each reservation object has customer and bike objects
    Customer *customer;
    Motorcycle *bike;

    Reservation(){}
    Reservation(Customer *cusP, Motorcycle &bikeP){
        customer = cusP;
        bike = &bikeP;
        customer->rent(); //setting customer reserved_any flag to true
        bike->reserve(); //setting bike reservation status to true
    }
    ~Reservation(){}

    void cancel_reservation();

};

void Reservation::cancel_reservation(){
    //setting the reservation flags in both objects to false when reseration is cancelled
    bike->hand_in_bike();
    customer->hand_over();
}


void showCustomers(list<Customer> &customer){
    /*This function is used to print out customers stored in the list*/

    list<Customer> :: iterator i ; //iterator

    if(customer.empty()){
        cout<<"List is empty"<<endl;
    }
    else{
        for(i=customer.begin();i !=customer.end(); i++){
            cout << *i;
            cout<< "----------------------"<<endl;
        }
    } 
}

void printAvailableBikes(Motorcycle bike[]){
    /*This function iterates over the bike array and prints out the available bikes*/
    cout<<"Available bikes"<<endl;
    cout<<"----------------"<<endl;
    for(int i=0; i<4; i++){
        if(!bike[i].is_reserved()){
            cout<<i+1<<"- "<<bike[i].get_make() <<", Plate Code: "<<bike[i].get_id_plate()<<endl;

        }
    }
}

void WriteReservationFile(list<Reservation> &reservations, ofstream& fileWriter){
    /*This function is used to write reservtions in the text file. the two parameters are the reservation list and the file writer object*/
    list<Reservation> :: iterator reservation_itr;
    fileWriter.open("reservations.txt");
    if(fileWriter.good())
    {   
        //iteration over the reservation list and writing into the text file
        for (reservation_itr=reservations.begin(); reservation_itr != reservations.end(); reservation_itr++)
        {
            fileWriter << reservation_itr->customer->get_firstname()
            << "\t" << reservation_itr->customer->get_lastname()
            << "\t" << reservation_itr->customer->get_telephone()
            << "\t" << reservation_itr->customer->get_license()
            << "\t" << reservation_itr->customer->get_date().get_day()
            << "\t" << reservation_itr->customer->get_date().get_month()
            << "\t" << reservation_itr->customer->get_date().get_year()
            << "\t" << reservation_itr->customer->get_address().get_postal_code()
            << "\t" << reservation_itr->customer->get_address().get_city()
            << "\t" << reservation_itr->customer->get_address().get_street()
            << "\t" << reservation_itr->bike->get_id_plate()<<endl;
        }
        
    }
    else{
        cout << "File cannot be accessed" << endl;
    }

    fileWriter.close();
}

int main(){
    
    int user_input; //holds user input

    //variables for customer information
    string first_name, last_name, id_plate, telephone; 
    int dd, mm, yyyy; // dd= day of birth, mm= month of birth, yyyy=year of birth
    string postal, city, street;
    char driving_lic; //driving license type

    bool is_found = false; //flag for customer to check if it's found
    bool bike_found = false; //flag for bike to check if it's found

    //reservation list to hold all reservation objects
    list<Reservation> reservations;
    //reservation iterator to iterate over the reservation list
    list<Reservation> :: iterator reservation_itr;

    //creating 4 objects of bikes
    Motorcycle suzuki("Suzuki Bandit", "S1");
    Motorcycle honda("Honda TransAlp", "H1");
    Motorcycle bmw("BMW F 650 GS", "B1");
    Motorcycle kawazaki("Kawasaki ZZR1400", "K1");

    //customer list and iterator
    list<Customer> customers_list;
    list<Customer> :: iterator customer_itr;

    //array of the 4 different bike objects
    Motorcycle motorcycles[4] = {suzuki, honda, bmw, kawazaki};

    //file stream objects for reading and writing
    ofstream fileWriter;
    ifstream fileReader;
    
    //creating pointers of customers and reservation
    Customer *c1;
    Reservation *r;

    
    //reading all reservation in the text file and creating objects of reservations, customers and push them to theirs lists
    fileReader.open("reservations.txt");

    if(fileReader.good())
    {
		while(fileReader >> first_name >> last_name >> telephone >> driving_lic >>dd >> mm >> yyyy >>postal >> city >> street>> id_plate)
    	{
			c1 = new Customer(first_name, last_name, telephone, driving_lic, dd, mm, yyyy, postal, city, street);
            c1->rent(); // changing reserved_any status
            customers_list.push_back(*c1);

            for(int i=0; i<4 ; i++){
                if (motorcycles[i].get_id_plate() == id_plate)
                {
                    motorcycles[i].reserve();
                    r = new Reservation(&*c1, motorcycles[i]);
                    break;
                }
                
            }
        	reservations.push_back(*r);
     	}
    }

    do{
        //Main menu
        cout<<"[1] Add Cutomers"<<endl
            <<"[2] List Customers"<<endl
            <<"[3] Reserve Bike "<<endl
            <<"[4] Hand-over Bike"<<endl
            <<"[5] List Reservation"<<endl
            <<"[0] Exit"<<endl
            <<"Enter Choice: ";
            
        cin>>user_input;

        try{

            switch(user_input){
           
                case 1:
                    /*Adding new customer using the overloaded input stream for customer object and then pushing to customer list*/
                    system("clear");
                    c1 = new Customer();
                    cin >> *c1;
                    customers_list.push_back(*c1);

                    break;
                    
                case 2:
                    //List customers
                    system("clear");
                    showCustomers(customers_list);
                    break;
                
                case 3: 
                    //Reserve a bike
                    system("clear");
                    printAvailableBikes(motorcycles);
                    cout<<"Enter the bike Plate code you with to reserve: ";
                    cin>>id_plate;

                    cout<<"Customer's first name: ";
                    cin>>first_name;
                    cout<<"Customer's last name: ";
                    cin>>last_name;
                    
                    //iterating over the customer list and get the customer object which matches with first and last name
                    for(customer_itr=customers_list.begin(); customer_itr !=customers_list.end(); customer_itr++){

                        if(customer_itr->get_firstname() == first_name && customer_itr->get_lastname() == last_name){
                            //if found, changing flag
                            is_found = true;

                        }
                        if(is_found && customer_itr->get_reservation_status() == true && customer_itr->get_license() == 'A'){
                            //check if customer has a previous reservation
                            cout<<"This customer already has a bike, cannot reserver another one"<<endl;
                        }

                        if (is_found && customer_itr->get_license() == 'A' && customer_itr->get_reservation_status() == false){
                            //check the validity of driving license 
                            for(int i=0; i<4; i++){
                                //iterating over the motorcycles array and reserve the bike if the condition is true
                                if(motorcycles[i].get_id_plate() == id_plate && !motorcycles[i].is_reserved()){
                                    
                                    motorcycles[i].reserve(); //changing bike status to reserved
                                    customer_itr->rent(); //chaning customer "reservation" status to true

                                    r = new Reservation(&*customer_itr, motorcycles[i]); //new reservation object
                                    reservations.push_back(*r);
                                    cout<<"Reserved Successfully!"<<endl<<endl;
                                    break;
                                }
                            }
                        }
                        
                        //is_found && customer_itr->get_reservation_status() == false && 
                        if(customer_itr->get_license() != 'A'){
                            
                            cout<<"Cannot make this reservation, because the driving license is not of type A"<<endl<<endl;
                        }
                    }

                    if(!is_found){
                        //if the entered first and last name , do not match with existing customer in the list
                        cout<<endl<<"No customer holding this name was found!"<<endl<<endl;

                    }

                    is_found = false; //reset flag to false for another time
                        
                    fileReader.close();
                    //writing to a file
                    WriteReservationFile(reservations, fileWriter);
                
                    break;

                case 4:

                    //Hand over a bike
                    system("clear");

                    cout<<"----Hand Over A bike----"<<endl;
                    cout<<"Enter Customer's first name: ";
                    cin>>first_name;
                    cout<<"Enter Customer's last name: ";
                    cin>>last_name;

                    //iterating over reservation list and delete reservation from the text file if first and last name match with any customer
                    for (reservation_itr=reservations.begin(); reservation_itr != reservations.end(); reservation_itr++)
                    {
                        if(reservation_itr->customer->get_firstname() == first_name && reservation_itr->customer->get_lastname() == last_name){
                            reservation_itr->cancel_reservation(); //changing flag values for both(customer and bike objects)
                            reservations.erase(reservation_itr); //remove from list
                            cout<<endl;
                            cout<<"Reservation deleted Successfully!"<<endl;
                            cout<<endl;
                            is_found = true;
                            break;
                        }
                    }

                    if(is_found){
                        fileReader.close();
                        for(customer_itr=customers_list.begin(); customer_itr !=customers_list.end(); customer_itr++){
                            if(customer_itr->get_firstname() == first_name && customer_itr->get_lastname() == last_name){
                                customer_itr->hand_over();

                        }
                    }
                        //rewrite the file with new values in the list
                        WriteReservationFile(reservations, fileWriter);

                        is_found = false;

                    }else{
                        cout<<"Reservation with this customer's name NOT found!"<<endl;
                    }
                
                    break;


                case 5:
                    /*Listing all reservation in the reservation list */
                    cout<<endl;
                    for (reservation_itr=reservations.begin(); reservation_itr != reservations.end(); reservation_itr++)
                    {
                        cout<<"Bike: "<<reservation_itr->bike->get_make()<<", Plate ID: "<<reservation_itr->bike->get_id_plate()<<
                        ", reserved by: "<<reservation_itr->customer->get_firstname()<<" "<<reservation_itr->customer->get_lastname()<<endl<<endl;
                    }

                case 0:
                        break;
                
                default:
                    cout<<"Wrong input"<<endl;
                    break ;         
            }  

        }
        catch(int msg){
            // catching error for later use
            cout<<""<<endl;
        }

    }while(user_input);

    return 0;
}

