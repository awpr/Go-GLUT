// DEFINE_FUNCS is needed because I'm unsure how to pass C function pointers in Go.
#define DEFINE_FUNCS(x, y, ...) \
extern void y(__VA_ARGS__); \
void set##x##Func() { glut##x##Func(y); } \
void clear##x##Func() { glut##x##Func(NULL); } \

DEFINE_FUNCS(Display, internalDisplayFunc)
DEFINE_FUNCS(OverlayDisplay, internalOverlayDisplayFunc)
DEFINE_FUNCS(Reshape, internalReshapeFunc, int width, int height)
DEFINE_FUNCS(Keyboard, internalKeyboardFunc, unsigned char key, int x, int y)
DEFINE_FUNCS(Mouse, internalMouseFunc, int button, int state, int x, int y)
DEFINE_FUNCS(Motion, internalMotionFunc, int x, int y)
DEFINE_FUNCS(PassiveMotion, internalPassiveMotionFunc, int x, int y)
DEFINE_FUNCS(Visibility, internalVisibilityFunc, int state)
DEFINE_FUNCS(Entry, internalEntryFunc, int state)
DEFINE_FUNCS(Special, internalSpecialFunc, int key, int x, int y)
DEFINE_FUNCS(SpaceballMotion, internalSpaceballMotionFunc, int x, int y, int z)
DEFINE_FUNCS(SpaceballRotate, internalSpaceballRotateFunc, int x, int y, int z)
DEFINE_FUNCS(SpaceballButton, internalSpaceballButtonFunc, int button, int state)
/* just in case you're on an SGI box.. :) */
DEFINE_FUNCS(ButtonBox, internalButtonBoxFunc, int button, int state)
DEFINE_FUNCS(Dials, internalDialsFunc, int dial, int value)
DEFINE_FUNCS(TabletMotion, internalTabletMotionFunc, int x, int y)
DEFINE_FUNCS(TabletButton, internalTabletButtonFunc, int button, int state, int x, int y)
DEFINE_FUNCS(MenuStatus, internalMenuStatusFunc, int status, int x, int y)
DEFINE_FUNCS(Idle, internalIdleFunc)
DEFINE_FUNCS(KeyboardUp, internalKeyboardUpFunc, unsigned char key, int x, int y)
DEFINE_FUNCS(SpecialUp, internalSpecialUpFunc, int key, int x, int y)

// glutCreateMenu callback
extern void internalMenuFunc(int value); // 
int goCreateMenu() { return glutCreateMenu(internalMenuFunc); }
int goCreateMenuWithoutCallback() { return glutCreateMenu(NULL); }

// glutJoystickFunc callback
extern void internalJoystickFunc(unsigned int buttonMask, int x, int y, int z);
void setJoystickFunc(int pollInterval) { glutJoystickFunc(internalJoystickFunc, pollInterval); }
void clearJoystickFunc(int pollInterval) { glutJoystickFunc(NULL, pollInterval); }

// cgo does not correctly interpret the GLUT font constants, so we try internalDisplayFunc different approach.
#define DEFINE_FONT(x) void* go_##x() { return x; }
DEFINE_FONT(GLUT_STROKE_ROMAN)
DEFINE_FONT(GLUT_STROKE_MONO_ROMAN)
DEFINE_FONT(GLUT_BITMAP_9_BY_15)
DEFINE_FONT(GLUT_BITMAP_8_BY_13)
DEFINE_FONT(GLUT_BITMAP_TIMES_ROMAN_10)
DEFINE_FONT(GLUT_BITMAP_TIMES_ROMAN_24)
DEFINE_FONT(GLUT_BITMAP_HELVETICA_10)
DEFINE_FONT(GLUT_BITMAP_HELVETICA_12)
DEFINE_FONT(GLUT_BITMAP_HELVETICA_18)
