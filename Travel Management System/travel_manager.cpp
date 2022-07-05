#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();

class ManageMenu
{
 
protected:
    string username; //hide user name

public: 
    ManageMenu()
    {
        system("color B0");
        cout<<"\n\n\n\n\n\n\t  Enter Your Name to continue as an Admin :";
        cin>>username;
        system("CLS");
        menu();
        
    }
    ~ManageMenu(){}

};

class Customers
{

public: 
    string name, gender, address ;
    int age , mobile_no ;
    static int ID;
    char all[999];

    void getDetails()
    {
        
        ofstream out("old-custromers.txt" , ios::app) ;
        {
            cout << "Enter Customer ID : ";
            cin >> ID ;
            cout << "Enter Name : ";
            cin >> name ;
            cout << "Enter Age : ";
            cin >> age ;
            cout << "Enter Mobile Number : ";
            cin >> mobile_no ;
            cout << "Enter Address : ";
            cin >> address ;
            cout << "Enter Gender : ";
            cin >> gender ; 
        }
        out << "\nCustomer ID : "<< ID << "\nName : " << name ;
        out <<"\nAge : "<<age<<"\nMobile Number : "<<mobile_no<< "\nAddress : "<<address<<"\nGender : "<<gender<<endl;
        out.close();
        cout<<"\nSaved \nNOTE : We save your details record for future purposes.\n"<<endl;
    }

    void showDetails()
    {
        ifstream in("old-customers.txt");
        {
            if(!in)
            {
                cout<<"File Error !"<<endl;
            }
            while(!(in.eof()))
            {
                in.getline(all,999);
                cout<< all << endl;
            }
            in.close();
        }
    }

};

int Customers::ID ;

class Cabs{

public: 
    int cabChoice, kilometers;
    float cabCost ;
    static float lastcabcost;

    void cabDetails()
    {
        cout<<"\n"<<endl;
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country " << endl;
        cout << "--------------KARMA Cabs---------------\n " << endl;
        cout << "1. Rent a Standared Cab - Rs.15 for 1 KM " << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 for 1 KM" << endl;

        cout<<"\nTo calculate the cost for your journey :\n"<<endl;
        cout<<"Enter which kind of cab you need : ";
        cin>>cabChoice;
        cout<<"Enter kilometers you have to travel : ";
        cin>>kilometers;

        int hireCab;

        if(cabChoice == 1)
        {
            cabCost = kilometers*15;
            cout<<"\nYour total tour cost is : Rs."<<cabCost<<" for a Standard Cab "<<endl;
            cout << "Press 1 to hire this cab : or\n";
            cout<<"Press 2 to select another cab : "<<endl;
            cin>>hireCab;

            system("CLS");

            if(hireCab==1)
            {
                lastcabcost = cabCost ;
                cout<<"\n\nYou have successfully hired a Standard Cab"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;
            }
            else if(hireCab==2)
            {
                cabDetails();
            }
            else
            {
                cout<<endl;
                cout<<"Invalid Input! Redirecting to previous menu \nPlease Wait!"<<endl;
                Sleep(999);
                system("CLS"); 
                cabDetails();   
            }

        }
        else if(cabChoice==2)
        {
            cabCost = kilometers*25;
            cout<<"\nYour total tour cost is : Rs."<<cabCost<<" for a Standard Cab "<<endl;
            cout << "Press 1 to hire this cab : or\n";
            cout<<"Press 2 to select another cab :\n";
            cin>>hireCab;

            system("CLS");

            if(hireCab==1)
            {
                lastcabcost = cabCost ;
                cout<<"\nYou have successfully hired a Standard Cab"<<endl;
                cout<<"Goto Menu and take the receipt"<<endl;
            }
            else if(hireCab==2)
            {
                cabDetails();
            }
            else
            {
                cout<<endl;
                cout<<"Invalid Input! Redirecting to Main menu \nPlease Wait!"<<endl;
                Sleep(999);
                system("CLS"); 
                menu();  
            }

        }
        
        cout<<"\nPress 1 to Redirect Main Menu :";
        cin>>hireCab;
        system("CLS");
        if(hireCab==1) menu();
        else menu();

    }
};

float Cabs::lastcabcost;

class Booking
{

public:
    int choiceHotel , packChoice;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = { "Blue Orchid" , "WanderLust","Avendra" };
        cout<<"\n"<<endl;
        for(int a = 1; a <= 3 ; a++)
        {
            cout<<a<<". Hotel "<<hotelNo[a-1] <<endl;
        }
        cout<<"\nCurrently we collaborated with above hotels!\n"<<endl;

