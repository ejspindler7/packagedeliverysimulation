/*! \mainpage CSCI 3081 Delivery Simulation project

Note -- All of the extra credit has been satisfied. See *How to Obtain, Compile,
and Run the Simulation* below for more information on running the extra credit.

### How to Obtain, Compile, and Run the Simulation

The following description assumes that a CSE Lab machine is being used to run
the simulation.

To obtain the simulation, begin by cloning the project repository from
https://github.umn.edu/umn-csci-3081-s21/repo-diers040.git onto the local
machine:
```
> git clone https://github.umn.edu/umn-csci-3081-s21/repo-diers040.git
```
Next, to build the project, change into the `project`
directory and run the following command:
```
> make
```
Once built, the simulation can be run using:
```
> ./bin/run.sh
```
This will start a server on port `8081` of the local host `127.0.0.1`. To view
the simulation, open a browser window and navigate to http://127.0.0.1:8081/.
Once the page has been loaded, the simulation will begin. To kill the
simulation, either press the *Kill Simulation* button in the top right of the
browser webpage, or interrupt the process from the terminal using `Ctrl+C`. 

Note -- If a `permission denied` error occurs when trying to run the simulation,
issue the following command (assumes that the current working directory is still
`project`):
```
chmod u+x ./bin/*
```
To run the extra credit scenes, an argument can be passed to `./bin/run.sh` with
the desired scene. All of the following commands execute as expected:
```
> ./bin/run.sh scenes/edge_case_1.json

> ./bin/run.sh scenes/edge_case_2.json

> ./bin/run.sh scenes/multiple_drones.json

> ./bin/run.sh scenes/multiple_packages.json

> ./bin/run.sh scenes/multiple_customers.json

> ./bin/run.sh scenes/multiple_deliveries.json
```

### Factory Patterns 
Three different factory patterns were considered as potential solutions for
handling entity creation in this project: a concrete factory pattern, an
abstract factory pattern, and a composite factory pattern. Ultimately, the
composite factory pattern was selected for the extensibility,
and minimal regression testing that it affords--a feature that is crucial given
the iterative approach to this project's development cycle. To understand why
this is the case, all three factory patterns will now be introduced and
compared.

First, consider the concrete factory pattern:
![Figure 1: Concrete factory pattern for entity creation.](../Concrete_Factory_UML_small.png)

In the concrete factory pattern, entity creation logic is moved from the
program--`DeliverySimulation` in this case--to the concrete factory `EntityFactory`.
In doing so, the program is decoupled from all entity creation logic, thereby
closing it to changes in the entity system. For example, if the signature of an
entity's constructor changes, no changes to `DeliverySimulation` are needed,
only the concrete factory `EntityFactory` needs to be updated. This is
particularly important if there are many separate parts of the code base that need to
create entities, as all changes will be contained to a single area.

Unfortunately, however, the concrete factory `EntityFactory` is not, itself,
closed to changes in the entity system. Any time a new entity is added, or the
entity creation logic of an existing entity is modified, so too must the
concrete factory be modified. Furthermore, if there are a large number of
entity types, the `CreateEntity` method of the concrete factory can quickly
grow in length, becoming more and more difficult to maintain and update. 

Next, consider the abstract factory pattern:
![Figure 2: Abstract factory pattern for entity creation.](../Abstract_Factory_UML_small.png)

In the abstract factory pattern, entity creation logic is moved to individual
concrete factories which handle the creation of a single entity. Each of these
specialized concrete factories implements a common factory interface
`IEntityFactory`. This enables the program to use runtime polymorphism to call
the appropriate methods of one of the specialized concrete classes for some
`IEntityFactory` pointer. As such, the abstract factory pattern eliminates the
need for a chain of conditional statements to handle object creation (see
concrete factory pattern UML above), replacing it with a single line of code:
```
IEntity* entity = factory->CreateEntity(object);
```
Unfortunately, however, a conditional chain is now needed to handle the factory
creation logic inside of `DeliverySimulation`. As such, the abstract factory
pattern, on its own, suffers from the same issue as the concrete factory
pattern. Specifically, if there are a large number of entity types, there will
also be a large number of entity factories--each handling the creation logic
of a single entity type. It follows that the factory creation logic inside of
`DeliverySimulation` can quickly grow in length as more entity factories are added,
making it more and more difficult to maintain and update. Additionally, because
the program handles the factory creation logic, there are now dependencies
between each factory class and the program class. To eliminate this coupling
between the program and the factories, the composite factory pattern must be
used.

Finally, consider the composite factory pattern:
![Figure 3: Composite factory pattern for entity creation.](../Composite_Factory_UML_small.png)

In the composite factory pattern, a composite factory is introduced to the
abstract factory pattern discussed above. The composite factory can contain any
number of concrete factories. When the composite factory is used to create an
entity, it iterates through each of its component factories until one is found
that successfully returns the requested entity. This is done using runtime
polymorphism (see the figure above for pseudocode), allowing the composite
factory to be closed to changes in the entity system, in addition to avoiding a
potentially long and difficult to maintain conditional chain. In fact, by using
the composite factory pattern, all parts of the program `DeliverySimulation`,
the factory interface `IEntityFactory`, and the composite factory are closed to
extensions of the entity system. This means that additional entity types can be
introduced without requiring any modifications to the existing code base or
regression testing. As was previously mentioned, it is for this reason that the
composite factory pattern was selected for use in this project.

While the composite factory pattern addresses many of the concerns with the
other factory patterns, it also comes with added complexity. As such, in
applications where extensibility is not a major concern, the concrete factory
pattern, or even a simple factory method are likely better options than the
composite factory pattern.



* \section Team Meetings
*  All team members engaged in each and every meeting.
 

 
* \section Observer Pattern Design
The observer design was to create a function called NotifyObserver within delivery simulation that handles the actual notifying the observers and to call this function when a
notification needs to be sent. The NotifyObserver has a helper function called ScheduledNotifications. ScheduledNotifications handles when a Drone/Robot is moving and when a package is
scheduled. ScheduledNotifications creates a pico json object and adds the correct value for the notification. ScheduledNotifications will then call NotifyObserver to send the notification 
with the associated notification and entity. NotifyObserver loops through all the observers and uses the OnEvent method to send the notification.
 
In ScheduleDelivery when a package is scheduled to be picked up the ScheduledNotifications is used to send the notification. In Update in delivery simulation,
The Drone/Robot moving notification is used by calling the ScheduleNotifications. In Update in delivery simulation, the Drone/Robot en route, idle, and moving notifications directly
call NotifyObserver after creating a pico json object and adding the according value(s).
 
To ensure the notification is only set out once rather than everytime update is called, the courier class uses the getNotification method. This method returns an integer that gets set to
a number dependent on which sequence of notifications it is on.  In Update within delivery simulation, there are checks that are made using the GetStatus and getNotification method from courier
class to determine the state of the package and Drone/Robot so the according notifications can be sent.

*/
