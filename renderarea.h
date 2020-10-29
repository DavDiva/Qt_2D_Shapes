#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line };

    void setBackgroundColor(QColor color)
    {
        mBackgroundColor = color;
    } //setter

    QColor getBackgroundColor() const
    {
        return mBackgroundColor;
    } //getter

    void setShapeColor(QColor color)
    {
        mShapeColor = color;
    }

    QColor getShapeColor() const
    {
        return mShapeColor;
    }

    void setShape(ShapeType shape)
    {
        mShape = shape; on_shape_changed();
    }//setter

    ShapeType getShape() const
    {
        return mShape;
    }//getter

    void setScale(float scale)
    {
        mScale = scale;
        repaint();
    }
    float getScale() const
    {
        return mScale;
    }

    void setInterval(float interval)
    {
        mIntervalLength = interval;
        repaint();
    }
    float getInterval() const
    {
        return mIntervalLength;
    }

    void setStepCount(int count)
    {
        mStepCount = count;
        repaint();
    }
    int getStepCount() const
    {
        return mStepCount;
    }


protected:

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


signals:

private:
    void on_shape_changed();
    QPointF compute(float t);//dispatch function based on mShape`s type
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line (float t);

    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;

};

#endif // RENDERAREA_H
