#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class SFMLWindow :  sf::RenderWindow,sf::Clock
{

public:

	


	SFMLWindow(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default,
		   const sf::ContextSettings& settings = sf::ContextSettings()) : RenderWindow(mode, title, style, settings)
	{
		onCreate();
	};
	SFMLWindow(sf::WindowHandle handle, const sf::ContextSettings& settings = sf::ContextSettings()) : RenderWindow(handle, settings)
	{
		onCreate();
	}
	SFMLWindow():RenderWindow()
	{ 
		onCreate();
	}


	void Start(
	)
	{
		double EndTime=0.0001;

	
		sf::VertexArray arr;
		
		
		
		arr.setPrimitiveType(sf::Quads);
		arr.resize(4);
		arr[0].position = sf::Vector2f(0, 0);
		arr[1].position = sf::Vector2f(100, 0);
		arr[2].position = sf::Vector2f(100, 100);
		arr[3].position = sf::Vector2f(0, 100);
		arr[0].color = sf::Color::Red;
		DrawObjects.push_back(&arr);
		

		while (isOpen())
		{
			

			dt = ( getElapsedTime().asMilliseconds()-EndTime)/1000+0.000001;
			EndTime = getElapsedTime().asMilliseconds();

			updateEvents();
			updateDisplay();
			
		    setTitle(getFPS()); 
			
		}
	}
	
	

	

	
private:

	
	double       dt = 0.001;    // Time betweeen frames 
	sf::Vector2i MousePos;      // Position of the cursor
	std::vector<sf::Drawable*> DrawObjects; // Vector with all the layers that must be drawn to the window
	 
	inline std::string getFPS() { return std::to_string(int(1 / dt)); } // Convert dt to FPS(string)

	void updateDisplay()
	{
		clear();
		for (auto& Layer : DrawObjects)
		{
			draw(*Layer);  // Draw all the layers
		}
		display();
	}

	void updateEvents()

	{
		sf::Mouse Mouse;
		MousePos = Mouse.getPosition(*this); // Get the position of the mouse inside window


		sf::Event event;
		while (pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A) { std::cout << "Key pressed : A "; }
				if (event.key.code == sf::Keyboard::S) { std::cout << "Key pressed : S "; }
				if (event.key.code == sf::Keyboard::D) { std::cout << "Key pressed : D "; }
				if (event.key.code == sf::Keyboard::W) { std::cout << "Key pressed : W "; }
			}
		}


	}

	virtual void onCreate()override
	{
		
		setFramerateLimit(60);    
		setVerticalSyncEnabled(0);
		

	}

	


};

