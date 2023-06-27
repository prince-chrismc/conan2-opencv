#include "mjpgv.h"

void help(char **av) {
  std::cout
      << "The program captures frames from a video file, image sequence "
         "(01.jpg, 02.jpg ... 10.jpg) or camera connected to your computer."
      << std::endl
      << "Usage:\n"
      << av[0] << " <video file, image sequence or device number>" << std::endl
      << "q,Q,esc -- quit" << std::endl
      << "space   -- save frame" << std::endl
      << std::endl
      << "\tTo capture from a camera pass the device number. To find the "
         "device number, try ls /dev/video*"
      << std::endl
      << "\texample: " << av[0] << " 0" << std::endl
      << "\tYou may also pass a video file instead of a device number"
      << std::endl
      << "\texample: " << av[0] << " video.avi" << std::endl
      << "\tYou can also pass the path to an image sequence and OpenCV will "
         "treat the sequence just like a video."
      << std::endl
      << "\texample: " << av[0] << " right%%02d.jpg" << std::endl;
}
int main(int ac, char **av) {
  if (ac != 2) {
    help(av);
    return 1;
  }
  mjpgv(av[1]);
}
