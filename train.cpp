#include <iostream>
#include <string>
using namespace std;
string usser; // the username in any momment
string Username[15];
string Password[15];
string Firstname[15];
string Lastname[15];
int Age[15];
long double Accountcredit[15];
int signIncounter[15];
int usernamecounter = -1;//to findout how many user accout has been exist
string TrainsoriginAnddestination[10][10];// tehran=0,shiraz=1,mashhad=2,esfahan=3,tabriz=4,karaj=5,qom=6,ahvaz=7,bushehr=8,kerman=9
string Trainnumber[10];
string Trainname[10];
string TraindateTable[10];
string TraintimeTable[10];
int availableClass1[10] = { 30,30,30,30,30,30,30,30,30,30 };
int availableClass2[10] = { 30,30,30,30,30,30,30,30,30,30 };
string reserveClass1seats[10][30];
string reserveClass2seats[10][30];
int class1value[10];
int class2value[10];
int linearsearch(string a, string B[]) { //to find anything in arras
	for (int i = 0; i < 15; i++)
		if (B[i] == a) return i;
	return -1;
}
int linearSearchfirst(string a, string B[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (B[i][j] == a) return i;
	}
	return -1;
}
int linearSearchsecound(string a, string B[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (B[i][j] == a) return j;
	}
	return -1;
}
int linearSearchuserSeat(string user, string trainnumber, string seats[10][30]) {
	for (int i = 0; i < 30; i++) {
		if (seats[linearsearch(trainnumber, Trainnumber)][i] == user) return i;
	}
	return -1;
}
string showplace(int placepoint) {
	if (placepoint == 0)return "tehran";
	else if (placepoint == 1)return "shiraz";
	else if (placepoint == 2)return "mashhad";
	else if (placepoint == 3)return "esfahan";
	else if (placepoint = 4)return "tabriz";
	else if (placepoint == 5)return "karaj";
	else if (placepoint == 6)return "qom";
	else if (placepoint == 7)return "ahvaz";
	else if (placepoint == 8)return "bushehr";
	else if (placepoint == 9)return "kerman";
}
int findEmptyarray(string Array[]) {
	for (int i = 0;; i++)
		if (Array[i] == "")return i;
}
int findEmptyarray(string Array[10][30], int i) {
	for (int j = 0; j < 30; j++)
		if (Array[i][j] == "") return j;
}
void userSignuppage() {
	cout << "enter a new username(without any space):";
	string username;
	cin >> username;
	if (linearsearch(username, Username) == -1) {
		Username[findEmptyarray(Username)] = username;
		system("cls");
		cout << "enter a password(without any space):";
		string password;
		cin >> password;
		Password[findEmptyarray(Password)] = password;
		system("cls");
		cout << "enter your firstname(without any space):";
		string firstname;
		cin >> firstname;
		Firstname[findEmptyarray(Firstname)] = firstname;
		system("cls");
		cout << "enter your lastname(without any space):";
		string lastname;
		cin >> lastname;
		Lastname[findEmptyarray(Lastname)] = lastname;
		system("cls");
		cout << "enter your age:";
		int age;
		cin >> age;
		Age[linearsearch(username, Username)] = age;
		system("cls");
		cout << "done!\n";
	}
	else {
		cout << endl << "this username has already exist.....\n";
		userSignuppage();
	}
}
void userLoginpage() {
	cout << "username: ";
	string username;
	cin >> username;
	if (linearsearch(username, Username) != -1) {
		system("cls");
		cout << "password: ";
		string password;
		cin >> password;
		if (Password[linearsearch(username, Username)] == password) {
			system("cls");
			cout << "welcome\n";
			usser = username;
			signIncounter[linearsearch(username, Username)]++;
		}
		else {
			cout << "wrong password...\n";
			userLoginpage();
		}

	}
	else if (username == "exit")return;
	else {
		cout << "the username not exist....\n";
		userLoginpage();
	}
}
bool adminFirstpage() {
	cout << "enter admin username: ";
	string adminUsername;
	cin >> adminUsername;
	if (adminUsername == "admin") {
		system("cls");
		cout << "enter admin password: ";
		string adminPassword;
		cin >> adminPassword;
		if (adminPassword == "admin") return true;
		else {
			cout << "wrong password....\n" << "try again";
			adminFirstpage();
		}
	}
	else {
		system("cls");
		cout << "username not exist ....\n" << "try again: ";
		adminFirstpage();
	}
}
bool usingmode() { //to select your using mode
	cout << "enter your using mode:(user / admin)";
	string mode;
	cin >> mode;
	if (mode == "user") {
		system("cls");
		return true;
	}
	else if (mode == "admin") {
		system("cls");
		return false;
	}
	else
	{
		system("cls");
		usingmode();
	}
}
void createNewaccount() {
	cout << "enter a new username(without any space):";
	string username;
	cin >> username;
	if (linearsearch(username, Username) == -1) {
		Username[findEmptyarray(Username)] = username;
		system("cls");
		cout << "enter a password(without any space):";
		string password;
		cin >> password;
		Password[findEmptyarray(Password)] = password;
		system("cls");
		cout << "enter your firstname(without any space):";
		string firstname;
		cin >> firstname;
		Firstname[findEmptyarray(Firstname)] = firstname;
		system("cls");
		cout << "enter your lastname(without any space):";
		string lastname;
		cin >> lastname;
		Lastname[findEmptyarray(Lastname)] = lastname;
		system("cls");
		cout << "enter your age:";
		int age;
		cin >> age;
		Age[linearsearch(username, Username)] = age;
		system("cls");
		cout << "done!\n";
	}
	else {
		cout << "this username has already exist.try an other one!!!\n";
		createNewaccount();
	}
}
void changepassword() {
	cout << "enter your password: ";
	string password;
	cin >> password;
	system("cls");
	if (Password[linearsearch(password, Password)] == password) {
		cout << "enter new password:";
		string newpass;
		cin >> newpass;
		Password[linearsearch(password, Password)] = newpass;
		system("cls");
		cout << "done!\n";
	}
}
void increasecredit() {
	cout << "how much do you want to add to your walet? \n";
	double extracredit;
	cin >> extracredit;
	Accountcredit[linearsearch(usser, Username)] += extracredit;
	system("cls");
	cout << endl;
	cout << "done!\n";

}
void deleteUseraccount() {
	cout << "enter the username:\n";
	string username;
	cin >> username;
	if (linearsearch(username, Username) != -1) {
		cout << "all the information about this account will be remove ....\n" << "are you sure about delete this account?(yes/no)\n";
		string confirmation;
		cin >> confirmation;
		if (confirmation == "yes") {
			Username[linearsearch(username, Username)] = {};
			Password[linearsearch(username, Username)] = {};
			Firstname[linearsearch(username, Username)] = {};
			Lastname[linearsearch(username, Username)] = {};
			Age[linearsearch(username, Username)] = {};
			Accountcredit[linearsearch(username, Username)] = {};
			usernamecounter--;
			cout << endl << "done!\n";

		}

	}
	else {
		cout << "the username not exist .....\n";
		deleteUseraccount();
	}
}
int setOrigin() {
	cout << endl << "enter departure( tehran,shiraz,mashhad,esfahan,tabriz,karaj,qom,ahvaz,bushehr,kerman):\n";
	string origin;
	cin >> origin;
	int originpoint;
	if (origin == "tehran") return 0;
	else if (origin == "shiraz")return 1;
	else if (origin == "mashhad")return 2;
	else if (origin == "esfahan")return 3;
	else if (origin == "tabriz")return 4;
	else if (origin == "karaj")return 5;
	else if (origin == "qom")return 6;
	else if (origin == "ahvaz")return 7;
	else if (origin == "bushehr")return 8;
	else if (origin == "kerman")return 9;
	else {
		cout << "the origin is not available!/n";
		setOrigin();
	}
}
int setdestination() {
	cout << endl << "enter destination( tehran,shiraz,mashhad,esfahan,tabriz,karaj,qom,ahvaz,bushehr,kerman):\n";
	string destination;
	cin >> destination;
	if (destination == "tehran")return 0;
	else if (destination == "shiraz")return  1;
	else if (destination == "mashhad")return  2;
	else if (destination == "esfahan")return  3;
	else if (destination == "tabriz")return  4;
	else if (destination == "karaj")return 5;
	else if (destination == "qom")return 6;
	else if (destination == "ahvaz")return 7;
	else if (destination == "bushehr")return 8;
	else if (destination == "kerman")return 9;
	else {
		cout << "the destination is not available!/n";
		setdestination();
	}
}
void addtrain() {
	cout << "enter train number:\n";
	string trainnumber;
	cin >> trainnumber;
	if (linearsearch(trainnumber, Trainnumber) == -1) {
		Trainnumber[findEmptyarray(Trainnumber)] = trainnumber;
		cout << endl << "enter train name:\n";
		string trainname;
		cin >> trainname;
		if (linearsearch(trainname, Trainname) == -1) {
			Trainname[findEmptyarray(Trainname)] = trainname;
			cout << endl << "enter train departure date(yyyy/mm/dd):\n";
			string date;
			cin >> date;
			TraindateTable[findEmptyarray(TraindateTable)] = date;
			cout << endl << "enter train departure time(hh:mm):\n";
			string clock;
			cin >> clock;
			TraintimeTable[findEmptyarray(TraintimeTable)] = clock;
			TrainsoriginAnddestination[setOrigin()][setdestination()] = trainnumber;
			cout << endl << "enter class1 seats price: \n";
			int class1price;
			cin >> class1price;
			class1value[linearsearch(trainname, Trainname)] = class1price;
			cout << endl << "enter class2 seats price: \n";
			int class2price;
			cin >> class2price;
			class2value[linearsearch(trainnumber, Trainnumber)] = class2price;
			system("cls");
			cout << "done!";
		}
		else {
			cout << "the name already exist... \n";
			Trainnumber[linearsearch(trainname, Trainname)] = "";
			addtrain();
		}
	}
	else {
		cout << "the number already exist... \n";
		addtrain();
	}


}
void traininformation(string trainnumber) {
	cout << endl << "train name:" << Trainname[linearsearch(trainnumber, Trainnumber)] << endl;
	cout << endl << "departure :" << showplace(linearSearchfirst(trainnumber, TrainsoriginAnddestination)) << "\t" << "destination:" << showplace(linearSearchsecound(trainnumber, TrainsoriginAnddestination)) << "\t" << TraindateTable[linearsearch(trainnumber, Trainnumber)] << "\t" << TraintimeTable[linearsearch(trainnumber, Trainnumber)];
	cout << endl << "class 1 seats:" << availableClass1[linearsearch(trainnumber, Trainnumber)] << "\t class 2 seats:" << availableClass2[linearsearch(trainnumber, Trainnumber)];
	cout << endl << "class 1 price:" << class1value[linearsearch(trainnumber, Trainnumber)] << "\t class 2 price:" << class2value[linearsearch(trainnumber, Trainnumber)];
	cout << endl << "****************************************************************************************************/n";
}
void removetrain() {
	cout << endl << "enter train number:\n";
	string trainnumber;
	cin >> trainnumber;
	if (linearsearch(trainnumber, Trainnumber) != -1) {
		traininformation(trainnumber);
		cout << endl << "are you sure about it(yes/no):\n";
		string confermation;
		cin >> confermation;
		if (confermation == "yes") {
			Trainnumber[linearsearch(trainnumber, Trainnumber)] = "";
			Trainname[linearsearch(trainnumber, Trainnumber)] = "";
			TraindateTable[linearsearch(trainnumber, Trainnumber)] = "";
			TraintimeTable[linearsearch(trainnumber, Trainnumber)] = "";
			TrainsoriginAnddestination[linearSearchfirst(trainnumber, TrainsoriginAnddestination)][linearSearchsecound(trainnumber, TrainsoriginAnddestination)] = "";
			class1value[linearsearch(trainnumber, Trainnumber)] = 0;
			class2value[linearsearch(trainnumber, Trainnumber)] = 0;
			cout << "done!\n";
		}
	}
	else {
		system("cls");
		cout << "the train number dose not exist...";
		removetrain();
	}
}
void edittrain() {
	cout << endl << "enter train number:\n";
	string trainnumber;
	cin >> trainnumber;
	if (linearsearch(trainnumber, Trainnumber) != -1) {
		cout << endl;
		traininformation(trainnumber);
		cout << endl << "which one?\n";
		cout << "train number >>>>> trainnumber\n";
		cout << "train name >>>>> trainname\n";
		cout << "train departure date >>>>> traindate\n";
		cout << "train departure time >>>>> traintime\n";
		cout << "departure and destination >>>>> location\n";
		cout << "class 1 seats price >>>>> class1\n";
		cout << "class 2 seats price >>>>> class2\n";
		cout << "enter a command:\n";
		string command;
		cin >> command;
		system("cls");
		if (command == "trainnumber") {
			cout << "enter new train number:\n";
			string newtrainnumber;
			cin >> newtrainnumber;
			Trainnumber[linearsearch(trainnumber, Trainnumber)] = newtrainnumber;
			TrainsoriginAnddestination[linearSearchfirst(trainnumber, TrainsoriginAnddestination)][linearSearchsecound(trainnumber, TrainsoriginAnddestination)] = newtrainnumber;
			system("cls");
			cout << "done!\n";
		}
		else if (command == "trainname") {
			cout << endl << "enter new train name:\n";
			string newtrainname;
			cin >> newtrainname;
			Trainname[linearsearch(trainnumber, Trainnumber)] = newtrainname;
			system("cls");
			cout << "done!";
		}
		else if (command == "traindate") {
			cout << endl << "enter new departure date(yyyy/mm/dd):\n";
			string newdate;
			cin >> newdate;
			TraindateTable[linearsearch(trainnumber, Trainnumber)] = newdate;
			system("cls");
			cout << "done!";
		}
		else if (command == "traintime") {
			cout << endl << "enter new departure time(hh:mm):\n";
			string newtime;
			cin >> newtime;
			TraintimeTable[linearsearch(trainnumber, Trainnumber)] = newtime;
			system("cls");
			cout << "done!";
		}
		else if (command == "location") {
			TrainsoriginAnddestination[linearSearchfirst(trainnumber, TrainsoriginAnddestination)][linearSearchsecound(trainnumber, TrainsoriginAnddestination)] = "";
			TrainsoriginAnddestination[setOrigin()][setdestination()] = trainnumber;
			system("cls");
			cout << "done!\n";
		}
		else if (command == "class1") {
			cout << endl << "enter new price:\n";
			int newprice;
			cin >> newprice;
			class1value[linearsearch(trainnumber, Trainnumber)] = newprice;
			system("cls");
			cout << "done!\n";
		}
		else if (command == "class2") {
			cout << endl << "enter new price:\n";
			int newprice;
			cin >> newprice;
			class2value[linearsearch(trainnumber, Trainnumber)] = newprice;
			system("cls");
			cout << "done!\n";
		}
		else {
			cout << endl << "the command not exist....\n";
			edittrain();
		}
	}
}
void allTrainsinfo() {
	for (int i = 0; i < 10; i++) {
		if (Trainnumber[i] != "") {
			cout << "train number:" << Trainnumber[i] << endl;
			string trainnumber = Trainnumber[i];
			cout << endl << "train name:" << Trainname[linearsearch(trainnumber, Trainnumber)] << endl;
			cout << endl << "departure :" << showplace(linearSearchfirst(trainnumber, TrainsoriginAnddestination)) << "\t" << "destination:" << showplace(linearSearchsecound(trainnumber, TrainsoriginAnddestination)) << "\t" << TraindateTable[linearsearch(trainnumber, Trainnumber)] << "\t" << TraintimeTable[linearsearch(trainnumber, Trainnumber)];
			cout << endl << "class 1 seats:" << availableClass1[linearsearch(trainnumber, Trainnumber)] << "\t class 2 seats:" << availableClass2[linearsearch(trainnumber, Trainnumber)];
			cout << endl << "class 1 price:" << class1value[linearsearch(trainnumber, Trainnumber)] << "\t class 2 price:" << class2value[linearsearch(trainnumber, Trainnumber)];
			cout << endl << "******************************************************************************";
			cout << endl << "******************************************************************************\n";
		}
	}
}
void reserveseats(string username) {
	allTrainsinfo();
	cout << "enter train number:\n";
	string trainnumber;
	cin >> trainnumber;
	if (linearsearch(trainnumber, Trainnumber) != -1) {
		cout << "which class seats do you want?(class1/class2)\n";
		string classcommand;
		cin >> classcommand;
		if (classcommand == "class1") {
			cout << "how many ticket do you want:\n";
			int ticket;
			cin >> ticket;
			if (ticket < availableClass1[linearsearch(trainnumber, Trainnumber)] && (ticket * class1value[linearsearch(trainnumber, Trainnumber)]) < Accountcredit[linearsearch(username, Username)]) {
				for (int i = ticket; i > 0; i--) {
					reserveClass1seats[linearsearch(trainnumber, Trainnumber)][findEmptyarray(reserveClass1seats, linearsearch(trainnumber, Trainnumber))] = username;
					availableClass1[linearsearch(trainnumber, Trainnumber)]--;
				}if (Age[linearsearch(username, Username)] <= 6) {
					Accountcredit[linearsearch(username, Username)] -= (ticket * class1value[linearsearch(trainnumber, Trainnumber)]) / 2;
				}
				else Accountcredit[linearsearch(username, Username)] -= (ticket * class1value[linearsearch(trainnumber, Trainnumber)]);
			}
			else {
				system("cls");
				cout << endl << "this number of ticket is not available or your credit is not enough....\n";
				reserveseats(username);

			}
		}
		else {
			cout << "how many ticket do you want:\n";
			int ticket;
			cin >> ticket;
			if (ticket < availableClass2[linearsearch(trainnumber, Trainnumber)] && (ticket * class2value[linearsearch(trainnumber, Trainnumber)]) < Accountcredit[linearsearch(username, Username)]) {
				for (int i = ticket; i > 0; i--) {
					reserveClass2seats[linearsearch(trainnumber, Trainnumber)][findEmptyarray(reserveClass2seats, linearsearch(trainnumber, Trainnumber))] = username;
					availableClass2[linearsearch(trainnumber, Trainnumber)]--;
				}
				if (Age[linearsearch(username, Username)] <= 6) {
					Accountcredit[linearsearch(username, Username)] -= (ticket * class2value[linearsearch(trainnumber, Trainnumber)]) / 2;
				}
				else Accountcredit[linearsearch(username, Username)] -= (ticket * class2value[linearsearch(trainnumber, Trainnumber)]);
			}
			else {
				system("cls");
				cout << endl << "this number of ticket is not available or your credit is not enough....\n";
				reserveseats(username);
			}
		}
		system("cls");
		cout << "done!\n";
	}
}
void cancelreservation(string username) {
	cout << endl << "enter the train number:\n";
	string trainnumber;
	cin >> trainnumber;
	if (linearsearch(trainnumber, Trainnumber) != -1) {
		cout << endl << "enter the seat class(class1/class2):\n";
		string seatclass;
		cin >> seatclass;
		if (seatclass == "class1") {
			if (reserveClass1seats[linearsearch(trainnumber, Trainnumber)][linearSearchuserSeat(username, trainnumber, reserveClass1seats)] == username) {
				cout << endl << "are you sure(yes/no)?\n";
				string comfermation;
				cin >> comfermation;
				if (comfermation == "yes") {
					reserveClass1seats[linearsearch(trainnumber, Trainnumber)][linearSearchuserSeat(username, trainnumber, reserveClass1seats)] = "";
					Accountcredit[linearsearch(username, Username)] += class1value[linearsearch(trainnumber, Trainnumber)];
					cout << endl << "done!\n";
				}
				else cout << endl << "canceled\n";
			}
		}
		else (seatclass == "class2"); {
			if (reserveClass2seats[linearsearch(trainnumber, Trainnumber)][linearSearchuserSeat(username, trainnumber, reserveClass2seats)] == username) {
				cout << endl << "are you sure(yes/no)?/n";
				string comfermation;
				cin >> comfermation;
				if (comfermation == "yes") {
					reserveClass2seats[linearsearch(trainnumber, Trainnumber)][linearSearchuserSeat(username, trainnumber, reserveClass2seats)] = "";
					availableClass2[linearsearch(trainnumber, Trainnumber)]++;
					Accountcredit[linearsearch(username, Username)] += class2value[linearsearch(trainnumber, Trainnumber)];
					cout << endl << "done!\n";
				}
				else cout << endl << "canceled\n";
			}
		}
	}
	else {
		cout << endl << "wrong train number....\n";
		cancelreservation(username);
	}
}
void departureAnddestination() {
	string subject = TrainsoriginAnddestination[setOrigin()][setdestination()];
	if (subject != "")traininformation(subject);
}
void usertickets(string username, string reserveClassseats[10][30]) {
	string tickets[300];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			if (reserveClassseats[i][j] == username) {
				cout << endl << "train number:" << Trainnumber[i] << "\t train name:" << Trainname[i];
				cout << endl << "date:" << TraindateTable[i] << "\t" << TraintimeTable[i];
				cout << endl << "departure :" << showplace(linearSearchfirst(Trainnumber[i], TrainsoriginAnddestination)) << "\t" << "destination:" << showplace(linearSearchsecound(Trainnumber[i], TrainsoriginAnddestination));
				cout << endl << "seat number:" << j++;
				cout << endl << "**********************************************************************************";
			}
		}
	}
}
void userinformation() {
	cout << endl << "enter a username:\n";
	string username;
	cin >> username;
	cout << endl << "name: " << Firstname[linearsearch(username, Username)] << " " << Lastname[linearsearch(username, Username)];
	cout << endl << "age: " << Age[linearsearch(username, Username)] << "\t         " << "sign in counter: " << signIncounter[linearsearch(username, Username)];
	cout << endl << " class 1 tickets :\n";
	usertickets(username, reserveClass1seats);
	cout << endl << "class 2 tickets :\n";
	usertickets(username, reserveClass2seats);
	cout << endl << "##############################################################################################################";
}
void allUsersinformation() {
	for (int i = 0; i < 15; i++) {
		if (Username[i] != "") {
			string username = Username[i];
			cout << endl << "name: " << Firstname[linearsearch(username, Username)] << " " << Lastname[linearsearch(username, Username)];
			cout << endl << "age: " << Age[linearsearch(username, Username)] << "\t              " << "sign in counter: " << signIncounter[linearsearch(username, Username)];
			cout << endl << "class 1 tickets :\n";
			usertickets(username, reserveClass1seats);
			cout << endl << "class 2 tickets :\n";
			usertickets(username, reserveClass2seats);
			cout << endl << "##############################################################################################################";
		}
	}
}
void allUsertickets(string username) {
	cout << endl << " class 1 tickets :\n";
	usertickets(username, reserveClass1seats);
	cout << endl << "class 2 tickets :\n";
	usertickets(username, reserveClass2seats);
	cout << "######################################################################################\n";
}
int main()
{
	string command;
	while (command != "exit") {
		if (usingmode() == true) {// user help command
			userLoginpage();
			while (command != "exit") {
				cout << "your credit is:" << Accountcredit[linearsearch(usser, Username)] << endl;
				cout << "what do you want to do?\n" << "change your password >>>>>>> changepass\n";
				cout << "switch using mode >>>>>>> usingmode\n";
				cout << "reserve a train >>>>>>>> reservation\n";
				cout << "cancel a reservation >>>>>>>> cancel\n";
				cout << "show all your tickets >>>>>>> alltickets \n";
				cout << "list of all trains >>>>>>> alltrain\n";
				cout << "find a train from departure and destination >>>>>>> findtrain \n";
				cout << "close the program >>>>>>> exit\n";
				cout << "increase your credit >>>>>>> chargecredit\n";
				cin >> command;
				system("cls");
				if (command == "changepass") changepassword();
				else if (command == "usingmode") break;
				else if (command == "chargecredit")increasecredit();
				else if (command == "reservation")reserveseats(usser);
				else if (command == "alltrain")allTrainsinfo();
				else if (command == "cancel")cancelreservation(usser);
				else if (command == "findtrain")departureAnddestination();
				else if (command == "alltickets")allUsertickets(usser);
				else cout << "the command is not exist ....\n" << " enter your command again:\n";
			}
		}
		else if (usingmode() == false) {// admin help command
			if (adminFirstpage() == true) {
				while (command != "exit") {
					cout << endl << " what do you want to do ?\n" << "create a new user >>>>>>> adduser\n";
					cout << "switch using mode >>>>>>> usingmode \n";
					cout << "delete a user account >>>>>>> deleteuser \n";
					cout << "add new train >>>>>>> addtrain \n";
					cout << "remove a train >>>>>>> removetrain \n";
					cout << "edit detail of train >>>>>>> edittrain \n";
					cout << "show informations of a train >>>>>>> traininfo \n";
					cout << "find a train from departure and destination >>>>>>> findtrain \n";
					cout << "show informations of all trains >>>>>>> alltrains \n";
					cout << "user information >>>>>>> userinfo \n";
					cout << "all users information >>>>>>> allinfo \n";
					cout << "close the program >>>>>>>> exit \n";
					cin >> command;
					system("cls");
					if (command == "adduser") createNewaccount();
					else if (command == "usingmode") break;
					else if (command == "deleteuser") deleteUseraccount();
					else if (command == "addtrain") addtrain();
					else if (command == "removetrain") removetrain();
					else if (command == "edittrain") edittrain();
					else if (command == "traininfo") {
						cout << endl << "enter train number: \n";
						string trainnumber;
						cin >> trainnumber;
						if (linearsearch(trainnumber, Trainnumber) != -1) traininformation(trainnumber);
						else cout << "trainnumber not exist.....\n";
					}
					else if (command == "findtrain")departureAnddestination();
					else if (command == "userinfo")userinformation();
					else if (command == "allinfo")allUsersinformation();
					else if (command == "alltrains")allTrainsinfo();
					else cout << "the command is not exist ....\n" << " enter your command again:\n";
				}
			}

		}
	}
}


