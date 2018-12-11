#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int ISVALID(int,int,int,int);

int main()
{int i,j;int intensity;int max=0;
Mat img=imread("index.jpg",0);
int col=img.cols;int intensitysum=0;int k,l;int th=1;
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
namedWindow("IMG2",WINDOW_NORMAL);
createTrackbar("slider","IMG2",&th,9);
Mat b(row,col,CV_8UC1,Scalar(0));
while(1)
{
for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{ 
			for(k=i-th;k<=i+th;k++)
			{
				for(l=j-th;l<=j+th;l++)
				{
					if(ISVALID(k,l,row,col)==1)
					{
				
							intensitysum=intensitysum+img.at<uchar>(k,l);
					}
				}
				
				
				
			}
			b.at<uchar>(i,j)=intensitysum/((2*th + 1)*(2*th + 1));
			intensitysum=0;
		}
	}
	imshow("IMG2",b);
	waitKey(1);
}
waitKey(0);




}
int ISVALID(int x,int y,int rows,int cols)
{
	if(x<0||y<0||x>=rows||y>=cols)
		return 0;
		return 1;
}
	

