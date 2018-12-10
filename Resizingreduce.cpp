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
Mat a(row/2,col/2,CV_8UC3,Scalar(0,0,0));
for(i=0;i<row/2;i++)
{
	for(j=0;j<col/2;j++)
	{
		a.at<Vec3b>(i,j)[0]=(img.at<Vec3b>(2*i,2*j)[0]+img.at<Vec3b>(2*i+1,2*j)[0]+img.at<Vec3b>(2*i,2*j+1)[0]+img.at<Vec3b>(2*i+1,2*j+1)[0])/4;
		a.at<Vec3b>(i,j)[1]=(img.at<Vec3b>(2*i,2*j)[1]+img.at<Vec3b>(2*i+1,2*j)[1]+img.at<Vec3b>(2*i,2*j+1)[1]+img.at<Vec3b>(2*i+1,2*j+1)[1])/4;
		a.at<Vec3b>(i,j)[2]=(img.at<Vec3b>(2*i,2*j)[2]+img.at<Vec3b>(2*i+1,2*j)[2]+img.at<Vec3b>(2*i,2*j+1)[2]+img.at<Vec3b>(2*i+1,2*j+1)[2])/4;

	}
}
imshow("IMG",a);
imshow("IMG2",img);
waitKey(0);
}
