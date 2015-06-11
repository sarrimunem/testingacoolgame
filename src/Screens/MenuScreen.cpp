#include "Screens/MenuScreen.h"

using namespace std;

MenuScreen::MenuScreen(CharacterCore* core) : Screen(core)
{
	m_screenSprite = sf::Sprite((*g_resourceManager->getTexture(ResourceID::Texture_screen_menu)));
}

Screen* MenuScreen::update(const sf::Time& frameTime)
{
	if (m_yesOrNoForm != nullptr && m_yesOrNoForm->isNoClicked())
	{
		m_yesOrNoForm->setDisposed();
		m_yesOrNoForm = nullptr;
		delete m_newCharacterCore;
		setAllButtonsEnabled(true);
	}
	else if (m_yesOrNoForm != nullptr && m_yesOrNoForm->isYesClicked())
	{
		m_yesOrNoForm->setDisposed();
		m_yesOrNoForm = nullptr;
		delete m_characterCore;
		m_characterCore = m_newCharacterCore;
		m_newCharacterCore = nullptr;
		return new LoadingScreen(m_characterCore->getData().currentMap, m_characterCore);
	}
	else if ((g_inputController->isKeyActive(Key::Escape) && m_characterCore == nullptr) || m_exitButton->isClicked())
	{
		// end the game
		m_requestQuit = true;
	}
	else if ((m_resumeGameButton != nullptr && m_resumeGameButton->isClicked()) || (g_inputController->isKeyActive(Key::Escape) && m_characterCore != nullptr))
	{
		// resume game
		return new LoadingScreen(m_characterCore->getData().currentMap, m_characterCore);
	}
	else if (m_newGameButton->isClicked())
	{
		if (m_characterCore == nullptr)
		{
			// we start a new game with an empty character core
			m_characterCore = new CharacterCore();
			m_characterCore->loadNew();
			return new LoadingScreen(m_characterCore->getData().currentMap, m_characterCore);
		}
		else
		{
			m_newCharacterCore = new CharacterCore();
			m_newCharacterCore->loadNew();
			m_yesOrNoForm = new YesOrNoForm(sf::FloatRect(400, 350, 450, 200));
			m_yesOrNoForm->setMessage("QuestionStartNewGame");
			addObject(GameObjectType::_Form, m_yesOrNoForm);
			setAllButtonsEnabled(false);
		}
	}
	else if (m_loadGameButton->isClicked())
	{
		// TODO the .sav files should be loaded in another screen. 
		char* saveFilename = "saves/testsave.sav";
		// TODO check if character core is set and ask if it should be overwritten
		if (m_characterCore == nullptr)
		{
			// we start a new game with an empty character core
			m_characterCore = new CharacterCore();
			if (!(m_characterCore->load(saveFilename)))
			{
				string errormsg = string(saveFilename) + ": save file corrupted!";
				g_resourceManager->setError(ErrorID::Error_dataCorrupted, errormsg);
			}
			return new LoadingScreen(m_characterCore->getData().currentMap, m_characterCore);
		} 
		else 
		{
			m_newCharacterCore = new CharacterCore();
			if (!(m_newCharacterCore->load(saveFilename)))
			{
				string errormsg = string(saveFilename) + ": save file corrupted!";
				g_resourceManager->setError(ErrorID::Error_dataCorrupted, errormsg);
			}
			m_yesOrNoForm = new YesOrNoForm(sf::FloatRect(400, 350, 450, 200));
			m_yesOrNoForm->setMessage("QuestionLoadGame");
			addObject(GameObjectType::_Form, m_yesOrNoForm);
			setAllButtonsEnabled(false);
		}
	} 
	else if (m_saveGameButton->isClicked())
	{
		// TODO hardcoded menu .sav file 
		char* saveFilename = "saves/menusave.sav";
		m_characterCore->save(saveFilename);
		setTooltipText(L"Saved file to: saves/menusave.sav", sf::Vector2f(10.f, 10.f), sf::Color::White, true);
	}
	else if (m_optionsButton->isClicked())
	{
		return new OptionsScreen(m_characterCore);
	}
	else if (m_creditsButton->isClicked())
	{
		return new CreditsScreen(m_characterCore);
	}
	updateTooltipText(frameTime);
	updateObjects(GameObjectType::_Undefined, frameTime);
	updateObjects(GameObjectType::_Button, frameTime);
	updateObjects(GameObjectType::_Form, frameTime);
	deleteDisposedObjects();
	return this;
}

void MenuScreen::setAllButtonsEnabled(bool value)
{
	vector<GameObject*>* buttons = getObjects(GameObjectType::_Button);
	for (auto it : *buttons)
	{
		Button* button = dynamic_cast<Button*>(it);
		if (button != nullptr)
		{
			button->setEnabled(value);
		}
	}
	m_saveGameButton->setEnabled(value && (m_characterCore != nullptr));
}

void MenuScreen::render(sf::RenderTarget &renderTarget) 
{
	renderTooltipText(renderTarget);
	setViewToStandardView(renderTarget);
	renderTarget.draw(m_screenSprite);
	renderObjects(GameObjectType::_Undefined, renderTarget);
	renderObjects(GameObjectType::_Button, renderTarget);
	renderObjects(GameObjectType::_Form, renderTarget);
}

void MenuScreen::execOnEnter(const Screen *previousScreen)
{
	// add burning fire baskets
	FireBasket* fireBasket1 = new FireBasket();
	FireBasket* fireBasket2 = new FireBasket();
	fireBasket1->setPosition(sf::Vector2f(60.f, 140.f));
	fireBasket2->setPosition(sf::Vector2f(998.f, 140.f));
	addObject(GameObjectType::_Undefined, fireBasket1);
	addObject(GameObjectType::_Undefined, fireBasket2);

	// add buttons
	if (m_characterCore != nullptr)
	{
		m_resumeGameButton = new Button(sf::FloatRect(475, 200, 300, 50));
		m_resumeGameButton->setText("Resume");
		addObject(GameObjectType::_Button, m_resumeGameButton);
	}
	m_newGameButton = new Button(sf::FloatRect(475, 270, 300, 50));
	m_newGameButton->setText("NewGame");
	m_loadGameButton = new Button(sf::FloatRect(475, 340, 300, 50));
	m_loadGameButton->setText("LoadGame");
	m_saveGameButton = new Button(sf::FloatRect(475, 410, 300, 50));
	m_saveGameButton->setText("SaveGame");
	m_saveGameButton->setEnabled(m_characterCore != nullptr);
	m_optionsButton = new Button(sf::FloatRect(475, 480, 300, 50));
	m_optionsButton->setText("Options");
	m_creditsButton = new Button(sf::FloatRect(475, 550, 300, 50));
	m_creditsButton->setText("Credits");
	m_exitButton = new Button(sf::FloatRect(475, 620, 300, 50));
	m_exitButton->setText("Exit");
	addObject(GameObjectType::_Button, m_newGameButton);
	addObject(GameObjectType::_Button, m_loadGameButton);
	addObject(GameObjectType::_Button, m_optionsButton);
	addObject(GameObjectType::_Button, m_creditsButton);
	addObject(GameObjectType::_Button, m_exitButton);
	addObject(GameObjectType::_Button, m_saveGameButton);
}

void MenuScreen::execOnExit(const Screen *nextScreen)
{
	g_resourceManager->deleteResource(ResourceID::Texture_screen_menu);
	g_resourceManager->deleteResource(ResourceID::Texture_screen_splash_fireanimation);
	delete m_newCharacterCore;
}