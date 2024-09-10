This project aims to teach concurrent programming, focusing on multithreading and multiprocessing. In order to do that, the subject require us to implement the well-known "Dining philosophers problem". The program is a simulation of this problem where each philo is represented by a thread and each fork is represented by a mutex. Therefore, each philo (thread) needs to grab a fork (lock his/her mutex and the one to their right/left depending on the implementation chosen) in order to start eating. The round table structure can be represented within the code with a double linked lists where each node is a philo struct.

In addition to the number of threads that represent the number of philos at the table, a supervisor thread was implemented too to check wether any philo dies during the simulation. Take into consideration that the number of philos,  time to die,  time to eat and time to sleep are all input that are passed to the program through the argvs. Therefore, depending on the input, philos will die or not. The supervisor thread is in charge of checking if any philo died, stopping the simulation if that is the case.

In the link below you can find some info about the so called philo problem: https://en.wikipedia.org/wiki/Dining_philosophers_problem


![Screenshot from 2024-09-10 18-17-49](https://github.com/user-attachments/assets/0e05a120-878e-4795-b80a-f55f3f4fce6b)



This project was first done and finished in a different repo to this one (42 camps provides us with independent repos for each project). Once finished, the project was then copied to my personal repo in gitHub.

In the following pdf you can find the project requirements as specified by 42 campus:[README_PHILO.pdf](https://github.com/Alvicina/PHILO/files/15310150/README_PHILO.pdf)

The following snapshot is proof that the project was succesfully done:
![Screenshot from 2024-09-09 17-50-10](https://github.com/user-attachments/assets/912d4142-a2a5-4aa0-a96e-1b716c11e09c)



