#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <windows.h>
#include <QGLWidget>
#include <QMouseEvent>
#include <terrain.h>
#include <mesh.h>

class GLDisplay : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLDisplay(QWidget *parent = 0);

    virtual void initializeGL();

    virtual void paintGL();

    virtual void resizeGL(int w, int h);

protected:
    virtual void mouseMoveEvent ( QMouseEvent * event );
    virtual void mousePressEvent ( QMouseEvent * event );

private:
    void drawSierpinski();
    Terrain terrain;
    Mesh m;
    float _angleX;
    float _angleY;
    QPoint _position;
    
signals:
    
public slots:
    
};

#endif // GLDISPLAY_H
