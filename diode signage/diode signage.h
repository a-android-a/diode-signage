#include"Header.h"
#pragma once

#define SIZE_CHAR_Y 9
#define SIZE_CHAR_X 8

class diode_panel
{
private:

	float diameter = 2.0, diodSpacing = 5.0;
	sf::Vector2f size_panel{ 0,0 };

	std::vector<std::vector<bool>> LayoutOfTheLoadedDiodes;
	std::vector<std::vector<bool>> panel;
	std::vector<std::vector<sf::CircleShape>> diode;

	sf::Color color_on, color_off;
	sf::Vector2f offsets;
	sf::Vector2f GlobalCoordinates = {0,0};

	void PositionDids(std::vector<std::vector<sf::CircleShape>>& diode) {
		float offset_x = GlobalCoordinates.x, offset_y = GlobalCoordinates.y, rad = (diameter / 2);

		for (int i = 0; i < size_panel.y; i++)
		{
			offset_x = GlobalCoordinates.x;
			for (int j = 0; j < size_panel.x; j++)
			{

				diode[i][j].setPosition(sf::Vector2f(offset_x, offset_y));

				offset_x = rad + offset_x + diodSpacing;
			}
			offset_y = rad + offset_y + diodSpacing;
		}
	}
	void InitializingTheDiameter(std::vector<std::vector<sf::CircleShape>>& diode) {
		for (int i = 0; i < size_panel.y; i++)
		{
			for (int j = 0; j < size_panel.x; j++)
			{

				diode[i][j].setRadius(float(diameter / 2));

			}

		}
	}
	void InitializingTheColor(std::vector<std::vector<sf::CircleShape>>& diode) {
		for (int i = 0; i < size_panel.y; i++)
		{
			for (int j = 0; j < size_panel.x; j++)
			{

				diode[i][j].setFillColor(color_on);

			}

		}
	}



public:

	void SetSize(const sf::Vector2f size) {
		size_panel = size;

		panel.resize(size_panel.y);
		diode.resize(size_panel.y);
		for (size_t i = 0; i < size_panel.y; i++)
		{
			panel[i].resize(size_panel.x);
			diode[i].resize(size_panel.x);
		}

		PositionDids(diode);
	}
	void SetDiodDiameter(const float d) {
		diameter = d;
		InitializingTheDiameter(diode);
	}
	void SetDiodSpacing(const float sp) {
		diodSpacing = sp;
		PositionDids(diode);
	}
	void SetColorOn(const sf::Color c) {
		color_on = c;
		InitializingTheColor(diode);
	}
	void SetColorOff(const sf::Color c) {
		color_off = c;
		InitializingTheColor(diode);
	}
	void SetGlobalCoordinates(const sf::Vector2f c) {
		GlobalCoordinates.x = c.x;
		GlobalCoordinates.y = c.y;
		PositionDids(diode);
	}

	sf::Vector2f GetSize() {
		return size_panel;
	}
	sf::Color GetColorOn() {
		return color_on;
	}
	sf::Color GetColorOff()
	{
		return color_off;
	}

	float GetDiodSpacing() {
		return diodSpacing;
	}
	float GetDiodDiameter() {
		return diameter;
	}
	bool GetDiodeStatus(const sf::Vector2f pos) {
		if (pos.x <= size_panel.x and pos.y <= size_panel.y) return panel[pos.y][pos.x];
	}
	sf::Vector2f GetGlobalCoordinates() {
		return GlobalCoordinates;
	}
	void loadDiodPanelData(const std::vector<std::vector<bool>>& in) {
	
		LayoutOfTheLoadedDiodes.clear();
		LayoutOfTheLoadedDiodes.resize(in.size());

		for (int i = 0; i < in.size(); i++)
		{
			LayoutOfTheLoadedDiodes[i].resize(in[0].size());
		}

		std::copy(in.begin(), in.end(), LayoutOfTheLoadedDiodes.begin());

		for (int i = 0; i < size_panel.y; i++)
		{
			for (int j = 0; j < size_panel.x; j++)
			{
				if(LayoutOfTheLoadedDiodes.size()> i and LayoutOfTheLoadedDiodes[0].size() > j )panel[i][j] = LayoutOfTheLoadedDiodes[i][j];
			}
		}
	}
	void turnOnDiodeAtCoordinates(const sf::Vector2f pos) {
		panel[pos.y][pos.x] = 1;
	}
	void turnOffDiodeAtCoordinates(const sf::Vector2f pos) {
		panel[pos.y][pos.x] = 0;
	}
	void DrawWindow(sf::RenderWindow& w) {
		for (size_t i = 0; i < size_panel.y; i++)
		{
			for (size_t j = 0; j < size_panel.x; j++)
			{
				if (panel[i][j] == 1) {
					diode[i][j].setFillColor(color_on);
					w.draw(diode[i][j]);
				}
				else
				{
					diode[i][j].setFillColor(color_off);
					w.draw(diode[i][j]);
				}
			}
		}
	}

	void ScrollingText(const unsigned int steps, const unsigned short direction) {
		
		switch (direction)
		{
		case 0:
			for (int i = 0; i < steps; i++)
			{
				for (int j = 0; j < size_panel.y; j++)
				{
					panel[j].insert(panel[j].begin(), panel[j][size_panel.x - 1]);
					panel[j].pop_back();


				}

			}
			break;
		case 1:
			for (int i = 0; i < steps; i++)
			{
				for (int j = 0; j < size_panel.y; j++)
				{
					panel[j].insert(panel[j].end(), panel[j][0]);
					panel[j].erase(panel[j].begin());


				}

			}
			break;
		case 2:
		{


			std::vector<bool> temp(size_panel.x, 0);
			for (int i = 0; i < steps; i++)
			{
				for (int i = 0; i < size_panel.x; i++)
				{
					temp[i] = panel[size_panel.y - 1][i];


				}
				panel.insert(panel.begin(), temp);
				panel.erase(panel.end() - 1);
				
				temp.clear();
			}
		}
			break;
		case 3:
			std::vector<bool> temp(size_panel.x, 0);
			for (int i = 0; i < steps; i++)
			{
				for (int i = 0; i < size_panel.x; i++)
				{
					temp[i] = panel[0][i];


				}
				panel.insert(panel.end(), temp);
				panel.erase(panel.begin());
				
				temp.clear();
			}
			break;
		}
	}
	void Invert() {
		for (int  i = 0; i < size_panel.y; i++)
		{
			for (int j = 0; j < size_panel.x; j++)
			{
				if (panel[i][j] == 1) panel[i][j] = 0; else {
					panel[i][j] = 1;
				}
			}
		}
	}
};


