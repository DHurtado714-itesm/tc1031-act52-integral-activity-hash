// =================================================================
//
// File: main.cpp
// Author: Daniel Hurtado
// Date: 23 / 11 / 2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	ifstream inputFile;
	ofstream outputFile;

	// Abrir el archivo de entrada y salida
	inputFile.open(argv[1]);
	if (inputFile.fail())
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	outputFile.open(argv[2]);
	if (outputFile.fail())
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	// Leer archivos de entrada
	int num_jobs, num_salaries;
	inputFile >> num_jobs >> num_salaries;

	// Leer archivo de entrada
	string job;
	int salary = 0;

	for (int i = 0; i < num_salaries; i++)
	{
		inputFile >> job >> salary;
		// Agregar a la tabla hash
		add(job, salary);
	}

	// Cerrar los archivos
	inputFile.close();
	outputFile.close();
	
	
	
	
	return 0;
}

/*

Objetivo:


Descripcion:
Cada empleado tiene una descripción de su puesto de trabajo.
Una descripción contiene unos pocos párrafos que describe las responsabilidad del puesto
Esta, junto con otros factores, como la antigüedad, se utiliza para determinar su salario.
la descripción del puesto simplemente se escanea en busca de palabras y frases que indiquen responsabilidad.
las descripciones de puestos que indican el control de un gran presupuesto o la gestión de un gran número de personas producen puntuaciones alta

Input:
Recibirás como entrada un diccionario y una serie de descripciones de puestos. 
La primera línea de entrada contiene 2 números enteros positivos: m ≤ 1,000, el número de palabras en diccionario "Unlimited Seas", y n ≤ 100, el número de descripciones de puestos. 
Las siguientes m líneas; cada una contiene una palabra y un valor en dólares
Las n descripciones de puestos.
Descripción de puesto de trabajo consta de uno o más líneas de texto.


TODO:
Para cada descripción, deberás calcular el salario asociado con el puesto, de acuerdo con el sistema.

Output:

*/
