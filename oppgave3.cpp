#include "oppgave3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

double f(const double x, const double y)
{
    return x * x * y;
}

std::vector<Vertex> generateVertices3()
{
    std::vector<Vertex> mVertices;

    float xmin=0.0f, xmax=1.0f, ymin=0.0f, ymax=1.0f, h=0.05f;

    for (auto x=xmin; x<xmax; x+=h)
    {
        for (auto y=ymin; y<ymax; y+=h)
        {
            float z = f(x, y);
            mVertices.push_back(Vertex{x,y,z,x,y,z});
            z = f(x+h, y);
            mVertices.push_back(Vertex{x+h,y,z,x,y,z});
            z = f(x, y+h);
            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
            mVertices.push_back(Vertex{x,y+h,z,x,y,z});
            z = f(x+h, y);
            mVertices.push_back(Vertex{x+h,y,z,x,y,z});
            z = f(x+h, y+h);
            mVertices.push_back(Vertex{x+h,y+h,z,x,y,z});
        }
    }
    return mVertices;
}

Vertex stringToVertex3(std::string& line)
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

void writeVertices3()
{
    std::vector<Vertex> vertices = generateVertices3();
    std::ofstream myFile;
    myFile.open("oppgave3.txt");

    myFile << vertices.size() << std::endl;

    for(const Vertex& v : vertices)
    {
        myFile << v.x << " " << v.y << " " << v.z << " " << v.r << " " << v.g << " " << v.b << std::endl;
    }

    myFile.close();
}

std::vector<Vertex> readVertices3()
{
    std::vector<Vertex> vertices;
    std::string line;

    std::ifstream myFile("oppgave3.txt");
    if (myFile.is_open())
    {
        bool firstLine = true;
        while (getline(myFile, line))
        {
            if(!firstLine)
            {
                vertices.push_back(stringToVertex3(line));
            }
            firstLine = false;
        }
    }

    return vertices;
}
