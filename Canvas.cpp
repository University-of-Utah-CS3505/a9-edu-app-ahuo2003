#include "Canvas.h"

// General Tool Declaration
Canvas::Canvas(QWidget *parent) : QLabel(parent) {
  // Base scale factor for 8x8 canvas
  scaleFactor = 20;
}

void Canvas::redrawCanvas(QImage frame) {
  QPixmap pixmap = QPixmap::fromImage(
      frame.scaled(frame.width() * scaleFactor, frame.height() * scaleFactor,
                   Qt::KeepAspectRatio, Qt::FastTransformation));
  setPixmap(pixmap);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
}
void Canvas::mouseReleaseEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
}
void Canvas::mouseMoveEvent(QMouseEvent *event) {
  emit mouseEventSignal(event);
}
