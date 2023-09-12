#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  vector<string> V;
  
  string command;
  string word;
  int index;

  ifstream fin;

  fin.open("transaction_file.txt");

  fin >> command; //read in first command
  
  while(!fin.eof())  //while transaction file contains text
    {
      if (command == "Insert") //if command is insert, read two more info
	{
	  fin >> word >> index;

	  if (index == 0 || index < V.size()) //if index within vector bounds
	    {
	      V.insert(V.begin()+index, word); //insert word in vector
	    }
	  else
	    {
	      cout << "Error: Insert not possible. Index beyond size of vector." << endl;
	    }
	}
      else if (command == "Delete") //if command is delete, read index number
	{
	  fin >> index;

	  if (index < V.size())  //if index within vector bounds
	    {
	      V.erase(V.begin()+index); //erase word in vector at index
	    }
	  else
	    {
	      cout << "Error: Delete not possible. Index not within vector bounds." << endl;
	    }
	}
      else if (command == "Print")
	{
	  for(int i = 0; i < V.size(); i++) //print vector V
	    {
	      cout << V[i] << " ";
	    }
	  cout << endl;
	}
      fin >> command; //read in next command 
    }
  
  return 0;
}
