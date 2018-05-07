#ifndef MaxFlow_H
#define MaxFlow_H

#include<map>
#include<vector>
#include<iostream>
#include<queue>
#include<limits.h>

using namespace std;


class Graph{
	private:
		int arr_size;
		int num_points;
		enum color_t{
  			WHITE, GRAY, BLACK
		};
	
		struct Edge{
			int capacity;
			int residual;
		};
		Edge **edges;
		//vector<vector<Edge>> edges;

		map<int, std::vector<int>> V;
		map<int, int> parent;
		map<int, int> distance;
		map<int, color_t> color;
		queue<int> Q;	// holds all gray vertices
	
		bool BFS (int s, int t);// returns true if path from s to t
	public:
		void resize(int);
		void addEdge(int,int, int); // add directed edge to the graph,
		int findMaxFlow(int, int);// Ford-Fulkerson Algorithm
		Graph(int n){
			arr_size = n;
			edges = new Edge*[n];
			for (int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					edges[i] = new Edge[n];
					edges[i][j].residual = -1;	
				}
			}
			num_points = 0;	
		}
	~Graph(){
		delete edges;	
	}
	
};

#endif