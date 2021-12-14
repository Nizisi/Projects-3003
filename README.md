# Space Jump SFML Game
Space Jump SFML Game is a vertical jumping game base on sfml library wrote by me with researchable resource from the SFML offical website.<br />
I made it mainly during November, I think I'm still in the entry level for C++ coding.<br />
This project is for the class final project.<br />
Class is COP 3003, I made this project mainly at home.<br />

## Demonstration
![Sample GIF](JNIzrIgziU.gif) 

## Documentation
[Doxygen](https://nizisi.github.io/Projects-3003/html/)

## Diagrams
![Sample Image](docs/html/classloc_point.png)

## Built With
* Visual Studio2019 
* SFML library
* SFML official website and forum

## Contributing
Any tips on how to make a score counter for the game would help!

## Author
* Jie Zhou

## License
![license](LICENSE)

## Acknowledgments

* https://www.sfml-dev.org/tutorials/2.5/
* https://en.sfml-dev.org/forums/index.php?action=search2

## History
* Added restricition both on platform and player, so player wont go through the wall, and the platform's random generation won't generate on the wall.
* adjust on velocity and hit algorithm do make the game easy to play and makes the player looks really like jump on the platform instead of hitting the air above the platform

## Key Programming Concepts Utilized
* A virtual function is a special type of function that, when called, resolves to the most-derived version of the function that exists between the base and derived class. This capability is known as polymorphism. A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides. 
* One of the most important concepts in object-oriented programming is that of inheritance. Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application. This also provides an opportunity to reuse the code functionality and fast implementation time.
