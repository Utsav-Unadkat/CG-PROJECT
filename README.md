# CG-PROJECT
 Visualization of shortest path
## STEPS TO USE THE APP
* Enter Any key to get to grid
![](Images%20for%20Algo/Screenshot%20(13).png)
* Enter 1 and select a cell with mouse this will be your start point (coloured blue)
![](Images%20for%20Algo/01.png)
* Enter 2 and select a cell with mouse this will be your end point (coloured green)
![](Images%20for%20Algo/01.png)
* Enter 3 and select a cell with mouse this will block those cell (coloured cyan)
![](Images%20for%20Algo/01.png)
* Repeat above step to create as manay block as you need
![](Images%20for%20Algo/01.png)

```
Note Don't Enter any other key and follow the steps carefully
```

* Enter any key to start the algo 
![](Images%20for%20Algo/01.png)

### Visualization
The algo will begin from start point and spread out according to Dijiksta Algorithm all the visited cell are coloured light purple and once it reaches the end point it starts tracing back of the shortest path.The path can be seen coloured as Orange.

## Explanation Of Algorithm
 This is a sample grid with three blocks, Let’s find shortest distance from start on (0,0) to end on (4,2). 

![](Images%20for%20Algo/01.png)


The demo is done with Euclidean Distances in mind. So horizontal path gets the value 1 and diagonal paths get 1.4.
First we define the distance of start as 0 and all other grids as infinity.

![](Images%20for%20Algo/02.png)

From the start grid, we set the minimum distance of the surrounding grids. The horizontal grid distance is 1. One is less than infinity. So we set 1 as distance of horizontal values. The diagonal value is 1.4. 1.4 is less than infinity. So we set diagonal grids’ distance as 1.4. Meanwhile we add the visiting nodes to a priority queue prioritized by the lesser distance value. And also we define the parent nodes of each node from which the minimum value was taken.


![](Images%20for%20Algo/03.png)
![](Images%20for%20Algo/04.png)
![](Images%20for%20Algo/05.png)

Once we find all node distances around the start node we set start node as ‘visited’. We won’t check visited nodes again.

![](Images%20for%20Algo/06.png)

Then we take the top node from the priority queue and change values surrounding that node. Here we add the distance of the current node to the value when finding distance to surrounding nodes.

![](Images%20for%20Algo/07.png)

At the end of 2nd node the values and parents are like this.

![](Images%20for%20Algo/08.png)

Then take the node from priority queue and do the same.

![](Images%20for%20Algo/09.png)

And again.

![](Images%20for%20Algo/10.png)

At the end of that iteration the values and parents are as follows.

![](Images%20for%20Algo/11.png)

Then we take the node from priority queue and do yet again.

![](Images%20for%20Algo/12.png)

And again.

![](Images%20for%20Algo/13.png)

You keep doing this until you hit the end node.

![](Images%20for%20Algo/14.png)

Once you get to the end node, trace back the parent nodes from the end to find the path. The distance is already found.

![](Images%20for%20Algo/15.png)

So that is how you find the shortest path in a grid.
