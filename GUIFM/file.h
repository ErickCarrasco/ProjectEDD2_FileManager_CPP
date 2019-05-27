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
    //File Properties
    fstream file; //Filestream del archivo
    string path; //Ruta del archivo que utilzará el File

    int lastDeleted; //Índex del ultimo registro borrado
    int recordSize; //Tamaño en bytes abarcado por un registro
    int metaSize; //Tamaño en bytes abarcado por el meta

    List<int> availList; //Espacios disponibles en el archivo
    List<Field> fields; //Campos del archivo actual

    BinaryTree index; //B-Tree de búsqueda para indexar

    bool locked;//Permite bloquear archivo

    int blockSize;//Size del bloque
    int currentBlock; //Bloque actual que el buffer está leyendo/escribiendo

    List<List<string>> inBuffer; //Registros cargados en memoria
    List<List<string>> outBuffer; //Registros cargados en memoria

    //Funciones del file
    int pos(int);//Calcula la posicion del registro a traves de un indice
    bool availistBuild(int);//Construir la lista de posiciones disponibles
    int position(int); //Calcula la posición del registro en el índice proporcionado


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
    int fieldQuantity(); //Cantidad de campos en el archivo
    int recordQuantity(); //Cantidad de registros en el buffer
    int blockQuantity(); //Cantidad de bloques en el archivo
    int getRecordSize(); //Retorna recordSize
    int getMetaSize(); //Retorna metaSize
    int getBlockSize(); //Retorna el tamaño de bloque

    //BUFFERS
    bool addField(int, string, int, bool); //Agregar un nuevo campo (type, nombre, size, isPrimaryKey)
    bool addField(int, string, int); //Añadir un nuevo campo (type, nombre, size)
    bool addField(Field); //Agregar un campo desde un objeto Field
    bool addRecord(List<string>); //Agrega un registro al buffer, toma una lista de strings como datos
    bool hasPrimaryKey(); //Retorna verdadero si existe un campo llave primaria en el archivo

    bool flush(); //Escribe todos los registros del buffer al archivo
    bool next(); //Pasa al siguiente bloque
    bool previous(); //Retorna al bloque anterior
    bool seek(int); //Busca el n-ésimo bloque (n es el parámetro)
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
