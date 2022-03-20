#include <iostream>
#include <string.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo_temp = "archivo_aux.dat";
int opc = 0;

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	char direccion[50];
	int telefono;
};

void menu();
void crear();
void leer();
void actualizar();
void delete_line();

main(){
menu();
}

void menu(){
	system("cls");
	
cout<<"1. Insertar estudiante"<<endl;
cout<<"2. Ver estudiantes"<<endl;
cout<<"3. Actualizar estudiante"<<endl;
cout<<"4. Eliminar estudiante"<<endl;
cout<<"5. Salir"<<endl<<endl;
cout<<"Digite su opcion: ";
cin>>opc; 
			
	system("cls");
	
	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: leer();					;break;
 		case 3: actualizar();	 		;break;
 		case 4: delete_line();	 		;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}	
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Direccion"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
		system("pause");
		
		menu();
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido,direccion;
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido,direccion;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese la Direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea agregar otro Estudiante (s/n): ";
		cin>>continuar;
		cout<<"___________________________________________________________"<<endl;
		cout<<endl;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}
void delete_line(){
 	
	FILE *archivo, *archivo_temp; 
	int codigo; 
	Estudiante estudiante; 
	
	archivo_temp=fopen(nombre_archivo_temp,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	                      				                
	cout<<"Codigo del estudiante a eliminar:"<<endl; 
	cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			if (estudiante.codigo != codigo) 
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	
	leer(); 

}
