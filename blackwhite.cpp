#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{int i,j;
Mat img=imread("fruits.png",0);
int col=img.cols;
int row=img.rows;
Mat a(row,col,CV_8UC1,Scalar(255));int th=0;
namedWindow("IMG",WINDOW_NORMAL);
createTrackbar("slider","IMG",&th,255);
while(1)
{
for(i=0;i<row;i++)
	{for(j=0;j<col;j++)
		{if((img.at<uchar>(i,j)>=th))
	a.at<uchar>(i,j)=255;
	else
		a.at<uchar>(i,j)=0;

			}
		}
		
	
imshow("IMG",a);
waitKey(1);
}

waitKey(0);
}