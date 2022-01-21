#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <QPixmap>
#include <QImage>
#include <QThread>
#include <opencv2/opencv.hpp>
#include "../Process/process.h"

#define ID_CAMERA 0 ///< Camera ID

class MyVideoCapture : public QThread
{
    Q_OBJECT
    public:
        MyVideoCapture(QObject *parent = nullptr);
        ~MyVideoCapture();
        QPixmap pixmap() const;
        double getWidth() const;
        double getHeight() const;
    signals:
        void newPixmapCaptured();
    protected:
        void run() override;
    private:
        QPixmap mPixmap;
        cv::Mat mFrame;
        cv::VideoCapture mCap;
        double mWidth;
        double mHeight;
};

#endif//VIDEOCAPTURE_H
 
