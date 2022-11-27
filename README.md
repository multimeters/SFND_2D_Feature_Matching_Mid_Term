[//]: # (Image References)
 
[image1]: ./MP2_KeypointDetection_images/BRISK/BRISK_0000_n=2757_t=47.649ms.png
[image2]: ./MP3_KeypointRemoval_images/BRISK/BRISK_0000_ntotal=2757_nremoved=2493.png
[image3]: ./MP4_KeypointDescriptors_images/det_FAST/det_FAST_decs_ORB/FAST_ORB_0000_n=149_t=1.806ms.png
[image4]: ./MP5_DescriptorMatching_images/det_BRISK/det_BRISK_decs_SIFT/det_BRISK_decs_SIFT_MAT_FLANN/det_BRISK_decs_SIFT_MAT_FLANN_n=168_t=7.533ms.png
[image5]: ./MP5_DescriptorMatching_images/det_ORB/det_ORB_decs_ORB/det_ORB_decs_ORB_MAT_FLANN/det_ORB_decs_ORB_MAT_FLANN_n=39_t=3.332ms.png
[image6]: ./MP7_PerformanceEvaluation1/mp7-1.png
[image7]: ./MP7_PerformanceEvaluation1/mp7-2.png
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

* The next scatter plot shows the distribuion of the detected keypoints on the preceding vehicle and time elapsed.As shown in the iamge,the BRISK feature detect a higher number of the Keypoints in a short elapsed time. the FAST feature shows capable to be fast and detect a good number of keypoints comparing with the others features.

![alt text |width=250px | align="middle"][image6]    

* The following histogram shows the distribution of the neighborhood size of 10 images' key points with different detectors.

![alt text |width=250px | align="middle"][image7]   
    

    
For the complete data, please check the file: [Detector_Evaluation](MP7_PerformanceEvaluation1/mp7_1.txt) and file: [Detector_Evaluation](MP7_PerformanceEvaluation1/mp7_2.txt)


## MP.8 - Performance Evaluation 2.
    
* count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, use the BF approach with the descriptor distance ratio set to 0.8.

| **RefImageIndex** | **SourceImageIndex** | **Detector** | **Descriptor** | **MatchPointNumber** |
|:-----------------:|:--------------------:|:------------:|:--------------:|:--------------------:|
| "0"               | "1"                  | "SHITOMASI"  | "BRISK"        | "95"                 |
| "1"               | "2"                  | "SHITOMASI"  | "BRISK"        | "88"                 |
| "2"               | "3"                  | "SHITOMASI"  | "BRISK"        | "80"                 |
| "3"               | "4"                  | "SHITOMASI"  | "BRISK"        | "90"                 |
| "4"               | "5"                  | "SHITOMASI"  | "BRISK"        | "82"                 |
| "5"               | "6"                  | "SHITOMASI"  | "BRISK"        | "79"                 |
| "6"               | "7"                  | "SHITOMASI"  | "BRISK"        | "85"                 |
| "7"               | "8"                  | "SHITOMASI"  | "BRISK"        | "86"                 |
| "8"               | "9"                  | "SHITOMASI"  | "BRISK"        | "82"                 |
| "0"               | "1"                  | "SHITOMASI"  | "BRIEF"        | "115"                |
| "1"               | "2"                  | "SHITOMASI"  | "BRIEF"        | "111"                |
| "2"               | "3"                  | "SHITOMASI"  | "BRIEF"        | "104"                |
| "3"               | "4"                  | "SHITOMASI"  | "BRIEF"        | "101"                |
| "4"               | "5"                  | "SHITOMASI"  | "BRIEF"        | "102"                |
| "5"               | "6"                  | "SHITOMASI"  | "BRIEF"        | "102"                |
| "6"               | "7"                  | "SHITOMASI"  | "BRIEF"        | "100"                |
| "7"               | "8"                  | "SHITOMASI"  | "BRIEF"        | "109"                |
| "8"               | "9"                  | "SHITOMASI"  | "BRIEF"        | "100"                |
| "0"               | "1"                  | "SHITOMASI"  | "ORB"          | "106"                |
| "1"               | "2"                  | "SHITOMASI"  | "ORB"          | "102"                |
| "2"               | "3"                  | "SHITOMASI"  | "ORB"          | "99"                 |
| "3"               | "4"                  | "SHITOMASI"  | "ORB"          | "102"                |
| "4"               | "5"                  | "SHITOMASI"  | "ORB"          | "103"                |
| "5"               | "6"                  | "SHITOMASI"  | "ORB"          | "97"                 |
| "6"               | "7"                  | "SHITOMASI"  | "ORB"          | "98"                 |
| "7"               | "8"                  | "SHITOMASI"  | "ORB"          | "104"                |
| "8"               | "9"                  | "SHITOMASI"  | "ORB"          | "97"                 |
| "0"               | "1"                  | "SHITOMASI"  | "FREAK"        | "86"                 |
| "1"               | "2"                  | "SHITOMASI"  | "FREAK"        | "90"                 |
| "2"               | "3"                  | "SHITOMASI"  | "FREAK"        | "86"                 |
| "3"               | "4"                  | "SHITOMASI"  | "FREAK"        | "88"                 |
| "4"               | "5"                  | "SHITOMASI"  | "FREAK"        | "86"                 |
| "5"               | "6"                  | "SHITOMASI"  | "FREAK"        | "80"                 |
| "6"               | "7"                  | "SHITOMASI"  | "FREAK"        | "81"                 |
| "7"               | "8"                  | "SHITOMASI"  | "FREAK"        | "86"                 |
| "8"               | "9"                  | "SHITOMASI"  | "FREAK"        | "85"                 |
| "0"               | "1"                  | "SHITOMASI"  | "SIFT"         | "112"                |
| "1"               | "2"                  | "SHITOMASI"  | "SIFT"         | "109"                |
| "2"               | "3"                  | "SHITOMASI"  | "SIFT"         | "104"                |
| "3"               | "4"                  | "SHITOMASI"  | "SIFT"         | "103"                |
| "4"               | "5"                  | "SHITOMASI"  | "SIFT"         | "99"                 |
| "5"               | "6"                  | "SHITOMASI"  | "SIFT"         | "101"                |
| "6"               | "7"                  | "SHITOMASI"  | "SIFT"         | "96"                 |
| "7"               | "8"                  | "SHITOMASI"  | "SIFT"         | "106"                |
| "8"               | "9"                  | "SHITOMASI"  | "SIFT"         | "97"                 |
| "0"               | "1"                  | "HARRIS"     | "BRISK"        | "12"                 |
| "1"               | "2"                  | "HARRIS"     | "BRISK"        | "10"                 |
| "2"               | "3"                  | "HARRIS"     | "BRISK"        | "14"                 |
| "3"               | "4"                  | "HARRIS"     | "BRISK"        | "15"                 |
| "4"               | "5"                  | "HARRIS"     | "BRISK"        | "16"                 |
| "5"               | "6"                  | "HARRIS"     | "BRISK"        | "16"                 |
| "6"               | "7"                  | "HARRIS"     | "BRISK"        | "15"                 |
| "7"               | "8"                  | "HARRIS"     | "BRISK"        | "23"                 |
| "8"               | "9"                  | "HARRIS"     | "BRISK"        | "21"                 |
| "0"               | "1"                  | "HARRIS"     | "BRIEF"        | "14"                 |
| "1"               | "2"                  | "HARRIS"     | "BRIEF"        | "11"                 |
| "2"               | "3"                  | "HARRIS"     | "BRIEF"        | "15"                 |
| "3"               | "4"                  | "HARRIS"     | "BRIEF"        | "20"                 |
| "4"               | "5"                  | "HARRIS"     | "BRIEF"        | "24"                 |
| "5"               | "6"                  | "HARRIS"     | "BRIEF"        | "26"                 |
| "6"               | "7"                  | "HARRIS"     | "BRIEF"        | "16"                 |
| "7"               | "8"                  | "HARRIS"     | "BRIEF"        | "24"                 |
| "8"               | "9"                  | "HARRIS"     | "BRIEF"        | "23"                 |
| "0"               | "1"                  | "HARRIS"     | "ORB"          | "12"                 |
| "1"               | "2"                  | "HARRIS"     | "ORB"          | "12"                 |
| "2"               | "3"                  | "HARRIS"     | "ORB"          | "15"                 |
| "3"               | "4"                  | "HARRIS"     | "ORB"          | "18"                 |
| "4"               | "5"                  | "HARRIS"     | "ORB"          | "24"                 |
| "5"               | "6"                  | "HARRIS"     | "ORB"          | "20"                 |
| "6"               | "7"                  | "HARRIS"     | "ORB"          | "15"                 |
| "7"               | "8"                  | "HARRIS"     | "ORB"          | "24"                 |
| "8"               | "9"                  | "HARRIS"     | "ORB"          | "22"                 |
| "0"               | "1"                  | "HARRIS"     | "FREAK"        | "13"                 |
| "1"               | "2"                  | "HARRIS"     | "FREAK"        | "13"                 |
| "2"               | "3"                  | "HARRIS"     | "FREAK"        | "15"                 |
| "3"               | "4"                  | "HARRIS"     | "FREAK"        | "15"                 |
| "4"               | "5"                  | "HARRIS"     | "FREAK"        | "17"                 |
| "5"               | "6"                  | "HARRIS"     | "FREAK"        | "20"                 |
| "6"               | "7"                  | "HARRIS"     | "FREAK"        | "12"                 |
| "7"               | "8"                  | "HARRIS"     | "FREAK"        | "21"                 |
| "8"               | "9"                  | "HARRIS"     | "FREAK"        | "18"                 |
| "0"               | "1"                  | "HARRIS"     | "SIFT"         | "14"                 |
| "1"               | "2"                  | "HARRIS"     | "SIFT"         | "11"                 |
| "2"               | "3"                  | "HARRIS"     | "SIFT"         | "16"                 |
| "3"               | "4"                  | "HARRIS"     | "SIFT"         | "19"                 |
| "4"               | "5"                  | "HARRIS"     | "SIFT"         | "22"                 |
| "5"               | "6"                  | "HARRIS"     | "SIFT"         | "22"                 |
| "6"               | "7"                  | "HARRIS"     | "SIFT"         | "13"                 |
| "7"               | "8"                  | "HARRIS"     | "SIFT"         | "24"                 |
| "8"               | "9"                  | "HARRIS"     | "SIFT"         | "22"                 |
| "0"               | "1"                  | "FAST"       | "BRISK"        | "97"                 |
| "1"               | "2"                  | "FAST"       | "BRISK"        | "104"                |
| "2"               | "3"                  | "FAST"       | "BRISK"        | "101"                |
| "3"               | "4"                  | "FAST"       | "BRISK"        | "98"                 |
| "4"               | "5"                  | "FAST"       | "BRISK"        | "85"                 |
| "5"               | "6"                  | "FAST"       | "BRISK"        | "107"                |
| "6"               | "7"                  | "FAST"       | "BRISK"        | "107"                |
| "7"               | "8"                  | "FAST"       | "BRISK"        | "100"                |
| "8"               | "9"                  | "FAST"       | "BRISK"        | "100"                |
| "0"               | "1"                  | "FAST"       | "BRIEF"        | "119"                |
| "1"               | "2"                  | "FAST"       | "BRIEF"        | "130"                |
| "2"               | "3"                  | "FAST"       | "BRIEF"        | "118"                |
| "3"               | "4"                  | "FAST"       | "BRIEF"        | "126"                |
| "4"               | "5"                  | "FAST"       | "BRIEF"        | "108"                |
| "5"               | "6"                  | "FAST"       | "BRIEF"        | "123"                |
| "6"               | "7"                  | "FAST"       | "BRIEF"        | "131"                |
| "7"               | "8"                  | "FAST"       | "BRIEF"        | "125"                |
| "8"               | "9"                  | "FAST"       | "BRIEF"        | "119"                |
| "0"               | "1"                  | "FAST"       | "ORB"          | "118"                |
| "1"               | "2"                  | "FAST"       | "ORB"          | "123"                |
| "2"               | "3"                  | "FAST"       | "ORB"          | "112"                |
| "3"               | "4"                  | "FAST"       | "ORB"          | "126"                |
| "4"               | "5"                  | "FAST"       | "ORB"          | "106"                |
| "5"               | "6"                  | "FAST"       | "ORB"          | "122"                |
| "6"               | "7"                  | "FAST"       | "ORB"          | "122"                |
| "7"               | "8"                  | "FAST"       | "ORB"          | "123"                |
| "8"               | "9"                  | "FAST"       | "ORB"          | "119"                |
| "0"               | "1"                  | "FAST"       | "FREAK"        | "98"                 |
| "1"               | "2"                  | "FAST"       | "FREAK"        | "99"                 |
| "2"               | "3"                  | "FAST"       | "FREAK"        | "91"                 |
| "3"               | "4"                  | "FAST"       | "FREAK"        | "98"                 |
| "4"               | "5"                  | "FAST"       | "FREAK"        | "85"                 |
| "5"               | "6"                  | "FAST"       | "FREAK"        | "99"                 |
| "6"               | "7"                  | "FAST"       | "FREAK"        | "102"                |
| "7"               | "8"                  | "FAST"       | "FREAK"        | "101"                |
| "8"               | "9"                  | "FAST"       | "FREAK"        | "105"                |
| "0"               | "1"                  | "FAST"       | "SIFT"         | "118"                |
| "1"               | "2"                  | "FAST"       | "SIFT"         | "123"                |
| "2"               | "3"                  | "FAST"       | "SIFT"         | "110"                |
| "3"               | "4"                  | "FAST"       | "SIFT"         | "119"                |
| "4"               | "5"                  | "FAST"       | "SIFT"         | "114"                |
| "5"               | "6"                  | "FAST"       | "SIFT"         | "119"                |
| "6"               | "7"                  | "FAST"       | "SIFT"         | "123"                |
| "7"               | "8"                  | "FAST"       | "SIFT"         | "117"                |
| "8"               | "9"                  | "FAST"       | "SIFT"         | "103"                |
| "0"               | "1"                  | "BRISK"      | "BRISK"        | "171"                |
| "1"               | "2"                  | "BRISK"      | "BRISK"        | "176"                |
| "2"               | "3"                  | "BRISK"      | "BRISK"        | "157"                |
| "3"               | "4"                  | "BRISK"      | "BRISK"        | "176"                |
| "4"               | "5"                  | "BRISK"      | "BRISK"        | "174"                |
| "5"               | "6"                  | "BRISK"      | "BRISK"        | "188"                |
| "6"               | "7"                  | "BRISK"      | "BRISK"        | "173"                |
| "7"               | "8"                  | "BRISK"      | "BRISK"        | "171"                |
| "8"               | "9"                  | "BRISK"      | "BRISK"        | "184"                |
| "0"               | "1"                  | "BRISK"      | "BRIEF"        | "178"                |
| "1"               | "2"                  | "BRISK"      | "BRIEF"        | "205"                |
| "2"               | "3"                  | "BRISK"      | "BRIEF"        | "185"                |
| "3"               | "4"                  | "BRISK"      | "BRIEF"        | "179"                |
| "4"               | "5"                  | "BRISK"      | "BRIEF"        | "183"                |
| "5"               | "6"                  | "BRISK"      | "BRIEF"        | "195"                |
| "6"               | "7"                  | "BRISK"      | "BRIEF"        | "207"                |
| "7"               | "8"                  | "BRISK"      | "BRIEF"        | "189"                |
| "8"               | "9"                  | "BRISK"      | "BRIEF"        | "183"                |
| "0"               | "1"                  | "BRISK"      | "ORB"          | "162"                |
| "1"               | "2"                  | "BRISK"      | "ORB"          | "175"                |
| "2"               | "3"                  | "BRISK"      | "ORB"          | "158"                |
| "3"               | "4"                  | "BRISK"      | "ORB"          | "167"                |
| "4"               | "5"                  | "BRISK"      | "ORB"          | "160"                |
| "5"               | "6"                  | "BRISK"      | "ORB"          | "182"                |
| "6"               | "7"                  | "BRISK"      | "ORB"          | "167"                |
| "7"               | "8"                  | "BRISK"      | "ORB"          | "171"                |
| "8"               | "9"                  | "BRISK"      | "ORB"          | "172"                |
| "0"               | "1"                  | "BRISK"      | "FREAK"        | "160"                |
| "1"               | "2"                  | "BRISK"      | "FREAK"        | "177"                |
| "2"               | "3"                  | "BRISK"      | "FREAK"        | "155"                |
| "3"               | "4"                  | "BRISK"      | "FREAK"        | "173"                |
| "4"               | "5"                  | "BRISK"      | "FREAK"        | "161"                |
| "5"               | "6"                  | "BRISK"      | "FREAK"        | "183"                |
| "6"               | "7"                  | "BRISK"      | "FREAK"        | "169"                |
| "7"               | "8"                  | "BRISK"      | "FREAK"        | "178"                |
| "8"               | "9"                  | "BRISK"      | "FREAK"        | "168"                |
| "0"               | "1"                  | "BRISK"      | "SIFT"         | "182"                |
| "1"               | "2"                  | "BRISK"      | "SIFT"         | "193"                |
| "2"               | "3"                  | "BRISK"      | "SIFT"         | "169"                |
| "3"               | "4"                  | "BRISK"      | "SIFT"         | "183"                |
| "4"               | "5"                  | "BRISK"      | "SIFT"         | "171"                |
| "5"               | "6"                  | "BRISK"      | "SIFT"         | "195"                |
| "6"               | "7"                  | "BRISK"      | "SIFT"         | "194"                |
| "7"               | "8"                  | "BRISK"      | "SIFT"         | "176"                |
| "8"               | "9"                  | "BRISK"      | "SIFT"         | "183"                |
| "0"               | "1"                  | "ORB"        | "BRISK"        | "73"                 |
| "1"               | "2"                  | "ORB"        | "BRISK"        | "74"                 |
| "2"               | "3"                  | "ORB"        | "BRISK"        | "79"                 |
| "3"               | "4"                  | "ORB"        | "BRISK"        | "85"                 |
| "4"               | "5"                  | "ORB"        | "BRISK"        | "79"                 |
| "5"               | "6"                  | "ORB"        | "BRISK"        | "92"                 |
| "6"               | "7"                  | "ORB"        | "BRISK"        | "90"                 |
| "7"               | "8"                  | "ORB"        | "BRISK"        | "88"                 |
| "8"               | "9"                  | "ORB"        | "BRISK"        | "91"                 |
| "0"               | "1"                  | "ORB"        | "BRIEF"        | "49"                 |
| "1"               | "2"                  | "ORB"        | "BRIEF"        | "43"                 |
| "2"               | "3"                  | "ORB"        | "BRIEF"        | "45"                 |
| "3"               | "4"                  | "ORB"        | "BRIEF"        | "59"                 |
| "4"               | "5"                  | "ORB"        | "BRIEF"        | "53"                 |
| "5"               | "6"                  | "ORB"        | "BRIEF"        | "78"                 |
| "6"               | "7"                  | "ORB"        | "BRIEF"        | "68"                 |
| "7"               | "8"                  | "ORB"        | "BRIEF"        | "84"                 |
| "8"               | "9"                  | "ORB"        | "BRIEF"        | "66"                 |
| "0"               | "1"                  | "ORB"        | "ORB"          | "67"                 |
| "1"               | "2"                  | "ORB"        | "ORB"          | "70"                 |
| "2"               | "3"                  | "ORB"        | "ORB"          | "72"                 |
| "3"               | "4"                  | "ORB"        | "ORB"          | "84"                 |
| "4"               | "5"                  | "ORB"        | "ORB"          | "91"                 |
| "5"               | "6"                  | "ORB"        | "ORB"          | "101"                |
| "6"               | "7"                  | "ORB"        | "ORB"          | "92"                 |
| "7"               | "8"                  | "ORB"        | "ORB"          | "93"                 |
| "8"               | "9"                  | "ORB"        | "ORB"          | "93"                 |
| "0"               | "1"                  | "ORB"        | "FREAK"        | "42"                 |
| "1"               | "2"                  | "ORB"        | "FREAK"        | "36"                 |
| "2"               | "3"                  | "ORB"        | "FREAK"        | "44"                 |
| "3"               | "4"                  | "ORB"        | "FREAK"        | "47"                 |
| "4"               | "5"                  | "ORB"        | "FREAK"        | "44"                 |
| "5"               | "6"                  | "ORB"        | "FREAK"        | "51"                 |
| "6"               | "7"                  | "ORB"        | "FREAK"        | "52"                 |
| "7"               | "8"                  | "ORB"        | "FREAK"        | "48"                 |
| "8"               | "9"                  | "ORB"        | "FREAK"        | "56"                 |
| "0"               | "1"                  | "ORB"        | "SIFT"         | "67"                 |
| "1"               | "2"                  | "ORB"        | "SIFT"         | "79"                 |
| "2"               | "3"                  | "ORB"        | "SIFT"         | "78"                 |
| "3"               | "4"                  | "ORB"        | "SIFT"         | "79"                 |
| "4"               | "5"                  | "ORB"        | "SIFT"         | "82"                 |
| "5"               | "6"                  | "ORB"        | "SIFT"         | "95"                 |
| "6"               | "7"                  | "ORB"        | "SIFT"         | "95"                 |
| "7"               | "8"                  | "ORB"        | "SIFT"         | "94"                 |
| "8"               | "9"                  | "ORB"        | "SIFT"         | "94"                 |
| "0"               | "1"                  | "AKAZE"      | "BRISK"        | "137"                |
| "1"               | "2"                  | "AKAZE"      | "BRISK"        | "125"                |
| "2"               | "3"                  | "AKAZE"      | "BRISK"        | "129"                |
| "3"               | "4"                  | "AKAZE"      | "BRISK"        | "129"                |
| "4"               | "5"                  | "AKAZE"      | "BRISK"        | "131"                |
| "5"               | "6"                  | "AKAZE"      | "BRISK"        | "132"                |
| "6"               | "7"                  | "AKAZE"      | "BRISK"        | "142"                |
| "7"               | "8"                  | "AKAZE"      | "BRISK"        | "146"                |
| "8"               | "9"                  | "AKAZE"      | "BRISK"        | "144"                |
| "0"               | "1"                  | "AKAZE"      | "BRIEF"        | "141"                |
| "1"               | "2"                  | "AKAZE"      | "BRIEF"        | "134"                |
| "2"               | "3"                  | "AKAZE"      | "BRIEF"        | "131"                |
| "3"               | "4"                  | "AKAZE"      | "BRIEF"        | "130"                |
| "4"               | "5"                  | "AKAZE"      | "BRIEF"        | "134"                |
| "5"               | "6"                  | "AKAZE"      | "BRIEF"        | "146"                |
| "6"               | "7"                  | "AKAZE"      | "BRIEF"        | "150"                |
| "7"               | "8"                  | "AKAZE"      | "BRIEF"        | "148"                |
| "8"               | "9"                  | "AKAZE"      | "BRIEF"        | "152"                |
| "0"               | "1"                  | "AKAZE"      | "ORB"          | "131"                |
| "1"               | "2"                  | "AKAZE"      | "ORB"          | "129"                |
| "2"               | "3"                  | "AKAZE"      | "ORB"          | "127"                |
| "3"               | "4"                  | "AKAZE"      | "ORB"          | "117"                |
| "4"               | "5"                  | "AKAZE"      | "ORB"          | "130"                |
| "5"               | "6"                  | "AKAZE"      | "ORB"          | "131"                |
| "6"               | "7"                  | "AKAZE"      | "ORB"          | "137"                |
| "7"               | "8"                  | "AKAZE"      | "ORB"          | "135"                |
| "8"               | "9"                  | "AKAZE"      | "ORB"          | "145"                |
| "0"               | "1"                  | "AKAZE"      | "FREAK"        | "126"                |
| "1"               | "2"                  | "AKAZE"      | "FREAK"        | "129"                |
| "2"               | "3"                  | "AKAZE"      | "FREAK"        | "127"                |
| "3"               | "4"                  | "AKAZE"      | "FREAK"        | "121"                |
| "4"               | "5"                  | "AKAZE"      | "FREAK"        | "122"                |
| "5"               | "6"                  | "AKAZE"      | "FREAK"        | "133"                |
| "6"               | "7"                  | "AKAZE"      | "FREAK"        | "144"                |
| "7"               | "8"                  | "AKAZE"      | "FREAK"        | "147"                |
| "8"               | "9"                  | "AKAZE"      | "FREAK"        | "138"                |
| "0"               | "1"                  | "AKAZE"      | "AKAZE"        | "138"                |
| "1"               | "2"                  | "AKAZE"      | "AKAZE"        | "138"                |
| "2"               | "3"                  | "AKAZE"      | "AKAZE"        | "133"                |
| "3"               | "4"                  | "AKAZE"      | "AKAZE"        | "127"                |
| "4"               | "5"                  | "AKAZE"      | "AKAZE"        | "129"                |
| "5"               | "6"                  | "AKAZE"      | "AKAZE"        | "146"                |
| "6"               | "7"                  | "AKAZE"      | "AKAZE"        | "147"                |
| "7"               | "8"                  | "AKAZE"      | "AKAZE"        | "151"                |
| "8"               | "9"                  | "AKAZE"      | "AKAZE"        | "150"                |
| "0"               | "1"                  | "AKAZE"      | "SIFT"         | "134"                |
| "1"               | "2"                  | "AKAZE"      | "SIFT"         | "134"                |
| "2"               | "3"                  | "AKAZE"      | "SIFT"         | "130"                |
| "3"               | "4"                  | "AKAZE"      | "SIFT"         | "136"                |
| "4"               | "5"                  | "AKAZE"      | "SIFT"         | "137"                |
| "5"               | "6"                  | "AKAZE"      | "SIFT"         | "147"                |
| "6"               | "7"                  | "AKAZE"      | "SIFT"         | "147"                |
| "7"               | "8"                  | "AKAZE"      | "SIFT"         | "154"                |
| "8"               | "9"                  | "AKAZE"      | "SIFT"         | "151"                |
| "0"               | "1"                  | "SIFT"       | "BRISK"        | "64"                 |
| "1"               | "2"                  | "SIFT"       | "BRISK"        | "66"                 |
| "2"               | "3"                  | "SIFT"       | "BRISK"        | "62"                 |
| "3"               | "4"                  | "SIFT"       | "BRISK"        | "66"                 |
| "4"               | "5"                  | "SIFT"       | "BRISK"        | "59"                 |
| "5"               | "6"                  | "SIFT"       | "BRISK"        | "64"                 |
| "6"               | "7"                  | "SIFT"       | "BRISK"        | "64"                 |
| "7"               | "8"                  | "SIFT"       | "BRISK"        | "67"                 |
| "8"               | "9"                  | "SIFT"       | "BRISK"        | "80"                 |
| "0"               | "1"                  | "SIFT"       | "BRIEF"        | "86"                 |
| "1"               | "2"                  | "SIFT"       | "BRIEF"        | "78"                 |
| "2"               | "3"                  | "SIFT"       | "BRIEF"        | "76"                 |
| "3"               | "4"                  | "SIFT"       | "BRIEF"        | "85"                 |
| "4"               | "5"                  | "SIFT"       | "BRIEF"        | "69"                 |
| "5"               | "6"                  | "SIFT"       | "BRIEF"        | "74"                 |
| "6"               | "7"                  | "SIFT"       | "BRIEF"        | "76"                 |
| "7"               | "8"                  | "SIFT"       | "BRIEF"        | "70"                 |
| "8"               | "9"                  | "SIFT"       | "BRIEF"        | "88"                 |
| "0"               | "1"                  | "SIFT"       | "FREAK"        | "65"                 |
| "1"               | "2"                  | "SIFT"       | "FREAK"        | "72"                 |
| "2"               | "3"                  | "SIFT"       | "FREAK"        | "64"                 |
| "3"               | "4"                  | "SIFT"       | "FREAK"        | "66"                 |
| "4"               | "5"                  | "SIFT"       | "FREAK"        | "59"                 |
| "5"               | "6"                  | "SIFT"       | "FREAK"        | "59"                 |
| "6"               | "7"                  | "SIFT"       | "FREAK"        | "64"                 |
| "7"               | "8"                  | "SIFT"       | "FREAK"        | "65"                 |
| "8"               | "9"                  | "SIFT"       | "FREAK"        | "79"                 |
| "0"               | "1"                  | "SIFT"       | "SIFT"         | "82"                 |
| "1"               | "2"                  | "SIFT"       | "SIFT"         | "81"                 |
| "2"               | "3"                  | "SIFT"       | "SIFT"         | "85"                 |
| "3"               | "4"                  | "SIFT"       | "SIFT"         | "93"                 |
| "4"               | "5"                  | "SIFT"       | "SIFT"         | "90"                 |
| "5"               | "6"                  | "SIFT"       | "SIFT"         | "81"                 |
| "6"               | "7"                  | "SIFT"       | "SIFT"         | "82"                 |
| "7"               | "8"                  | "SIFT"       | "SIFT"         | "102"                |
| "8"               | "9"                  | "SIFT"       | "SIFT"         | "104"                |

