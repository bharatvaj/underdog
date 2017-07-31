# underdog
An attempt to detect vulnerabilities in programs using concepts such as machine learning

### Detecting Unsafe Functions
Unsafe functions are very common in C because of the availability of memory available to the programmer. The most common unsafe functions in C are explained below and how they can be detected are discussed in the further sections.

### Vulnerability checking algorithm
Conventional algorithms for vulnerability checking use semantic approaches for parsing the machine code and requires the interaction of a trained person.
The steps are followed,
Comparing the source code with already known database (approach of most of the Anti-Virus softwares)
Testing input boundary conditions
Detecting the usage of unsafe functions
Stress testing the application with higher input values

### Dynamic Approach
Rather than only training the application through user inputs, dynamic approach goes one step forward and trains itself using snippets which we throw at it which can be achieved simply by using the Natural Language Processor and making it learn by itself.
