/*
* Computer Game AI Assignment.
* An Implementation of the A* algorithm.
* Chloe Madden (B00286864) & Adam Stanton (B00266256).

* All data loaded into our graph comes from Data.h which is the hard coded data from the assignment .dot file.
* Our AStarAlgorithm function was done based on the following psuedocode found here http://mat.uab.cat/~alseda/MasterOpt/AStar-Algorithm.pdf 
*/

#include <vector>
#include <iostream>
#include <math.h>    

#include "node.h"
#include "AStarGraph.h"


//Euclidean distance calculation (used for the heuristic values)
float distanceHeuristic(node* startNode, node* goalNode)
{
	location start = startNode->getPos();
		
	location end = goalNode->getPos();

	float dx = start.x - end.x;
	float dy = start.y - end.y;
	return ::sqrt(dx * dx + dy * dy);
}



//find the node with the lowest cost ( g() + h() )
node* lowest(std::vector<node*> nodes, node* goal)
{
	//Exit if the list is empty
	if (nodes.empty())
	return nullptr;

	//Start at first node
	node* currentLowest = nodes[0];
	float currentLowestCost = nodes[0]->g + nodes[0]->h;

	//compare all nodes leaving the lowest stored
	for(int i = 1; i < nodes.size(); i++)
	{
		nodes[i]->f = nodes[i]->g + nodes[i]->h;

		if (nodes[i]->f  < currentLowestCost)
		{
			currentLowest = nodes[i];
			currentLowestCost = nodes[i]->f;
		}
		
	}

	return currentLowest;
}



//Test if a node is inside a given vector
bool isInside(std::vector<node*> list, node* node)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == node)
			return true;
	}

	return false;
}

//Removes node from given list
bool remove(std::vector<node*>& list, node* node)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == node)
		{
			list.erase(list.begin() + i);
		}
	}

	return false;
}



std::vector<node*> AStarAlgorithm(AstarGraph graph, int start, int goal)
{
	//The nodes taken to goal
	std::vector<node*> pathToGoal;

	//Nodes visited but not fully expanded
	std::vector<node*> openList;

	//Nodes vistited and fully expanded
	std::vector<node*> closedList;

	//Node we start off from
	node *startNode = graph.nodes[start];

	//End destination
	node *goalNode = graph.nodes[goal];

	//Init current node
	node* currentNode = nullptr;


	//Push start node into openlist and set its f()
	startNode->h = distanceHeuristic(startNode, goalNode);
	startNode->f = startNode->h;

	openList.push_back(startNode);


	while (!openList.empty())
	{
		//Take out the node in openList with the lowest f()
		currentNode = lowest(openList, goalNode);

		//	Check if current node is the goal, if so we are done
		if (currentNode == graph.nodes[goal])
		{	
			//Follow the parents all the way back to the start node, now we have our route
			while (currentNode->parent != NULL )
			{
				pathToGoal.push_back(currentNode);
				currentNode = currentNode->parent;
			}

			std::cout << "A* Pathfinding Complete: " << std::endl;

			return pathToGoal;
		}


		// Find all nodes connected via paths to our current node
		std::vector<int> successorIDs = currentNode->getSuccessors();

		// This stores the current successors g()
		float current_succ_cost;

		//	For each successor of current node
	for (int i = 0; i < successorIDs.size(); i++)
		{
			node* successor = graph.nodes[successorIDs[i]];

			//	set current successors g() to be its parents + the cost from parent to itself
			current_succ_cost = currentNode->g + successor->getPathWeight(currentNode->getName()); 

			//If successor is in the openlist
			if (isInside(openList, successor))
			{
				if (successor->g <= current_succ_cost)		goto LOOP;

			}//If successor is in the closedList
			else if (isInside(closedList, successor))
			{
				if (successor->g <= current_succ_cost)      goto LOOP;

				remove(closedList, successor);
				openList.push_back(successor);	
			}
			else //never encountered this node so put in openList for expansion and init h()
			{
				openList.push_back(successor);
				successor->h = distanceHeuristic(successor, goalNode);
			}

			successor->g = current_succ_cost;
			successor->parent = currentNode;


		LOOP:	std::cout << "";//goto leads here. 
		}
		
	//currentNode has been fully expanded and can now be moved to closedList
	remove(openList, currentNode);
	closedList.push_back(currentNode);
	

	}//while

	if (currentNode != goalNode)
	{
		std::cout << "A* algorithm failed: Goal node not found" << std::endl;
	}
}



int main(int argc, char **argv)
{
	//Create the graph...
	unsigned int numberOfEdges = sizeof(edge_array) / sizeof(path);
	int numberOfNodes = sizeof(name) / sizeof(*name);
	AstarGraph Graph(name, locations, edge_array, weights, numberOfNodes, numberOfEdges);

	//Initialise our start and goal node values...
	int start = -5;
	int goal = -5;


	//Display an introductary message:
	std::cout << "Welcome to this A* pathfinding algorithm solution..." << std::endl << std::endl;

	//Update start and goal values from user input instead of generating manually:
	while ((start  < 0) || (start  > numberOfNodes - 1))
	{
		std::cout << "Enter starting node (0-" << numberOfNodes - 1 << "): ";
		std::cin >> start;
	}
	while ((goal  < 0) || (goal  > numberOfNodes - 1))
	{
		std::cout << "Enter goal node (0-" << numberOfNodes - 1 << "): ";
		std::cin >> goal;
	}
	std::cout << std::endl << std::endl << "Finding a path from " << name[start] << " to " << name[goal] << "..." << std::endl;

	//The A* algorithm function outputs a vector of nodes to represent the pathway found...
	std::vector<node*> foundPath = AStarAlgorithm(Graph, start, goal);
	
	
	float costCounter = 0; //Stores the cost of the pathway found.

	//Print results:
	for (int i = foundPath.size() -1; i >= 0; i--)
	{
		path pathway = foundPath[i]->parentRoute();
		costCounter += foundPath[i]->parentPathWeight();
		std::cout << pathway.first << " -- " << pathway.second << std::endl;	
	}
	std::cout <<"Total cost of route:  " << costCounter << std::endl;

	//If no route was found, inform the user...
	if (foundPath.size() == 0)
		std::cout << "No Path Found." << std::endl;

	//Loop at program end 
	int num;
	std::cin >> num;

	return 0;
}