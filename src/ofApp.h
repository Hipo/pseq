#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxOpenCv.h"
#include "ofxXmlSettings.h"
#include "MSABPMTapper.h"

#include "SequencerTheme.h"
#include "Sequencer.h"


// Comment to disable CoreMotion Framework
#define _USE_CORE_MOTION


#ifdef _USE_CORE_MOTION
#include "ofxCoreMotion.h"
#endif

#define camWidth    480
#define camHeight   360


using namespace msa;


class ofApp : public ofxiOSApp {
	
#ifdef _USE_CORE_MOTION
    ofxCoreMotion coreMotion;
    ofCamera camera;
#endif
    
    ofRectangle themeRect;
    
    float       drawResizeFactor = 1.68f;
    
    int         lastStep;
    int         totalSteps;
    int         currentStep;
    
    bool        retina;
    
public:
    
    ofApp();
    
    void setup();
    void update();
    void draw();
    void exit();
	
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);
    
    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
    
    void currentThemeIdChanged(int &newThemeId);
    void bpmChanged(float &newBpm);
    void columnsChanged(int &newColumns);
    void rowsChanged(int &newRows);
    
    void saveSettings();
    
    ofVideoGrabber  vidGrabber;
    unsigned char   *pix;
    
    ofxCvColorImage			colorImg;
    ofxCvGrayscaleImage 	grayImage;
    ofxCvGrayscaleImage 	grayBg;
    ofxCvGrayscaleImage 	grayDiff;
    ofxCvContourFinder      contourFinder;
    vector<ofPoint>         blobCenters;	// detected objects' centers
    
    // Sequencer
    Sequencer           *currentSequencer;
    vector<Sequencer>   sequencers;
    
    
    BPMTapper       bpmTapper;
    ofFbo           sequencerFbo;
    
    ofParameter<float>      bpm;
    ofParameter<int>        columns;
    ofParameter<int>        rows;
    ofxXmlSettings          settingsXml;
    
    ofParameter<int>        currentThemeId;
    SequencerTheme          *currentTheme;
    vector<SequencerTheme>  themes;
    
    int 		threshold;
    bool		bLearnBackground = true;
    bool        bDebugMode;
    bool        bPlay = true;
};
