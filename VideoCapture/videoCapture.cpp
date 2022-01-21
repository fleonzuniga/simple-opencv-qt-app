/**
*   @file videoCapture.cpp
*   video capture class
*/
#include "videoCapture.h"

MyVideoCapture::MyVideoCapture(QObject *parent):QThread{parent},mCap{ID_CAMERA}
{
    mWidth = mCap.get(cv::CAP_PROP_FRAME_WIDTH);
    mHeight = mCap.get(cv::CAP_PROP_FRAME_HEIGHT);
}

MyVideoCapture::~MyVideoCapture()
{
    //
}

QPixmap MyVideoCapture::pixmap() const
{
    cv::Mat converted;
    cv::cvtColor(mFrame,converted,cv::COLOR_BGR2RGB);
    QImage result = QImage((const unsigned char*)(converted.data),
                           converted.cols,
                           converted.rows,
                           QImage::Format_RGB888);
    return QPixmap::fromImage(result);
}

double MyVideoCapture::getWidth() const
{
    return mWidth;
}

double MyVideoCapture::getHeight() const
{
    return mHeight;
}

void MyVideoCapture::run()
{
    if(mCap.isOpened())
    {
        while(true)
        {
            cv::Mat frame;
            mCap >> frame;
            process(frame,mFrame);
            if(!mFrame.empty())
            {
                emit newPixmapCaptured();
            }
        }
    }
}
