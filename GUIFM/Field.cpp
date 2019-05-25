#include "Field.h"

Field::Field(){
	type = 0;
	primaryKey = false;
	size = 10;
	name = "undefined";
}

Field::Field(int nType, string nName, int nSize){
	type = nType;
	name = nName;
	size = nSize;
	primaryKey= false;

	if(type == 1){
		size=5;
	}
}

int Field::getType(){
	return type;
}

bool Field::getIsPrimaryKey(){
	return primaryKey;
}

int Field::getSize(){
	return size;
}

string Field::getName(){
	return name;
}


void Field::setType(int nType){
	type = nType;
	if (type == 1){
		size = 5;
	}
}

void Field::setPrimaryKey(bool nPrimaryKey){
	primaryKey = nPrimaryKey;
}

void Field::setSize(int nSize){
	size=nSize;
}

void Field::setName(string nName){
  name = nName;
}