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


* \section meeting_ Team Meetings
*  All team members engaged in each and every meeting.

Iteration 2 First Deliverable:


March 26, 2021:
    Meeting one consisted of reading the Iteration 2 requirements and having an understanding of the requirements for the first deliverable.
This meeting also consisted of making the decision on whose code to use. The team collectively decided to use Anthony's code from
Iteration 1 for Iteration 2. Anthony pushed his code to the shared repo for our team. The work was distributed between team members.
Planned for next meeting on Monday.
 - Anthony was assigned Priority level 1 number 2. This consisted of creating a robot class and restructuring the
a courier class. Anthony already had the capability of multiple drones and packages being delivered from multiple Drone/Robots
because he completed the extra credit from Iteration 1. This satisfies Priority level 2 number 1.
 - Tia was assigned to fix the google tests from Iteration 1. This was Priority level 1 number 1.
 - Imran was assigned writing google tests for the Observer pattern.
 - Emma was assigned the Observer, priority level 2 number 2 and 3. Emma was responsible for getting the observer to report when the
packages are scheduled, picked up, and dropped off. Emma was also responsible for getting the observer to report for Drone/Robot's
entering idle state and entering moving state.


March 29, 2021: Meeting two consisted of updating each other on where we are at with our assigned work and to look over the grading rubric for this
deliverable. Discussed if there needs to be any modifications on the distribution of work. As google tests for the observer are no
longer a part of the first deliverable Imrans tasks need to be altered. Planned for next meeting on Tuesday after spring break.
 - Imran was unassigned writing google tests for the observer and instead is now responsible for priority level 2 number 3. Imran is
responsible for getting the observer to reportfor Drone/Robot's entering idle state and entering moving state.
 - Emma was unassigned priority level 2 number 3, the observer pattern for the Drone/Robot.
 - Tia was assigned google tests for the refactored code from Drone, Robot, courier, and corresponding factory classes.


Iteration 2 Final Deliverable:


April 13, 2021:
Meeting three consisted of understanding the requirements for this deliverable and distributing the work between the team. Planned for
a follow up meeting to occur on Friday at 3 pm.
 - Anthony was assigned priority level 3 which consists implementing a route strategy. Anthony is also responsible for documenting the design
and implementation.
 - Tia was assigned the documentation of all new classes and methods are documented and updated the UML according to the changes made.
 - Imran was assigned priority level 4 which consists of handling the case when the battery runs out and the need to reschedule the delivery.
 - Emma was assigned the documentation of the Team Meetings.


April 16, 2021:
Discussed the distribution of the tasks. Went over the grading rubric to ensure all tasks were accounted for. Discussed the rubric's and
assigned remaining tasks. Discussed if everyone felt they would be able to complete their tasks before the deadline. Planned next meeting
for Monday at 4 pm.
 - Emma was assigned the documentation for the Observer Pattern.
 - Tia was assigned modifying google tests for the routes.

April 19, 2021:
Reviewed the accomplished work and submitted Iteration 2 Final Deliverable.

\section routes_ Designing and Implementing the routes

To address the design requirement that drones be able to use any one of many
different route types (eg. smart, beeline, or parabolic) when picking up
and delivering packages, we decided to implement a strategy pattern. The
strategy pattern allows for easy extensibility in the event that future
iterations require that new route types be added to the delivery simulation.
Additionally, the strategy pattern was particularly well suited to this
application given that routes--regardless of strategy--are of the same form.
Specifically, the courier movement logic expects that a route be in the form of a
queue of three dimensional vectors where each vector points to some point in
space relative to the base frame of the simulation. Given such a route, the
courier will then travel to each point in FIFO order until the queue is empty.
Thus, each strategy is expected to take two arguments--a source point and a
destination point--and return a properly formatted queue of vectors. The
following figure displays the specifics of our implementation:

![Figure 4: strategy pattern for route generation.](../Strategy_Pattern_UML_small.png)

Note that the Courier base class is oblivious to the implementation details of
the concrete route strategies--meaning that it is closed to changes in those
strategies. Each concrete strategy must override the pure abstract method
`GetRoute` of the route strategy interface class `IRoute`. By default, all
Couriers use the `SmartRoute` strategy as per the project requirements. If,
however, a `path` key is found in the picojson object passed to the
constructor of the Drone class, then `Courier::SetPathType` is called with the string
value that is paired with the `path` key. As indicated in the figure above, this
sets the Drone to use the desired route strategy when calls to `UpdateRoute` are
made.

