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


In your Doxygen mainpage add a section named: 
Team Documentation that includes summaries of team meetings
 (minimum of three) and who was assigned a task to complete.

* \section Team Meetings
*  All team mebers engaged in each and every meeting. 

Iteration 2 First Deliverable
March 26, 2021
Meeting one consisted of reading the Iteration 2 requirements and having an understanding of the requirements for the first deliverable.
This meeting also consisted of making the decision to use Anthony's code from Iteration 1 for Iteration 2. Anthony pushed his code to 
the shared repo for our team. Planned for next meeting on Monday.
 
Anthony was assigned Priority level 1 number 2. This consisted of created a robot class and restructuring the code then to have
a courier class. Anthony already had the capability of multiple drones and packages being delivered from multiple Drone/Robots 
because he completed the extra credit from Iteration 1. This satisfies Priority level 2 number 1.
 
Tia was assigned to fix the google tests from Iteration 1. This was Priority level 1 number 1.
 
Imran was assigned writing google tests for the Observer pattern.
 
Emma was assigned the Observer, priority level 2 number 2 and 3. Emma was responsible for getting the observer to report when the 
packages are scheduled, picked up, and dropped off. Emma was also responsible for getting the observer to report for Drone/Robot's 
entering idle state and entering moving state.
 
 
March 29, 2021
Meeting two consisted of updated each other on where we are at with our assigned work and to look over the grading rubric for this 
deliverable. Discussed if there needs to be any modifications on the distribution of work. As google tests for the observer are no 
longer a part of the first deliverable Imrans tasks need to be altered. Planned for next meeting on Tuesday after spring break.
 
Imran was unassigned writing google tests for the observer and instead is now responsible for priority level 2 number 3. Imran is 
responsible for getting the observer to reportfor Drone/Robot's entering idle state and entering moving state.
 
Emma was unassigned priority level 2 number 3, the observer pattern for the Drone/Robot.
 
Tia was assigned google tests for the refactored code from Drone, Robot, courier, and corresponding factory classes.
 
 
Iteration 2 Final Deliverable
April 13, 2021
Meeting three consisted of understanding the requirements for this deliverable and distributing the work between the team. Planned for 
a follow up meeting to occur on Friday at 3 pm.
 
Anthony was assigned priority level 3 which consists implementing a route strategy. Anthony is also responsible for documenting the design 
and implementation.
 
Tia was assigned the documentation of all new classes and methods are documented and updated the UML according to the changes made.
 
Imran was assigned priority level 4 which consists of handling the case when the battery runs out and the need to reschedule the delivery.
 
Emma was assigned the documentation of the Team Meetings.
 
 
April 16, 2021
Discussed the distribution of the tasks to ensure it felt equal. Went over the grading rubric to ensure all tasks were accounted for. Discussed if everyone felt they would be able to
complete their tasks before the deadline. Planned next meeting for Monday at 4 pm.
 
Emma was assigned the documentation for the Observer Pattern.

*/