// include the librealsense C++ header file
#include <librealsense2/rs.hpp>

// include OpenCV header file
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	rs2::pipeline pipe;
	rs2::config cfg;
	cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);
	pipe.start(cfg);
	rs2::frameset frames;
	char key = ' ';
	while (key != 'q')
	{
		frames = pipe.wait_for_frames();
		rs2::frame color_frame = frames.get_color_frame();
		Mat color(Size(640, 480), CV_8UC3, (void*)color_frame.get_data(), Mat::AUTO_STEP);

		// Display in a GUI
		namedWindow("Display Image", WINDOW_AUTOSIZE);

		imshow("Display Image", color);

		key = waitKey(10);
	}
	return 0;
}
