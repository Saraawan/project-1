#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct food_price
{
	int burger[4] = { 695, 650, 550, 750 };
	int pizza[3] = { 400, 700, 1100 };
	int trad_dessert[3] = { 500, 300, 600 };
	int cake[4] = { 1050, 1100, 800, 950 };
	int tea[2] = { 70, 90 };
	int softdrink[2] = { 80,80 };
};

int total_price[100], delivery_price, quantity;
char decision, main_menu_decison;

food_price food;
void fast_food(string category);
void Desserts(string category);
void beverages(string category);

void dine_in();
void takeaway();
void delivery();
//void exit();
string name, filename;
string place;
int amount;
int contact;
int remaining;
ofstream fout;
string line;
int main()
{
	fstream f;
	ifstream fin;
	

	int option;
	cout << "================================================================================== " << endl;
	cout << "\t\t\t * WELCOME TO OUR RESTAURANT * " << endl;
	cout << "================================================================================== " << endl;
	cout << "ENTER YOUR NAME: ";

	getline(cin, name);
	cout << "\n\n";

	if (fout.is_open())
		fout << "customer name: " << name << "\n";
	fout.close();

	cout << "HEY! " << name << " WELCOME " << endl << "\n\n";


	string word;
	f.open("main_menu.txt");
	while (getline(f, word))
	{
		cout << word << "\n";
	}
	cout << "\nPlease choose from the options given below: ";
	cin >> option;


	int sum=0, total=0;
	switch (option)
	{
	case 1:
	{
		dine_in();
		//CREATING A FILE ACCORDING TO THE USER ENTERED NAME AND SAVING TO THE USER OPTED FOLDER
		ofstream write;
		filename = "DINE_IN\\customers\\" + name + ".txt";
		write.open((filename).c_str(), ofstream::app);
		for (int j = 0; j < 20; j++) {
			sum += total_price[j];
		}
		write << "Your Total Bill " << sum;
		write.close();
		cout << "\nYour Receipt\n";

		//reading from the customer file

		fin.open((filename).c_str());
		while (!fin.eof())
		{
			getline(fin, line);
			cout << line << endl;
		}


		cout << "Please Enter Your Amount: ";
		cin >> amount;
		if (sum > amount) {
			cout << "Sorry Sir You don't have enough money to pay the bill\n";
			remove((filename).c_str());
		}
		else {
			remaining = amount - sum;
			cout << "Your Remaining Amount After Paying Is: " << remaining << endl;
			cout << "Thank You " << name << "For Your Time In our restaurant\n";
			cout << "\nPlease Enter your phone number so that we can message you about some new offers: ";
			cin >> contact;
			fout << endl << contact;
			cout << "\nPlease visit us later too!\n";

		}

		break;
	}
	case 2:
	{
		takeaway();
		ofstream write;
		//CREATING A FILE ACCORDING TO THE USER ENTERED NAME AND SAVING TO THE USER OPTED FOLDER
		filename = "TAKEAWAY\\customers\\" + name + ".txt";
		write.open((filename).c_str(), ofstream::app | ios::out);
		for (int j = 0; j < 20; j++) 
		{
			sum += total_price[j];
		}
		write << "Your Total Bill is " << sum;
		cout << "\nYour Receipt\n";
		write.close();

		fin.open((filename).c_str());
		while (!fin.eof()) {
			getline(fin, line);
			cout << line << endl;
		}
		cout << "Please Enter Your Amount: ";
		cin >> amount;
		if (total > amount) {
			cout << "Sorry Sir You don't have enough money to pay the bill\n";
			remove((filename).c_str());
		}
		else
		{
			remaining = amount - sum;
			cout << "Your Remaining Amount After Paying Is: " << remaining << endl;
			cout << "Thank You " << name << "For Your Time In our restaurant\n";
			cout << "Please Enter your phone number so that we can message you about some new offers: ";
			cin >> contact;
			fout << endl << contact;
			cout << "\nPlease visit us later too!";

		}
		break;
	}
	case 3:
	{
		delivery();
		ofstream write;
		//CREATING A FILE ACCORDING TO THE USER ENTERED NAME AND SAVING TO THE USER OPTED FOLDER
		filename = "DELIVERY\\customers\\" + name + ".txt";
		
		write.open((filename).c_str(), ofstream::app);
		for (int j = 0; j < 20; j++)
		{
			sum += total_price[j];
		}
		total = sum + delivery_price;
		write << "Delivery Charges For " << place << " : " << delivery_price << endl;
		write << "So Your Total Bill is " << sum << " + (" << delivery_price << ")Delivery Charges = " << total << endl;

		write.close();
		cout << endl << endl << "Receipt\n";
		fin.open((filename).c_str());
		while (!fin.eof()) {
			getline(fin, line);
			cout << line << endl;
		}
		cout << "Please Enter Your Amount: ";
		cin >> amount;
		if (total > amount)
		{
			cout << "Sorry Sir You don't have enough money to pay the bill\n";
			remove((filename).c_str());
		}
		else {
			remaining = amount - sum;
			cout << "Your Remaining Amount After Paying Is: " << remaining << endl;
			cout << "Thank You " << name << "For Your Time In our restaurant\n";
			cout << "Please Enter your phone number so that we can message you about some new offers: ";
			cin >> contact;
			write << endl << contact;
			cout << "\nPlease visit us later too!\n";

		}
		break;
	}
	case 4:
		return 0;
		break;

	default:
		cout << "Invalid option" << endl;
		break;
	}
	system("pause");
	return 0;

}

