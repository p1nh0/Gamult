#include "ofApp.h"

ModuleConsole::ModuleConsole(ofVec2f setOrigin, float setConsoleWidth, int setModule){
    consoleWidth = setConsoleWidth;
    origin.set(setOrigin);
    module = setModule;
    
    remove = new Button(module, origin.x+10, origin.y+10, "Remove");
    loop = new Button(module,origin.x+10,origin.y+30,"Loop");
    freeze = new Button(module,origin.x+10,origin.y+50,"Freeze");
    
    gravity = new Fader("Gravity",origin.x+(consoleWidth/2),origin.y+10+5,100);
    loopSpeed = new Fader("Loop Speed",origin.x+(consoleWidth/2),origin.y+50+5,100);

}

void ModuleConsole::display() {
    
    ofPushStyle();
    ofSetColor(50, 128);
    ofFill();
    // changing original code to include a variable defined in setup to indicate console height
    ofRect(origin.x, origin.y, consoleWidth, ofApp::consoleHeight);
    displayButtons();
    displayFaders();
    ofPopStyle();
    
}

void ModuleConsole::displayButtons() {
    
    remove->displayClick();
    loop->displayToggle();
    freeze->displayToggle();
    
}

void ModuleConsole::displayFaders() {
    
    gravity->display();
    loopSpeed->display();
    
}