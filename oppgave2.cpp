#include "oppgave2.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::vector<Vertex> generateVertices2()
{
    std::vector<Vertex> vertices;

    float x, y;

    for (float i = 0; i < 24 * 3.14159265358979323846264; i += 0.1)
    {
        x = cos(i);
        y = sin(i);

        vertices.push_back(Vertex{x, y, i/10, 0.2, 0.2, 1, 0, 0});
    }

    return vertices;
}

Vertex stringToVertex2(std::string& line)
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

void writeVertices2()
{
    std::vector<Vertex> vertices = generateVertices2();
    std::ofstream myFile;
    myFile.open("oppgave2.txt");

    myFile << vertices.size() << std::endl;

    for(const Vertex& v : vertices)
    {
        myFile << v.x << " " << v.y << " " << v.z << " " << v.r << " " << v.g << " " << v.b << std::endl;
    }

    myFile.close();
}

std::vector<Vertex> readVertices2()
{
    std::vector<Vertex> vertices;
    std::string line;

    std::ifstream myFile("oppgave2.txt");
    if (myFile.is_open())
    {
        bool firstLine = true;
        while (getline(myFile, line))
        {
            if(!firstLine)
            {
                vertices.push_back(stringToVertex2(line));
            }
            firstLine = false;
        }
    }

    return vertices;
}
