#include "ofApp.h"
#include "Button.h"

ModuleConsole::ModuleConsole(int x, float width, int module, vector<string> iconPaths) {
	
	this->width = width;
	this->x = x;
	this->y = 0;
	this->module = module;
	
	int y = 0;
    
    this->height = CONSOLE_HEIGHT * ofGetHeight();
    
    int buttonSize = BUTTON_SIZE*height;
    int faderSize = FADER_SIZE*height;
    int buttonPositionOffset = (height*CONSOLE_SECTION_HEIGHT)/3;
	
    btnGravity = new Button(BUTTON_TOGGLE, module, buttonSize, x+(width*0.1), y+buttonPositionOffset-buttonSize/2, "Gravity");
    
   // btnFreeze  = new Button(BUTTON_TOGGLE, module, buttonSize, x+width - 8*buttonSize, y+buttonSize, "Freeze");
    
    btnFreeze  = new Button(BUTTON_TOGGLE, module, buttonSize, x+width*0.6, y+buttonPositionOffset-buttonSize/2, "Freeze");
    
    btnRemove  = new Button(BUTTON_REMOVE,  module, width/2, x+1, CONSOLE_SECTION_HEIGHT*height,   "Remove");
    btnClear   = new Button(BUTTON_CLEAR, module, width/2, x + width/2 + 1, CONSOLE_SECTION_HEIGHT*height, "Clear");

	fadSpeed = new Fader(x+(width*0.1), y+buttonPositionOffset*2+buttonSize/2, faderSize, "Speed");
	
	// by default gravity is on
    btnGravity->on();
    btnRemove->off();
	btnFreeze->off();

	x = x + width/2;

	//loadIcons(iconPaths);
	
	//ofAddListener(ofEvents().mouseReleased, this, &ModuleConsole::mousePressed);
	
}

//void ModuleConsole::loadIcons(vector<string> paths) {
//
//    for (int i = 0; i < paths.size(); i++) {
//		ofImage img;
//		img.loadImage(paths[i]);
//		icons.push_back(img);
//	
//		// TODO-UI: extrapolate to proper globals or constants
//    	int padding = 5;
//    	int size = 20;
//        int buttonSize = ofGetHeight()*0.018;
//    	int y = CONSOLE_HEIGHT - size - padding;
//		
//		ofRectangle rect;
//		rect.set(x+buttonSize + i*size + 2*width/3, y, size, size);
//		rects.push_back(rect);
//	}
//	
//}

void ModuleConsole::draw() {

	ofPushStyle();
	
	ofSetHexColor(CONSOLE_COLOR);

	ofFill();

	ofDrawRectangle(x, y, width, height);
    
    ofSetHexColor(BUTTON_COLOR);
    
    ofDrawRectangle(x , height * 0.75, width, height * 0.25);

	ofPopStyle();

	btnRemove->draw();
    btnClear->draw();
	btnGravity->draw();
	btnFreeze->draw();
	fadSpeed->draw();
	
	//drawIcons();

}
/*
void ModuleConsole::drawIcons() {
	// TODO-UI: extrapolate to proper globals or constants
	int padding = 5;
	int size = 20;
    int buttonSize = ofGetHeight()*0.018;
	int y = CONSOLE_HEIGHT - size - padding;
	for (int i = 0; i < icons.size(); i++) {
		icons[i].draw(x+buttonSize + i*size + 2*width/3, y, size, size);
//		ofRect(rects[i]);
	}
	
}

void ModuleConsole::mousePressed(ofMouseEventArgs& event) {
	for (int i = 0; i < rects.size(); i++) {
		if (rects[i].inside(event.x, event.y)) {
			cout << "module " << module << " active instrument now is index " << i << endl;
			ofApp::modules[module]->changeInstrument(i);
			return;
		}
	}
}

*/
