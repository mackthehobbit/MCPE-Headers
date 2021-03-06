#pragma once

#include <memory>
#include <string>

#include "App.h"
#include "Vibration.h"
#include "GameCallbacks.h"
#include "SkinInfoFactory.h"
#include "AbstractScreen.h"
#include "MinecraftKeyboardManager.h"
#include "LevelSettings.h"

class PushNotificationMessage;
class ScreenChooser;
class Font;
class UIDefRepository;
class MinecraftInputHandler;
class Entity;
class Options;

// Size : 584
class MinecraftClient : public App, public Vibration, public GameCallbacks, public SkinInfoFactory {
public:
	//vtable for Vibration						// 16
	//vtable for GameCallbacks					// 20
	//vtable for SkinInfoFactory				// 24
	MinecraftKeyboardManager keyboardManager;	// 28
	char filler1[8];							// 40
	std::string worldFolder;					// 48
	std::string peFolder;						// 52
	char filler2[260];							// 56
	Options *options;							// 316
	char filler3[264];							// 320

	MinecraftClient(int, char **);
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onPushNotificationReceived(PushNotificationMessage const &);
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void useTouchscreen();
	virtual void setTextboxText(std::string const &);
	virtual void update();
	virtual void setUISizeAndScale(int, int, float);
	virtual void setRenderingSize(int, int);
	virtual void init();
	virtual void handleBack(bool);
	virtual void onInternetUpdate();
	virtual void canActivateKeyboard();
	virtual void onLevelCorrupt();
	virtual void onGameModeChanged();
	virtual void onGameSessionReset();
	virtual std::unique_ptr<SkinInfoData> createSkin();
	virtual void onLevelExit();
	virtual void onTick(int, int);
	virtual void vibrate(int);

	void startLocalServer(std::string, std::string, LevelSettings);
	void leaveGame(bool);

	Font *getFont() const;
	UIDefRepository *getUIDefRepo() const;
	MinecraftInputHandler *getInput() const;

	void requestScreenshot(std::string const &);

	void initOptionObservers();

	void handleToggleDayCycleActiveButtonPress();
	void handleToggleGameModeButtonPress();
	void handleToggleNoClipButtonPress();
	void handleSetSpawnPositionButtonPress();
	void handleTimeStepForwardButtonPress();
	void handleSimTimeScale(float);
	void handleSimTimePause(bool);
	void handleShowUpsellScreen(bool);
	void handleToggleEnableNewScreensDebugButtonPress();
	void handleReloadUIDefinitions();

	ScreenChooser *getScreenChooser() const;

	void pushScreen(std::shared_ptr<AbstractScreen>, bool);
	void popScreen(int);

	void setCameraTargetEntity(Entity *);
	void setCameraEntity(Entity *);

	Entity *getCameraTargetEntity();
	Entity *getCameraEntity();
};