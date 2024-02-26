//A program to study for upcoming C++ quiz
// Note: Hard Difficulty has not yet been properly implemented
//Made by Colin Bradley

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
using namespace std;

struct {
	vector<string> init    = { "char" , "int", "unsigned int", "float" , "string" , "double" };


	vector<string> varsInt    = { "Input" , "Age" , "Cars" , "Quantity" , "Pets"};
	vector<string> varsDouble = { "Weight" , "Height" , "BMI" , "Exclusion" };
	vector<string> opps       = { "%" , "+" , "-" , "*" , "/" };
	
	vector<string> varsString = { "dogs" , " dogs " , "cats" , " cats " , "eggs" , " eggs " };

} easylib;

struct {
	vector<string> Correct   = { "<< 3 ","<< \" \" ","<< 5 ","<< \"cool\" ","<< \"green\" " };
	vector<string> outCorr   = {    "3" ,     " " ,     "5" ,     "cool" ,       "green" };

	vector<string> Wrong     = { ">> 11 ",">> green ","< \"very cool\" " };
	vector<string> outWrong = {     "11" ,   "green" ,    "very cool" };
} mediumlib;

//struct {
//	vector<string> 
//} hardlib;

int userErrs;

void ranEasy() {
	cout << "Consider the following lines of Code: " << endl;
	int typeQ = rand() % 3;
	if (typeQ == 0)
	{
		int varName = (rand() % easylib.varsInt.size()); // Variable name
		int vVar = (rand() % 20) * 20;						 // Number stored into var

		int cVar    = (rand() % 50) + 1;				 // Righthand constant

		int oppsVar = (rand() % easylib.opps.size());
		

		cout << "> Input: " << vVar << endl << endl;
		cout << "int main() {" << endl;



		cout << "\tint user" + easylib.varsInt[varName] << ";" << endl;
		cout << "\tcin >> user" + easylib.varsInt[varName] << ";" << endl << endl;

		cout << "\tcout <<" << " user" + easylib.varsInt[varName] << " " << easylib.opps[oppsVar] << " " << cVar << ";" << endl;
		cout << "\treturn 0;" << endl;
		cout << "}" << endl << endl;

		int userOut, output;
		cout << "Output: ";
		cin >> userOut;
		cout << endl;
		
		// Determining output value
		if (oppsVar == 0)
		{
			output = vVar % cVar;
		}
		else if (oppsVar == 1)
		{
			output = vVar + cVar;
		}
		else if (oppsVar == 2)
		{
			output = vVar - cVar;
		}
		else if (oppsVar == 3)
		{
			output = vVar * cVar;
		}
		else
		{
			output = vVar / cVar;
		}

		if (userOut == output)
		{
			cout << "Correct!";
		}
		else
		{
			cout << "Wrong!";
		}
	}
	else if (typeQ == 1)
	{
		int wCoinf = (rand() % 5);

		int varName = (rand() % easylib.varsDouble.size()); // Variable name: Vector
		double vVar = (rand() % 20);					    // Number stored into var
		if (wCoinf > 1)
		{
			vVar = vVar + (static_cast<double>(wCoinf) / 4);
		}

		double cVar = (rand() % 50) + 1;				    // Righthand constant
		if (wCoinf > 1)
		{
			cVar = cVar + (static_cast<double>(rand() % 20) / 4.0);
		}

		int oppsVar = (rand() % (easylib.opps.size() - 1)) + 1; // Operator: Vector

		cout << "> Input: " << setprecision(2) << vVar << endl << endl;
		cout << "int main() {" << endl;

		cout << "\tdouble user" + easylib.varsDouble[varName] << ";" << endl;
		cout << "\tcin >> user" + easylib.varsDouble[varName] << ";" << endl << endl << endl;
		
		if (wCoinf > 0)
		{
			cout << "\tuser" + easylib.varsDouble[varName] << " = static_cast<int>(user" + easylib.varsDouble[varName] << ") / 3;" << endl;
			cout << "\tuser" + easylib.varsDouble[varName] << " = static_cast<double>(user" + easylib.varsDouble[varName] << ");";
			cout << endl << endl << endl;
			vVar = static_cast<int>(vVar) / 3.0;
			vVar = static_cast<double>(vVar);
		}
		
		cout << "\tcout <<" << " user" + easylib.varsDouble[varName] << " " << easylib.opps[oppsVar] << " " << cVar << ";" << endl;
		cout << "\treturn 0;" << endl;
		cout << "}" << endl << endl;

		double userOut, output;
		cout << "Output: ";
		cin >> userOut;
		cout << endl;

		// Determining output value
		
		if (oppsVar == 1)
		{
			output = vVar + cVar;
		}
		else if (oppsVar == 2)
		{
			output = vVar - cVar;
		}
		else if (oppsVar == 3)
		{
			output = vVar * cVar;
		}
		else
		{
			output = vVar / cVar;
		}
		

		

		if (abs(userOut-output) < 0.01)
		{
			cout << "Correct!";
		}
		else
		{
			cout << "Wrong!" << endl;
			cout << output;
		}

	}
	else
	{
		cout << endl << endl;
		cout << "int main() {" << endl;

		int randName = rand() % 6;

		cout << "\tstring str1 = \"" << easylib.varsString[randName] << "\";" << endl;

		cout << "\tcout << \"I have \" << rand() % 6 + 1 << str1 << \"remaining\";" << endl << endl;
		cout << "\treturn 0;" << endl;
		cout << "}" << endl << endl;

		cout << "Output(assume 2 for random value): " << endl;

		string userOut, outPut = "I have 2" + easylib.varsString[randName] + "remaining";

		cin.ignore();

		getline(cin, userOut);
		cout << endl << endl;

		if (userOut == outPut)
		{
			cout << "Correct!";
		}
		else
		{
			cout << "Wrong!" << endl;
			cout << outPut;
		}
	}
}

