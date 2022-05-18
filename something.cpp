#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
    public:
    vector<int> adj;
    bool isVisited = false;
    int index;
    int distance;
    int data;
};

class Graph{
    public:
    vector<Node*> nodes;
    bool isOdd = false;
    int max_distance = -1;

    Node* addNode(int data);
    void addEdge(Node* start, Node* end);

    void DFS(Node* currentNode, Node* previousNode);
};


void Graph::DFS(Node* currentNode, Node* previousNode){

    currentNode->isVisited = true;

    if(previousNode != nullptr){
        currentNode->distance = previousNode->distance + 1;

        if(max_distance < currentNode->distance){
            max_distance = currentNode->distance;
        }
    }

    if(currentNode->data%2 != 0){
        isOdd = true;
    }

    for(int i = 0; i < currentNode->adj.size(); i++){

        if(currentNode->data == 0){
            isOdd = false;
        }

        auto cn = nodes[currentNode->adj[i]];

        if(isOdd && cn->data%2 != 0){
            continue;
        }

        if(!cn->isVisited){
            DFS(cn, currentNode);
        }

    }
}

int main(){



}


