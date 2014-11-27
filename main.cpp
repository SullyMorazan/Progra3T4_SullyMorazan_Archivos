#include "Evaluador.h"
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str());//Crea el archivo y si exite sobreescribe en el, se usa c_str() para sacar el objeto string
    out<<num<<endl; //escribe el numero de la variable num en el archivo
    out.flush();//para que se almacene directamente
    out.close();//cierra el archivo
}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str()); //crea un variable ifstream llamada archivo que contiene el nombre del arhivo para leerlo
    int num; //variable entera para almacenar el entero que contenga el archivo
    archivo>>num;//lee el número del archivo
    return num; //retorna el numero que hay en el archivo
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());
    out<<str<<endl;//escribe el string dado en el archivo
    out.flush();//para que se almacene directamente
    out.close();//cierra el archivo
}
string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str()); //crea un ifstream para poder leerlo
    string str; //variable string para almacenar la cadena que contenga el archivo
    in>>str;//lee el string del archivo
    return str; //retorna el string que hay en el archivo
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
   ofstream out(nombre_archivo.c_str());

   out.write((char*)&num,4); //write siempre espera un char puntador, hacer el casteo, el numero es cuantos bytes quiere escribir
   out.close(); //cierra el archivo
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());

    int leido;
    in.read((char*)&leido,4);//read siempre espera un char puntador, hacer el casteo, el numero es cuantos bytes quiere escribir
    return leido; //devuelve el entero que está en el archivo
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());//se declara un ofstream para crear el archivo binario
    out.write(str.c_str(),20);//se escribe en el archivo el string dado
    out.close();//se cierra el archivo
}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str()); //crea un ifstream para poder leerlo
    char cad[20];//arreglo tipo char para leer el string del archivo
    string cadena;//se declara una variable string para almacenar el arreglo char que lee el string del archivo
    in.read(cad,20);//se lee el string del archivo utilizando el arreglo tipo char

    cadena = cad;//se almacena en la variable tipo string cadena; el arreglo tipo char que contiene la cadena del archivo binario

    return cadena;//devuelve la cadena leida del archivo binario
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream in(nombre_archivo.c_str());//crea un ifstream para poder leerlo
    string cadena; //variable para almacenar el string del archivo
    bool resu = false;//variable boolean para retornar si existe o no el string dado
    int c = 0;//variable contador que ayuda a que la variable cadena se desplaze a la siguiente palabra del string del archivo

   do
    {
      in>>cadena; //se lee una palabra de la cadena string del archivo

      if (cadena == str) //se compara la palabra de la cadena del archivo con el string dado como paramatro
      {
        in.close(); //se cierra el archivo si la cadena es igual que el string dado
        resu = true;//asigna true a la variable que determina que existe el string dado en la cadena del archivo
      }
      else
        resu = false;//asigna false si la palabra no es igual que el string
      c++;//aumenta el contador en 1
    }
     while(cadena[c-2]); //hace mientras el contador este dentro del limite del arreglo de la cadena,
                         //se le resta 2 al contador en la cadena para que coincida con cada indica de la cadena
     return resu;//devuelve el resultado de comparar la palabra con el string dado
    }

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream in(nombre.c_str());//se crea un ifstream para leer el archivo
    in.seekg(0,ios::end); //se posiciona al final del archivo
    int tamano = in.tellg();//indica el tamano en bytes del archivo
    in.seekg(0,ios::beg); //se posiciona al inicio del archivo

    int mayor = -999; //inicializacion de la variable mayor
    while(in.tellg()<tamano)//si posicion actual es menor que tamano
    {
        int num; //se inicilaiza la variable entera num para almacenar el numero que se va leyendo
        in.read((char*)&num,4); //se lee el numero de la posicion actual
        if(mayor<num)//si mayor es menor que num
            mayor = num; // mayor sera igual a num
    }//se cierra el ciclo donde se han comparado todos los numeros del archivo
    return mayor;//retorna la variable que contiene el numero mayor
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
