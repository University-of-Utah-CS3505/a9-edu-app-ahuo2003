#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QTimer>
#include <QWidget>

class SceneWidget : public QWidget {
  Q_OBJECT
public:
  explicit SceneWidget(QWidget *parent = nullptr);
signals:

public slots:
  void updateWorld();

private:
};

#endif // SCENEWIDGET_H
