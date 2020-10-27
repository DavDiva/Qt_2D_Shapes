#include "renderarea.h"
#include "qpainter.h"

RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
    mBackgroundColor(0,0,255),
    mShapeColor(255,255,255),
    mShape(Astroid)
{
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}
QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}
void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);

    switch (mShape) {
    case Astroid:
        mBackgroundColor = QColorConstants::Red;
        break;

    case Cycloid:
        mBackgroundColor = QColorConstants::Green;
        break;

    case HuygensCycloid:
        mBackgroundColor = QColorConstants::Blue;
        break;

    case HypoCycloid:
        mBackgroundColor = QColorConstants::Yellow;
        break;

    default:
        break;
    }

     painter.setBrush(mBackgroundColor);
     painter.setPen(mShapeColor);


    //drawing area
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(),this->rect().bottomRight());
}
