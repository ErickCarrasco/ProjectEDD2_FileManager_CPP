#include "file.h"

List<Field> File::getFields(){
  return fields;
}

//*** CONSTRUCTORS ***

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
    qDebug() << "Attempting to lock file";

    if (locked) {

        return;
    }

    if (fields.size <= 0) {

        return;
    }

    locked = true;

    //Escribir meta al archivo y calcular los tamaños
    writeMetaData();
    //calculateSizes();

    //qDebug() << "File locked successfully";
    //seekFirst();
}

//Open File
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
      readMetaData();
      //seekFirst();
      //loadIndex();
    }

   //qDebug() << "File opened successfully";
    return true;
  }

 //qDebug() << "Error opening file";
  return false;
}

//Open File with path
bool File::openFile(string nPath){
  path = nPath;
  return openFile();
}

//Close File
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

//*** WRITE METADATA ***

//Write Metadata
bool File::writeMetaData(){
  if (writeAvailData() && writeFieldData()) {
   qDebug() << "Meta written successfully";
    return true;
  }

 qDebug() << "Error at writing meta";
  return false;
}


//Write AvailList
bool File::writeAvailData(){
  file.clear();

  if (file) {
    file.seekp(0, ios::beg);
    string temp = to_string(lastDeleted);

    while(temp.length() < 6){
      temp += "*";
    }

    if (temp.length() > 6) {
      temp = temp.substr(0, 5);
    }

    temp += "\n";

    file.write(temp.c_str(), temp.length());
    file.flush();
    return true;
  }

  return false;
}

//Write Fields
bool File::writeFieldData(){ //Escribir los campos al meta
  file.clear();

  if (file) {
    string out = "";

    /* Estructura del string de los campos:
    type,name,size|type,name,size */

    for (int i = 1; i <= fields.size; i++) { //Leer la lista de campos
         out += to_string(fields[i].getType());
        out += ",";
        out += fields[i].getName();
        out += ",";
        out += to_string(fields[i].getSize());
        out += ",";

        if (fields[i].getIsPrimaryKey()) {
            out += "1";
        }else{
            out += "0";
        }
            if (i != fields.size) { //No añade un '|' después del último registro
            out += "|";
        }

    }

  out += "\n"; //Agregar un salto de línea

  //Moverse a la posición 8 (el AvailList abarca 7 bytes) y escribir
  file.seekp(8);
  file.write(out.c_str(), out.length());
  file.flush();
  return true;
  }

  qDebug() << "Error at writing fields";
  return false;
}

//*** READ METADATA ***

//READ METADATA
bool File::readMetaData(){
  if (readFieldData() && readAvailData()) {
    return true;
  }
  return false;
}

//READ AVAIL LIST
bool File::readAvailData(){
  file.clear();

  if(file){
    file.seekg(0, ios::beg);

    string in = "";
    for (size_t i = 0; i < 7; i++) {
      in += char(file.get());
    }

    //Eliminar los asteriscos del string
    for (size_t i = 0; i < in.length(); i++) {
      if (in[i] == '*') {
        in = in.substr(0, i);
        break;
      }
    }

    //Construir el AvailList
    availList.clear();
    lastDeleted = stoi(in);
    availistBuild(lastDeleted);
    return true;
  }

  return false;
}

//READ FIELD DATA
bool File::readFieldData(){
  file.clear();

  if (file) {
    string line;
    string field;

    file.seekg(8);
    getline(file, line);

    stringstream pipeStream(line);
    fields.clear();

    while (getline(pipeStream, field, '|')) {
      stringstream commaStream(field);

      string type, name, size, isPrimary;
      getline(commaStream, type, ',');
      getline(commaStream, name, ',');
      getline(commaStream, size, ',');
      getline(commaStream, isPrimary, ',');


      Field nField(stoi(type), name, stoi(size));

      if (isPrimary == "1") {
        nField.setPrimaryKey(true);
      }

      fields.insert(nField);
    }

    //calculateSizes();
    return true;
  }

  return false;
}

//*** AVAIL LIST BUILD ***
bool File::availistBuild(int pos){
  if (recordSize == -1) {
    return false;
  }

  if (pos != -1) {
    file.clear();

    if (file) {
      availList.insert(pos);
      file.seekp(position(pos));
      string in = "";

      getline(file, in);
      for (size_t i = 1; i < in.length(); i++) {
        if (in[i] == '*') {
          in = in.substr(1, i-1);
          break;
        }
      }

     //qDebug() << in.c_str();
      return availistBuild(stoi(in));

    }else{
      return false;
    }
  }

  return true;
}

//*** POSITION ***
int File::position(int index){
    index --;
    return (recordSize*index) + metaSize;
}

//*** BUFFER FUNCTIONS ***

//FLUSH
bool File::flush(){
    if(locked){
        file.clear();
        if(file){
            for (int i =1 ;i <= outBuffer.size;i++) {
                if(!availList.isEmpty()){
                    //Escribir en la posicion del availList
                    file.seekp(position(availList[availList.size]));
                    availList.remove(availList.size);
                }else{
                    //Escritura al final del archivo
                    file.seekp(0, ios_base::end);
                }

                for (int j = 1;j <= outBuffer.size; j++) {
                    string out = outBuffer[i][j];//Datos a escribir

                    //Agregar espacios si el campo es menor que el field size
                    while (int(out.length()) < fields[j].getSize()) {
                        out += " ";
                    }

                     //Acortar string en caso de que sea mayor que el field size
                    if(int(out.length()) > fields[j].getSize()){
                        out = out.substr(0, fields[j].getSize());
                    }

                    //Escribir String al archivo
                    file.write(out.c_str(), out.length());

                    //Escribir coma en caso que no sea el ultimo field del record
                    if (j < fields.size) {
                        file.write(",",1);
                    }

                }//FIN FOR ESCRITURA DATA

                file.write("\n", 1);
                //Salto de linea despues de cada registro

            }//FIN FOR INICIAL

            file.flush();
            outBuffer.clear();
            return true;
        }else {
            return false;
        }
    }
    return false;
}

//DESTRUCTOR
File::~File(){
    file.close();
}





