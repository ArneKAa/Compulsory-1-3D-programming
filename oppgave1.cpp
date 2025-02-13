#include "oppgave1.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

float f(const float x)
{
    return (x*x*x) - (9*x*x) + (8*x) - 13;
}

float fd(const float x)
{
    return (3*x*x) - (18*x) + 8;
}


std::vector<Vertex> generateVertices()
{
    std::vector<Vertex> vertices;

    Df df{-750, 750};
    int n = 7500;
    float h = (df.b - df.a) / n;

    float x = df.a;

    float green, red;

    for(int i = 0; i < n + 1; i++)
    {
        if(fd(x) < 0)
        {
            green = 0.0;
            red = 1.0;
        }
        else
        {
            green = 1.0;
            red = 0.0;
        }

        vertices.push_back(Vertex{x/4, f(x)/4, 0.0f, red, green, 0.0f, 0.0f, 0.0f});

        x += h;
    }

    return vertices;
}

Vertex stringToVertex(std::string& line)
{
    Vertex vertex;

    std::istringstream stream(line);

    std::string token;

    int i = 0;

    while (getline(stream, token, ' '))
    {
        if(i == 0)
        {
            vertex.x = stof(token);
        }
        else if(i == 1)
        {
            vertex.y = stof(token);
        }
        else if(i == 2)
        {
            vertex.z = stof(token);
        }
        else if(i == 3)
        {
            vertex.r = stof(token);
        }
        else if(i == 4)
        {
            vertex.g = stof(token);
        }
        else if(i == 5)
        {
            vertex.b = stof(token);
        }
        else if(i == 6)
        {
            vertex.u = stof(token);
        }
        else if(i == 7)
        {
            vertex.v = stof(token);
        }

        i++;
    }

    return vertex;
}

void writeVertices()
{
    std::vector<Vertex> vertices = generateVertices();
    std::ofstream myFile;
    myFile.open("oppgave1.txt");

    myFile << vertices.size() << std::endl;

    for(const Vertex& v : vertices)
    {
        myFile << v.x << " " << v.y << " " << v.z << " " << v.r << " " << v.g << " " << v.b << std::endl;
    }

    myFile.close();
}

std::vector<Vertex> readVertices()
{
    std::vector<Vertex> vertices;
    std::string line;

    std::ifstream myFile("oppgave1.txt");
    if (myFile.is_open())
    {
        bool firstLine = true;
        while (getline(myFile, line))
        {
            if(!firstLine)
            {
                vertices.push_back(stringToVertex(line));
            }
            firstLine = false;
        }
    }

    return vertices;
}

