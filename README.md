[//]: # (Image References)
 
[image1]: ./MP2_KeypointDetection_images/BRISK/BRISK_0000_n=2757_t=47.649ms.png
[image2]: ./MP3_KeypointRemoval_images/BRISK/BRISK_0000_ntotal=2757_nremoved=2493.png
[image3]: ./MP4_KeypointDescriptors_images/det_FAST/det_FAST_decs_ORB/FAST_ORB_0000_n=149_t=1.806ms.png
[image4]: ./MP5_DescriptorMatching_images/det_BRISK/det_BRISK_decs_SIFT/det_BRISK_decs_SIFT_MAT_FLANN/det_BRISK_decs_SIFT_MAT_FLANN_n=168_t=7.533ms.png
[image5]: ./MP5_DescriptorMatching_images/det_ORB/det_ORB_decs_ORB/det_ORB_decs_ORB_MAT_FLANN/det_ORB_decs_ORB_MAT_FLANN_n=39_t=3.332ms.png
[image6]: ./MP7_PerformanceEvaluation1/mp7_1.png
[image7]: ./MP7_PerformanceEvaluation1/mp7_2.bmp
[image8]: ./images/Det_FAST_Descriptors_evaluation.png
[image9]: ./images/Descriptor_BRIEF_Detectors_evaluation.png

[image10]: ./images/Detector_FAST.gif
[image11]: ./images/Detector_FAST_Descriptor_BRIEF.gif
[image12]: ./images/Mathing_Detector_FAST_Descriptor_BRIEF.gif
[image13]: ./images/Detector_SIFT.gif

# SFND 2D Feature Tracking

<img src="images/keypoints.png" width="820" height="248" align="middle"/>

The idea of the camera course is to build a collision detection system - that's the overall goal for the Final Project. As a preparation for this, you will now build the feature tracking part and test various detector / descriptor combinations to see which ones perform best. This mid-term project consists of four parts:

* First, you will focus on loading images, setting up data structures and putting everything into a ring buffer to optimize memory load. 
* Then, you will integrate several keypoint detectors such as HARRIS, FAST, BRISK and SIFT and compare them with regard to number of keypoints and speed. 
* In the next part, you will then focus on descriptor extraction and matching using brute force and also the FLANN approach we discussed in the previous lesson. 
* In the last part, once the code framework is complete, you will test the various algorithms in different combinations and compare them with regard to some performance measures. 

See the classroom instruction and code comments for more details on each of these parts. Once you are finished with this project, the keypoint matching part will be set up and you can proceed to the next lesson, where the focus is on integrating Lidar points and on object detection using deep-learning. 

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * This must be compiled from source using the `-D OPENCV_ENABLE_NONFREE=ON` cmake flag for testing the SIFT and SURF detectors.
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D_feature_tracking`.# SFND_2D_Feature_Matching_Mid_Term

## MP.1 - Data Buffer Optimization.

* Implemented on the file [MidTermProject_Camera_Student.cpp](src/MidTermProject_Camera_Student.cpp) from lines 67 to 75.

## MP.2 - Keypoint Detection.

* Implemented over the functions `detKeypointsShiTomasi`,`detKeypointsHarris` and `detKeypointsModern` on the file [matching2D_Student.cpp](src/matching2D_Student.cpp) from lines 9 to 257. And call in the main code [MidTermProject_Camera_Student.cpp](src/MidTermProject_Camera_Student.cpp) from line 215 to 232.

* All The detectors list was implemented for all [Dataset images](images/KITTI/2011_09_26/image_00/data/) available.The next image is a example of the result.

file:[BRISK_0000_n=2757_t=47.649ms.png](MP2_KeypointDetection_images/BRISK/BRISK_0000_n=2757_t=47.649ms.png)

![alt text |width=450px | align="middle"][image1]

## MP.3 - Keypoint Removal.

* Implemented on the file [MidTermProject_Camera_Student.cpp](src/MidTermProject_Camera_Student.cpp) from lines 242 to 255.

* The next image is a example of the result

file:[BRISK_0000_ntotal=2757_nremoved=2493.png](MP3_KeypointRemoval_images/BRISK/BRISK_0000_ntotal=2757_nremoved=2493.png)

![alt text |width=450px | align="middle"][image2]

## MP.4 - Keypoint Descriptors.

* Implemented over the function `descKeypoints`on the file [matching2D_Student.cpp](src/matching2D_Student.cpp) from lines 260 to 357. And call in the main code [MidTermProject_Camera_Student.cpp](src/MidTermProject_Camera_Student.cpp) from line 285 to 295.

* All The Descriptors list was implemented for all [Dataset images](images/KITTI/2011_09_26/image_00/data/) available.The next image is a example of the result (FAST+ORB).

file:[FAST_ORB_0000_n=149_t=1.806ms.png](MP4_KeypointDescriptors_images/det_FAST/det_FAST_decs_ORB/FAST_ORB_0000_n=149_t=1.806ms.png)

![alt text |width=450px | align="middle"][image3]

## MP.5 - Descriptor Matching

* Implemented over the function `matchDescriptors`on the file [matching2D_Student.cpp](src/matching2D_Student.cpp) from lines 359 to 480 And call in the main code [MidTermProject_Camera_Student.cpp](src/MidTermProject_Camera_Student.cpp) from line 307 to 329.

* All The matching Descriptors list was implemented for all [Dataset images](images/KITTI/2011_09_26/image_00/data/) available.The next image is a example of the result (BRISK+SIFT) mathing points between image 1 and the previous image 0.

file:[det_BRISK_decs_SIFT_MAT_FLANN_n=168_t=7.533ms.png](MP5_DescriptorMatching_images/det_BRISK/det_BRISK_decs_SIFT/det_BRISK_decs_SIFT_MAT_FLANN/det_BRISK_decs_SIFT_MAT_FLANN_n=168_t=7.533ms.png)

![alt text |width=450px | align="middle"][image4]

## MP.6 - Descriptor  Distance Ratio

* Implemented over the function `matchDescriptors`on the file [matching2D_Student.cpp](src/matching2D_Student.cpp) from lines 359 to 480 And call in the main code [MidTermProject_Camera_Student.cpp](src/MidTermProject_Camera_Student.cpp) from line 307 to 329.

* All The matching Descriptors list was implemented for all [Dataset images](images/KITTI/2011_09_26/image_00/data/) available.The next image is a example of the result (BRISK+SIFT) mathing points between image 1 and the previous image 0.

file:[det_ORB_decs_ORB_MAT_FLANN_n=39_t=3.332ms.png](MP5_DescriptorMatching_images/det_ORB/det_ORB_decs_ORB/det_ORB_decs_ORB_MAT_FLANN/det_ORB_decs_ORB_MAT_FLANN_n=39_t=3.332ms.png)

![alt text |width=450px | align="middle"][image5]

## MP.7 - Performance Evaluation 1.
    
* count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.

* The next scatter plot shows the distribuion of the detected keypoints on the preceding vehicle and time elapsed.

![alt text |width=450px | align="middle"][image6]    

* The next scatter plot shows the distribuion of the detected keypoints on the preceding vehicle and time elapsed.

![alt text |width=450px | align="middle"][image7]   
    
The BRISK feature detect a higher number of the Keypoints in a short elapsed time. the FAST feature shows capable to be fast and detect a good number of keypoints comparing with the others features.
    
For the complete evaluation, please check the `notebook file`: [Detector_Evaluation](Detector_Evaluation.ipynb)
