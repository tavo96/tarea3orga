#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <tchar.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

void MostrarMenu(){
	system("CLS");

	cout << "*****Bienvenido******" << endl;
	cout << "Ingrese una opcion" << endl;
	cout << "1. Crear Archivo" << endl;
	cout << "2. Editar Archivo" << endl;
	cout << "3. Imprimir Archivo" << endl;
	cout << "4. Eliminar Archivo " << endl;
	cout << "5. Listar Directorio" << endl;
	cout << "0. Salir" << endl;
	cout << endl;



}

void EliminarArchivo (char nombre[100]){

  char path_archivo[200] = "C:\\Progra3\\";


	if (remove(nombre) == -1){

			cout<< "error desconocido";
	}

	 else {
	cout << "Archivo eliminado con exito..." << endl;
}

	system("PAUSE");



}


void CrearArchivo(char nombre[100]){


	char path_archivo[200] = "C:\\Progra3\\";

	strcpy(path_archivo, nombre);

	ofstream archivo;

	archivo.open(path_archivo);

	archivo.close();

	cout << "Archivo creado con exito..." << endl;

	system("PAUSE");
}

void EditarArchivo(char nombre[100]){


	char path_archivo[200] = "C:\\Progra3\\";
	string linea;

	strcpy(path_archivo, nombre);

	ofstream archivo;

	archivo.open(path_archivo);

	cout << "> ";


	getline(cin,linea);

	while (linea != ""){
		archivo << linea << endl;
    	cout << "> ";
    	getline(cin,linea);
	}

	archivo.close();

	cout << endl << "Se termin? de editar el archivo" << endl;

	system("PAUSE");
}

void MostrarContenido(char nombre[100]){

	char path_archivo[200] = "C:\\Progra3\\";
	string linea;
	strcpy(path_archivo, nombre);

	ifstream archivolectura(nombre);

	cout << endl << "Contenido del archivo: " << nombre << endl;

	if (!archivolectura){
		cout << endl << "No se pudo abrir el archivo";
	}
	else{
		while (getline(archivolectura, linea)){
			cout << linea << endl;
		}
	}

	system("PAUSE");
}


void ListarDirectorio(char directorio[100]){
   WIN32_FIND_DATA ffd;
   LARGE_INTEGER filesize;
   TCHAR szDir[MAX_PATH];
   size_t length_of_arg;
   HANDLE hFind = INVALID_HANDLE_VALUE;
   DWORD dwError=0;

   string tipo_archivo;
   string nombre_archivo;


   strcat(directorio,"\\*");

   hFind = FindFirstFile(directorio, &ffd);

   if (INVALID_HANDLE_VALUE == hFind)
   {
      cout << "Error en FindFirstFile" << endl;
   }


   do
   {

      nombre_archivo = ffd.cFileName;

      if ((nombre_archivo != ".") && (nombre_archivo != "..")){
    	  if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
          {

		      tipo_archivo = "D";
          }
          else
          {

			  tipo_archivo = "A";
          }
          cout << "<" << tipo_archivo << ">   " << setw(100) << left << nombre_archivo;
          cout << endl;
	  }
   }
   while (FindNextFile(hFind, &ffd) != 0);

   dwError = GetLastError();

   if (dwError != ERROR_NO_MORE_FILES)
   {
      cout << endl << "Error desconocido";
   }

   FindClose(hFind);

}


int main(){
    int opcion = 0;
    char nombre_archivo[100];
    char directorio[100];


    do{
	    MostrarMenu();

		cin >> opcion;


		cin.ignore();

		switch (opcion){


			case 1:
				cout << endl << "Ingrese nombre del archivo: ";
				cin >> nombre_archivo;
				CrearArchivo(nombre_archivo);
				break;
			case 2:
				EditarArchivo(nombre_archivo);
				break;
			case 3:
				MostrarContenido(nombre_archivo);
				break;
			case 4:
                cout << endl << "Ingrese nombre del archivo: ";
				cin >> nombre_archivo;
                 EliminarArchivo(nombre_archivo);
				 break;
			case 5:
                cout << "Ingrese directorio: ";
                 cin >> directorio;
                 ListarDirectorio(directorio);
                 system("PAUSE");
                 break;

		}


	} while (opcion != 0);

	system("PAUSE");
	return 0;
}
