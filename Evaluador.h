#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>       // std::cin, std::cout
#include <fstream>       // std::cin, std::cout
#include <stack>          // std::stack
using namespace std;

void evaluar();

void escribirNumeroTexto(string nombre_archivo, int num);
int leerNumeroTexto(string nombre_archivo);
void escribirStringTexto(string nombre_archivo, string str);
string leerStringTexto(string nombre_archivo);
void escribirNumeroBinario(string nombre_archivo, int num);
int leerNumeroBinario(string nombre_archivo);
void escribirStringBinario(string nombre_archivo, string str);
string leerStringBinario(string nombre_archivo);
bool existe(string nombre_archivo, string str);
int obtenerMayor(string nombre);
#endif // EVALUADOR_H
