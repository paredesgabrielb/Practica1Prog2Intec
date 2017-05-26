#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <windows.h>

// Practica1.cpp :
//		Programa que desplegue menu con las opciones:
//			1. Digitar 5 Numeros
//			2. El segundo Mayor
//			3. Suma de numeros
//			4. Numero Primo
//			5. Delta mayor y menor
//			6. Borrar datos
//
//		sergio.lopez@gmail.com
//		Titulo : LP_01_Matricula

using namespace std;

int numeros[5];
int numerosOld[5];
bool isFull = false;
// Metodos
int* ordenar(int num[]);
int* obtener();
int segundoMayor(int num[]);
int sumar(int num[]);
int primosCant(int num[] , int length);
int* primos(int num[], int length);
bool esPrimo(int num);
void delta(int num[]);
void imprimirCabecera();
void printMenu();
void limpiarPantalla();
void volverAlMenu();
void run();

int main()
{
	run();
	system("pause");
	return 0;
}

void printArray(int num[]) {
	int length = 5;
	for (int i = 0; i < length; i++)
	{
		cout << num[i] << ", ";
	}
	cout << endl;
}
int* ordenar(int num[]) { // Orden
	int length = 5;
	int swapHolder = -1;
	int endd = 4;
	//printArray(num);
	for (int counter = length+1; counter > 0; counter--)
	{
		for (int index = 0; index < endd; index++)
		{
			if (num[index] > num[index + 1])
			{
				swapHolder = num[index + 1];
				num[index + 1] = num[index];
				num[index] = swapHolder;
			}
		}
		endd--;
	}

	//printArray(num);
	return num;
}

int* obtener() { // 1: Return Array int
	cout << "\nDigite el 1er. Numero:\n";
	cin >> numeros[0];

	cout << "\nDigite el 2do. Numero:\n";
	cin >> numeros[1];

	cout << "\nDigite el 3er. Numero:\n";
	cin >> numeros[2];

	cout << "\nDigite el 4to. Numero:\n";
	cin >> numeros[3];

	cout << "\nDigite el 5to. Numero:\n";
	cin >> numeros[4];

	numerosOld[0] = numeros[0];
    numerosOld[1] = numeros[1];
    numerosOld[2] = numeros[2];
    numerosOld[3] = numeros[3];
    numerosOld[4] = numeros[4];
    isFull = true;
	return numeros;
}

int segundoMayor(int num[]) // 2: Second Max
{
	num = ordenar(num);
	return num[3];
}

int sumar(int num[]) // 3: SUm
{
	int sum=0;
	int length = sizeof(num)+1;
	for (int i = 0; i < length; i++)
	{
		sum = sum + num[i];
	}
	return sum;
}
bool esPrimo(int num) {
	bool result = false;
	int a = 0;
	// si es negativo, lo convierte a positivo
	if (num < 0) {
		num = num*(-1);
	}
	// divide el numero insertado entre todos los numeros anterior a el
	// y entre el mismo
	// y va contando las veces que la division fue perfecta
	for (int i = 1; i<(num + 1); i++) {
		if (num % i == 0) {
			a++;
		}
	}
	// los numeros primos solo son divisibles entre ellos y la unidad
	// por lo que el contador debe ser igual a 2
	if (a <= 2) {
		result = true;
	}
	return result;
}
int primosCant(int num[] , int length) { // 4: Prime Numbers
	int c = 0;
	for (int i = 0; i < length ; i++)
	{
		if (esPrimo(num[i]))
		{
			c++;
		}
	}
	return c;
}

int* primos(int num[], int length) { // 4: Prime Numbers
    int cant =  primosCant(num, length);
	int* numPrimos = new int[cant];
	int c = 0;
	for (int i = 0; i <length ; i++)
	{
		if (esPrimo(num[i]))
		{
			numPrimos[c] = num[i];
			c++;
		}
	}
	return numPrimos;
}

void delta(int num[]) { // 5: Delta
	num = ordenar(num);
	cout << "Mayor("<<num[4]<<") - Menor("<<num[0]<<") "
	<<"= "  <<  num[4]-num[0];
}

void imprimirCabecera() {
	cout << "*************************************" << endl;
	cout << "*           PRACTICA NO.1           *" << endl;
	cout << "*************************************" << endl;
}

void printMenu() {
	cout << "1. Digitar 5 Numeros" << endl;
	cout << "2. El segundo Mayor" << endl;
	cout << "3. Suma de numeros" << endl;
	cout << "4. Numero Primo" << endl;
	cout << "5. Delta mayor y menor" << endl;
	cout << "6. Borrar datos" << endl;
	cout << "7. Salir" << endl;
	cout << "\nElija una opcion => ";
}
void limpiarPantalla() {
	system("cls");
}
void volverAlMenu() {
	cout << "\n--Presione ENTER para regresar el menu principal--\n";
	system("pause");
	limpiarPantalla();
	run();
}

void run() {
	int opcion;
	limpiarPantalla();
	imprimirCabecera();
	printMenu();
	cin >> opcion;
	switch (opcion)
	{
		case 1:
			obtener();
			volverAlMenu();
			break;
		case 2:
		    if(isFull){
                cout<< "El segundo numero mayo es: " << segundoMayor(numeros) << endl;
                volverAlMenu();
            }else{
                cout << "No ha digitado los 5 numeros para elegir esta opcion." << endl << "Elija la Opcion 1 despues de volver al menu" << endl;
                volverAlMenu();
            }
			break;
		case 3:
            if(isFull){
                cout<< "La suma de todos los numeros es: " << sumar(numeros) << endl;
                volverAlMenu();
			}else{
                cout << "No ha digitado los 5 numeros para elegir esta opcion." << endl << "Elija la Opcion 1 despues de volver al menu" << endl;
                volverAlMenu();
            }
			break;
		case 4:
		{
            if(isFull){
                int* prim = primos(numeros,5);
                int length = primosCant(numeros,5);
                cout << "Hay un total de " << length << " numeros primos.\nEstos Son:" <<endl;
                for (int i = 0; i < length; i++)
                {
                    cout << prim[i] << "\t";
                }
                volverAlMenu();
			}else{
                cout << "No ha digitado los 5 numeros para elegir esta opcion." << endl << "Elija la Opcion 1 despues de volver al menu" << endl;
                volverAlMenu();
            }
		}
		break;
		case 5:
            if(isFull){
                cout << "El delta es: " << endl;
                delta(numeros);
                volverAlMenu();
			}else{
                cout << "No ha digitado los 5 numeros para elegir esta opcion." << endl << "Elija la Opcion 1 despues de volver al menu" << endl;
                volverAlMenu();
            }
			break;
		case 6:
            if(isFull){
                numeros[0] = 0;
                numeros[1] = 0;
                numeros[2] = 0;
                numeros[3] = 0;
                numeros[4] = 0;
                isFull = false;
                volverAlMenu();
			}else{
                cout << "No ha digitado los 5 numeros para elegir esta opcion." << endl << "Elija la Opcion 1 despues de volver al menu" << endl;
                volverAlMenu();
            }
			break;
		case 7:
			break;
		default:
			volverAlMenu();
			break;
	}

}
