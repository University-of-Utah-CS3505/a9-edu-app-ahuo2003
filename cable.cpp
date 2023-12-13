#include "cable.h"

Cable::Cable(QPoint startPos, QColor cableColor) {
  // Set the color of the cables.
  this->cableColor = cableColor;
  cableEndPosColor = cableColor.darker();
  moveHorizontal = false;
  moveVertical = false;

  // Append the starting position to the path list.
  path.append(startPos);
  cableEndPos = &(path[0]);
  canDraw = false;
}

void Cable::mousePressed(QImage &image, const QPoint &mouseLocation) {
  if ((mouseLocation.x() == cableEndPos->x()) &&
      (mouseLocation.y() == cableEndPos->y())) {
    canDraw = true;
    image.setPixelColor(*cableEndPos, cableColor);
  }
}

void Cable::mouseReleased(QImage &image) {
  // Set the end of the cable to the last item in the path list, and set its
  // pixel color in the canvas to a darker version.
  if (canDraw) {
    image.setPixelColor(*cableEndPos, cableEndPosColor);
    canDraw = false;
    moveHorizontal = false;
    moveVertical = false;
  }
}

void Cable::mouseMoved(QImage &image, const QPoint &mouseLocation) {

  if (mouseLocation.x() < 32 && mouseLocation.x() >= 0 &&
      mouseLocation.y() >= 0 && mouseLocation.y() < 32) {
    if (canDraw) {
      if (!moveHorizontal && !moveVertical) {
        int dx = cableEndPos->x() - mouseLocation.x();
        int dy = cableEndPos->y() - mouseLocation.y();
        if (*cableEndPos != mouseLocation) {
          if (dx == 0) {
            moveVertical = true;
          } else if (dy == 0) {
            moveHorizontal = true;
          }
        }
      }
      // It will delete the entire path between the end of the cable, and 12
      // pixels prior if faster deleition is desired, otherwise just the
      // previous pixels.
      if (path.contains(mouseLocation) &&
          (path.indexOf(mouseLocation) >= path.size() - 12)) {
        deleteFromPath(image, mouseLocation);
      } else {
        appendToPath(image, *cableEndPos, mouseLocation);
      }
    }
  }
}

void Cable::appendToPath(QImage &image, const QPoint &startPoint,
                         const QPoint &endPoint) {
  int step = 1;
  if (moveVertical) {
    if (endPoint.y() < startPoint.y())
      step = -1;
    for (int y = startPoint.y(); y != endPoint.y() + step; y += step) {
      QPoint newPoint(startPoint.x(), y);
      if (startPoint.x() != endPoint.x())
        break;

      if (!path.contains(newPoint)) {
        path.append(newPoint);
        image.setPixelColor(newPoint, cableColor);
      }
    }
  } else if (moveHorizontal) {
    if (endPoint.x() < startPoint.x())
      step = -1;
    for (int x = startPoint.x(); x != endPoint.x() + step; x += step) {
      QPoint newPoint(x, startPoint.y());
      if (startPoint.y() != endPoint.y())
        break;
      if (!path.contains(newPoint)) {
        path.append(newPoint);
        image.setPixelColor(newPoint, cableColor);
      }
    }
  }
  cableEndPos = &(path[path.size() - 1]);
}

void Cable::deleteFromPath(QImage &image, const QPoint &point) {
  for (int i = path.size() - 1; i > path.indexOf(point); i--) {
    image.setPixelColor(path[i], Qt::transparent);
    path.removeAt(i);
  }
  cableEndPos = &(path[path.size() - 1]);
}

void Cable::changeScaleFactor(int newScaleFactor) {
  scaleFactor = newScaleFactor;
}

QPoint *Cable::getCableEndPos() const { return cableEndPos; }

void Cable::redrawCable(QImage &image) {
  for (QPoint point : path) {
    image.setPixelColor(point, cableColor);
  }
  image.setPixelColor(*cableEndPos, cableEndPosColor);
}

void Cable::changeCableColor(QColor color) {
  cableColor = color;
  cableEndPosColor = color.darker();
}
