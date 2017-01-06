#ifndef TERRAIN_H
#define TERRAIN_H

#include <windows.h>
#include <QObject>
#include <QVector>
#include <GL/gl.h>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QVector3D>
#include <QVector2D>
#include <QRgb>
#include <QColor>
#include <math.h>
#include <perlin.h>
#include <ctime>
#include <vegetation.h>
#include <iostream>

class Terrain
{
public:
    Terrain();
    Terrain(int width, int length);

    void loadFromHeightMap(QString name);
    void setHeightAt(int x, int y, double z);
    void setDirtAt(int x, int y, double dirtValue);
    void setTemperAt(int x, int y,double value);
    void setNormAt(int x, int y, QVector3D value);
    void setAvgSlope(int x, int y, double value);
    void setVeget(int x,int y, vegetation value);

    void generateTerrainFromNoise(double freq, double amp,int start, boolean ridge);

    double getHeightAt(int x, int y);
    double getDirtAt(int x, int y);
    double getTemperAt(int x, int y);
    QVector3D getNormAt(int x,int y);
    double getAvgSlope(int x, int y);
    vegetation getVeget(int x,int y);
    int countVeget(int x, int y);

    int getLength();
    int getWidth();

    void drawTriangle(QVector3D v1, QVector3D v2, QVector3D v3);
    void saveAsImage(QString name);
    void display();

    void waterErode(int iterations);
    void erode(int iterations);
    void generateDirtMap();
    void generateColorMap();
    void initializeDirt();
    void initializeSlope();
    void initNormal();
    void initVeget(int nbveget,int nbCycles);
    void doCycles(int nbCycles, int nbveget, double maxDirt);
       void addTree(int nbveget, double maxDirt);
    void drawVeget();
    bool checkVeget2(int x, int y,double rayon,int &index);
    void positiveHeight();

    QVector<double> height;
    QVector<double> dirt;
    QVector<double> temper;
    QVector<double> avgSlope;
    QVector<vegetation> veget;
    QVector<QVector3D> norm;
private:
    int width;
    int length;
    double talus;

    double* V8(int x, int y);
    double** V8N(int x, int y);
    double** V4N(int x, int y);
    void Slide(double* from);
};

#endif // TERRAIN_H