        cout<<"Press any key to go back or \nEnter number of hotel you want to book : ";
        cin>>choiceHotel;
        
        system("CLS");
        int gotoMenu ;
        if(choiceHotel == 1)
        {
            cout<<"\n"<<endl;
            cout<< "----------WELCOME TO HOTEL BLUE ORCHID-----------\n"<<endl;
            cout<< "The Garden, Food and beverage. Enjoy all you can drink, Stay cool and get chilled in summer sun.\n"<<endl;

            cout<< "Packages offered by BLUE ORCHID :\n"<<endl;

            cout<< "1. Standard Pack"<<endl;
            cout<< "\tAll the basic facilities you need just for : Rs.5000.00"<<endl;
            cout<< "2. Premium Pack"<<endl;
            cout<< "\tEnjoy Premium : Rs.10000.00"<<endl;
            cout<< "3. Luxury Pack"<<endl;
            cout<< "\tLive a Luxury at Blue Orchid : Rs.15000.00"<<endl;

            cout<<"\nPress another key to go back or\nEnter package number you want to book : ";
            cin>>packChoice;

            if(packChoice == 1)
            {
                hotelCost = 5000.00;
                cout<< "\nYou have successfully booked Standard Pack at Blue Orchid "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else if(packChoice==2)
            {
                hotelCost = 10000.00;
                cout<< "\nYou have successfully booked Premium Pack at Blue Orchid "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else if(packChoice==3)
            {
                hotelCost = 15000.00;
                cout<< "\nYou have successfully booked Luxury Pack at Blue Orchid "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else 
            {
                cout<<endl;
                cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
    
            cout<<"\nPress 1 to redirect Main Menu : " ;
            cin>>gotoMenu ;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else{
                menu();
            }

        }
        else if(choiceHotel == 2)
        {
            cout<<"\n"<<endl;
            cout<< "----------WELCOME TO HOTEL WANDERLUST-----------\n"<<endl;
            cout<< "This Summer, Stay cool and get chilled in Swimming Pool and Garden along with the beverages.\n"<<endl;

            cout<< "Packages offered by WANDERLUST :\n"<<endl;

            cout<< "1. Standard Pack"<<endl;
            cout<< "\tAll the basic facilities you need just for : Rs.15000.00"<<endl;
            cout<< "2. Premium Pack"<<endl;
            cout<< "\tEnjoy Premium : Rs.20000.00"<<endl;
            cout<< "3. Luxury Pack"<<endl;
            cout<< "\tLive a Luxury at WANDERLUST : Rs.30000.00"<<endl;

            cout<<"\nPress another key to go back or\nEnter package number you want to book : ";
            cin>>packChoice;

            if(packChoice == 1)
            {
                hotelCost = 15000.00;
                cout<< "\nYou have successfully booked Standard Pack at Wanderlust "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else if(packChoice==2)
            {
                hotelCost = 20000.00;
                cout<< "\nYou have successfully booked Premium Pack at Wanderlust "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else if(packChoice==3)
            {
                hotelCost = 30000.00;
                cout<< "\nYou have successfully booked Luxury Pack at Wanderlust "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else 
            {
                cout<<endl;
                cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout<<"\nPress 1 to redirect Main Menu : " ;
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else{
                menu();
            }

        }
        else if(choiceHotel == 3)
        {
            cout<<"\n"<<endl;
            cout<< "----------WELCOME TO HOTEL AVENDRA-----------\n"<<endl;
            cout<< "Avendra welcomes you to enjoy your summer in family friendly hotel.\n"<<endl;

            cout<< "Packages offered by AVENDRA :\n"<<endl;

            cout<< "1. Standard Pack"<<endl;
            cout<< "\tAll the basic facilities you need just for : Rs.7000.00"<<endl;
            cout<< "2. Premium Pack"<<endl;
            cout<< "\tEnjoy Premium : Rs.10000.00"<<endl;
            cout<< "3. Luxury Pack"<<endl;
            cout<< "\tLive a Luxury at AVENDRA : Rs.20000.00"<<endl;

            cout<<"\nPress another key to go back or\nEnter package number you want to book : ";
            cin>>packChoice;

            if(packChoice == 1)
            {
                hotelCost = 7000.00;
                cout<< "\nYou have successfully booked Standard Pack at Avendra "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else if(packChoice==2)
            {
                hotelCost = 10000.00;
                cout<< "\nYou have successfully booked Premium Pack at Avendra "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else if(packChoice==3)
            {
                hotelCost = 20000.00;
                cout<< "\nYou have successfully booked Luxury Pack at Avendra "<<endl;
                cout<< "Goto Menu and take receipt "<<endl;
            }
            else 
            {
                cout<<endl;
                cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout<<"\nPress 1 to redirect Main Menu : " ;
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else{
                menu();
            }

        }
        else
        {
             cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
             Sleep(1100);
             system("CLS");
             menu();
        }

    }

};

float Booking::hotelCost ;

class charges : public Booking, Cabs, Customers
{

public:
    void printBill()
    {
        ofstream outf("receipt.txt");
        {
            outf << "----------KARMA Travel Agency---------" << endl;
            outf << "----------------Receipt---------------" << endl;
            outf << "______________________________________" << endl;

            outf << "Customer ID :" <<Customers::ID<< endl<<endl;
            outf << "Description\t\t Total :" << endl;
            outf << "Hotel Cost :\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost << endl;
            outf << "Travel Cost (cab cost) :\t" <<fixed<<setprecision(2)<< Cabs::lastcabcost << endl;

            outf << "______________________________________" << endl;
            outf << "Total Charge :\t\t "<<fixed<<setprecision(2)<<Booking::hotelCost + Cabs::lastcabcost << endl;
            outf << "______________________________________" << endl;
            outf << "--------------THANK YOU---------------" << endl;

        }

        outf.close();

    }
    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if( !inf )
            {
                cout << "File opening error!" << endl ;
            }
            while( !(inf.eof()) )
            {
                inf.getline(all,999);
                cout<<all<<endl;
            }
        }
        inf.close();
    }

};


void menu()
{
    int mainChoice ;
    int inchoice;
    int gotoMenu ;

    cout<<"\n"<<endl;
    cout << "\t\t        * KARMA TRAVELS *\n" << endl;
    cout << "\t------------------------Main Menu------------------------" << endl;

    cout << "\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "\t|\t\t\t\t\t" << endl;
    cout << "\t|\t  Customer Management   ->  1\t|" << endl;
    cout << "\t|\t  Cabs Management       ->  2\t|" << endl;
    cout << "\t|\t  Bookings Management   ->  3\t|" << endl;
    cout << "\t|\t  Charges & Bill        ->  4\t|" << endl;
    cout << "\t|\t  Exit                  ->  5\t| " << endl;
    // cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    
    cout << "\nEnter Your Choice :" << endl;
    cin >> mainChoice ;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    charges a5;
    
    if(mainChoice == 1)
    {
        cout<<"\n"<<endl;
        cout << "-----------Customers-----------" << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter Choice : ";
        cin>>inchoice;
        system("CLS") ;
        cout<<"\n"<<endl;
        if(inchoice==1)
        {
            a2.getDetails();
        }
        else if(inchoice==2)
        {
            a2.showDetails();
        }
        else {
           
           cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
           Sleep(1100);
           system("CLS");
           menu();
        }

        cout<<"\nPress 1 to redirect to Main Menu :";
        cin>>gotoMenu;
        system("CLS");
        cout<<"\n"<<endl;
        if(gotoMenu==1)
        {
            menu();
        }
        else { menu() ; }

    }
    else if(mainChoice == 2)
    {
        cout<<"\n"<<endl;
        a3.cabDetails();
    }
    else if(mainChoice==3)
    {
        cout<<"\n"<<endl;
        cout<<"----> Book a luxury hotel and enjoy the comfort <----"<<endl;
        a4.hotels();
    }
    else if(mainChoice==4)
    {
        cout<<"\n"<<endl;
        cout<<"       ----> Get your receipt <----"<<endl;
        a5.printBill();

        cout << "Your receipt is printed. You can get it from file path.\n" <<endl;
        cout << "To display the receipt on the screen, Enter 1 :\nor Enter another key to go back to main menu.\n"<<endl;
        cin>>gotoMenu;

        if(gotoMenu==1)
        {
            system("CLS");
            cout<<endl;
            a5.showBill();
            cout<<"\nPress 1 to redirect to Main Menu :" ;
            cin>>gotoMenu;
            system("CLS");
            cout<<"\n"<<endl;
            if(gotoMenu==1) menu();
            else menu();

        }

    }
    else if(mainChoice==5)
    {
        cout << "--------GOOD-BYE * VISIT AGAIN--------"<<endl;
        Sleep(999);
        system("CLS");
        cout<<"\n"<<endl;
        menu();
    }
    else 
    {
        cout<<endl;
        cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
        Sleep(1100);
        system("CLS");
        menu();
    }

}

int main()
{
    
    ManageMenu startObj ;

    return 0;
}