#include "file.h"

//Constructores
File::File(){
    path = "";
    recordSize = -1;
    locked = false;
    metaSize = -1;
    currentBlock = -1;
    lastDeleted = -1;
    blockSize=10;
    inBuffer = List<List<string>>(blockSize);
    outBuffer = List<List<string>>(blockSize);

}

File::File(string nPath){
    path = nPath;
    recordSize = -1;
    locked = false;
    metaSize = -1;
    currentBlock = -1;
    lastDeleted = -1;
    blockSize=10;
    inBuffer = List<List<string>>(blockSize);
    outBuffer = List<List<string>>(blockSize);

}

File::File(string nPath, int nBlockSize){
    path = nPath;
    recordSize = -1;
    locked = false;
    metaSize = -1;
    currentBlock = -1;
    lastDeleted = -1;
    blockSize = nBlockSize;
    inBuffer = List<List<string>>(blockSize);
    outBuffer = List<List<string>>(blockSize);

}

void File::setLock(){
 //qDebug() << "Attempting to lock file";

  if (locked) {

    return;
  }

  if (fields.size <= 0) {

    return;
  }

  locked = true;

  //Escribir meta al archivo y calcular los tamaños
  //writeMeta();
  //calculateSizes();

 //qDebug() << "File locked successfully";
  //seekFirst();
}

bool File::openFile(){
  bool exists;
  ifstream infile(path);

  if (!infile.good()) {
    ofstream outfile(path);
    outfile.close();
    exists = false;
  }else{
    exists = true;
  }

  infile.close();

  file.close();
  file.open(path, fstream::out | fstream::in);

  if (exists) {
    file.seekg(0, ios::beg);

    char first = file.get();

    if (!isdigit(first) && first != '-') {
      return false;
    }
  }

  if (file) {
    //NEEDS UPDATE !!
    if (exists) {
      //readMeta();
      //seekFirst();
      //loadIndex();
    }

   //qDebug() << "File opened successfully";
    return true;
  }

 //qDebug() << "Error opening file";
  return false;
}

bool File::openFile(string nPath){
  path = nPath;
  return openFile();
}

void File::closeFile(){
  file.close();

  path = "";
  lastDeleted = -1;
  recordSize = -1;
  metaSize = -1;
  blockSize = 10;
  currentBlock = -1;

  locked = false;

  inBuffer = List<List<string>>(blockSize);
  outBuffer = List<List<string>>(blockSize);
  fields.clear();
  availList.clear();
}

//METADATA

bool File::writeMetaData(){
  if (writeAvailData() && writeFieldData()) {
   qDebug() << "Meta written successfully";
    return true;
  }

 qDebug() << "Error at writing meta";
  return false;
}




