#include "file.h"


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
    readMetaData();

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
    readMetaData();

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

    //Escribir meta al archivo y calcular los sizes
    writeMetaData();
    calculateSize();

    qDebug() << "File locked successfully";
    seekFirst();
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

        if (exists) {
          readMetaData();
          seekFirst();
          //LoadIndex();
        }

       qDebug() << "File opened successfully";
        return true;
      }

     qDebug() << "Error opening file";
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
        type,name,size, ifPrimaryKey|type,name,size, ifPrimaryKey */

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
          qDebug() << in[i];
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

        calculateSize();
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

          qDebug() << in.c_str();
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

//*** FILESIZE ***
long File::filesize(){
    ifstream infile(path, ios::binary | ios::ate);
    if(infile){
        long retVal = infile.tellg();
        infile.close();
        return retVal;
    }
    return -1;
}

//*** CALCULATESIZE ***
void File::calculateSize(){
    recordSize = 0;
    for(int i =1; i<=fields.size; i++){
        recordSize += fields[i].getSize();
        //Suma el size de todos los campos
    }

    recordSize += fields.size;
    recordSize ++;

    //Bytes abarcados por el metadata
    file.clear();
    file.seekg(0, ios::beg);

    string in = "";
    metaSize = 0;
    getline(file, in, '\n');
    metaSize += in.length();
    getline(file, in, '\n');
    metaSize += in.length();

    //El tamaño del meta sería todo lo que ha recorrido hasta que termina la info de campos más un salto de línea
    metaSize += 4;
}

//*** BUFFER FUNCTIONS ***

//AddFIELD
bool File::addField(int type, string name, int size, bool isPrimaryKey){
    if(!locked){
        if(isPrimaryKey){
            Field newField(type, name, size);
            if(hasPrimaryKey()){
                return false;
            }
            newField.setPrimaryKey(true);
            return fields.insert(newField);
        }else{
            return fields.insert(Field(type, name, size));
        }
    }
}

//ADDFIELD NO PRIMARY KEY
bool File::addField(int type, string name, int size){
    return addField(type, name, size, false);
}

//ADDFIELD AS FIELD OBJECT
bool File::addField(Field nField){
    if(!locked){
        return fields.insert(nField);
    }
    return false;
}

//ADDRECORD
bool File::addRecord(List<string> newRecord){
    return outBuffer.insert(newRecord);
}

//IFHASPRIMARYKEY
bool File::hasPrimaryKey(){
    for (int i = 1;i <= fields.size; i++) {
        if(fields[i].getIsPrimaryKey()){
            return true;
        }
    }
    return false;
}

//DELETEFIELD
bool File::deleteField(int index){
    if(!locked){
        return fields.remove(index);
    }
    return false;
}

