# ECS Framework
I made a small ECS framework as a first experience with this pattern. The goal was to make something that is pattern-compliant, user friendly, and efficient. 

## Getting Started

The framework comes with a system base class, a system manager, and managers for components and entities. A main and a file with engine variables are also provided. There is also an example component, system, and component manager with some example functionality in the game loop as well.

### Entities
In ECS, entities are nothing more than ID's. Their only purpose is to make sure the user is able to access the relevant components belonging to a single entity. All the data that is linked to an entity should be in the entity's components.

The EntityManager provides functionality for keepoing track of existing entities and cleaning them up, notifying the ComponentManager to clean up the components linked to that entity as well. It also keeps a list of freed entities: entities that have been deleted. This allows us to make the next entity that's created belong to that index so that we don't leave empty spaces in our array.

### Components
In ECS, components only hold data. This means that they are POD's; plain ol' data. To keep track of them, I created the ComponentManager class. It's a templated class, which allows the user to create a struct with data as their component and then make a component manager for each type of component they have. 

### Systems
All the functionality in an ECS-compliant framework goes through systems. In my framework, there is a system base class from which the user can inherit and add their system child class to the systemmanager. The user can then override the start, update, and end methods of the system base and add functionality as they please.

## TODO'S

#### Critical Issues
1. Move the data out of the systems, these should be in components

#### High Importance Issues
1. Replace the reference to the IComponentManagers in the EntityManager with an Observer Pattern, this is a lot cleaner and will minimize unnecessary dependencies

#### Goals
1. Implement SDL for input, will open the door for much more interesting use cases
2. Add a more robust game loop
3. Improve error handling