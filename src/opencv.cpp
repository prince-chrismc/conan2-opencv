#include "opencv.h"

void opencv(std::string f) {
  cv::VideoCapture capture(f); // try to open string, this will attempt to open
                               // it as a video file or image sequence
  if (!capture.isOpened())     // if this fails, try to open as a video camera,
                               // through the use of an integer param
    capture.open(atoi(f.c_str()));
  if (!capture.isOpened()) {
    std::cerr
        << "Failed to open the video device, video file or image sequence!\n"
        << std::endl;
    return;
  }
  if (!process(capture))
    std::cerr << "processing error!" << std::endl;
  else
    std::cout << "bye!" << std::endl;

  /* std::cout << "Hello world from opencv!" << std::endl;
  std::vector<cv::Mat> frames;
  cv::imreadmulti(f, frames);
  if (frames.size() == 0) {
    std::cerr << "Could not open or find the image(s)" << std::endl;
    return;
  }
  std::cout << frames.size() << std::endl;
  cv::namedWindow(f,
                  cv::WINDOW_NORMAL & cv::WINDOW_KEEPRATIO); // Create a window
  for (auto &m : frames) {
    cv::imshow(f, m); // Show our image inside the created window.
    cv::waitKey(0);   // Wait for any keystroke in the window
  }
  cv::destroyWindow(f); // destroy the created window */
}

int process(cv::VideoCapture &capture) {
  int n = 0;
  char filename[200];
  std::string window_name = "video | q or esc to quit";
  std::cout << "press space to save a picture. q or esc to quit" << std::endl;
  cv::namedWindow(window_name, cv::WINDOW_KEEPRATIO); // resizable window;
  cv::Mat frame;

  for (;;) {
    capture >> frame;
    if (frame.empty())
      break;

    cv::imshow(window_name, frame);
    char key = (char)cv::waitKey(
        30); // delay N millis, usually long enough to display and capture input

    switch (key) {
    case 'q':
    case 'Q':
    case 27: // escape key
      return 0;
    case ' ': // Save an image
      std::sprintf(filename, "filename%.3d.jpg", n++);
      cv::imwrite(filename, frame);
      std::cout << "Saved " << filename << std::endl;
      break;
    default:
      break;
    }
  }
  return 0;
}