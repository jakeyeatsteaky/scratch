#include <iostream>
#include <vector>
#include <set>

std::vector<int> dijkstras(int start, std::vector<std::vector<std::vector<int>>> edges);
int minNodes(std::vector<int> *shortestPaths, std::set<int> visited);

int main (int argc, char** argv){
    int start = 1;
    std::vector<std::vector<std::vector<int>>> edges = {
        {{1,2}},
        {{0,1}},
        {{3,1}},
        {{2,2}}
    };
    std::vector<int> distanceFromStart = dijkstras(start, edges);
}

std::vector<int> dijkstras(int start, std::vector<std::vector<std::vector<int>>> edges){
    int size = edges.size();
    std::set<int> visitedNodes = {};
    std::vector<int> shortestPaths(size, INT_MAX);
    shortestPaths[start] = 0;
    int nextNode;

    while(visitedNodes.size() < edges.size()){
        nextNode = minNodes(&shortestPaths, visitedNodes);
        visitedNodes.insert(nextNode);
        for(int i = 0; i < edges[nextNode].size(); i++){
            // if the outgoing node from nextNode is already in visitedNodes, we can continue;
            std::set<int>::iterator it = visitedNodes.find(edges[nextNode][i][0]);
            if(it != visitedNodes.end())
                continue;
            int outgoingNodeDistance = edges[nextNode][i][1];
            int distanceFromStart = outgoingNodeDistance + shortestPaths[nextNode];
            if(distanceFromStart < shortestPaths[edges[nextNode][i][0]] && shortestPaths[nextNode] != -1)
                shortestPaths[edges[nextNode][i][0]] = distanceFromStart;
        }
    }
    return shortestPaths;
}

int minNodes(std::vector<int> *shortestPaths, std::set<int> visited){
    int shortest = INT_MAX - 1;
    int node = -1;
    for(int i = 0; i < shortestPaths->size(); i++){
        std::set<int>::iterator it = visited.find(i);
        if(it == visited.end()){
            if((*shortestPaths)[i] < shortest){
                shortest = (*shortestPaths)[i];
                node = i;
            }
        }
    }

    if(node < 0){
        for(int i = 0; i < shortestPaths->size(); i++){
        std::set<int>::iterator it = visited.find(i);
        if(it == visited.end()){
            if((*shortestPaths)[i] == INT_MAX){
                (*shortestPaths)[i] = -1;
                return i;
            }
        }
    }
    }
    return node;
}