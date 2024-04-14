#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#pragma once
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>
#include <QtWidgets>
#include <QSlider>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class imageLoader : public QObject
{
  Q_OBJECT

public:
    imageLoader(QLabel *label, QSlider *slider, QGraphicsPixmapItem *item,
                QGraphicsScene *scene, QGraphicsView *view, QGraphicsBlurEffect *blurEffect, QString *path, QPixmap *img);


public slots:
    void loadImage();

public slots:
    void changeImage(int value);


private:
    QLabel *label;
    QSlider *slider;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsBlurEffect *blurEffect;
    QString *path;
    QPixmap *img;

};

#endif // IMAGELOADER_H
