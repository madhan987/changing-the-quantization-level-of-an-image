
//New images by changing quantization level
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;

int main()
{
	//Reading an image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p3.png");

	//Displaying an image
	imshow("1", image);

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat sixbits(image.cols, image.rows, CV_8UC1);
	Mat fourbits(image.cols, image.rows, CV_8UC1);
	Mat twobits(image.cols, image.rows, CV_8UC1);
	Mat onebit(image.cols, image.rows, CV_8UC1);

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}




	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			onebit.at<uchar>(i, j) = grey_image.at<uchar>(i, j) / 128;//one bits
			twobits.at<uchar>(i, j) = grey_image.at<uchar>(j, i) / 64;//Two bits
			fourbits.at<uchar>(i, j) = grey_image.at<uchar>(i, j) / 16;//Four bits
			sixbits.at<uchar>(i, j) = grey_image.at<uchar>(i, j) / 4;//Six bits
		}
	}

	
	imshow("Original", image);
	imshow("Grey image", grey_image);
	imshow("One bit", onebit);
	imshow("Two bit", twobits);
	imshow("Four bit", fourbits);
	imshow("Six bit", sixbits);

	waitKey(0);

	return 1;
}