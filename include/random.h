#ifndef RANDOM_H
#define RANDOM_H

void randomize(void);

// devuelve en (0; 1) (el cero incluido)
double randNormalize(void);

// devuelve entre (izq, der) (ambos incluidos)
int randInt(int, int);

// devuelve entre (izq, der) (izq incluida)
double randReal(double, double);

#endif