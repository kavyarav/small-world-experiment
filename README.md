small-world-experiment
======================
1. In this code we will re-examine the small-world experiment in social network using
uninformed search algorithms. 

2. To give you a realistic and modern context, we twist the experiment and put it
into a limited scope of a simplified social network.

3. Suppose Alice wants to send a message to Noah. Thanks to Facebook, Alice is able to see the friends Noah has. Unfortunately, Alice cannot find any mutual friends she has with  Noah. However, she manages to find the relevant people
who might be able to forward her message. 

4. The social network, is considered a graph, where links between two nodes represent “friend” relationship between the two people.

5. The input file contains names of people forming the small world social network followed by their connection graph adjacency matrix.

6. Output produces 3 files each correspoding to the search algorithm used- BFS, DFS and Uniform Cost Search.

7. For the sake of simplicity the input file name has been hard-coded as social-network.txt.

8. To compile type g++ h1_ai.cpp -o socialnetwork

9. To run tyoe ./socialnetwork
