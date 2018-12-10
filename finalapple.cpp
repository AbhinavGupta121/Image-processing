#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{int i,j;
Mat img=imread("fruits.png",1);
int col=img.cols;
int row=img.rows;
Mat a(row,col,CV_8UC3,Scalar(0,0,0));int thblue,th1blue,th2green,th3green,th4red,th5red;thblue=th2green=th4red=0;th1blue=th3green=th5red=254;
namedWindow("IMG",WINDOW_NORMAL);
createTrackbar("sliderblue","IMG",&thblue,255);
createTrackbar("slider2blue","IMG",&th1blue,255);
createTrackbar("slider3green","IMG",&th2green,255);
createTrackbar("slider4green","IMG",&th3green,255);
createTrackbar("slider5red","IMG",&th4red,255);
createTrackbar("slider6red","IMG",&th5red,255);
while(1)
{
for(i=0;i<row;i++)
	{for(j=0;j<col;j++)
		{if((img.at<Vec3b>(i,j)[0]>=thblue&&(img.at<Vec3b>(i,j)[0]<=th1blue))&&(img.at<Vec3b>(i,j)[1]>=th2green&&(img.at<Vec3b>(i,j)[1]<=th3green))&&(img.at<Vec3b>(i,j)[2]>=th4red&&(img.at<Vec3b>(i,j)[2]<=th5red)))
			{
	a.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
	a.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
	a.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
	}
	else
		{a.at<Vec3b>(i,j)[0]=0;
	a.at<Vec3b>(i,j)[1]=0;
	a.at<Vec3b>(i,j)[2]=0;}
		

			}
		}
		
	
imshow("IMG",a);
waitKey(1);
}

waitKey(0);
}