//Madlibs reader
//Created by: Alexander Bix

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Reading File based on user input
int ReadFile(){

  //User input
  string FileName;
  cout << "Type filename: ";
  cin >> FileName;

  //Opening File based on user input
  ifstream File;
  File.open(FileName.c_str());

  //Error Opening File
  if(!File){
    cout << "There was an error opening the file";
    return -1;
  }

  //Read file line by line
  else{
    string line;
    ofstream output;
    output.open("output.txt");
    
    while(File >> line){
      
      //When a fill-in-the-blank is inserted
      if(line[0] == '#'){
	int i = 1;
	cout << "Pick a ";
	while(line[i] != '#'){
	  cout << line[i];
	  i++;
	}
	cout << ": ";

	string NewWord;
	cin >> NewWord;

	output << NewWord << " ";

      }

      //Copy the word onto the output file
      else{
	output << line << " ";
      }
      
    }
    
  }
  
  File.close();
  
  return 1;
}

//Reading new file
void ReadNewFile(){
  ifstream Reading;
  string line;
  Reading.open("output.txt");
  while(Reading >> line){
    cout << line << " ";
  }
  cout << endl;
}

//Main function
int main(){
  string YorN = "y";

  while(YorN != "n" && YorN != "N"){

    if(ReadFile() != -1){
      ReadNewFile();
    }
      
    cout << endl << "Would you like to play again (y/n): ";
    cin >> YorN;
  }

  return 0;
}
