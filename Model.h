#ifndef MODEL_H
#define MODEL_H

#include "Level.h"
#include "cable.h"
#include "qimage.h"
#include <QMouseEvent>
#include <QObject>

class Model : public QObject {
  Q_OBJECT

public:
  explicit Model(QObject *parent = nullptr);


signals:
  void invalidate(QImage img);
  void changeLevel(QImage levelImage);

public slots:
  void mouseEvent(QMouseEvent *event);
  void setAndLevel();

private:
  QImage *levelView;
  Cable *currCable;
  QList<Cable *> cables;
  Level currLevel;
  int scaleFactor;
  /**
     * @brief mapToImageCoordinates converts mouse coordinates to the model's image coordinates.
     * @param point the point to be converted.
     * @param scaleFactor factor to scale the point to the model's image coordinates.
     * @return a point in the model's image.
     */
  QPoint mapToImageCoordinates(const QPoint& point, int scaleFactor);
  void loadLevel(int levelNum);
  friend class Cable;
  friend class Level;
};

#endif // MODEL_H
