//motorcycle reserved once ( flag)
//customer reserve only one (flag)

//customers list which will be used to check reservations


//class Bike ... name and reserved(boolean0)
//class Customer ->has bike object
//class reservation

#include <iostream>
#include <list>
#include <fstream>

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

    string get_postal_code();
    string get_city();
    string get_street();

    void set_postal_code(string);
    void set_city(string);
    void set_street(string);
};

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
    
    private:
    string make;
    bool reserved;
    string id_plate;

    public:
    Motorcycle(){}
    Motorcycle(string make, string id_plate){
        this->make = make;
        this->id_plate = id_plate;
        reserved = false;
    }
    ~Motorcycle(){}

    string get_make();
    string get_id_plate();
    bool is_reserved();

    void set_make(string);
    void reserve();
    void hand_in_bike();

};

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
    char driving_licence; // letter like A, C ,B or nothing(no driving license - > cannot reserve)
    bool reserved_any; 
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
        reserved_any = false;
    }
    
    friend istream& operator>> (istream& is, Customer& cus);
    friend ostream& operator<< (ostream& os, Customer& cus);

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

istream& operator>> (istream& is, Customer& cus) {

    int dd, mm, yyyy;
    string postal, city, street;

    cout << endl << "First Name: ";
    is >> cus.first_name;
    cout << "Last Name: ";
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

    return is;
}

ostream& operator<< (ostream& os, Customer& cus) {

    os << "Cutomer Name: "<<cus.first_name <<" "<<cus.last_name<<endl;
    os << "Telephone: "<<cus.telephone_number<<endl;
    os << "Driving license: "<<cus.driving_licence<<endl;
    os << "Date of Birth: "<<cus.birth_date.get_day()<<"/"<<cus.birth_date.get_month()<<"/"<<cus.birth_date.get_year()<<endl;
    os << "Postal Code: "<<cus.address.get_postal_code()<<endl;
    os << "City: "<<cus.address.get_city()<<endl;
    os << "Street: "<<cus.address.get_street()<<endl;
    if(cus.get_reservation_status()){
        os << "Has Reservation?: "<<"Yes"<<endl;
    }
    else{
        os << "Has Reservation?: "<<"No"<<endl;
    }
    
    return os;
}

class Reservation{

    public:
    Customer customer;
    Motorcycle bike;

    
    Reservation(Customer customer, Motorcycle bike){
        this->customer = customer;
        this->bike = bike;
        this->customer.rent();
        this->bike.reserve();
    }
    ~Reservation(){}

    // Motorcycle get_motorcycle(){
    //     return bike;
    // }
    // Customer get_customer(){
    //     return customer;
    // }

    void cancel_reservation();

};

void Reservation::cancel_reservation(){
    bike.hand_in_bike();
    customer.hand_over();
}


void showCustomers(list<Customer> &customer){
    list<Customer> :: iterator i ;

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

    cout<<"Available bikes"<<endl;
    cout<<"----------------"<<endl;
    for(int i=0; i<4; i++){
        if(!bike[i].is_reserved()){
            cout<<i+1<<"- "<<bike[i].get_make() <<", Plate Code: "<<bike[i].get_id_plate()<<endl;

        }
    }
}

Customer* findCustomer(list<Customer> customer, string first_name, string last_name){
    list<Customer> :: iterator i;
    for(i=customer.begin();i !=customer.end(); i++){
            if(i->get_firstname() == first_name && i->get_lastname() == last_name){
                return &*i;
        }   
    }
    return nullptr;

}

