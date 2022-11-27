/* INCLUDES FOR THIS PROJECT */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include "dataStructures.h"
#include "matching2D.hpp"

//#include <io.h>
#include<sys/stat.h>
#include "unistd.h"

using namespace std;

/* MAIN PROGRAM */
int main(int argc, const char *argv[])
{

    /* INIT VARIABLES AND DATA STRUCTURES */

    // data location
    string dataPath = "../";

    // camera
    string imgBasePath = dataPath + "images/";
    string imgPrefix = "KITTI/2011_09_26/image_00/data/000000"; // left camera, color
    string imgFileType = ".png";
    int imgStartIndex = 0; // first file index to load (assumes Lidar and camera names have identical naming convention)
    int imgEndIndex = 9;   // last file index to load
    int imgFillWidth = 4;  // no. of digits which make up the file index (e.g. img-0001.png)

    // misc
    int dataBufferSize = 2;       // no. of images which are held in memory (ring buffer) at the same time
    vector<DataFrame> dataBuffer; // list of data frames which are held in memory at the same time
    bool bVis = false;            // visualize results

    bool mp2 = false;
    bool mp3 = false;
    bool mp4 = false;
    bool mp5 = false;
    bool mp6 = false;
    bool mp7 = true;
    //loop all detectors
    vector<std::string> det_desc_matc_sel_string;
    vector<vector<std::string>> det_desc_matc_sel_strings;
    vector<std::string> detStrings={"SHITOMASI","HARRIS", "FAST", "BRISK", "ORB", "AKAZE", "SIFT"};
    vector<std::string> decsStrings={"BRISK","BRIEF", "ORB", "FREAK", "AKAZE", "SIFT"};
    vector<std::string> matcherStrings={"MAT_BF", "MAT_FLANN"};
    vector<std::string> selectorStrings={"SEL_NN", "SEL_KNN"};
    if(mp2)
    {
        for(int i=0;i<detStrings.size();i++)
        {
         
            det_desc_matc_sel_string={detStrings[i],"BRISK","MAT_BF","SEL_NN"};
            det_desc_matc_sel_strings.push_back(det_desc_matc_sel_string);
        }
         for(int i=0;i<det_desc_matc_sel_strings.size();i++)
        {
            string dir_name="../MP2_KeypointDetection_images/"+det_desc_matc_sel_strings[i][0];
                
            if (access(dir_name.c_str(), 0) == -1)	
            {	
                if(int re = mkdir(dir_name.c_str(), 0777)==0)
                {   	
                    cout<<"folder "<<dir_name<<" created!"<<endl;
                }
                else
                {
                    cout<<"mkdir folder "<<dir_name<<" failed!";
                }
            } 
        } 
    }
    if(mp3)
    {
        for(int i=0;i<detStrings.size();i++)
        {
            
            det_desc_matc_sel_string={detStrings[i],"BRISK","MAT_BF","SEL_NN"};
            det_desc_matc_sel_strings.push_back(det_desc_matc_sel_string);
        }
        for(int i=0;i<det_desc_matc_sel_strings.size();i++)
        {
            string dir_name="../MP3_KeypointRemoval_images/"+det_desc_matc_sel_strings[i][0];
                
            if (access(dir_name.c_str(), 0) == -1)	
            {	
                if(int re = mkdir(dir_name.c_str(), 0777)==0)
                {   	
                    cout<<"folder "<<dir_name<<" created!"<<endl;
                }
                else
                {
                    cout<<"mkdir folder "<<dir_name<<" failed!";
                }
            } 
        } 
    }
    if(mp4)
    {
        for(int i=0;i<detStrings.size();i++)
        {
            for(int j=0;j<decsStrings.size();j++)
            {
                
                if(detStrings[i]=="AKAZE" || decsStrings[j]!="AKAZE" && !(detStrings[i]=="SIFT" && decsStrings[j]=="ORB"))
                {
                    det_desc_matc_sel_string={detStrings[i],decsStrings[j],"MAT_BF","SEL_NN"};
                    det_desc_matc_sel_strings.push_back(det_desc_matc_sel_string);
                    cout<<detStrings[i]<<" "<<decsStrings[j]<<endl;
                }
            }
        }
        for(int i=0;i<det_desc_matc_sel_strings.size();i++)
        {
            string dir_name="../MP4_KeypointDescriptors_images/det_"+det_desc_matc_sel_strings[i][0];
                
            if (access(dir_name.c_str(), 0) == -1)	
            {	
                if(int re = mkdir(dir_name.c_str(), 0777)==0)
                {   	
                    cout<<"folder "<<dir_name<<" created!"<<endl;
                }
                else
                {
                    cout<<"mkdir folder "<<dir_name<<" failed!";
                }
                dir_name=dir_name+"/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1];
                if (access(dir_name.c_str(), 0) == -1)	
                {	
                    if(int re = mkdir(dir_name.c_str(), 0777)==0)
                    {   	
                        cout<<"folder "<<dir_name<<" created!"<<endl;
                    }
                    else
                    {
                        cout<<"mkdir folder "<<dir_name<<" failed!";
                    }
                } 
            } 
            else
            {   dir_name=dir_name+"/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1];
                if (access(dir_name.c_str(), 0) == -1)	
                {	
                    if(int re = mkdir(dir_name.c_str(), 0777)==0)
                    {   	
                        cout<<"folder "<<dir_name<<" created!"<<endl;
                    }
                    else
                    {
                        cout<<"mkdir folder "<<dir_name<<" failed!";
                    }
                } 
            }
            
        }  

    }
    if(mp5)
    {
        for(int i=0;i<detStrings.size();i++)
        {
            std::string dir_name="../MP5_DescriptorMatching_images/det_"+detStrings[i];
            int re = mkdir(dir_name.c_str(), 0777);
            for(int j=0;j<decsStrings.size();j++)
            {
                
                if(detStrings[i]=="AKAZE" || decsStrings[j]!="AKAZE" && !(detStrings[i]=="SIFT" && decsStrings[j]=="ORB"))
                {
                    std::string dir_name1=dir_name+"/det_"+detStrings[i]+"_decs_"+decsStrings[j];
                    re = mkdir(dir_name1.c_str(), 0777);
                    for(int m=0;m<matcherStrings.size();m++)
                    {
                        std::string dir_name2=dir_name1+"/det_"+detStrings[i]+"_decs_"+decsStrings[j]+"_"+matcherStrings[m];
                        re = mkdir(dir_name2.c_str(), 0777);
                        det_desc_matc_sel_string={detStrings[i],decsStrings[j],"MAT_FLANN","SEL_KNN"};
                        det_desc_matc_sel_strings.push_back(det_desc_matc_sel_string);
                    }
                    
                }
            }
        }
        
    }

    if(mp6)
    {
        for(int i=0;i<detStrings.size();i++)
        {
            std::string dir_name="../MP6_DescriptorDistanceRatio_images/det_"+detStrings[i];
            int re = mkdir(dir_name.c_str(), 0777);
            for(int j=0;j<decsStrings.size();j++)
            {
                
                if(detStrings[i]=="AKAZE" || decsStrings[j]!="AKAZE" && !(detStrings[i]=="SIFT" && decsStrings[j]=="ORB"))
                {
                    std::string dir_name1=dir_name+"/det_"+detStrings[i]+"_decs_"+decsStrings[j];
                    re = mkdir(dir_name1.c_str(), 0777);
                    for(int m=0;m<matcherStrings.size();m++)
                    {
                        std::string dir_name2=dir_name1+"/det_"+detStrings[i]+"_decs_"+decsStrings[j]+"_"+matcherStrings[m];
                        re = mkdir(dir_name2.c_str(), 0777);
                        for(int n=0;n<selectorStrings.size();n++)
                        {
                            std::string dir_name3=dir_name2+"/det_"+detStrings[i]+"_decs_"+decsStrings[j]+"_"+matcherStrings[m]+"_"+selectorStrings[n];
                           re = mkdir(dir_name3.c_str(), 0777);
                            det_desc_matc_sel_string={detStrings[i],decsStrings[j],matcherStrings[m],selectorStrings[n]};
                            det_desc_matc_sel_strings.push_back(det_desc_matc_sel_string);
                        }  
                    }
                    
                }
            }
        }
    }
    
    if(mp7)
    {
        for(int i=0;i<detStrings.size();i++)
        {
         
            det_desc_matc_sel_string={detStrings[i],"BRISK","MAT_BF","SEL_NN"};
            det_desc_matc_sel_strings.push_back(det_desc_matc_sel_string);
        }
        std::string rmseFile = "../MP7_PerformanceEvaluation1/mp7_1.txt";
        if (access(rmseFile.c_str(), 0) == 0) 
        {
            remove(rmseFile.c_str());
        }
        rmseFile = "../MP7_PerformanceEvaluation1/mp7_2.txt";
        if (access(rmseFile.c_str(), 0) == 0) 
        {
            remove(rmseFile.c_str());
        }


    }
    /* MAIN LOOP OVER ALL IMAGES */
    for(int i=0;i<det_desc_matc_sel_strings.size();i++)
    {
            dataBuffer.clear();
            for (size_t imgIndex = 0; imgIndex <= imgEndIndex - imgStartIndex; imgIndex++)
            {
                /* LOAD IMAGE INTO BUFFER */

                // assemble filenames for current index
                ostringstream imgNumber;
                imgNumber << setfill('0') << setw(imgFillWidth) << imgStartIndex + imgIndex;
                string imgFullFilename = imgBasePath + imgPrefix + imgNumber.str() + imgFileType;

                // load image from file and convert to grayscale
                cv::Mat img, imgGray;
                img = cv::imread(imgFullFilename);
                cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

                //// STUDENT ASSIGNMENT
                //// TASK MP.1 -> replace the following code with ring buffer of size dataBufferSize

                // push image into data frame buffer
                DataFrame frame;
                frame.cameraImg = imgGray;
                if(dataBuffer.size()<dataBufferSize)
                {   
                    dataBuffer.push_back(frame);
                }
                else
                {
                    dataBuffer[0]=dataBuffer[1];
                    dataBuffer[1]=frame;
                }
                
                //// EOF STUDENT ASSIGNMENT
                cout << "#1 : LOAD IMAGE INTO BUFFER done" <<imgIndex<< endl;

                /* DETECT IMAGE KEYPOINTS */

                // extract 2D keypoints from current image
                vector<cv::KeyPoint> keypoints; // create empty feature list for current image
                //string detectorType = "SHITOMASI";

                //// STUDENT ASSIGNMENT
                //// TASK MP.2 -> add the following keypoint detectors in file matching2D.cpp and enable string-based selection based on detectorType
                //// -> HARRIS, FAST, BRISK, ORB, AKAZE, SIFT
                //break;
                

                string detectorType = det_desc_matc_sel_strings[i][0];
                if (detectorType.compare("SHITOMASI") == 0)
                {
                    detKeypointsShiTomasi(keypoints, imgGray,imgNumber.str(), false,mp2,mp7);
                }
                else
                {
                    if (detectorType.compare("HARRIS") == 0)
                    {
                        detKeypointsHarris(keypoints, imgGray,imgNumber.str(), false,mp2,mp7);
                    }
                    else
                    {

                        detKeypointsModern(keypoints, imgGray, detectorType,imgNumber.str(),false,mp2,mp7);
                    }
                    
                }
                
                
            
                            
                //// EOF STUDENT ASSIGNMENT

                //// STUDENT ASSIGNMENT
                //// TASK MP.3 -> only keep keypoints on the preceding vehicle

                // only keep keypoints on the preceding vehicle
                bool bFocusOnVehicle = true;
                cv::Rect vehicleRect(535, 180, 180, 150);
                vector<cv::KeyPoint> keypoints_temp;
                if (bFocusOnVehicle)
                {
                    for (auto it = keypoints.begin(); it != keypoints.end(); ++it)
                    {
                        //if(it->pt.x>vehicleRect.tl().x && it->pt.x<vehicleRect.br().x && it->pt.y>vehicleRect.tl().y && it->pt.y<vehicleRect.br().y)
                        if(vehicleRect.contains(it->pt))
                        {
                            keypoints_temp.push_back(*it);
                        }
                    }   
                    
                    //std::cout<<keypoints.size()<<std::endl;
                }
               
                
                if(mp7)
                {
                    string dir_name1="../MP7_PerformanceEvaluation1/mp7_2.txt";
                    ofstream out1;
                    out1.open(dir_name1,std::ios_base::app);
                    double kpsize;
                    for (auto kp : keypoints_temp) {
                        kpsize=kp.size;
                        std::stringstream ss;
                        ss << std::setiosflags(std::ios::fixed) << std::setprecision(3) <<  kpsize ;
                        std::string str = ss.str();
                        
                        out1 <<detectorType<<" "<<str<<"\n";
                    }
                    out1.close(); 

                    string dir_name="../MP7_PerformanceEvaluation1/mp7_1.txt";
                    ofstream out;
                    out.open(dir_name,std::ios_base::app);
                    out << " "<<to_string(keypoints_temp.size())<<" "<<"\n";
                    //out << "This is another line.\n";
                    out.close();   
                }
                if(mp3)
                {
                    string dir_name="../MP3_KeypointRemoval_images/"+detectorType;
                    cv::Mat visImage = img.clone();
                    cv::drawKeypoints(img, keypoints_temp, visImage, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
                    cv::imwrite(dir_name+"/"+detectorType+"_"+imgNumber.str()+ "_ntotal="+to_string(keypoints.size())+"_nremoved="+to_string(keypoints.size()-keypoints_temp.size())+".png",visImage);
                }

                keypoints=keypoints_temp;
                //// EOF STUDENT ASSIGNMENT

                // optional : limit number of keypoints (helpful for debugging and learning)
                bool bLimitKpts = false;
                if (bLimitKpts)
                {
                    int maxKeypoints = 50;

                    if (detectorType.compare("SHITOMASI") == 0)
                    { // there is no response info, so keep the first 50 as they are sorted in descending quality order
                        keypoints.erase(keypoints.begin() + maxKeypoints, keypoints.end());
                    }
                    cv::KeyPointsFilter::retainBest(keypoints, maxKeypoints);
                    cout << " NOTE: Keypoints have been limited!" << endl;
                }

                // push keypoints and descriptor for current frame to end of data buffer
                (dataBuffer.end() - 1)->keypoints = keypoints;
                cout << "#2 : DETECT KEYPOINTS done" << endl;

                /* EXTRACT KEYPOINT DESCRIPTORS */

                //// STUDENT ASSIGNMENT
                //// TASK MP.4 -> add the following descriptors in file matching2D.cpp and enable string-based selection based on descriptorType
                //// -> BRIEF, ORB, FREAK, AKAZE, SIFT

                cv::Mat descriptors;
                //string descriptorType = "BRISK"; // BRIEF, ORB, FREAK, AKAZE, SIFT
                string descriptorType= det_desc_matc_sel_strings[i][1];
                //cout<<det_decs_pairs[i].first<<" "<<det_decs_pairs[i].second<<" "<<imgNumber.str()<<endl;
                string prifex=det_desc_matc_sel_strings[i][0]+"_"+det_desc_matc_sel_strings[i][1]+"_"+imgNumber.str();
                string dir_name="../MP4_KeypointDescriptors_images/det_"+det_desc_matc_sel_strings[i][0]+"/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1];
                descKeypoints((dataBuffer.end() - 1)->keypoints, (dataBuffer.end() - 1)->cameraImg, descriptors, descriptorType,dir_name,prifex,mp4);
                //// EOF STUDENT ASSIGNMENT
                
                // push descriptors for current frame to end of data buffer
                (dataBuffer.end() - 1)->descriptors = descriptors;

                cout << "#3 : EXTRACT DESCRIPTORS done" << endl;

                if (dataBuffer.size() > 1) // wait until at least two images have been processed
                {

                    /* MATCH KEYPOINT DESCRIPTORS */

                    vector<cv::DMatch> matches;
                    std::string matcherType = det_desc_matc_sel_strings[i][2];        // MAT_BF, MAT_FLANN
                    std::string descriptorType_matching;
                    if (descriptorType.compare("SIFT")== 0) 
                    {
                        descriptorType_matching = "DES_HOG"; 
                    }
                    else
                    {
                        descriptorType_matching = "DES_BINARY"; // DES_BINARY, DES_HOG
                    }
                    
                    std::string selectorType = det_desc_matc_sel_strings[i][3];       // SEL_NN, SEL_KNN

                    //// STUDENT ASSIGNMENT
                    //// TASK MP.5 -> add FLANN matching in file matching2D.cpp
                    //// TASK MP.6 -> add KNN match selection and perform descriptor distance ratio filtering with t=0.8 in file matching2D.cpp
                    double t = (double)cv::getTickCount();
                    cout<<dataBuffer.size()<<descriptorType_matching<<matcherType<<selectorType<<endl;
                    matchDescriptors((dataBuffer.end() - 2)->keypoints, (dataBuffer.end() - 1)->keypoints,
                                    (dataBuffer.end() - 2)->descriptors, (dataBuffer.end() - 1)->descriptors,
                                    matches, descriptorType_matching, matcherType, selectorType);
                    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
                    //// EOF STUDENT ASSIGNMENT

                    // store matches in current data frame
                    (dataBuffer.end() - 1)->kptMatches = matches;

                    cout << "#4 : MATCH KEYPOINT DESCRIPTORS done" << endl;

                    // visualize matches between current and previous image
                    if (mp5)
                    {
                        string dir_name_mp5="../MP5_DescriptorMatching_images/det_"+det_desc_matc_sel_strings[i][0]+
                                            "/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+
                                            "/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+"_"+det_desc_matc_sel_strings[i][2];                                       ;
                        string prifex_mp5="/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+"_"+det_desc_matc_sel_strings[i][2];                          
                        cv::Mat matchImg = ((dataBuffer.end() - 1)->cameraImg).clone();
                        cv::drawMatches((dataBuffer.end() - 2)->cameraImg, (dataBuffer.end() - 2)->keypoints,
                                        (dataBuffer.end() - 1)->cameraImg, (dataBuffer.end() - 1)->keypoints,
                                        matches, matchImg,
                                        cv::Scalar::all(-1), cv::Scalar::all(-1),
                                        vector<char>(), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                        std::stringstream ss;
                        ss << std::setiosflags(std::ios::fixed) << std::setprecision(3) << 1000 * t / 1.0;
                        std::string str = ss.str();
                        cv::Mat visImage = img.clone();
                        cv::drawKeypoints(img, keypoints, visImage, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
                        cv::imwrite(dir_name_mp5+"/"+prifex_mp5+ "_n="+to_string(matches.size())+"_t="+str +"ms"+ ".png",matchImg);
                    }
                    if (mp6)
                    {
                        string dir_name_mp6="../MP6_DescriptorDistanceRatio_images/det_"+det_desc_matc_sel_strings[i][0]+
                                            "/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+
                                            "/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+"_"+det_desc_matc_sel_strings[i][2]+  
                                            "/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+"_"+det_desc_matc_sel_strings[i][2]+"_"+det_desc_matc_sel_strings[i][3];                                
                        string prifex_mp6="/det_"+det_desc_matc_sel_strings[i][0]+"_decs_"+det_desc_matc_sel_strings[i][1]+"_"+det_desc_matc_sel_strings[i][2]+"_"+det_desc_matc_sel_strings[i][3];                          
                        cv::Mat matchImg = ((dataBuffer.end() - 1)->cameraImg).clone();
                        cv::drawMatches((dataBuffer.end() - 2)->cameraImg, (dataBuffer.end() - 2)->keypoints,
                                        (dataBuffer.end() - 1)->cameraImg, (dataBuffer.end() - 1)->keypoints,
                                        matches, matchImg,
                                        cv::Scalar::all(-1), cv::Scalar::all(-1),
                                        vector<char>(), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                        std::stringstream ss;
                        ss << std::setiosflags(std::ios::fixed) << std::setprecision(3) << 1000 * t / 1.0;
                        std::string str = ss.str();
                        cv::Mat visImage = img.clone();
                        cv::drawKeypoints(img, keypoints, visImage, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
                        cv::imwrite(dir_name_mp6+"/"+prifex_mp6+ "_n="+to_string(matches.size())+"_t="+str +"ms"+ ".png",matchImg);
                    }
                    bVis = false;
                    if (bVis)
                    {
                        cv::Mat matchImg = ((dataBuffer.end() - 1)->cameraImg).clone();
                        cv::drawMatches((dataBuffer.end() - 2)->cameraImg, (dataBuffer.end() - 2)->keypoints,
                                        (dataBuffer.end() - 1)->cameraImg, (dataBuffer.end() - 1)->keypoints,
                                        matches, matchImg,
                                        cv::Scalar::all(-1), cv::Scalar::all(-1),
                                        vector<char>(), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                        string windowName = "Matching keypoints between two camera images";
                        cv::namedWindow(windowName, 7);
                        cv::imshow(windowName, matchImg);
                        cout << "Press key to continue to next image" << endl;
                        cv::waitKey(0); // wait for key to be pressed
                    }
                    bVis = false;
                }

    } // eof loop over all images
        
    }
    return 0;
}
