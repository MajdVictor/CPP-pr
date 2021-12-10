#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Item{

    private:
    string name;
    float price;
    int quantity;

    public:
    Item(string desc, float pr, int quant){
        name = desc;
        price = pr;
        quantity = quant;
    }

    ~Item(){}

    string get_name(){
        return name;
    }

    float get_price(){
        return price;
    }

    int get_quantity(){
        return quantity;
    }

    void increase_quantity(){
        quantity += 1;
    }

    void set_name(string n){
        name = n;
    }

    void set_price(float p){
        price = p;
    }

    void set_quantity(int q){
        quantity = q;
    }

    float get_total_price(){
        return price * quantity;
    }

};

void showList(list<Item> &l){
    list<Item> :: iterator i ;
    for(i=l.begin();i !=l.end(); i++){
        cout<< "Name: " << i->get_name() << ", Price: "<< i->get_price()<< ", Quantity: "<<i->get_quantity()<<endl;
        
    }
    cout<<endl;
}

int main(){

    int user_input;
    string name_to_modify;
    string name;
    float price;
    int quantity;
    float total_price;

    ofstream fileWriter;
    ifstream fileReader;

    list<Item> shoppinglist;
    list<Item> :: iterator itr;

    fileReader.open("shoppingList.txt");

    if(fileReader.good())
    {
		while(fileReader >> name >> price >> quantity)
    	{
			Item *it = new Item(name,price,quantity);
        	shoppinglist.push_back(*it);
     	}
    }

    fileReader.close();


    do{
        cout<<"[1] Add Item"<<endl<<"[2] Modify Item"<<endl<<"[3] Delete Item"<<endl<<"[4] Display shopping list"<<endl<<"[5] Empty cart"<<endl<<"[0] Exit"<<endl;
        cin>>user_input;

        try{

            switch(user_input){
           
                case 1:
                    
                    cout<<"Enter name: ";
                    cin>>name;

                    cout<<"Enter price: ";
                    cin>>price;

                    if(price <= 0){
                        throw 1;
                    }

                    cout<<"Enter quantity: ";
                    cin>>quantity;
                    if(quantity <= 0){
                        throw 2;
                    }

                    //first time adding into sl
                    if(shoppinglist.empty()){
                        Item *newItem = new Item(name, price, quantity);
                        shoppinglist.push_back(*newItem);
                    }else{
                        //check if in list ( if true increase quantity by one, else add new item)
                        for(itr = shoppinglist.begin(); itr != shoppinglist.end() ; itr++){
                            if(itr->get_name() == name){
                                itr->increase_quantity();
                            }
                            else{
                                Item *newItem = new Item(name, price, quantity);
                                shoppinglist.push_back(*newItem);
                                break;
                            }
                        }
                    }

                    break;
                    
                case 2:
                    //modify elements
                    cout<<"Enter the name of the item you wish to modify"<<endl;
                    showList(shoppinglist);

                    cout<<"Select name: ";
                    cin>>name_to_modify;

                    for(itr = shoppinglist.begin(); itr != shoppinglist.end() ; itr++){
                        if (itr->get_name() == name_to_modify){
                            cout<<"Enter new name: ";
                            cin>>name;
                            cout<<"Enter new price: ";
                            cin>>price;
                            if(price <= 0){
                                throw 1;
                            }
                            cout<<"Enter new Quantity: ";
                            cin>>quantity;
                            if(quantity <= 0){
                                throw 2;
                            }

                            itr->set_name(name);
                            itr->set_price(price);
                            itr->set_quantity(quantity);

                            cout<<"Item modified successfuly!"<<endl<<endl;

                        }
                        else{
                            cout<<"No Item found with this name"<<endl;
                        }
                    }



                    break;
                
                case 3: 
                    //Delete item
                    showList(shoppinglist);
                    cout<<"select name of item to delete: ";
                    cin>>name_to_modify;
                    for(itr = shoppinglist.begin(); itr != shoppinglist.end() ; itr++){
                        if (itr->get_name() == name_to_modify){
                            shoppinglist.erase(itr);
                            cout<<"Item Deleted successfully!!"<<endl;
                            showList(shoppinglist);
                            break;
                        }else{
                            cout<<"No item found with this name!"<<endl;
                        }
                    }
                    
                    break;

                case 4:
                    showList( shoppinglist );
                    break;

                case 5:
                    shoppinglist.clear();

                case 0:
                    fileWriter.open("shoppinglist.txt");
	            	if(fileWriter.good())
	            	{
						for (itr=shoppinglist.begin(); itr != shoppinglist.end(); itr++)
						{
							fileWriter << itr->get_name() << "\t" << itr->get_price() << "\t" << itr->get_quantity() << endl;
						}
						
					}
					else
						cout << "Datei shoppinglist.txt cannot be opened. Old list remains." << endl;

	            	cout << "Goodbye!" << endl;
	                break;
                    break;
                
                default:
                    cout<<"Wrong input"<<endl;
                    break ;
                    
                }

        }
        catch(int msg){
            if(msg == 1){
                cout<<"Invalid price"<<endl;
            }
            else if(msg == 2){
                cout<<"Invalid quantity"<<endl;
            }
            // return 0;
        }


    }while(user_input);




    // list<Item> shoppingList;

    // Item *it1 = new Item("a",20,3);
    // Item *it2 = new Item("b",30,4);
    // Item *it3 = new Item("c",20,1);

    // shoppingList.push_back(*it1);
    // shoppingList.push_back(*it2);
    // shoppingList.push_back(*it3);

    // shoppingList.



    return 0;
}