#ifndef MODEL_H
#define MODEL_H

#include "cable.h"
#include "qimage.h"
#include <QMouseEvent>
#include <QObject>

class Model : public QObject {
  Q_OBJECT

public:
  explicit Model(QObject *parent = nullptr);
  enum class GateType { AND, OR, NOT, INPUT, OUTPUT };

signals:
  void invalidate(QImage img);

public slots:
  void mouseEvent(QMouseEvent *event);

private:
  QImage *levelView;
  Cable *currCable;
  QList<Cable*> cables;
  QList<GateType> gates;
};

#endif // MODEL_H
