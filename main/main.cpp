#include"Header_main.h"


int main()
{
    srand(time(0));
    int width = 800, height = 800;

    sf::RenderWindow window(sf::VideoMode(width, height), "diode panel emulator");
    window.setFramerateLimit(15);
    window.setVerticalSyncEnabled(0);
   std::string temp;
    int x = 0, y = 0;
    diode_panel a;
   
    a.SetSize(sf::Vector2f(70, 70));

    a.SetDiodDiameter(5);
    a.SetDiodSpacing(3);
    a.SetColorOn(sf::Color::Cyan);
    a.SetColorOff(sf::Color(100, 100, 100));
    a.SetGlobalCoordinates(sf::Vector2f(width / 3, height / 3));
 
    TextToDiodLayoutConverter conv;
 
  
    temp = "1234";
  
    a.loadDiodPanelData(conv.textToDiodMatrix(temp));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
     
     
       
        a.DrawWindow(window);
        a.ScrollingText(1, ShifTtoTheRight);
    
      
        window.display();
    }

    return EXIT_SUCCESS;
}