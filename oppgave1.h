#ifndef OPPGAVE1_H
#define OPPGAVE1_H

#include <vector>
#include "vertex.h"


struct Df
{
    float a, b;
};

std::vector<Vertex> generateVertices();

void writeVertices();

Vertex stringToVertex(std::string& line);

std::vector<Vertex> readVertices();


#endif // OPPGAVE1_H
