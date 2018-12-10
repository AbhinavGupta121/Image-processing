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
Mat a(row,col,CV_8UC1,Scalar(255));
for(i=0;i<row;i++)
	{for(j=0;j<col;j++)
		{a.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;
			}
		}
imshow("IMG",a);
imshow("IMG2",img);
waitKey(0);
}