void ranMedium() {
	int numSegs, numWrong = 0;
	int errs;
	string output, input;
	numSegs = rand() % 4 + 1;
	cout << "cout ";
	for (int i = 0, m; i != numSegs;) {
		if (rand() % 2) {
			m = rand() % mediumlib.Correct.size();
			cout << mediumlib.Correct[m];
			i++;
			output = output + mediumlib.outCorr[m];
		}
		else {
			m = rand() % mediumlib.Wrong.size();
			cout << mediumlib.Wrong[m];
			numWrong++;
			output = output + mediumlib.outWrong[m];
		}
	};
	cout << ";" << endl << endl;
	cout << "> # of Errors?" << endl;
	cin >> errs;
	if (errs == numWrong) {
		cout << "Correct!" << endl;
	}
	cout << "Expected output?" << endl << "> Assume opperator and quotation errors are corrected" << endl;

	cin.ignore();
	getline(cin, input);

	if (output == input) {
		cout << "Correct!";
	}

	system("CLS");

}

void ranHard() {

}

int main() {
	//Seed randomizer
	srand((unsigned)time(0));

	//Start screen
	cout << "This study tool includes 3 settings:" << endl << endl;
	cout << "> Easy: Prompts involve single lines of code with questions" << endl;
	cout << "pertaining to outputs or syntax" << endl << endl;

	cout << ">> Medium: Prompts involve 2-4 lines of code with questions" << endl;
	cout << "pertaining to outputs, inputs, operations, or syntax" << endl << endl;

	cout << ">>> Hard(non-functional): Prompts involve multiple lines of code or whole" << endl;
	cout << "functions with questions pertaining to outputs, syntax," << endl;
	cout << "or varriable assignments; you may also be asked to write " << endl;
	cout << "additional lines of code to complete or modify existing " << endl;
	cout << "functions" << endl << endl;

	cout << "Press Enter to continue: ";
	char ent;
	cin.get(ent);

	system("CLS");

	int numEasy, numMed, numHard;
	cout << "How many easy problems would you like to solve?" << endl;
	cin >> numEasy;
	cout << endl;

	cout << "How many medium problems would you like to solve?" << endl;
	cin >> numMed;
	cout << endl;

	cout << "How many hard problems would you like to solve?" << endl;
	cin >> numHard;
	cout << endl;

	for (int i = 0; i < numEasy; i++)
	{
		ranEasy();
	}

	system("CLS");

	for (int i = 0; i < numMed; i++)
	{
		ranMedium();
	}

	system("CLS");

	/*for (int i = 0; i < numHard; i++)
	{
		ranHard();
	}

	system("CLS");*/

	cout << "Thank you for using my study tool. Have a nice Day!!!" << endl;

	cout << "Press Enter to exit: ";
	cin.get(ent);

	return 0;
}