//THIS IS FOR DINE IN MENU
void dine_in()
{
	string category = "DINE_IN\\";
	fstream f;
	
	ifstream fin;

	int dinein_options;

	string word;
	f.open("DINE_IN\\dineinmainmanu.txt");
	while (getline(f, word))
	{
		cout << word << "\n";
	}
	cout << "\nEnter Your choice: ";
	cin >> dinein_options;

	if (dinein_options == 1)
	{
		cout << "\nYou have choosen: Fast Food" << endl;

		fast_food(category);
	}
	else if (dinein_options == 2)
	{
		cout << "\nYou have choosen: Desserts" << endl;
		Desserts(category);
	}
	else if (dinein_options == 3)
	{
		cout << "\nYou have choosen: Beverages" << endl;
		beverages(category);
	}
	
}
void takeaway()
{
	string category = "TAKEAWAY\\";
	int takeaway_options;
	fstream f;
	ifstream fin;
	string word;
	f.open("TAKEAWAY\\takeawaymainmenu.txt");
	while (getline(f, word))
	{

		cout << word << "\n";
	}

	cout << "Enter Your choice: ";
	cin >> takeaway_options;
	if (takeaway_options == 1)
	{
		cout << "\nYou have choosen: Fast Food" << endl;
		fast_food(category);
	}
	else if (takeaway_options == 2)
	{
		cout << "\nYou have choosen: Deserts" << endl;
		Desserts(category);
	}
	else if (takeaway_options == 3)
	{
		cout << "\nYou have choosen: Beverages" << endl;
		beverages(category);
	}
}
void delivery()
{
	string category = "DELIVERY\\";
	fstream f;
	ifstream fin;

	int delivery_options;
	string word;
	f.open("DELIVERY\\deliverymainmenu.txt");
	while (getline(f, word))
	{
		cout << word << "\n";
	}

	cout << "Enter your Choice : ";
	cin >> delivery_options;
	if (delivery_options == 1)
	{
		cout << "\nYou have choosen: Fast Food" << endl;
		fast_food(category);
	}
	else if (delivery_options == 2)
	{
		cout << "\nYou have choosen: Deserts" << endl;
		Desserts(category);
	}
	else if (delivery_options == 3)
	{
		cout << "\nYou have choosen: Beverages" << endl;
		beverages(category);
	}

jump:
	cout << "We Are Available in johar,gulshan,dha,malir,nagan only!\n";
	cout << "pLease enter your place where you want your food to be delivered: ";
	cin >> place;
	if (place == "johar") {
		cout << "the delivery charges for johar are 250 Rs.\n";
		delivery_price = 250;
	}
	else if (place == "gulshan") {
		cout << "the delivery charges for gulshan are 150 Rs.\n";
		delivery_price = 150;
	}
	else if (place == "dha") {
		cout << "the delivery charges for dha are 300 Rs.\n";
		delivery_price = 300;
	}
	else if (place == "malir") {
		cout << "the delivery charges for malir are 400 Rs.\n";
		delivery_price = 400;
	}
	else if (place == "nagan") {
		cout << "the delivery charges for nagan are 350 Rs.\n";
		delivery_price = 350;
	}
	else {
		cout << "we are not available at " << place << "\n";
		cout << "please try again from the given places: ";
		goto jump;
	}
	
}


