#include "MaxFlow.h"
#include <iostream>
#include <chrono>
#include <time.h>  

using namespace std;

int main(){
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds;
	std::time_t end_time; 
	
	Graph g(20);	//create graph with n edges
	
	//addEdge(1st point, 2nd point, capacity)
	
	//models the graph from https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
	g.addEdge(0,1,16);
	g.addEdge(0,2,13);
	g.addEdge(1,2,10);
	g.addEdge(2,1,4);
	g.addEdge(1,3,12);
	g.addEdge(2,4,14);
	g.addEdge(3,2,9);
	g.addEdge(4,3,7);
	g.addEdge(3,5,20);
	g.addEdge(4,5,4);

	


	
	cout <<"Finding Maximum Flow..." << endl;
	start = std::chrono::system_clock::now();
	cout << "The Maximum Flow is: " << g.findMaxFlow(0,5) << endl;	//find max flow from s to t
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	end_time = std::chrono::system_clock::to_time_t(end);
	std::cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	
}