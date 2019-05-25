#ifndef FIELD_H
#define FIELD_H

#include <string>
using namespace std;

class Field{
	private:
		int type;
		bool primaryKey;
		string name;
	public:
		int size;

		//Constructores
		Field();
		Field(int, string, int);

		//Getters
		int getType();
		bool getIsPrimaryKey();
		int getSize();
		string getName();

		//Setters
		void setType(int);
		void setPrimaryKey(bool);
		void setSize(int);
		void setName(string);

		//~Field();
	
};

#endif