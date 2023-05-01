#include <iostream>
#include <windows.h>
#include <cstdlib> // Needed to use random numbers
#include <conio.h>
#include <ctime>
#include <vector>
#include <iomanip>
#include <utility>

using namespace std;

// Vectors to store car details
vector<string> carName;
vector<int> carNo;
vector<int> rentPrice;

// Vector to store Rented Car details
vector<string> R_carName;
vector<int> R_carNo;
vector<int> R_rentPrice;

string getName;
string getMail;


int choice;

void Reg()
{
    // User Registration Form
    cout << "Enter Your Name: ";
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, getName);
    cout << "Enter your Email: ";
    cin >> getMail;
    cout << "Enter your Contact Number: ";
    string PhoneNo;
    cin >> PhoneNo;
    cout << "Enter your Contact Address: ";
    string Address;
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, Address);
    cout << endl;
}

void login()
{
    char ch;
    // Login Page
    string correctPass = "password"; // Define the correct password

    while (true)
    {
        string loginMail;
        string pass; // Define the password variable
        cout << "\n\n\t\t\t Welcome to Auto Motors";
        cout << "\n\n\t Enter Your Email: ";
        cin >> loginMail;
        cout << "\n\n\t Enter Password: ";
        ch = _getch();
        while (ch != 13) // character 13 is enter
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        // Compare the Get_mail and the login_mail or 'U' and 'P' 7
        if (((loginMail == getMail) && (pass == correctPass)) || ((loginMail == "U") && (pass == "P")) || ((loginMail == "u") && (pass == "p")))
        {
            // if either of the two is true
            // Print the below
            cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
            system("CLS");
            break; // Exit the loop after successful login
        }
        else
        {
            // if false print the below
            cout << "\n\n\n\n\t\t\t\t\t Incorrect Mail or Password...Please Try Again!!\n";
            system("CLS");
        }
    }
}
int carOptions()
{
    // List of what actions to be taking
    cout << "\n\n\t\t\t Welcome to Auto Motors" << endl;
    cout << endl;
    cout << "\t\t 1. Show All Cars" << endl;
    cout << "\t\t 2. New Car" << endl;
    cout << "\t\t 3. Modify Car" << endl;
    cout << "\t\t 4. Remove Car" << endl;
    cout << "\t\t 5. Rent a Car" << endl;
    cout << "\t\t 6. Show Rent Records" << endl;
    cout << "\t\t 0. Exit" << endl;
    cout << "\t\t --- Choose any one option ---" << endl;
    cout << "\t\t Enter one option: ";
    cin >> choice;
    return choice;
}

