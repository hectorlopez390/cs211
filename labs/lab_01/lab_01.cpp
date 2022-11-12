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
	      V.insert(V.begin()+index, word); 
	    }
	  else
	    {
	      cout << "Error: Insert not possible. Index beyond size of vector." << endl;
	    }
	}
      else if (command == "Delete") //if command is delete, read index number
	{
	  fin >> index;

	  if (index < V.size()) 
	    {
	      V.erase(V.begin()+index);
	    }
	  else
	    {
	      cout << "Error: Delete not possible. Index beyond size of vector." << endl;
	    }
	}
      else if (command == "Print")
	{
	  for(int i = 0; i < V.size(); i++)
	    {
	      cout << V[i] << " ";
	    }
	  cout << endl;
	}
      fin >> command; //read in next command 
    }
  
  return 0;
}