//THIS IS FOR FAST FOOD MENU
void fast_food(string category)
{
	string sub_category = "fast_food\\";
	string file;
	file = category + "customers\\" + name + ".txt";

	fstream f;

	ifstream fin;
	fin.open((file).c_str());
	fout.open((file).c_str(), ofstream::app);

	int fastfood_option;
	cout << "we have alot of variety \n";

	//yaha pr jump hoga
menu_fast_food:

	string word;
	f.open((category + sub_category + "fastfood_manu_a.txt").c_str());
	while (getline(f, word))
	{
		cout << word << "\n";
	}
	f.close();
	cout << "\nEnter Your choice: ";
	cin >> fastfood_option;

	if (fastfood_option == 1)
	{
		char burger_options;

		string word;
		f.open(category + sub_category + "burger_options.txt");
		while (getline(f, word))
		{
			cout << word << "\n";
		}
		f.close();
		cout << "\nEnter Your choice: ";
		cin >> burger_options;
		if (burger_options == 'a')
		{
			cout << "You Have Chose Beef Grilled Burger\n";

			cout << "\nThe Price Of This Burger Is:---PKR " << food.burger[0] << endl;

			cout << "\nPLease Enter How Many Beef Grilled Burgers You Want To Buy:";
			cin >> quantity;


			total_price[0] += quantity * food.burger[0];

			cout << "Your Total Price  For Now Is: " << total_price[0] << endl;
			fout << "Category: " << category << endl;
			fout << "BEEF GRILLED BURGER: " << "  " << food.burger[0] << endl;
			fout << "Quantity of burgers : " << quantity << endl;
			fout << "Price For " << quantity << " Burgers: " << total_price[0] << endl;
			fout.close();
			fin.close();
			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;

			}

			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {


						system("cls");
						delivery();
					}
				}

				else {

					cout << "thank you for buying we will have your receipt generated.\n";
				}


			}

		}
		else if (burger_options == 'b') {
			cout << "\nYou Have Chose Crispy chicken Burger\n";
			cout << "\nThe Price Of This Burger Is:---PKR " << food.burger[1] << endl;
			cout << "\nPLease Enter How Many Crispy Chicken Burgers You Want To Buy:";
			cin >> quantity;
			total_price[1] += quantity * food.burger[1];
			cout << "Your Total Price  For Now Is: " << total_price[1] << endl;
			fout << "Category: " << category << endl;
			fout << "CRISPY CHICKEN BURGER: " << "  " << food.burger[1] << endl;
			fout << "Quantity of burgers : " << quantity << endl;
			fout << "Price For " << quantity << " Burgers: " << total_price[1] << endl;

			fout.close();
			fin.close();
		
			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;
					
					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {
						
						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {
					//agr wo n dabata hai to else pr ajaega or phr wo ye puchega
					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;
					//agr y dabaya to wo dine wale function may dobara chlejaega jaha pr hamara menu hai saari cheezay hain
					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {
						//ye system("cls") screen ko clear krwadeta hai
						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {
					//agr wo n dabata hai to else pr ajaega or phr wo ye puchega
					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;
					//agr y dabaya to wo dine wale function may dobara chlejaega jaha pr hamara menu hai saari cheezay hain
					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {
						//ye system("cls") screen ko clear krwadeta hai
						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";
				}


			}
		}
		else if (burger_options == 'c')
		{
			cout << "\nYou Have Chose veggies Burger\n";
			cout << "\nThe Price Of This Burger Is:---PKR " << food.burger[2] << endl;
			cout << "\nPLease Enter How Many Veggies Burgers You Want To Buy:";
			cin >> quantity;
			total_price[2] += quantity * food.burger[2];
			cout << "Your Total Price  For Now Is: " << total_price[2] << endl;
			fout << "Category: " << category << endl;
			fout << "VEGGIES BURGER: " << "  " << food.burger[2] << endl;
			fout << "Quantity of burgers : " << quantity << endl;
			fout << "Price For " << quantity << " Burgers: " << total_price[2] << endl;
			ofstream::app;
			fout.close();
			fin.close();
		
			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;
			}
			else
			{
				if (category == "DINE_IN\\") {
					//agr wo n dabata hai to else pr ajaega or phr wo ye puchega
					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;
					//agr y dabaya to wo dine wale function may dobara chlejaega jaha pr hamara menu hai saari cheezay hain
					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {
						//ye system("cls") screen ko clear krwadeta hai
						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}
				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}

		}
		else if (burger_options == 'd') {
			cout << "\nYou Have Chose chicken jalapeno Burger\n";
			cout << "\nThe Price Of This Burger Is:---PKR " << food.burger[3] << endl;
			cout << "\nPLease Enter How Many Chicken Jalapeno Burgers You Want To Buy:";
			cin >> quantity;
			total_price[3] += quantity * food.burger[3];
			cout << "Your Total Price  For Now Is: " << total_price[3] << endl;
			fout << "Category: " << category << endl;
			fout << "CHICKEN JALAPENO BURGER: " << "  " << food.burger[3] << endl;
			fout << "Quantity of burgers : " << quantity << endl;
			fout << "Price For " << quantity << " Burgers: " << total_price[3] << endl;
			fout.close();
			fin.close();

			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}

		}

	}
	else if (fastfood_option == 2)
	{

		fstream f;
		ifstream fin;
		fin.open((file).c_str());
		fout.open((file).c_str(), ofstream::app);


		char pizza_flavour;

		string word;
		f.open(category + sub_category + "pizza_flavour.txt");
		while (getline(f, word))
		{
			cout << word << "\n";
		}
		f.close();

		cout << "\nEnter Your choice: ";
		cin >> pizza_flavour;
		if (pizza_flavour == 'a') {
			cout << "\nYou Have Chose chicken fajita \n";


		}
		else if (pizza_flavour == 'b') {
			cout << "\nYou Have Chose creamy tikka \n";


		}
		else if (pizza_flavour == 'c') {
			cout << "\nYou Have Chose cheese pizza \n";

		}
		else if (pizza_flavour == 'd') {
			cout << "\nYou Have Chose  veggies pizza \n";

		}

		int pizza_size;


		string word1;
		f.open(category + sub_category + "pizza_size.txt");
		while (getline(f, word1))
		{
			cout << word1 << "\n";
		}
		cout << "\nEnter Your choice: ";
		cin >> pizza_size;

		if (pizza_size == 1)
		{
			cout << "\nyou have chose small size \n";
			cout << "\nthe price of this pizza is:---PKR " << food.pizza[0] << endl;
			cout << "\nPLease Enter How Many Pizza You Want To Buy:";
			cin >> quantity;
			total_price[4] += quantity * food.pizza[0];
			cout << "Your Total Price  For Now Is: " << total_price[4] << endl;
			fout << "Category: " << category << endl;
			fout << "small size: " << "  " << food.pizza[0] << endl;
			fout << "Quantity of Pizza : " << quantity << endl;
			fout << "Price For " << quantity << " Pizza: " << total_price[4] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}
				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}

		}
		else if (pizza_size == 2)
		{
			cout << "\nyou have chose regular size \n";
			cout << "\nthe price of this pizza is:---PKR " << food.pizza[1] << endl;

			cout << "\nPLease Enter How Many Pizza You Want To Buy:";
			cin >> quantity;
			total_price[5] += quantity * food.pizza[1];
			cout << "Your Total Price  For Now Is: " << total_price[5] << endl;
			fout << "Category: " << category << endl;
			fout << "medium size pizza: " << "  " << food.pizza[1] << endl;
			fout << "Quantity of Pizza : " << quantity << endl;
			fout << "Price For " << quantity << " Pizza: " << total_price[5] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{

					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}


		}
		else if (pizza_size == 3)
		{
			cout << "\nyou have chose large size \n";
			cout << "\nthe price of this pizza is:---PKR " << food.pizza[2] << endl;
			cout << "\nPLease Enter How Many Pizza You Want To Buy:";
			cin >> quantity;
			total_price[6] += quantity * food.pizza[2];
			cout << "Your Total Price  For Now Is: " << total_price[6] << endl;
			fout << "Category: " << category << endl;
			fout << "large size pizza: " << "  " << food.pizza[2] << endl;
			fout << "Quantity of Pizza : " << quantity << endl;
			fout << "Price For " << quantity << " Pizza: " << total_price[6] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Fast Food Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_fast_food;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}

		}
	}


}
void Desserts(string category)
{
	string sub_Category = "desserts\\";
	string file;
	file = category + "customers\\" + name + ".txt";

	fstream f;
	ifstream fin;
	fin.open((file).c_str());
	fout.open((file).c_str(), ofstream::app);
	int dessert_options;
menu_dessert:
	string word;
	f.open((category + sub_Category + "dessert_menu_a.txt").c_str());
	while (getline(f, word))
	{
		cout << word << "\n";
	}
	f.close();


	cout << "\nEnter Your choice: ";
	cin >> dessert_options;
	if (dessert_options == 1)
	{
		char traditional_options;

		string word;
		f.open(category + sub_Category + "traditional_options.txt");
		while (getline(f, word))
		{

			cout << word << "\n";
		}
		f.close();
		cout << "\nEnter Your choice: ";
		cin >> traditional_options;

		if (traditional_options == 'a')
		{

			cout << "\nYou Have Chose Rasmalai\n";
			cout << "\nThe Price Of This Dessert Is:---PKR " << food.trad_dessert[0] << endl;
			cout << "\nPlease Enter How Many Rasmalai You Want To Buy: ";
			cin >> quantity;
			total_price[7] += quantity * food.trad_dessert[0];
			cout << "Your Total Price  For Now Is: " << total_price[7] << endl;
			fout << "Category: " << category << endl;
			fout << "RASMALAI: " << "  " << food.trad_dessert[0] << endl;
			fout << "Quantity of Rasmalai : " << quantity << endl;
			fout << "Price For " << quantity << " Rasmalai: " << total_price[7] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}
				else
				{

					cout << "thank you for buying we will have your receipt generated.\n";


				}


			}
		}

		else if (traditional_options == 'b')
		{
			cout << "\nYou Have Chose Kheer\n";
			cout << "\nThe Price Of This Dessert Is:---PKR " << food.trad_dessert[1];
			cout << "\nPlease Enter How Many Kheer You Want To Buy: ";
			cin >> quantity;
			total_price[8] += quantity * food.trad_dessert[1];
			cout << "Your Total Price  For Now Is: " << total_price[8] << endl;
			fout << "Category: " << category << endl;
			fout << "KHEER: " << "  " << food.trad_dessert[1] << endl;
			fout << "Quantity of Kheer : " << quantity << endl;
			fout << "Price For " << quantity << " Kheer: " << total_price[8] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}
		}

		else if (traditional_options == 'c')
		{
			cout << "\nYou Have Chose Gajar ka halwa\n";
			cout << "\nThe Price Of This Dessert Is:---PKR " << food.trad_dessert[2];
			cout << "\nPlease Enter How Many Gajar Ka Halwa You Want To Buy: ";
			cin >> quantity;
			total_price[9] += quantity * food.trad_dessert[2];
			cout << "Your Total Price  For Now Is: " << total_price[9] << endl;
			fout << "Category: " << category << endl;
			fout << "GAJAR KA HALWA: " << "  " << food.trad_dessert[2] << endl;
			fout << "Quantity of Gajar ka halwa : " << quantity << endl;
			fout << "Price For " << quantity << " Gajar ka halwa: " << total_price[9] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";
				}


			}
		}

	}

	else if (dessert_options == 2)
	{
		fstream f;
		ifstream fin;
		ofstream fout;
		fin.open((file).c_str());
		fout.open((file).c_str(), ofstream::app);
		char cakes_options;

		string word;
		f.open(category + sub_Category + "cakes_options.txt");
		while (getline(f, word))
		{

			cout << word << "\n";
		}
		f.close();
		cout << "\nEnter Your Option: ";
		cin >> cakes_options;
		if (cakes_options == 'a')
		{
			cout << "\nYou Have Chose Chocolate Fudge Cake\n";
			cout << "\nThe Price Of This Dessert Is:---PKR " << food.cake[0];
			cout << "\nPlease Enter How Many Chocolate Fudge Cake You Want To Buy: ";
			cin >> quantity;
			total_price[10] += quantity * food.cake[0];
			cout << "Your Total Price  For Now Is: " << total_price[10] << endl;
			fout << "Category: " << category << endl;
			fout << "CHOCLATE FUDGE CAKE: " << "  " << food.cake[0] << endl;
			fout << "Quantity of choclate fudge cake : " << quantity << endl;
			fout << "Price For " << quantity << "choclate fudge cake : " << total_price[10] << endl;
			fin.close();
			
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}
		}


		else if (cakes_options == 'b')
		{
			cout << "\nYou Have Chose Red velvet cake\n";
			cout << "\nThe Price Of This Dessert Is:---PKR " << food.cake[1];
			cout << "\nPlease Enter How Many Red velvet cake You Want To Buy: ";
			cin >> quantity;
			total_price[11] += quantity * food.cake[1];
			cout << "Your Total Price  For Now Is: " << total_price[11] << endl;
			fout << "Category: " << category << endl;
			fout << "RED VELVET CAKE: " << "  " << food.cake[1] << endl;
			fout << "Quantity of red velvet cake : " << quantity << endl;
			fout << "Price For " << quantity << "red velvet cake : " << total_price[11] << endl;
			
			fin.close();
		
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}
		}
		else if (cakes_options == 'c')
		{
			cout << "\nYou Have Chose Black forest cake\n";
			cout << "\nThe Price Of This Dessert Is:--PKR " << food.cake[2];
			cout << "\nPlease Enter How Many Black Forest Cake You Want To Buy: ";
			cin >> quantity;
			total_price[12] += quantity * food.cake[2];
			cout << "Your Total Price  For Now Is: " << total_price[12] << endl;
			fout << "Category: " << category << endl;
			fout << "BLACK FOREST CAKE: " << "  " << food.cake[2] << endl;
			fout << "Quantity of black forest cake : " << quantity << endl;
			fout << "Price For " << quantity << "black forest cake : " << total_price[12] << endl;
			
			fin.close();
			
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}
				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";


				}


			}

		}
		else if (cakes_options == 'd')
		{
			cout << "\nYou Have Chose Milky malt cake\n";
			cout << "\nThe Price Of This Dessert Is:---PKR " << food.cake[3];
			cout << "Please Enter How Many Milky Malt Cake You Want To Buy: ";
			cin >> quantity;
			total_price[13] += quantity * food.cake[3];
			cout << "Your Total Price  For Now Is: " << total_price[13] << endl;
			fout << "Category: " << category << endl;
			fout << "MILKY MALT CAKE: " << "  " << food.cake[3] << endl;
			fout << "Quantity of  Milky malt cake : " << quantity << endl;
			fout << "Price For " << quantity << " Milky malt cake : " << total_price[13] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Dessert Items?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_dessert;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{


					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}

		}

	}

	fout.close();

}
void beverages(string category)
{

	string sub_Category = "beverages\\";
	string file;
	file = category + "customers\\" + name + ".txt";

	fstream f;
	ifstream fin;
	fin.open((file).c_str());
	fout.open((file).c_str(), ofstream::app);
	int beverages_options;
menu_beverages:
	string word;
	f.open((category + sub_Category + "beveragesmenu_a.txt").c_str());
	while (getline(f, word))
	{
		cout << word << "\n";
	}
	f.close();



	cout << "\nEnter Your Choice: ";
	cin >> beverages_options;

	if (beverages_options == 1)
	{

		char softdrink_options;
		string word;
		f.open(category + sub_Category + "softdrink_options.txt");
		while (getline(f, word))
		{

			cout << word << "\n";
		}

		cout << "\nEnter Your choice: ";
		cin >> softdrink_options;

		if (softdrink_options == 'a')
		{
			cout << "You Have Chose Coke \n";
			cout << "The Price Of This Soft Drink Is:---PKR " << food.softdrink[0];
			cout << "\nPlease Enter How Many Coke You Want To Buy: ";
			cin >> quantity;
			total_price[14] += quantity * food.softdrink[0];
			cout << "Your Total Price  For Now Is: " << total_price[14] << endl;
			fout << "Category: " << category << endl;
			fout << "Coke: " << "  " << food.softdrink[0] << endl;
			fout << "Quantity of coke : " << quantity << endl;
			fout << "Price For " << quantity << " coke : " << total_price[14] << endl;
			fout.close();
			fin.close();
			cout << "\nDo You Want To Buy More Soft Drink?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_beverages;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}
				else
				{

					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}
		}
		else if (softdrink_options == 'b')
		{
			cout << "\nYou Have Chose Sprite \n";
			cout << "\nThe Price Of This Soft Drink Is:---PKR " << food.softdrink[1];
			cout << "\nPlease Enter How Many Sprite You Want To Buy: ";
			cin >> quantity;
			total_price[15] += quantity * food.softdrink[1];
			cout << "Your Total Price  For Now Is: " << total_price[15] << endl;
			fout << "Category: " << category << endl;
			fout << "SPRITE: " << "  " << food.softdrink[1] << endl;
			fout << "Quantity of SPRITE : " << quantity << endl;
			fout << "Price For " << quantity << " sprite : " << total_price[15] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Soft Drink?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_beverages;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}
				else
				{

					cout << "thank you for buying we will have your receipt generated.\n";


				}
			}
		}
		
	}
	else if (beverages_options == 2)
		{
		fstream f;
		ifstream fin;
		fin.open((file).c_str());
		fout.open((file).c_str(), ofstream::app);

		char tea_options;

		cout << " press a for: Simple Tea----PKR 70/--" << endl;
		cout << " press b for: Cardamon Tea--PKR 90/--" << endl;
		cout << "\nEnter Your choice: ";
		cin >> tea_options;

		if (tea_options == 'a')
		{

			cout << "You Have Chose Simple Tea \n";
			cout << "The Price Of This Tea Is:---PKR " << food.tea[0];
			cout << "\nPlease Enter How Many Simple Tea You Want To Buy: ";
			cin >> quantity;
			total_price[16] += quantity * food.tea[0];
			cout << "Your Total Price  For Now Is: " << total_price[16] << endl;
			fout << "Category: " << category << endl;
			fout << "SIMPLE TEA: " << "  " << food.tea[0] << endl;
			fout << "Quantity of Simple Tea : " << quantity << endl;
			fout << "Price For " << quantity << " Simple Tea : " << total_price[16] << endl;
			fout.close();
			fin.close();
			
			cout << "\nDo You Want To Buy More Beverages?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_beverages;
			}
			else
			{
				cout << "Do You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
				cin >> main_menu_decison;

				if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

					system("cls");
					dine_in();
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";

				}


			}
		}
		else if (tea_options == 'b')
		{
			cout << "\nYou Have Chose Cardamom Tea \n";
			cout << "\nThe Price Of This Soft Drink Is:---PKR " << food.tea[1];
			cout << "\nPlease Enter How Many Cardamom Tea You Want To Buy: ";
			cin >> quantity;
			total_price[17] += quantity * food.tea[1];
			cout << "Your Total Price  For Now Is: " << total_price[17] << endl;
			fout << "Category: " << category << endl;
			fout << "CARDAMON TEA: " << "  " << food.tea[1] << endl;
			fout << "Quantity of Cardamom Tea : " << quantity << endl;
			fout << "Price For " << quantity << " Cardamom Tea : " << total_price[17] << endl;
			fout.close();
			fin.close();
			cout << "\nDo You Want To Buy More Tea?(Press y or n): ";
			cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				system("cls");
				goto menu_beverages;
			}
			else
			{
				if (category == "DINE_IN\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						dine_in();
					}
				}
				else if (category == "TAKEAWAY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						takeaway();
					}
				}
				else if (category == "DELIVERY\\") {

					cout << "\nDo You Want To Go The Main Menu Of Our Restaurant?(Press y or n): ";
					cin >> main_menu_decison;

					if (main_menu_decison == 'y' || main_menu_decison == 'Y') {

						system("cls");
						delivery();
					}
				}

				else
				{
					cout << "thank you for buying we will have your receipt generated.\n";


				}


			}

		}
		}

}
