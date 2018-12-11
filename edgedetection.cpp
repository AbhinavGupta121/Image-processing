#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;
int ISVALID(int,int,int,int);
int sx=0;int sy=0;int ty=0;int th1=0;int p=0;int q=0;
int main()
{int i,j;int k,l;
Mat img=imread("lenaTest3.jpg",0);
int col=img.cols;
int row=img.rows;
Mat a(row,col,CV_8UC1,Scalar(0));int kernel1[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};int kernel2[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};cout<<kernel1[1][2]<<endl;
namedWindow("IMG",WINDOW_NORMAL);
            createTrackbar("slider","IMG",&th1,2000);
            createTrackbar("slider1","IMG",&p,1000);
            createTrackbar("slider2","IMG",&q,1000);
while(1)
          {
          	

            for(i=0;i<row;i++)
	          {
	          
		        for(j=0;j<col;j++)
		         { 
			     for(k=i-1;k<=i+1;k++)
			        {
				        for(l=j-1;l<=j+1;l++)
				         {
					        if(ISVALID(k,l,row,col)==1)
					          {
						        sx=sx+kernel1[k-i+1][l-j+1]*(img.at<uchar>(k,l));
						          sy=sy+kernel2[k-i+1][l-j+1]*(img.at<uchar>(k,l));
					          }
			    	      }
			        }

			ty=(int)sqrt(sx*sx+sy*sy);
			
       
          if(ty>=th1||abs(sx)>=p||abs(sy)>=q)
                a.at<uchar>(i,j)=250;
            else
            	a.at<uchar>(i,j)=0;
            sx=0;sy=0;
                 }
              }
          
          imshow("IMG",a);
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
	
       


						
