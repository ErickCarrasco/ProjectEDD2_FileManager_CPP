#ifndef FILE_H
#define FILE_H

#include "Field.h"
#include "BinaryTree.h"
#include "linkedlist.h"
#include <fstream>
#include <sstream>
#include <limits>
#include <cmath>
#include <QMessageBox>
#include <QDebug>

using namespace std;

class File{

private:
    //Variables ya no utilizadas
    /*
    ifstream readr;
    ofstream temp;
    ofstream save;
    */
    //File Properties
    fstream file; //Filestream del archivo
    string path; //Ruta del archivo que utilzará el File

    int lastDeleted; //Index del ultimo registro borrado
    int recordSize; //Size en bytes abarcado por un registro
    int metaSize; //Size en bytes abarcado por el meta

    List<int> availList; //Espacios disponibles en el archivo
    List<Field> fields; //Campos del archivo actual

    BinaryTree index; //B-Tree de busqueda para indexar

    bool locked;//Permite bloquear archivo

    int blockSize;//Size del bloque
    int currentBlock; //Bloque actual que el buffer está leyendo/escribiendo

    List<List<string>> inBuffer; //Registros cargados en memorie
    List<List<string>> outBuffer; //Registros cargados en memoria

    //Funciones del file
    long filesize(); //Calcula el tamaño del archivo
    bool availistBuild(int);//Construir la lista de posiciones disponibles
    int position(int); //Calcula la posicion del registro en el indice proporcionado
    void calculateSize();//Calcula multiples sizes (Record size, metadata size)..


public:
    //CONSTRUCTORES
    File();//Inicializacion de un archivo por defecto
    File(string);//Inicializacion de un archivo con ruta designada
    File(string, int);//Inicializacion de un archivo con ruta y size del block

    //Funciones Primarias del Archivo
    void setLock();//Bloquea el archivo para evitar modificaciones
    bool openFile();//Abrir un archivo
    bool openFile(string);//Abrir archivo con ruta especificada
    void closeFile();//Cerrar el archivo
    //void optSetPath(string);//OPTIONAL -> Proporcionar nueva ruta al archivo

    //METADATA
    bool writeMetaData();//Metodo escritura del metadata
    bool writeFieldData();//Informacion de los campos ingresados por el usuario
    bool writeAvailData();//Escribe la ultima posicion borrada al metadata

    //GET METADATA
    bool readMetaData();//Lectura Principal del metadata
    bool readFieldData();//Lectura de los campos en el metadata
    bool readAvailData();//Lectura de la ultima posicion borrada del metadata

    //Funciones del FIELD
    List<Field> getFields(); //Retorna fields
    List<Field>* getFieldsLocation();
    int fieldQuantity(); //Cantidad de campos en el archivo
    int recordQuantity(); //Cantidad de registros en el buffer
    int blockQuantity(); //Cantidad de bloques en el archivo
    int getRecordSize(); //Retorna recordSize
    int getMetaSize(); //Retorna metaSize
    int getBlockSize(); //Retorna el tamaño de bloque
    string getPath();//Retorna el path
    bool getLocked();//Retorna si el archivo esta bloqueado
    int getCurrentBlock();//Retorna bloque actual

    //BUFFERS
    bool addField(int, string, int, bool); //Agregar un nuevo campo (type, nombre, size, isPrimaryKey)
    bool addField(int, string, int); //Agregar un nuevo campo (type, nombre, size)
    bool addField(Field); //Agregar un campo desde un objeto Field
    bool addRecord(List<string>); //Agrega un registro al buffer, toma una lista de strings como datos
    bool hasPrimaryKey(); //Retorna verdadero si existe un campo llave primaria en el archivo
    bool deleteField(int);//Borrar un campo del archivo si este archivo no esta bloqueado
    bool deleteRecord(int);//Borrar un registro existente del file

    bool flush(); //Escribe todos los registros del buffer al archivo
    bool next(); //Pasa al siguiente bloque
    bool previous(); //Retorna al bloque anterior
    bool seek(int); //Busca el n-ésimo bloque (n es el parámetro)
    bool recSeek();//Repite el seek en el bloque actual
    bool seekFirst();
    bool seekLast();
    List<List<string>> data(); //Retorna el bloque actual
    List<string> getRecord(int); //Retorna el n-ésimo registro


    //OPERADOR
    operator bool(){ //Retorna falso si el archivo no está cargado.
      if (path == "") {
        return false;
      }

      return true;
    }

    //DESTRUCTOR
    ~File();

};

#endif // FILE_H
