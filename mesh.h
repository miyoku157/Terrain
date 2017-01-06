#ifndef MESH_H
#define MESH_H

#include <QVector>
#include <QVector3D>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <face.h>
#include <edge.h>
#include <sommet.h>
#include <terrain.h>


class Mesh
{
public:
    Mesh();
    Mesh(Terrain &T);

    //Mesh(Terrain T);
    void saveAsObj(Terrain obj );

    int LoadFromOff(QString fileName);
    void draw();
    void drawFilDeFer();
    void drawPoint();

    Face* faceDebut();
    Face* faceFin();

    Sommet* sommetDebut();
    Sommet* sommetFin();

    Face* getFaceAt(int ind);
    Sommet* getSommetAt(int ind);

    void saveAsOFF(QString name);

private:
    void drawTriangle(Sommet v1,Sommet v2,Sommet v3);
    QVector<Sommet> sommets;
    QVector<Face> faces;

    void drawType1(int& start,QVector3D pos, int size);
    void drawType2(int& start,QVector3D pos, int size);

};

#endif // MESH_H
