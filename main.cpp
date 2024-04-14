#include "mainwindow.h"
#include <QApplication>
#include "imageloader.h"
#include <QtWidgets>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("image");
    QVBoxLayout layout(&window);
    QGraphicsPixmapItem item;
    QGraphicsScene scene;
    QGraphicsView view;
    QGraphicsBlurEffect blurEffect;
    QLabel label;
    QString path;
    QPixmap img;
    QSlider slider(Qt::Horizontal);
    QPushButton button("select image");
    imageLoader imageloader(&label, &slider, &item, &scene, &view, &blurEffect, &path, &img);
    slider.setMinimum(0);
    slider.setMaximum(10);
    slider.setEnabled(false);
    layout.addWidget(&label);
    layout.addWidget(&slider);
    layout.addWidget(&button);

    QObject::connect(&button, &QPushButton::clicked, &imageloader, &imageLoader::loadImage);

    window.show();
    return a.exec();
}