Both the smart and beeline route strategies are very simple in their
implementations. The smart route strategy makes use of the provided
`Igraph*->GetPath` function which, itself, uses a shortest path algorithm (A*) to
generate a vector of points leading from some source point to some destination
point, avoiding obstacles along the way. Beyond calling
`Igraph*->GetPath`, `SmartRoute::GetRoute` converts the returned path to the
desired route format outlined above, before returning. The beeline route
strategy, meanwhile, simply generates a queue of four points:
the source point, the source point translated a fixed number of units straight
up, the destination point translated a fixed number of units straight up, and
finally the destination point.

The parabolic route strategy, unlike the beeline and smart routes, involves a
fair bit of complication in its implementation. The first two and last two
points of the parabolic route are generated identically to the four points of
the beeline route. In between these points, however, the parabolic route--as its
name suggests--generates a sequence of points along a parabola which connects the
second point in the route to the penultimate point. This is achieved by stepping
a fixed distance forward, towards the destination, and translating
the new point upwards to the intersection of the new point with the parabola
that is being traced. The mathematical expressions for this translation can be
found in the
[Lab14_Strategy_Drone_Routes](https://github.umn.edu/umn-csci-3081-s21/shared-upstream/tree/support-code/labs/Lab14_Strategy_Drone_Routes)
writup in the course's `shared-upstream` repository. This document, in fact, was
the main source consulted in designing and implementating the
strategy pattern and concrete strategies. Additional sources of information
which assisted in understanding the strategy pattern include:
+ https://www.geeksforgeeks.org/strategy-pattern-set-1/
+ https://www.geeksforgeeks.org/strategy-pattern-set-2/
+ 3081S21LecutreNineteenStrategyPattern which can be accessed on Canvas.

As a result of sound design principles in the first iteration of the delivery
simulation, in addition to the extremely helpful Lab 14 writup mentioned above,
there was very little challenge experienced in implementing the various routes
and strategy pattern. Without Lab 14, however, the parabolic route would have
been rather challenging to implement since the provided mathematical expressions 
are not trivial to derive. As such, we strongly suggest consulting Lab 14 for
anyone attempting a similar implemenation of parabolic routes. 

\section design_ Observer Pattern Design
The observer design includes the implementation of the observer pattern to report when a Package is scheduled, delivered, or enroute to all of the observers. The observer pattern design
includes the implementation to report when either entity the drone or the robot are moving or idle. The observer pattern design roots from the function called NotifyObserver within delivery
simulation. NotifyObserver handles the actual notifying of the observers and to call this function when a notification needs to be sent. The NotifyObserver has a helper function called
ScheduledNotifications. ScheduledNotifications handles when a Drone/Robot is moving and when a Package is scheduled when a courier is available at the time of the the delivery schedule.
ScheduledNotifications creates a pico json object and adds the correct value for the notification. ScheduledNotifications will then call NotifyObserver to send the notification with the
associated notification and entity. NotifyObserver loops through all the observers and uses the OnEvent method to send the notification.

Each notification that needs to be sent has conditions within the update function to check the status of the entities along with checks to ensure each notification is only sent once. Each notification
has a pico json object with added values accroding to the notification. Then calls Notify observer on the pico json object and the entity, with the exception of the schedule and moving notifications
go through the ScheduledNotifications. The conditions used to ensure the notification is only sent once consists of the Courier getNotification() function and the Package IsDelivered function.
Within the courier class an integer variable is changed according to the status of the Drone/Robot.

In ScheduleDelivery when a package is scheduled to be picked up by a courier the ScheduledNotifications is used to send the notifications that the package is scheduled and the Drone/Robot is moving.
In the case that a courier is not available, ScheduledNotifications is called within update when a courier is available to pick up the package. In Update in delivery simulation, the Drone/Robot idle,
moving, pacakge is delivered, and package is enroute notifications are made when their condidtions are met.

The observer design pattern also consisted of adding and removing observers with the functions AddObserver and RemoveObserver. These functions simply push and pop accordingly to the observers_ which is a list of IEntityObserver*.

The observer pattern is within the delivery simulation therefore we do not have corresponding tests.
*/
