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
#include <map>
// #include "hash.h"

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
	int num_jobs, num_paragraphs;
	inputFile >> num_jobs >> num_paragraphs;

	string job;
	int salary = 0;

	// Crear tabla hash
	map<string, int> salaries;

	// Almancenar los trabajos y su salario en la tabla hash

	for (int i = 0; i < num_jobs; i++)
	{
		inputFile >> job >> salary;
		salaries[job] = salary;
	}

	// Leer la descripcion del puesto y buscar el salario
	string job_description;
	int salary_sum = 0;
	

	for (int i = 0; i < num_paragraphs; i++)
	{
		inputFile >> job_description;
		salary_sum += salaries[job_description];

		while(job_description != ".")
		{
			inputFile >> job_description;
			salary_sum += salaries[job_description];
		}
		outputFile << salary_sum << endl;
		salary_sum = 0;
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
Descripción contiene pocos párrafos que describe las responsabilidad del puesto
Esta, junto con otros factores, como la antigüedad, se utiliza para determinar su salario.
la descripción del puesto simplemente se escanea en busca de palabras y frases que indiquen responsabilidad.
las descripciones de puestos que indican el control de un gran presupuesto o la gestión de un gran número de personas producen puntuaciones alta

Input:
m, número de palabras en diccionario "Unlimited Seas"
n, el número de descripciones de puestos (parrafos). 
Siguientes m líneas; (puesto, $salario)
Las n descripciones de puestos.
Descripción de puesto de trabajo consta de uno o más líneas de texto.


TODO:
Calcular el salario asociado con el puesto.

Output:

Notas:
Utilizar tabla de dispersio
Se conoce como diccionario. Mapa en c++



*/
