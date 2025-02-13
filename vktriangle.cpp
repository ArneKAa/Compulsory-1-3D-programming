#include "vktriangle.h"
#include "vertex.h"

//#include "oppgave1.h"
//#include "oppgave2.h"
#include "oppgave3.h"

VkTriangle::VkTriangle()
{
    // Y up, front = CCW
    // X,     Y,     Z,     R,    G,    B, U, V
    //Vertex v1{-1.0f, -0.5f,  0.0f,   1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    //Vertex v2{1.0f,  -0.5f,  0.0f,   0.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    //Vertex v3{0.0f,   0.5f,  0.0f,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    //Vertex v4{1.0f,   0.5f,  0.0f,   1.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    //mVertices.push_back(v1);
    //mVertices.push_back(v2);
    //mVertices.push_back(v3);
    //mVertices.push_back(v3);
    //mVertices.push_back(v2);
    //mVertices.push_back(v4);

    writeVertices3();

    mVertices = readVertices3();

    //Oppgave 1 og 2 bruker topologi LINE_STRIP
    //Oppgave 3 bruker TRIANGLE_LIST
    //For Oppgave en bruk writeVertices og readVertices uten tall, og tallet 2 etter for oppgave 2
}