int main()
{

    // Available Car Details
    // Car Name
    carName.push_back("Ford Explorer");
    carName.push_back("Honda Civic");
    carName.push_back("Toyota RAV4");
    carName.push_back("Toyota Camry");
    carName.push_back("Lexus LC 500 Coupe");

    // Car Numbers
    carNo.push_back(23001);
    carNo.push_back(23002);
    carNo.push_back(23003);
    carNo.push_back(23004);
    carNo.push_back(23005);

    // Car Rent Price
    rentPrice.push_back(100);
    rentPrice.push_back(200);
    rentPrice.push_back(300);
    rentPrice.push_back(400);
    rentPrice.push_back(500);

    int newCarNo;
    int newCarPrice;

    // Generate Random Number For the Receipt
    int Rand;
    srand((unsigned)time(0));
    Rand = (rand() % 99) + 10;

    while (true)
    {
        // Front Page
        cout << "\n\n\t\t\t Welcome to Auto Motors" << endl;
        cout << endl;
        cout << "1. Register " << endl; // Register as a new customer
        cout << "2. Login" << endl;     // Or Login as an existing Customer
        cout << "Please select: ";
        int select;
        cin >> select;

        system("CLS");

        if (select == 1)
        {
            // Register Page
            cout << "\n\n\n\n\n\t\t\t----------------------- Fill The Form -----------------------\t\t\t\t\n"
                 << endl;
            Reg();
            system("PAUSE");
            system("CLS");
            cout << "\n\n\n\n\n\t\t\t----------------------- Fill your Next of Kins Form -----------------------\t\t\t\t\n"
                 << endl;
            system("cls");
            login();
            goto LOGIN; // If login is true jump to LOGIN page
        }
        else if (select == 2)
        {
            login();    // Login
            goto LOGIN; // If login is true jump to LOGIN section
        }
        else
        {
            cout << "!!!!! INVALID INPUT !!!!!" << endl;
            system("PAUSE");
            system("CLS");
        }
    }

LOGIN: // Leads to the main body of the code

    string newCarName;

    system("CLS");

    Sleep(100);

    int days;
    while (true)
    {
        carOptions();
        if (choice == 1) // Show all Car
        {
            Sleep(100);
            system("CLS");
            cout << "\t\t------------- The following Cars are available -------------" << endl;
            cout << endl;
            if (carName.size() > 0)
            {
                // List all available cars if available
                for (unsigned int i = 0; i < carName.size(); i++)
                {
                    cout << "\t" << i + 1;
                    cout << "\t Car Name: " << carName[i] << endl;
                    cout << "\t\t Car No: " << carNo[i] << endl;
                    cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                    cout << "\t\t----------------------------------" << endl;
                }
                system("PAUSE");
                system("CLS");
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n"
                     << endl;
                cout << "\t\t\t\t\t----------- There are no cars available for rentage -----------" << endl;
                system("PAUSE");

                system("cls");
            }
        }
        else if (choice == 2) // Add a New Car Details
        {
            //
            cout << "Enter the name of the car: ";
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, newCarName);
            carName.push_back(newCarName);
            cout << "Enter the number of the car: ";
            cin >> newCarNo;
            carNo.push_back(newCarNo);
            cout << "Enter the rental price of the car: ";
            cin >> newCarPrice;
            rentPrice.push_back(newCarPrice);
            Sleep(100);
            system("CLS");
            cout << "\t\t------------- The following Cars are available -------------" << endl;
            cout << endl;
            if (carName.size() > 0) // Show all cars including the added cars
            {
                for (unsigned int i = 0; i < carName.size(); i++)
                {
                    cout << "\t" << i + 1;
                    cout << "\t Car Name: " << carName[i] << endl;
                    cout << "\t\t Car No: " << carNo[i] << endl;
                    cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                    cout << "\t\t----------------------------------" << endl;
                }

                system("PAUSE");

                system("CLS");
            }
            else
            {
                system("cls");

                cout << "\n\n\n\n\n\n\n\n\n"
                     << endl;
                cout << "\t\t\t\t\t----------- There are no cars available ----------- " << endl;

                system("PAUSE");

                system("cls");
            }
        }
        else if (choice == 3) // Modify any available  car
        {
            system("cls");
            cout << "\t\t------------- The following Cars are available -------------" << endl;
            cout << endl;
            if (carName.size() > 0)
            {
                while (true)
                {
                    for (unsigned int i = 0; i < carName.size(); i++)
                    {
                        cout << "\t" << i + 1;
                        cout << "\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;
                    }
                   unsigned int i;
                    cout << "Enter The Number assigned to the car you want to modify: ";
                    cin >> i;
                    i = i - 1;
                    if (i >= 0 && i < carName.size())
                    {
                        system("PAUSE");

                        system("CLS");

                        // Show Modified Car
                        cout << "\t The Car you want to modify is: " << endl;
                        cout << "\t\t----------------------------------" << endl;
                        cout << "\t\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;

                        system("PAUSE");

                        // Store Modified car details
                        string modName;
                        int modNo;
                        int modPrice;

                        // Enter New car details
                        cout << endl;
                        cout << "\t Enter The New Car Details!! " << endl;
                        cout << "\t\t----------------------------------" << endl;
                        cout << "\t\t Car Name: ";
                        if (cin.peek() == '\n')
                        {
                            cin.ignore();
                        }
                        getline(cin, modName);

                        cout << "\t\t Car No: ";
                        cin >> modNo;
                        cout << "\t\t Rental Price: $";
                        cin >> modPrice;
                        cout << "\t\t----------------------------------" << endl;

                        // Store Modified details into the existing car details address
                        carName[i] = modName;
                        carNo[i] = modNo;
                        rentPrice[i] = modPrice;

                        cout << "\t The Car you modified: " << endl;
                        cout << "\t\t----------------------------------" << endl;
                        cout << "\t\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;

                        system("PAUSE");

                        system("CLS");
                        break;
                    }
                    else
                    {

                        system("cls");
                        cout << "\n\n\n\n\n\n\n\n\n"
                             << endl;
                        cout << "\t\t\t\t\t----------- INVALID CAR NUMBER -----------" << endl;

                        system("PAUSE");

                        system("cls");
                    }
                }
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n"
                     << endl;
                cout << "\t\t\t\t\t----------- There are no cars available for Modification -----------" << endl;

                system("PAUSE");

                system("cls");
            }
        }
        else if (choice == 4) // Remove any available car
        {
            system("cls");
            cout << "\t\t------------- The following Cars are available -------------" << endl;
            cout << endl;
            if (carName.size() > 0)
            {
                while (true)
                {
                    for (unsigned int i = 0; i < carName.size(); i++)
                    {
                        cout << "\t" << i + 1;
                        cout << "\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;
                    }

                    unsigned int i;
                    cout << "Enter The Number assigned to the car you want to remove: ";
                    cin >> i;
                    i = i - 1;
                    if (i >= 0 && i < carName.size())
                    {
                        system("PAUSE");

                        system("CLS");

                        cout << "\t The Car you want to remove is: " << endl;
                        cout << "\t\t----------------------------------" << endl;
                        cout << "\t\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;

                        system("PAUSE");

                        // Delete the car
                        carName.erase(carName.begin() + i);
                        carNo.erase(carNo.begin() + i);
                        rentPrice.erase(rentPrice.begin() + i);

                        system("cls");
                        break;
                    }
                    else
                    {

                        system("cls");
                        cout << "\n\n\n\n\n\n\n\n\n"
                             << endl;
                        cout << "\t\t\t\t\t----------- INVALID CAR NUMBER -----------" << endl;

                        system("PAUSE");

                        system("cls");
                    }
                }
            }
            else
            {

                system("cls");

                cout << "\n\n\n\n\n\n\n\n\n"
                     << endl;
                cout << "\t\t\t\t\t----------- There are no cars available for Removal-----------" << endl;

                system("PAUSE");

                system("cls");
            }
        }
        else if (choice == 5) // Rentage of car
        {
            system("cls");

            cout << "\t\t------------- The following Cars are available for Rentage -------------" << endl;
            cout << endl;
            if (carName.size() > 0)
            {
                while (true)
                {
                    for (unsigned int i = 0; i < carName.size(); i++)
                    {
                        cout << "\t" << i + 1;
                        cout << "\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;
                    }
                  unsigned  int i;
                    cout << "Enter The Number assigned to the car you want to Rent: ";
                    cin >> i;
                    i--;
                    if (i >= 0 && i < carName.size())
                    {

                        system("CLS");

                        cout << "\t The Car you want to Rent is: " << endl;
                        cout << "\t\t----------------------------------" << endl;
                        cout << "\t\t Car Name: " << carName[i] << endl;
                        cout << "\t\t Car No: " << carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;

                        cout << "Enter the Number of days you want to rent the car for: ";
                        cin >> days;

                        cout << "\t\n";

                        Sleep(250);

                        cout << endl;
                        cout << endl;
                        cout << "\t\t-------- THE CAR '" << carName[i] << "' HAS BEEN RESERVED ------" << endl;

                        Sleep(250);

                        system("CLS");
                        cout << "\n\n\n\n"
                             << endl;
                        cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
                        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
                        cout << "\t\t	| Invoice No. :"
                             << "------------------|" << setw(22) << "#Cnb78" << Rand << "|" << endl;
                        cout << "\t\t	| Customer Name:"
                             << "-----------------|" << setw(24) << getName << "|" << endl;
                        cout << "\t\t	| Car Name. :"
                             << "--------------------|" << setw(24) << carName[i] << "|" << endl;
                        cout << "\t\t	| Car No. :"
                             << "----------------------|" << setw(24) << carNo[i] << "|" << endl;
                        cout << "\t\t	| Number of days :"
                             << "---------------|" << setw(24) << days << "|" << endl;
                        cout << "\t\t	| Your Rental Amount is($) :"
                             << "-----|" << setw(24) << rentPrice[i] << "|" << endl;
                        cout << "\t\t	 ________________________________________________________" << endl;
                        cout << "\n";
                        cout << "\t\t	| Total Rental Amount is($) :"
                             << "----|" << setw(24) << rentPrice[i] << "|" << endl;
                        cout << "\t\t	 ________________________________________________________" << endl;
                        cout << " " << endl;
                        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
                        cout << "\t\t	You are advised to pay up the amount before due date." << endl;
                        cout << "\t\t	Otherwise penalty fee will be applied" << endl;
                        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

                        system("PAUSE");

                        // Move the car details to The Reserved vectors details
                        R_carName.push_back(carName[i]);
                        R_carNo.push_back(carNo[i]);
                        R_rentPrice.push_back(rentPrice[i]);

                        // Delete remnant of car details
                        carName.erase(carName.begin() + i);
                        carNo.erase(carNo.begin() + i);
                        rentPrice.erase(rentPrice.begin() + i);

                        system("CLS");
                        break;
                    }
                    else
                    {

                        system("cls");
                        cout << "\n\n\n\n\n\n\n\n\n"
                             << endl;
                        cout << "\t\t\t\t\t----------- INVALID CAR NUMBER -----------" << endl;

                        system("PAUSE");

                        system("cls");
                    }
                }
            }
            else
            {
                system("cls");

                cout << "\n\n\n\n\n\n\n\n\n"
                     << endl;
                cout << "\t\t\t\t\t----------- There are no cars available for Rentage -----------" << endl;

                system("PAUSE");

                system("cls");
            }
        }
        else if (choice == 6) // Show rent records
        {
            while (true)
            {
                system("cls");
                cout << "\t\t------------- The following Cars has been Rented out -------------" << endl;
                cout << endl;

                if (R_carName.size() > 0)
                {
                    for (unsigned int i = 0; i < R_carName.size(); i++)
                    {
                        cout << "\t" << i + 1;
                        cout << "\t Car Name: " << R_carName[i] << endl;
                        cout << "\t\t Car No: " << R_carNo[i] << endl;
                        cout << "\t\t Rental Price: $" << R_rentPrice[i] << endl;
                        cout << "\t\t----------------------------------" << endl;
                    }
                    cout << "\t\t Do you want to Print rent Receipt? (Yes/No) ";
                    string res;
                    cin >> res;
                    if ((res == "Yes") || (res == "YES") || (res == "yes"))
                    {
                       unsigned int i;
                        cout << "\t\t Enter the number assigned to the rented car; ";
                        cin >> i;
                        i = i - 1;
                        if (i >= 0 && i < carName.size())
                        {
                            system("CLS");
                            cout << "\n\n\n\n"
                                 << endl;
                            cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
                            cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
                            cout << "\t\t	| Invoice No. :"
                                 << "------------------|" << setw(22) << "#Cnb78" << Rand << "|" << endl;
                            cout << "\t\t	| Customer Name:"
                                 << "-----------------|" << setw(24) << getName << "|" << endl;
                            cout << "\t\t	| Car Name. :"
                                 << "--------------------|" << setw(24) << R_carName[i] << "|" << endl;
                            cout << "\t\t	| Car No. :"
                                 << "----------------------|" << setw(24) << R_carNo[i] << "|" << endl;
                            cout << "\t\t	| Number of days :"
                                 << "---------------|" << setw(24) << days << "|" << endl;
                            cout << "\t\t	| Your Rental Amount is($) :"
                                 << "-----|" << setw(24) << R_rentPrice[i] << "|" << endl;
                            cout << "\t\t	 ________________________________________________________" << endl;
                            cout << "\n";
                            cout << "\t\t	| Total Rental Amount is($) :"
                                 << "----|" << setw(24) << R_rentPrice[i] << "|" << endl;
                            cout << "\t\t	 ________________________________________________________" << endl;
                            cout << " " << endl;
                            cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
                            cout << "\t\t	You are advised to pay up the amount before due date." << endl;
                            cout << "\t\t	Otherwise penalty fee will be applied" << endl;
                            cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

                            system("PAUSE");
                            system("cls");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\n\n\n\n\n\n\n\n"
                                 << endl;
                            cout << "\t\t\t\t\t----------- INVALID CAR NUMBER -----------" << endl;

                            system("PAUSE");

                            system("cls");
                            break;
                        }
                    }

                    else if ((res == "No") || (res == "NO") || (res == "no"))
                    {
                        system("cls");

                        cout << "\n\n\n\n\n\n\n\n\n"
                             << endl;
                        cout << "\t\t\t\t\t----------- THANK YOU ---------------" << endl;

                        system("PAUSE");

                        system("cls");

                        break;
                    }
                }
                else
                {
                    system("cls");

                    cout << "\n\n\n\n\n\n\n\n\n"
                         << endl;
                    cout << "\t\t\t\t\t----------- No Car Has Been Rented Out-----------" << endl;

                    system("PAUSE");

                    system("cls");
                    break;
                }
            }
        }
        else if (choice == 0) // Exit
        {

            cout << "\t\t\t\t\t----------- THANK YOU FOR CHOOSING AUTO MOTORS---------------" << endl;

            system("PAUSE");
            break;
        }
        else
        {
            cout << "\t\t--------------- INVALID INPUT ---------------" << endl;

            system("PAUSE");

            system("cls");
        }
    }

    return 0;
}
