#ifndef MODEL_H
#define MODEL_H

#include "Level.h"
#include "cable.h"
#include "qimage.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "InGate.h"
#include "NotGate.h"
#include "OutGate.h"
#include <QMouseEvent>
#include <QObject>

/**
 * @brief The Model class handles all the operations for the Educational Project to function as desired.
 */
class Model : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Model constructor for the model class.
   * @param parent nullptr.
   */
  explicit Model(QObject *parent = nullptr);

signals:
  /**
   * @brief invalidate updates the view.
   * @param img new image to be drawn.
   */
  void invalidate(QImage img);

  /**
   * @brief changeLevel changes the level.
   * @param levelImage image of the level.
   */
  void changeLevel(QImage levelImage);

  /**
   * @brief wonLevel lets the view know that the player won the level.
   */
  void wonLevel();

  /**
   * @brief levelLost lets the view know that the player lost the level.
   */
  void levelLost();

public slots:
  /**
   * @brief mouseEvent handler for different types of mouse events.
   * @param event type of event (pressed, released, and moved).
   */
  void mouseEvent(QMouseEvent *event);

    /**
   * @brief setAndLevel sets the level.
   * @param levelSelect level identifier.
   */
  void setAndLevel(int levelSelect);

  /**
   * @brief checkWinningCondition checks if the player won the level.
   */
  void checkWinningCondition();

private:
  QImage *levelView;
  Cable *currCable;
  QList<Cable*> currLevelCables;
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
   * @brief loadLevel loads the level.
   * @param levelNum level identifier.
   */
  void loadLevel(int levelNum);

  /**
   * @brief changeCurrentCable changes the current cable based on the mouse position.
   * @param mousePos mouse position.
   */
  void changeCurrentCable(QPoint mousePos);

  friend class Cable;
  friend class Level;
  friend class Gate;
};

#endif // MODEL_H
