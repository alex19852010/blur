#include "imageloader.h"

imageLoader::imageLoader(QLabel *label, QSlider *slider, QGraphicsPixmapItem *item, QGraphicsScene *scene, QGraphicsView *view,
                         QGraphicsBlurEffect *blurEffect, QString *path, QPixmap *img) : QObject(), label(label), slider(slider),item(item), scene(scene),
                         view(view), blurEffect(blurEffect), path(path), img(img)

{

}


void imageLoader::loadImage()
{

  QString imagePath = QFileDialog::getOpenFileName(nullptr, "select image", "", "Images (*.png *.jpg)");
          if (!imagePath.isEmpty()) {
              QPixmap image(imagePath);
              *path = imagePath;
              label->setPixmap(image);
              slider->setEnabled(true);
              QObject::connect(slider, &QSlider::valueChanged, this, &imageLoader::changeImage);

            }
}


void imageLoader::changeImage(int value)
{

  QPixmap img(*path);
  QSize size = img.size();
  scene->setSceneRect(QRectF(0, 0, size.width(), size.height()));
  view->setScene(scene);
  item = scene->addPixmap(QPixmap(*path));
  blurEffect->setBlurRadius(value);
  item->setGraphicsEffect(blurEffect);
  view->show();

}
