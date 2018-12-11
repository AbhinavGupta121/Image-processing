#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{int i,j;int intensity;int max=0;
Mat img=imread("lowcontrast.PNG",0);
int col=img.cols;
int row=img.rows;
int farray[256];
for(i=0;i<256;i++)
{
	farray[i]=0;
}
for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{ 
               intensity=img.at<uchar>(i,j);
               farray[intensity]++;
           }

	}
for(i=0;i<=255;i++)
{
	if(farray[i]>=max)
	{
		max=farray[i];
	}
}
Mat a(max,255,CV_8UC1,Scalar(0));
for(i=0;i<=255;i++)
	{
		for(j=0;j<farray[i];j++)
		{ 
               a.at<uchar>(j,i)=255;
           }

	}
	cout<<max<<endl;
imshow("IMG",a);
waitKey(0);
}

