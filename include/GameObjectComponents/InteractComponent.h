#pragma once

#include "GameObjectComponents/TooltipComponent.h"

class MainCharacter;

// Used for objects which Cendric can interact with. These include a tooltip, as well.
class InteractComponent : public virtual TooltipComponent {
public:
	InteractComponent(std::string tooltip, AnimatedGameObject* parent, MainCharacter* mainChar);
	~InteractComponent() {}

	void update(const sf::Time& frameTime) override;
	void renderAfterForeground(sf::RenderTarget& renderTarget) override;

	void setOnInteract(const std::function<void()>& agent);
	void interact();
	void setInteractText(const std::string& textKey);
	void setInteractRange(float range);
	void setFocused(bool focused);
	void setInteractable(bool interactable);

	float getDistanceToMainChar() const;

private:
	// placeholder for agents
	void nop() const {};

private:
	bool m_isInteractable;
	bool m_isFocused;
	float m_interactRange;
	MainCharacter* m_mainChar;
	std::string m_interactString;
	std::string m_tooltipString;
	std::function<void()> m_executeOnInteract;
};