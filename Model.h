#ifndef MODEL_H
#define MODEL_H

#include "Level.h"
#include "cable.h"
#include "qimage.h"
#include <QMouseEvent>
#include <QObject>

/**
 * @brief The Model class
 */
class Model : public QObject {
  Q_OBJECT
public:
  explicit Model(QObject *parent = nullptr);

signals:
  /**
   * @brief invalidate TODO
   * @param img TODO
   */
  void invalidate(QImage img);

  /**
   * @brief changeLevel TODO
   * @param levelImage TODO
   */
  void changeLevel(QImage levelImage);

public slots:
  /**
   * @brief mouseEvent TODO
   * @param event TODO
   */
  void mouseEvent(QMouseEvent *event);

    /**
   * @brief setAndLevel TODO
   * @param levelSelect TODO
   */
  void setAndLevel(int levelSelect);

private:
  QImage *levelView;
  Cable *currCable;
  Level currLevel;
  int scaleFactor;
  /**
   * @brief mapToImageCoordinates converts mouse coordinates to the model's
   * image coordinates.
   * @param point the point to be converted.
   * @param scaleFactor factor to scale the point to the model's image
   * coordinates.
   * @return a point in the model's image.
   */
  QPoint mapToImageCoordinates(const QPoint &point, int scaleFactor);

  /**
   * @brief loadLevel TODO
   * @param levelNum TODO
   */
  void loadLevel(int levelNum);

  /**
   * @brief changeCurrentCable TODO
   * @param mousePos TODO
   */
  void changeCurrentCable(QPoint mousePos);

  friend class Cable;
  friend class Level;
  friend class Gate;
};

#endif // MODEL_H
