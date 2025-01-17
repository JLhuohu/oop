#pragma once

#include <istream>

#include <SFML/System/Vector2.hpp>

#include <GAME/log/Log.hpp>
#include <GAME/serialize/InObjectsTable.hpp>
#include <GAME/serialize/OutObjectsTable.hpp>

class Viewport : public Loggable {
private:
	// Position in real pixels
	float viewportLeft, viewportTop;
	float scale = 1;

	float left, top, right, bottom;

	// Should be updated after setScale and setSize functions
	// Viewport's size in real pixels
	float viewportWidth, viewportHeight;
	float maximumViewportWidth, maximumViewportHeight;

	// Map is fully visible
	float minScale = 1;
	float maxScale = 10;
	
	float mapWidth, mapHeight;

	void updateViewportSizes();
	void validatePosition();

	float clamp(float val, float minVal, float maxVal) const;

public:
	Viewport(std::istream& is, InObjectsTable& table);
	void writeObject(std::ostream& os, OutObjectsTable& table);
	virtual ~Viewport() {}

	Viewport();
	Viewport(const Viewport& viewport);
	Viewport(Viewport&& viewport);
	Viewport& operator=(const Viewport& other);
	Viewport& operator=(Viewport&& other);

	sf::Vector2f mapCoordsToPixels(const sf::Vector2f& coords) const;
	sf::Vector2f mapPixelsToCoords(const sf::Vector2f& pixels) const;

	void move(float dx, float dy);

	// this function uses curent scale to compute dx and dy that
	// will be applied
	void moveScaled(float dx, float dy);

	void moveTo(float left, float top);
	
	void setSize(float mapWidth, float mapHeight);

	// Set new size with limits for viewport (user newer see something 
	// abroad)
	void setSize(float screenWidth, float screenHeight, float left, float top, float right, float bottom);

	// Just setScale(scale, cx, cy) with current coordinates
	void setScale(float scale);
	float getScale() const;

	virtual void fillLogInfo(LogInfo& info) override;

	// Coordinates here is not next viewport center, screen just will be moved 
	// closer to this coordinates. Both centerX and centerY should be inside current
	// viewport, otherwise they will be validated
	// CURRENTLY FROZEN
	// void setScale(float scale, float centerX, float centerY);
};