//DELETERECORD
bool File::deleteRecord(int index){
    file.clear();//Opens file
    if(file){
        file.seekp(position(index));//Busca la posicion del registro a eliminar
        string out;
        out = "*" + to_string(lastDeleted)+"*";//Agregar el * que marca el borrado y el ultimo eliminado (LastDeleted)
        file.write(out.c_str(), out.length());
        lastDeleted = index;//El avail List se actualiza y la ultima posicion eliminada es index
        writeAvailData();//Update del avail List
        readAvailData();
        return true;
    }
    return false;
}

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

                for (int j = 1;j <= outBuffer[i].size; j++) {
                    string out = outBuffer[i][j];//Datos a escribir
                    qDebug()<<"Buffer size"<< outBuffer.size;
                    qDebug() << "Raw out: " << out.c_str();
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

//SEEK
bool File::seek(int block){
    file.clear();
    if(!locked){
        //File is not locked. Can't process
        return false;
    }

    if(file){
        if(block > blockQuantity()){//Out of bounds
            return false;
        }
        if(block<1){//Can't search negatives
            return false;
        }

        long seekPosition = metaSize + (block-1)*blockSize*recordSize;
        qDebug() << "Seek position: " << seekPosition;

        if(seekPosition > filesize()){
            return false;
            qDebug()<<"Failed to load";
        }

        file.seekg(seekPosition, ios::beg);
        inBuffer.clear();

        int cont =0;
        string in;
        while (getline(file, in) && cont < blockSize) {
            qDebug()<<"Extracting..";
            in = in.substr(0, in.length()-2);
            stringstream inStream(in);
            List<string> nRecord;
            for (int i = 0; i < fields.size; i++) {
              string data;
              getline(inStream, data, ',');

              nRecord.insert(data);
            }
            inBuffer.insert(nRecord);
            cont++;
        }
        currentBlock = block;
        qDebug()<<"Extracted";
        return true;
    }
    return false;
}

//RECSEEK
bool File::recSeek(){
    return seek(currentBlock);
}

//SEEKFIRST
bool File::seekFirst(){
    currentBlock=1;
    return seek(currentBlock);
}

bool File::seekLast(){
    return seek(blockQuantity());
}

//NEXT
bool File::next(){
    if (currentBlock<=-1) {
        currentBlock=1;
    }else{
        currentBlock++;
    }

    if(seek(currentBlock)){
        return true;
    }else{
        currentBlock--;
        return false;
    }
}

//PREVIOUS
bool File::previous(){
    currentBlock--;

    if(seek(currentBlock)){
        return true;
    }else{
        currentBlock++;
        return false;
    }
}

//BLOCK DATA
List<List<string>> File::data(){
  return inBuffer;
}

//GET RECORD
List<string> File::getRecord(int posicion){
    file.clear();

    if (file) {
      string in;
      file.seekg(position(posicion));
      getline(file, in);

      stringstream inStream(in);
      List<string> nRecord;

      for (int i = 0; i < fields.size; i++) {
        string data;
        getline(inStream, data, ',');

        nRecord.insert(data);
      }

      return nRecord;
    }

    return List<string>(0);

}

//GETFIELDS
List<Field> File::getFields(){
  return fields;
}

//GETFIELDSLOCATION
List<Field>* File::getFieldsLocation(){
    return &fields;
}

//GetFieldQuantity
int File::fieldQuantity(){
    return fields.size;
}

//GETRECORDQUANTITY
int File::recordQuantity(){
    if(locked){
        return (filesize()-metaSize)/recordSize;
    }
    return -1;
}

//BLOCKQUANTITY
int File::blockQuantity(){
    if(locked){
        int fileS= filesize();
        int cont=0;
        if((fileS - metaSize) % blockSize !=0){
            cont++;
        }
        cont+=(((fileS - metaSize)/blockSize)/recordSize);
        return cont;
    }
    return -1;
}

//GetRecordSize
int File::getRecordSize(){
    return recordSize;
}

//GetMetaDataSize
int File::getMetaSize(){
    return metaSize;
}

//GetBlockSize
int File::getBlockSize(){
    return blockSize;
}

//GetPath
string File::getPath(){
    return path;
}

//GetIsLocked
bool File::getLocked(){
    return locked;
}

int File::getCurrentBlock(){
    return currentBlock;
}

//*** INDEX FUNCTIONS ***

//BuildIndex
bool File::buildIndex(){
    file.clear();

    if (!locked) {
       return false;
    }

    if (!hasPrimaryKey()) {
       return false;
    }

    if (recordQuantity() <= 0) {
       return false;
    }

    if(file){
        index = BinaryTree(6);
        int pastBlock = currentBlock;
        seekFirst();

        int primaryKeyIndex =0;
        for(int i = 1; i<=fields.size;i++){
            if(fields[i].getIsPrimaryKey()){
                primaryKeyIndex = i;
                break;
            }
        }

        for(int i = 1; i<=blockQuantity(); i++){
            List<List<string>> block = data();
            for(int j = 1; j<=block.size; j++){
                index.insert(new Key(block[j][primaryKeyIndex], j + ((i-1)*(blockSize))));
                qDebug() << "Indexing Key " << block[j][primaryKeyIndex].c_str() << " at " << j + ((i - 1)*blockSize);
            }
            next();
        }
        file.clear();
        seek(pastBlock);
        return true;
    }else{
        qDebug() << "File unaccesible. Aborting index build.";
        return false;
    }
}

//SaveIndex
void File::saveIndex(){
    ofstream ret;
    if (!hasPrimaryKey()) {
        qDebug() << "File has no primary key. Process killed.";
        return;
    }
    qDebug()<<QString::fromStdString(path);
    ret.open(string(path + ".index"), ios::binary);
    if(ret){
        index.printPrev();
        ret << index.getString();
        ret.flush();
        ret.close();
        qDebug()<<"Index has been created";
        //QMessageBox::about(0,"Saved","Index has been saved");
    }else{
        qDebug() << "Error on saving index. Process killed.";
        //QMessageBox::about(0,"Error","Index couldn't be saved");
    }

}

//LoadIndex
void File::LoadIndex(){
    ifstream inFile;
    inFile.open(string(path + ".index"));
    if (inFile && hasPrimaryKey()) {
        index = BinaryTree(5);
        string extData = "";
        while (getline(inFile, extData, '\n')) {
            string extKey;
            string extIndex;
            index.insert(new Key(extKey, stoi(extIndex)));

        }
        inFile.close();
        qDebug()<<"index extracted";
    }else {
        QMessageBox::warning(0,"Error", "Index could not be loaded, check that the file has an index");
        qDebug()<<"Error at reading the index. Could not be found or has no index";
    }
}

//*** SEEK RECORD WITH INDEX ***

//RecordSeeker

bool File::RecordSeeker(string key){
    int primaryKeySize = 0;
    for (int i = 1;i<=fields.size;i++) {
        if(fields[i].getIsPrimaryKey()){
            primaryKeySize= fields[i].getSize();
        }
    }
    if(primaryKeySize>0){
        //La llave enviada debe tener el mismo size del primaryKey creado por el usuario
        while(int(key.length())<primaryKeySize){
            key+=" ";
        }

        int ind = index.findIndex(key);
        if(ind == -1){
            return false;
        }else{
            seek(floor(ind/blockSize) +1);
            return true;
        }

    }
    return false;
}

//*** EXPORT ***

//ExportCSV
void File::exportCSV(string exportPath){
    ofstream expCSV;
    expCSV.open(exportPath);
    if(expCSV){
        for(int i =1; i<= fields.size;i++){
            expCSV<< fields[i].getName();
            if(i<fields.size){
                expCSV<<",";
            }
        }
        expCSV<<endl;
        seekFirst();
        for(int i = 1; i<=blockQuantity(); i++){
            List<List<string>> block = data();
            for (int j = 1; j<=block.size;j++) {
                for(int k =1;k<=block[j].size; k++){
                    expCSV<<block[j][k];
                    if(k<block[j].size){
                        expCSV<<",";
                    }
                }
                expCSV<<endl;
            }
            next();
        }
        expCSV.close();
    }

}

//DESTRUCTOR
File::~File(){
    file.close();
}