int main(){

    int user_input;
    string first_name, last_name, id_plate, telephone;
    int dd, mm, yyyy;
    string postal, city, street;
    char driving_lic;
    Customer *customer_found = nullptr;
    bool is_found = false;

    list<Reservation> reservations;
    list<Reservation> :: iterator reservation_itr;

    Motorcycle suzuki("Suzuki Bandit", "S1");
    Motorcycle honda("Honda TransAlp", "H1");
    Motorcycle bmw("BMW F 650 GS", "B1");
    Motorcycle kawazaki("Kawasaki ZZR1400", "K1");

    list<Customer> customers_list;
    list<Customer> :: iterator customer_itr;

    Motorcycle motorcycles[4] = {suzuki, honda, bmw, kawazaki};

    ofstream fileWriter;
    ifstream fileReader;
    
    Customer *c1;
    Reservation *r;

    // fileWriter.open("reservations.txt");
    // if(fileWriter.good())
    // {
    //     cout<<"MAJD"<<endl;
    // }

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
                    r = new Reservation(*c1, motorcycles[i]);
                }
                
            }
        	reservations.push_back(*r);
     	}
        
    }

    

    do{
        cout<<"[1] Add Cutomers"<<endl<<"[2] List Customers"<<endl<<"[3] Reserve Bike "<<endl<<"[4] Hand-over Bike"<<endl<<"[5] List Reservation"<<endl<<"[0] Exit"<<endl;
        cin>>user_input;

        try{

            switch(user_input){
           
                case 1:

                    c1 = new Customer();
                    cin >> *c1;
                    customers_list.push_back(*c1);

                    break;
                    
                case 2:
                    //List customers
                    showCustomers(customers_list);
                    break;
                
                case 3: 
                    //Reserve a bike

                    printAvailableBikes(motorcycles);
                    cout<<"Enter the bike Plate code you with to reserve: ";
                    cin>>id_plate;
                    cout<<"Customer's first name: ";
                    cin>>first_name;
                    cout<<"Customer's last name: ";
                    cin>>last_name;
                    

                    for(customer_itr=customers_list.begin(); customer_itr !=customers_list.end(); customer_itr++){

                        if(customer_itr->get_firstname() == first_name && customer_itr->get_lastname() == last_name){
                            is_found = true;
                            // cout<<"HERE"<<endl;
                        }
                        if(is_found && customer_itr->get_reservation_status() == true && customer_itr->get_license() == 'A'){
                            cout<<"This customer already has a bike, cannot reserver another one"<<endl;
                        }

                        if (is_found && customer_itr->get_license() == 'A' && customer_itr->get_reservation_status() == false){
                            for(int i=0; i<4; i++){
                                if(motorcycles[i].get_id_plate() == id_plate && !motorcycles[i].is_reserved()){
                                    // cout<<"HERE1"<<endl;
                                    motorcycles[i].reserve();
                                    customer_itr->rent();
                                    r = new Reservation(*customer_itr, motorcycles[i]);
                                    reservations.push_back(*r);
                                    // cout<<"HERE2"<<endl;
                                    break;
                                }
                            }
                        }
                        
                        if(is_found && customer_itr->get_reservation_status() == false && customer_itr->get_license() != 'A'){
                            cout<<"Cannot make this reservation, because the driving license is not of type A"<<endl;
                        }
                    }

                    if(!is_found){
                        cout<<"No customer holding this name was found!"<<endl;

                    }
                    is_found = false;
                        
                        
                    
                    
                    fileReader.close();
                    fileWriter.open("reservations.txt");
	            	if(fileWriter.good())
	            	{   
						for (reservation_itr=reservations.begin(); reservation_itr != reservations.end(); reservation_itr++)
						{
							fileWriter << reservation_itr->customer.get_firstname()
                            << "\t" << reservation_itr->customer.get_lastname()
                            << "\t" << reservation_itr->customer.get_telephone()
                            << "\t" << reservation_itr->customer.get_license()
                            << "\t" << reservation_itr->customer.get_date().get_day()
                            << "\t" << reservation_itr->customer.get_date().get_month()
                            << "\t" << reservation_itr->customer.get_date().get_year()
                            << "\t" << reservation_itr->customer.get_address().get_postal_code()
                            << "\t" << reservation_itr->customer.get_address().get_city()
                            << "\t" << reservation_itr->customer.get_address().get_street()
                            << "\t" << reservation_itr->bike.get_id_plate()<<endl;
						}
						
					}
					else{
						cout << "File cannot be accessed" << endl;
                    }

                    fileWriter.close();
                
                    break;

                case 4:
                    //Hand over a bike
                    cout<<"----Hand Over A bike----"<<endl;
                    cout<<"Enter Customer's first name: ";
                    cin>>first_name;
                    cout<<"Enter Customer's last name: ";
                    cin>>last_name;

                    
                    
                    for (reservation_itr=reservations.begin(); reservation_itr != reservations.end(); reservation_itr++)
                    {
                        if(reservation_itr->customer.get_firstname() == first_name && reservation_itr->customer.get_lastname() == last_name){
                            reservations.erase(reservation_itr);
                            cout<<"Reservation deleted Successfully!"<<endl;
                            is_found = true;
                        }
                    }

                    if(is_found){
                        for(customer_itr=customers_list.begin();customer_itr !=customers_list.end(); customer_itr++){
                        if(customer_itr->get_firstname() == first_name && customer_itr->get_lastname() == last_name){
                            customers_list.erase(customer_itr);
                        }
                    }
                    }
                    

                    if(is_found){
                        fileReader.close();
                        fileWriter.open("reservations.txt");
                        if(fileWriter.good())
                        {   
                            for (reservation_itr=reservations.begin(); reservation_itr != reservations.end(); reservation_itr++)
                            {
                                fileWriter << reservation_itr->customer.get_firstname()
                                << "\t" << reservation_itr->customer.get_lastname()
                                << "\t" << reservation_itr->customer.get_telephone()
                                << "\t" << reservation_itr->customer.get_license()
                                << "\t" << reservation_itr->customer.get_date().get_day()
                                << "\t" << reservation_itr->customer.get_date().get_month()
                                << "\t" << reservation_itr->customer.get_date().get_year()
                                << "\t" << reservation_itr->customer.get_address().get_postal_code()
                                << "\t" << reservation_itr->customer.get_address().get_city()
                                << "\t" << reservation_itr->customer.get_address().get_street()
                                << "\t" << reservation_itr->bike.get_id_plate()<<endl;
                            }
                            
                        }
                        else{
                            cout << "File cannot be accessed" << endl;
                        }

                        is_found = false;

                    }else{
                        cout<<"Reservation with this customer's name NOT found!"<<endl;
                    }



                    
                    
                    
                    break;

                case 5:
                    
                    break;

                case 0:
                        break;
                
                default:
                    cout<<"Wrong input"<<endl;
                    break ;         
            }  

        }
        catch(int msg){
            cout<<""<<endl;
        }


    }while(user_input);


    return 0;
}

