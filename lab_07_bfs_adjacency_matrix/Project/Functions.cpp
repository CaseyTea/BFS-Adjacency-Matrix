/*
	Lauguico, Marco
	Orellana, Romario

	CS A200
	March 10, 2017

	Lab 7
*/

#include "Graph.h"

// Definition function clearGraph
void Graph::clearGraph()
{
	for (int i = 0; i < maxVertices; ++i)
	{
		delete matrix[i];
		matrix[i] = new int[maxVertices](); // The parenthesis will initialize the array to 0
	}
	numOfVertices = 0;
}

// Definition of destructor
Graph::~Graph()
{
	delete[] vertices;
	vertices = nullptr;

	for (int i = 0; i < maxVertices; ++i)
	{
		delete matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;

	numOfVertices = 0;
}


// Definition function bfsTraversal
void Graph::bfsTraversal(char vertex, vector<char>& bfs) const
{
	// if numOfVertices == 0 or less than 0 then do nothing.
	if (numOfVertices > 0)  
	{
		if (numOfVertices == 1)
		{
			bfs.push_back(vertex);
		}
		else  
		{
			queue<int> bfsQueue;
			// Dynamic array of visited vertices.
			// Sets to true if index of the vertex has been visited.
			bool* visited = new bool[numOfVertices](); 
			// Finds the index of the char vertex.
			int index = 0;
			while (!visited[index])
			{
				if (vertices[index] == vertex)
					visited[index] = true;
				else
					++index;
			}
			// Pushes the index of the first vertex into the queue.
			bfsQueue.push(index);
			int visitedCounter = 1; 

			// This loops until all vertexes are in the BFS.
			do
			{
				index = bfsQueue.front();
				bfs.push_back(vertices[index]);
				// Won't traverse anymore if all vertices has already been added to the queue.
				if (visitedCounter != numOfVertices) 
				{
					int col = index;
					// Traverse through the matrix and search for the successors of the bfsQueue.front();
					for (int row = 0; row < numOfVertices; ++row)
					{
						// If this condition is true, add the index of vertex in the queue
						// row == successor's index
						if ((matrix[row][col] == 1) && (!visited[row])) 
						{
							bfsQueue.push(row);
							++visitedCounter;
							visited[row] = true;
							// This condition will force stop the for loop if it's true.
							if (visitedCounter == numOfVertices)
								row = numOfVertices;
						}
					}
				}
				bfsQueue.pop();
			} while (!bfsQueue.empty());
			delete[] visited;
		}
	}
}
