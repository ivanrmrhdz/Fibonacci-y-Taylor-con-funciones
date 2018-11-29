//Carlos Ivan Romero Hernandez RH18030

//Librerias necesarias
#include <iostream>
#include <cstdlib>
#include <math.h>//pow
#include <fstream>//uso de ficheros
#include <sstream>//convertir a string 
#include <conio.h>

using namespace std;

//Declaracion de funciones
void menu();//Menu principal
void fibo();//Funcion de Fibonacci 
//Funciones de Serie de Taylor
void taylor();
double tay(int n, int x);
double factorial(int n);
void finalizar();//opcion salir
//Acciones con el archivo .txt
int escribir(int o, string n, string d, string r);
void leer();

//Funcion principal
int main(){
	
	system("color 2F");
 //Lamma al menu
   menu();
return 0;
}

//Funcion Menú
void menu(){

    system("cls");//Cada que se ejecuta limpia la pantalla

	int n;

	cout<<"*** Menu Principal ***"<<endl;
	cout<<endl;
	cout<<"1. Resolver Fibonacci"<<endl;
	cout<<"2. Serie de Taylor"<<endl;
	cout<<"3. Ver resultados"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<endl;
	cout<<"Elija una opcion: "; cin>>n;
	system("cls");

	switch(n){

		case 1:
			fibo();
			break;

		case 2:
			taylor();
			break;

		case 3:
	    	leer();
			break;

		case 4:
		    finalizar();
			break;
	}
}

//Funcion de Fibonacci (Reutilizada de Internet)
void fibo(){
	
	string nom = "Fibonacci";//Se asigna el nombre para el registro 
 
    int i, n, cont = 0; 
    long long int a[100];
    
    stringstream ss;//Se usa para convertir a string el vector   
    a[0] = 0;
    a[1] = 1;
 
    cout << "Numero de terminos de la serie = "; 
    cin >> n; 
    cout << "\n";
    
    for(i=1; i < n; i++){
 
        a[i+1] = a[i-1] + a[i]; 
    }
 
     for(i=0; i < n; i++){
 
        if (cont == 10){ 
 
            cout << "\n";
            cont = 0;           
        }
        cout << a[i] << " ";
        cont += 1;   
        
  	ss<< a[i] << " ";    //Se guarda cada iteracion en la variable que luego para a ser string 
   
     }  
    cout << "\n";
    //Se convierten a string los datos ingresados por el usuario
    stringstream sq;    
  	sq<<"Terminos de la serie: "<<n;       
    string datos= sq.str();
    //Aquí se convierte finalmente la variable que tiene las iteraciones de fibonacci
    string res= ss.str();
    
    //Se envian las variables a la funcion escribir, que guarda en el registro
    escribir(1, nom, datos, res);
    
    //Se solicita Enter para ir al menú
    getch();
    menu();
}

//Funcion de Serie de Taylor 
void taylor(){
	//declaracion de variables
	int n;
	int x;
	double res;
	string nom = "Serie de Taylor";//Se asigna el nombre para el registro 
	
	cout<<"Ingrese valor de n: "; cin>> n;
	cout<<"Ingrese valor de x: "; cin>> x;
	cout<<endl;
    res = tay(n,x);//Se llama a la variable que realiza la operacion
	cout<<"El valor de Taylor para n= "<<n<<" y x= "<<x<<" es igual a: "<<res<<endl;//Se muestra el resultado
	
	//Se convierten a string los datos necesarios para se almacenados 
    stringstream ss;    
  	ss<<"n= "<<n <<" y x= "<<x;       
    string datos= ss.str();
     stringstream sr;    
  	sr<<"El resultado es: "<<res;       
    string re= sr.str();
    //Se envian a guardar
	escribir(2, nom, datos, re);
	
	//Enter para ir al menu
	getch();
	menu();
}

//Operaciones de la serie de taylor (Reutilizado de internet)
double tay(int n, int x){
	
	double t;
	double s;
	
	for (int i = 0; i < n; i++){
		
		t = pow(x, i) / factorial(i);
		s += t;
	}
	return s;
}

double factorial(int n){
	
	double fact =1;
	for(int i= 2; i<=n; i++){
		fact*=i;
	}
	return fact;
}

//Funcion que guarda en el archivo .txt
int escribir(int o, string n, string d, string r){
	
	fstream file("registro.txt", ios::in | ios::out | ios::app);//Se abre el archivo de manera que se carguen los datos previamente almacenados
  //Se comprueba si se abre correctamente 
  if (!file.is_open()){
  	
  	cout<<"Error al abrir archivo!";
  	
  }else{
  	
  	cout<<"Archivo abierto..."<<endl;
  	
  	cout<<"Escribiendo en el archivo... Se ha guardado correctamente!"<<endl;
  
  //guardando en el archivo    
    
    //Se convierten los datos si es necesario, se igualan las variables. 
    stringstream sa;
  	sa<<o;
  	string opcion= sa.str();
          
    string nombre = n;
  	string datos = d;
   
  	string resultado=r;
    	
  	file<<opcion<<" - "<<nombre<<" - "<<datos<<" - "<<resultado<<endl;//Se envia a guardar el texto 
}
return 0;
}

//Funcion que permite leer los datos almacenados en el archivo .txt
void leer(){
	
		fstream file("registro.txt", ios::in | ios::out | ios::app);//Se abre el archivo de manera que se carguen los datos previamente almacenados
  //Se comprueba si se abre correctamente 
  if (!file.is_open()){
  	
  	cout<<"Error al abrir archivo";
  	
  }else{
  	
  	//Codigo para extraer el texto y mostratlo en consola (reutilizado de internet)
  	file.seekg(0);
  	string line;
  	cout<<"-Registro-"<<endl;
  	cout<<endl;
  	while(file.good()){
  	 	getline(file, line);
  	    cout << line << endl;
	}
}

//Enter para ir al menu
getch();
menu();

}

//Funcion como pantalla de salida
void finalizar(){

cout<<endl;
system("pause");
system("cls");

cout<<"-----------------------------------------"<<endl;
cout<<"||   Que tenga un maravilloso dia!     ||"<<endl;
cout<<"-----------------------------------------"<<endl;

}
