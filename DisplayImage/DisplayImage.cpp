#include "dbg.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main (int argc, char ** argv){
Mat image;
  __check (argc == 2, "Usage: DisplayImage <ImagePath>");



  image = imread ( argv[1], 1 );

  if ( !image.data ){
    __log_warn("No image data detected.");
    return -1;
  }
  namedWindow("Display Image", WINDOW_AUTOSIZE);
  imshow("Display Image", image);

  waitKey(0);
return 0;


 error:
  __debug("%s",USER_ERR_MSG);
  free(USER_ERR_MSG);
  return -1;
}
