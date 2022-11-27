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

| **Detector** | **Descriptor** | **MatchingSize** |
|:------------:|:--------------:|:----------------:|
| 'SHITOMASI'  | 'BRISK'        | 95               |
| 'SHITOMASI'  | 'BRISK'        | 88               |
| 'SHITOMASI'  | 'BRISK'        | 80               |
| 'SHITOMASI'  | 'BRISK'        | 90               |
| 'SHITOMASI'  | 'BRISK'        | 82               |
| 'SHITOMASI'  | 'BRISK'        | 79               |
| 'SHITOMASI'  | 'BRISK'        | 85               |
| 'SHITOMASI'  | 'BRISK'        | 86               |
| 'SHITOMASI'  | 'BRISK'        | 82               |
| 'SHITOMASI'  | 'BRIEF'        | 115              |
| 'SHITOMASI'  | 'BRIEF'        | 111              |
| 'SHITOMASI'  | 'BRIEF'        | 104              |
| 'SHITOMASI'  | 'BRIEF'        | 101              |
| 'SHITOMASI'  | 'BRIEF'        | 102              |
| 'SHITOMASI'  | 'BRIEF'        | 102              |
| 'SHITOMASI'  | 'BRIEF'        | 100              |
| 'SHITOMASI'  | 'BRIEF'        | 109              |
| 'SHITOMASI'  | 'BRIEF'        | 100              |
| 'SHITOMASI'  | 'ORB'          | 106              |
| 'SHITOMASI'  | 'ORB'          | 102              |
| 'SHITOMASI'  | 'ORB'          | 99               |
| 'SHITOMASI'  | 'ORB'          | 102              |
| 'SHITOMASI'  | 'ORB'          | 103              |
| 'SHITOMASI'  | 'ORB'          | 97               |
| 'SHITOMASI'  | 'ORB'          | 98               |
| 'SHITOMASI'  | 'ORB'          | 104              |
| 'SHITOMASI'  | 'ORB'          | 97               |
| 'SHITOMASI'  | 'FREAK'        | 86               |
| 'SHITOMASI'  | 'FREAK'        | 90               |
| 'SHITOMASI'  | 'FREAK'        | 86               |
| 'SHITOMASI'  | 'FREAK'        | 88               |
| 'SHITOMASI'  | 'FREAK'        | 86               |
| 'SHITOMASI'  | 'FREAK'        | 80               |
| 'SHITOMASI'  | 'FREAK'        | 81               |
| 'SHITOMASI'  | 'FREAK'        | 86               |
| 'SHITOMASI'  | 'FREAK'        | 85               |
| 'SHITOMASI'  | 'SIFT'         | 112              |
| 'SHITOMASI'  | 'SIFT'         | 109              |
| 'SHITOMASI'  | 'SIFT'         | 104              |
| 'SHITOMASI'  | 'SIFT'         | 103              |
| 'SHITOMASI'  | 'SIFT'         | 99               |
| 'SHITOMASI'  | 'SIFT'         | 101              |
| 'SHITOMASI'  | 'SIFT'         | 96               |
| 'SHITOMASI'  | 'SIFT'         | 106              |
| 'SHITOMASI'  | 'SIFT'         | 97               |
| 'HARRIS'     | 'BRISK'        | 12               |
| 'HARRIS'     | 'BRISK'        | 10               |
| 'HARRIS'     | 'BRISK'        | 14               |
| 'HARRIS'     | 'BRISK'        | 15               |
| 'HARRIS'     | 'BRISK'        | 16               |
| 'HARRIS'     | 'BRISK'        | 16               |
| 'HARRIS'     | 'BRISK'        | 15               |
| 'HARRIS'     | 'BRISK'        | 23               |
| 'HARRIS'     | 'BRISK'        | 21               |
| 'HARRIS'     | 'BRIEF'        | 14               |
| 'HARRIS'     | 'BRIEF'        | 11               |
| 'HARRIS'     | 'BRIEF'        | 15               |
| 'HARRIS'     | 'BRIEF'        | 20               |
| 'HARRIS'     | 'BRIEF'        | 24               |
| 'HARRIS'     | 'BRIEF'        | 26               |
| 'HARRIS'     | 'BRIEF'        | 16               |
| 'HARRIS'     | 'BRIEF'        | 24               |
| 'HARRIS'     | 'BRIEF'        | 23               |
| 'HARRIS'     | 'ORB'          | 12               |
| 'HARRIS'     | 'ORB'          | 12               |
| 'HARRIS'     | 'ORB'          | 15               |
| 'HARRIS'     | 'ORB'          | 18               |
| 'HARRIS'     | 'ORB'          | 24               |
| 'HARRIS'     | 'ORB'          | 20               |
| 'HARRIS'     | 'ORB'          | 15               |
| 'HARRIS'     | 'ORB'          | 24               |
| 'HARRIS'     | 'ORB'          | 22               |
| 'HARRIS'     | 'FREAK'        | 13               |
| 'HARRIS'     | 'FREAK'        | 13               |
| 'HARRIS'     | 'FREAK'        | 15               |
| 'HARRIS'     | 'FREAK'        | 15               |
| 'HARRIS'     | 'FREAK'        | 17               |
| 'HARRIS'     | 'FREAK'        | 20               |
| 'HARRIS'     | 'FREAK'        | 12               |
| 'HARRIS'     | 'FREAK'        | 21               |
| 'HARRIS'     | 'FREAK'        | 18               |
| 'HARRIS'     | 'SIFT'         | 14               |
| 'HARRIS'     | 'SIFT'         | 11               |
| 'HARRIS'     | 'SIFT'         | 16               |
| 'HARRIS'     | 'SIFT'         | 19               |
| 'HARRIS'     | 'SIFT'         | 22               |
| 'HARRIS'     | 'SIFT'         | 22               |
| 'HARRIS'     | 'SIFT'         | 13               |
| 'HARRIS'     | 'SIFT'         | 24               |
| 'HARRIS'     | 'SIFT'         | 22               |
| 'FAST'       | 'BRISK'        | 97               |
| 'FAST'       | 'BRISK'        | 104              |
| 'FAST'       | 'BRISK'        | 101              |
| 'FAST'       | 'BRISK'        | 98               |
| 'FAST'       | 'BRISK'        | 85               |
| 'FAST'       | 'BRISK'        | 107              |
| 'FAST'       | 'BRISK'        | 107              |
| 'FAST'       | 'BRISK'        | 100              |
| 'FAST'       | 'BRISK'        | 100              |
| 'FAST'       | 'BRIEF'        | 119              |
| 'FAST'       | 'BRIEF'        | 130              |
| 'FAST'       | 'BRIEF'        | 118              |
| 'FAST'       | 'BRIEF'        | 126              |
| 'FAST'       | 'BRIEF'        | 108              |
| 'FAST'       | 'BRIEF'        | 123              |
| 'FAST'       | 'BRIEF'        | 131              |
| 'FAST'       | 'BRIEF'        | 125              |
| 'FAST'       | 'BRIEF'        | 119              |
| 'FAST'       | 'ORB'          | 118              |
| 'FAST'       | 'ORB'          | 123              |
| 'FAST'       | 'ORB'          | 112              |
| 'FAST'       | 'ORB'          | 126              |
| 'FAST'       | 'ORB'          | 106              |
| 'FAST'       | 'ORB'          | 122              |
| 'FAST'       | 'ORB'          | 122              |
| 'FAST'       | 'ORB'          | 123              |
| 'FAST'       | 'ORB'          | 119              |
| 'FAST'       | 'FREAK'        | 98               |
| 'FAST'       | 'FREAK'        | 99               |
| 'FAST'       | 'FREAK'        | 91               |
| 'FAST'       | 'FREAK'        | 98               |
| 'FAST'       | 'FREAK'        | 85               |
| 'FAST'       | 'FREAK'        | 99               |
| 'FAST'       | 'FREAK'        | 102              |
| 'FAST'       | 'FREAK'        | 101              |
| 'FAST'       | 'FREAK'        | 105              |
| 'FAST'       | 'SIFT'         | 118              |
| 'FAST'       | 'SIFT'         | 123              |
| 'FAST'       | 'SIFT'         | 110              |
| 'FAST'       | 'SIFT'         | 119              |
| 'FAST'       | 'SIFT'         | 114              |
| 'FAST'       | 'SIFT'         | 119              |
| 'FAST'       | 'SIFT'         | 123              |
| 'FAST'       | 'SIFT'         | 117              |
| 'FAST'       | 'SIFT'         | 103              |
| 'BRISK'      | 'BRISK'        | 171              |
| 'BRISK'      | 'BRISK'        | 176              |
| 'BRISK'      | 'BRISK'        | 157              |
| 'BRISK'      | 'BRISK'        | 176              |
| 'BRISK'      | 'BRISK'        | 174              |
| 'BRISK'      | 'BRISK'        | 188              |
| 'BRISK'      | 'BRISK'        | 173              |
| 'BRISK'      | 'BRISK'        | 171              |
| 'BRISK'      | 'BRISK'        | 184              |
| 'BRISK'      | 'BRIEF'        | 178              |
| 'BRISK'      | 'BRIEF'        | 205              |
| 'BRISK'      | 'BRIEF'        | 185              |
| 'BRISK'      | 'BRIEF'        | 179              |
| 'BRISK'      | 'BRIEF'        | 183              |
| 'BRISK'      | 'BRIEF'        | 195              |
| 'BRISK'      | 'BRIEF'        | 207              |
| 'BRISK'      | 'BRIEF'        | 189              |
| 'BRISK'      | 'BRIEF'        | 183              |
| 'BRISK'      | 'ORB'          | 162              |
| 'BRISK'      | 'ORB'          | 175              |
| 'BRISK'      | 'ORB'          | 158              |
| 'BRISK'      | 'ORB'          | 167              |
| 'BRISK'      | 'ORB'          | 160              |
| 'BRISK'      | 'ORB'          | 182              |
| 'BRISK'      | 'ORB'          | 167              |
| 'BRISK'      | 'ORB'          | 171              |
| 'BRISK'      | 'ORB'          | 172              |
| 'BRISK'      | 'FREAK'        | 160              |
| 'BRISK'      | 'FREAK'        | 177              |
| 'BRISK'      | 'FREAK'        | 155              |
| 'BRISK'      | 'FREAK'        | 173              |
| 'BRISK'      | 'FREAK'        | 161              |
| 'BRISK'      | 'FREAK'        | 183              |
| 'BRISK'      | 'FREAK'        | 169              |
| 'BRISK'      | 'FREAK'        | 178              |
| 'BRISK'      | 'FREAK'        | 168              |
| 'BRISK'      | 'SIFT'         | 182              |
| 'BRISK'      | 'SIFT'         | 193              |
| 'BRISK'      | 'SIFT'         | 169              |
| 'BRISK'      | 'SIFT'         | 183              |
| 'BRISK'      | 'SIFT'         | 171              |
| 'BRISK'      | 'SIFT'         | 195              |
| 'BRISK'      | 'SIFT'         | 194              |
| 'BRISK'      | 'SIFT'         | 176              |
| 'BRISK'      | 'SIFT'         | 183              |
| 'ORB'        | 'BRISK'        | 73               |
| 'ORB'        | 'BRISK'        | 74               |
| 'ORB'        | 'BRISK'        | 79               |
| 'ORB'        | 'BRISK'        | 85               |
| 'ORB'        | 'BRISK'        | 79               |
| 'ORB'        | 'BRISK'        | 92               |
| 'ORB'        | 'BRISK'        | 90               |
| 'ORB'        | 'BRISK'        | 88               |
| 'ORB'        | 'BRISK'        | 91               |
| 'ORB'        | 'BRIEF'        | 49               |
| 'ORB'        | 'BRIEF'        | 43               |
| 'ORB'        | 'BRIEF'        | 45               |
| 'ORB'        | 'BRIEF'        | 59               |
| 'ORB'        | 'BRIEF'        | 53               |
| 'ORB'        | 'BRIEF'        | 78               |
| 'ORB'        | 'BRIEF'        | 68               |
| 'ORB'        | 'BRIEF'        | 84               |
| 'ORB'        | 'BRIEF'        | 66               |
| 'ORB'        | 'ORB'          | 67               |
| 'ORB'        | 'ORB'          | 70               |
| 'ORB'        | 'ORB'          | 72               |
| 'ORB'        | 'ORB'          | 84               |
| 'ORB'        | 'ORB'          | 91               |
| 'ORB'        | 'ORB'          | 101              |
| 'ORB'        | 'ORB'          | 92               |
| 'ORB'        | 'ORB'          | 93               |
| 'ORB'        | 'ORB'          | 93               |
| 'ORB'        | 'FREAK'        | 42               |
| 'ORB'        | 'FREAK'        | 36               |
| 'ORB'        | 'FREAK'        | 44               |
| 'ORB'        | 'FREAK'        | 47               |
| 'ORB'        | 'FREAK'        | 44               |
| 'ORB'        | 'FREAK'        | 51               |
| 'ORB'        | 'FREAK'        | 52               |
| 'ORB'        | 'FREAK'        | 48               |
| 'ORB'        | 'FREAK'        | 56               |
| 'ORB'        | 'SIFT'         | 67               |
| 'ORB'        | 'SIFT'         | 79               |
| 'ORB'        | 'SIFT'         | 78               |
| 'ORB'        | 'SIFT'         | 79               |
| 'ORB'        | 'SIFT'         | 82               |
| 'ORB'        | 'SIFT'         | 95               |
| 'ORB'        | 'SIFT'         | 95               |
| 'ORB'        | 'SIFT'         | 94               |
| 'ORB'        | 'SIFT'         | 94               |
| 'AKAZE'      | 'BRISK'        | 137              |
| 'AKAZE'      | 'BRISK'        | 125              |
| 'AKAZE'      | 'BRISK'        | 129              |
| 'AKAZE'      | 'BRISK'        | 129              |
| 'AKAZE'      | 'BRISK'        | 131              |
| 'AKAZE'      | 'BRISK'        | 132              |
| 'AKAZE'      | 'BRISK'        | 142              |
| 'AKAZE'      | 'BRISK'        | 146              |
| 'AKAZE'      | 'BRISK'        | 144              |
| 'AKAZE'      | 'BRIEF'        | 141              |
| 'AKAZE'      | 'BRIEF'        | 134              |
| 'AKAZE'      | 'BRIEF'        | 131              |
| 'AKAZE'      | 'BRIEF'        | 130              |
| 'AKAZE'      | 'BRIEF'        | 134              |
| 'AKAZE'      | 'BRIEF'        | 146              |
| 'AKAZE'      | 'BRIEF'        | 150              |
| 'AKAZE'      | 'BRIEF'        | 148              |
| 'AKAZE'      | 'BRIEF'        | 152              |
| 'AKAZE'      | 'ORB'          | 131              |
| 'AKAZE'      | 'ORB'          | 129              |
| 'AKAZE'      | 'ORB'          | 127              |
| 'AKAZE'      | 'ORB'          | 117              |
| 'AKAZE'      | 'ORB'          | 130              |
| 'AKAZE'      | 'ORB'          | 131              |
| 'AKAZE'      | 'ORB'          | 137              |
| 'AKAZE'      | 'ORB'          | 135              |
| 'AKAZE'      | 'ORB'          | 145              |
| 'AKAZE'      | 'FREAK'        | 126              |
| 'AKAZE'      | 'FREAK'        | 129              |
| 'AKAZE'      | 'FREAK'        | 127              |
| 'AKAZE'      | 'FREAK'        | 121              |
| 'AKAZE'      | 'FREAK'        | 122              |
| 'AKAZE'      | 'FREAK'        | 133              |
| 'AKAZE'      | 'FREAK'        | 144              |
| 'AKAZE'      | 'FREAK'        | 147              |
| 'AKAZE'      | 'FREAK'        | 138              |
| 'AKAZE'      | 'AKAZE'        | 138              |
| 'AKAZE'      | 'AKAZE'        | 138              |
| 'AKAZE'      | 'AKAZE'        | 133              |
| 'AKAZE'      | 'AKAZE'        | 127              |
| 'AKAZE'      | 'AKAZE'        | 129              |
| 'AKAZE'      | 'AKAZE'        | 146              |
| 'AKAZE'      | 'AKAZE'        | 147              |
| 'AKAZE'      | 'AKAZE'        | 151              |
| 'AKAZE'      | 'AKAZE'        | 150              |
| 'AKAZE'      | 'SIFT'         | 134              |
| 'AKAZE'      | 'SIFT'         | 134              |
| 'AKAZE'      | 'SIFT'         | 130              |
| 'AKAZE'      | 'SIFT'         | 136              |
| 'AKAZE'      | 'SIFT'         | 137              |
| 'AKAZE'      | 'SIFT'         | 147              |
| 'AKAZE'      | 'SIFT'         | 147              |
| 'AKAZE'      | 'SIFT'         | 154              |
| 'AKAZE'      | 'SIFT'         | 151              |
| 'SIFT'       | 'BRISK'        | 64               |
| 'SIFT'       | 'BRISK'        | 66               |
| 'SIFT'       | 'BRISK'        | 62               |
| 'SIFT'       | 'BRISK'        | 66               |
| 'SIFT'       | 'BRISK'        | 59               |
| 'SIFT'       | 'BRISK'        | 64               |
| 'SIFT'       | 'BRISK'        | 64               |
| 'SIFT'       | 'BRISK'        | 67               |
| 'SIFT'       | 'BRISK'        | 80               |
| 'SIFT'       | 'BRIEF'        | 86               |
| 'SIFT'       | 'BRIEF'        | 78               |
| 'SIFT'       | 'BRIEF'        | 76               |
| 'SIFT'       | 'BRIEF'        | 85               |
| 'SIFT'       | 'BRIEF'        | 69               |
| 'SIFT'       | 'BRIEF'        | 74               |
| 'SIFT'       | 'BRIEF'        | 76               |
| 'SIFT'       | 'BRIEF'        | 70               |
| 'SIFT'       | 'BRIEF'        | 88               |
| 'SIFT'       | 'FREAK'        | 65               |
| 'SIFT'       | 'FREAK'        | 72               |
| 'SIFT'       | 'FREAK'        | 64               |
| 'SIFT'       | 'FREAK'        | 66               |
| 'SIFT'       | 'FREAK'        | 59               |
| 'SIFT'       | 'FREAK'        | 59               |
| 'SIFT'       | 'FREAK'        | 64               |
| 'SIFT'       | 'FREAK'        | 65               |
| 'SIFT'       | 'FREAK'        | 79               |
| 'SIFT'       | 'SIFT'         | 82               |
| 'SIFT'       | 'SIFT'         | 81               |
| 'SIFT'       | 'SIFT'         | 85               |
| 'SIFT'       | 'SIFT'         | 93               |
| 'SIFT'       | 'SIFT'         | 90               |
| 'SIFT'       | 'SIFT'         | 81               |
| 'SIFT'       | 'SIFT'         | 82               |
| 'SIFT'       | 'SIFT'         | 102              |
| 'SIFT'       | 'SIFT'         | 104              |
