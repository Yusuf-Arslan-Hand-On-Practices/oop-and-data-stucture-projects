In the implementation of BinPacking,
I implemented 2 class: Time, Flight. 

Time class is used to store the time of the flight. It has 2 attributes: hour and minute.
Flight class is used to store the information of the flight. It has 2 attributes: time and weight of object.
    -Time constructor creates a random time between 0:00 and 23:59.

But weights of objects will be taken from the user.

After all weights are taken, I sorted the flights according to the times.

Algorithm is work such that:
    First, finds the largest number weight object and adds it to a container.
    Then, finds the other largest number weight object and adds it to the container if container size is not full, this continues
    until the container is full.
    After a container is full, we will create another container and repeat the process.


Question1: Does this program produce an optimal solution, that is, finding the minimum number of containers to pack the objects?
Answer:
    This program finds the optimal solution for given example, It finds number of containers is 3.

Question2: Does the algorithm always find the optimal solution?
Answer:
    No. Since we find the largest number and add it to the container, we may pass some cases that will used less containers.
