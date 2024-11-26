# Class [diode signage]

## description
### method: SetSize()
This method sets the size by x and y. The parameter takes sf::Vector2f size
### method: SetDiodDiameter()
This method sets the diameter of the LED with the float parameter
### method: SetDiodSpacing()
This method sets the distance between the LEDs
### method: SetColorOn()
This method sets the emitted color in the running state by the parameter accepts sf::Color
### method: SetColorOff()
This method sets the emitted color in a non-working state with the parameter accepts sf::Color
### method: SetGlobalCoordinates()
This method sets the position inside the window with the parameter  sf::Vector2f
### method: GetSize()
This method returns the size of the matrix in x and y returns Vector2f
### method: GetColorOn()  GetColorOff()
These two methods return sf::Color 
GetColorOn()- returns the color of the LED that will be turned on 
GetColorOff()- returns the color of the off LED
### method: GetDiodSpacing()
This method returns the space between the LEDs returns the float value
### method: GetDiodDiameter()
This method returns the diameter of the LED returns float
### method: GetDiodeStatus()
This method returns the state of the LED in certain coordinates, the parameter takes sf::Vector2f
### method: GetGlobalCoordinates()
This method returns the global coordinates of the LED panel inside the window
### method: loadDiodPanelData()
This method is designed to load information into the LED panel takes in the std parameter std::vector<std::vector<bool>>
### method: turnOnDiodeAtCoordinates() turnOffDiodeAtCoordinates()
These two methods turn the LEDs on and off at certain coordinates using the sf::Vector2f parameter
### method: DrawWindow()
This method is intended for rendering the LED panel in the window  parameter accepts sf::RenderWindow
### method: ScrollingText()
This method is designed to create a running line effect and takes two parameters. 
1. Step he is responsible for how many steps need to be done in one rendering cycle. 
2. The direction is defined 3 directions have been defined by macros for convenience.
### method: Invert()
This method inverts the current state of the LED panel
