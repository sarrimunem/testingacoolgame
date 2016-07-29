#pragma once

#include "global.h"

class Dialogue;

// describes the configuration that can be modified by the user via options.
// it stores mainly paths.
struct Configuration {
	std::string npcFolder;
	std::string sqlFolder;
	std::string dialogueFolder;
};

const struct Configuration DEFAULT_CONFIGURATION {
	"res/npc/",
	"res/db/insert_scripts/dialogue/",
	"res/convenience/dialogue/"
};

// current state of the application. It holds the configuration and the current dialogue.
// singleton + global
class ApplicationState {
public:
	ApplicationState();
	~ApplicationState();

	void load();
	
	void setConfiguration(const Configuration& configuration);
	// returns the current dialogue of the application. May return null.
	Dialogue* getDialogue() const;
	Configuration& getConfiguration();
	bool isQuitRequested() const;

	// quits the application
	void requestQuit();
	// tries to start a new dialogue
	void requestNewDialogue();

private:
	Dialogue* m_dialogue = nullptr;
	Configuration m_configuration;
	bool m_isQuitRequested = false;
};