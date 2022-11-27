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
    
**TA** count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, use the BF approach with the descriptor distance ratio set to 0.8.
* Average computation time (detector,descriptor) and average keypoints number under different combinations (Sort in ascending computation time order)

| **Detector+Descriptor** | **MatchedKeyPoints** |
|:-----------------------:|:--------------------:|
| HARRIS_BRISK            | 14.2                 |
| HARRIS_FREAK            | 14.4                 |
| HARRIS_ORB              | 16.2                 |
| HARRIS_SIFT             | 16.3                 |
| HARRIS_BRIEF            | 17.3                 |
| ORB_FREAK               | 42                   |
| ORB_BRIEF               | 54.5                 |
| SIFT_BRISK              | 59.2                 |
| SIFT_FREAK              | 59.3                 |
| SIFT_BRIEF              | 70.2                 |
| ORB_BRISK               | 75.1                 |
| ORB_ORB                 | 76.3                 |
| ORB_SIFT                | 76.3                 |
| SHITOMASI_BRISK         | 76.7                 |
| SHITOMASI_FREAK         | 76.8                 |
| SIFT_SIFT               | 80                   |
| FAST_FREAK              | 87.8                 |
| FAST_BRISK              | 89.9                 |
| SHITOMASI_ORB           | 90.8                 |
| SHITOMASI_SIFT          | 92.7                 |
| SHITOMASI_BRIEF         | 94.4                 |
| FAST_SIFT               | 104.6                |
| FAST_ORB                | 107.1                |
| FAST_BRIEF              | 109.9                |
| AKAZE_ORB               | 118.2                |
| AKAZE_FREAK             | 118.7                |
| AKAZE_BRISK             | 121.5                |
| AKAZE_AKAZE             | 125.9                |
| AKAZE_BRIEF             | 126.6                |
| AKAZE_SIFT              | 127                  |
| BRISK_ORB               | 151.4                |
| BRISK_FREAK             | 152.4                |
| BRISK_BRISK             | 157                  |
| BRISK_SIFT              | 164.6                |
| BRISK_BRIEF             | 170.4                |

## MP.9 - Performance Evaluation 3.
* Average computation time (detector,descriptor) and  average  keypoints number  under different combinations (Sort in ascending  computation time order)

| **Detector+Descriptor** | **ComputationTime** | **KeypointsNumber** |
|:-----------------------:|:-------------------:|:-------------------:|
| FAST_BRIEF              | 2.0997              | 109.9               |
| FAST_ORB                | 2.3652              | 107.1               |
| FAST_BRISK              | 2.7521              | 89.9                |
| ORB_BRIEF               | 9.148               | 54.5                |
| ORB_BRISK               | 12.0285             | 75.1                |
| ORB_ORB                 | 19.0127             | 76.3                |
| SHITOMASI_BRIEF         | 19.1266             | 94.4                |
| HARRIS_BRIEF            | 19.9661             | 17.3                |
| HARRIS_ORB              | 20.8743             | 16.2                |
| SHITOMASI_ORB           | 21.6959             | 90.8                |
| HARRIS_BRISK            | 24.0256             | 14.2                |
| SHITOMASI_BRISK         | 26.9768             | 76.7                |
| FAST_SIFT               | 35.7522             | 104.6               |
| BRISK_BRIEF             | 36.8287             | 170.4               |
| SHITOMASI_SIFT          | 37.6537             | 92.7                |
| BRISK_BRISK             | 40.0579             | 157                 |
| BRISK_ORB               | 41.5307             | 151.4               |
| HARRIS_SIFT             | 43.522              | 16.3                |
| FAST_FREAK              | 57.908              | 87.8                |
| SHITOMASI_FREAK         | 62.5829             | 76.8                |
| HARRIS_FREAK            | 71.4491             | 14.4                |
| ORB_FREAK               | 73.2577             | 42                  |
| BRISK_FREAK             | 85.2084             | 152.4               |
| ORB_SIFT                | 103.2322            | 76.3                |
| BRISK_SIFT              | 104.6372            | 164.6               |
| AKAZE_BRIEF             | 120.0492            | 126.6               |
| AKAZE_BRISK             | 125.1874            | 121.5               |
| AKAZE_ORB               | 133.2668            | 118.2               |
| AKAZE_SIFT              | 137.2498            | 127                 |
| SIFT_BRISK              | 145.8045            | 59.2                |
| SIFT_BRIEF              | 146.445             | 70.2                |
| SIFT_FREAK              | 191.0153            | 59.3                |
| AKAZE_FREAK             | 204.0801            | 118.7               |
| SIFT_SIFT               | 213.153             | 80                  |
| AKAZE_AKAZE             | 249.5201            | 125.9               |
