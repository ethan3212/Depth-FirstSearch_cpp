#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string name;
    vector<Node *> children;

    Node(string str) {
        name = str;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }

    vector<string> depthFirstSearch(vector<string> *array) {
        array->push_back(this->name);
        for(int i = 0;  i < this->children.size(); i++) {
            children[i]->depthFirstSearch(array);
        }
        return *array;
    }
};

int main() {
    Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");
    vector<string> array;
    vector<string> output = graph.depthFirstSearch(&array);
    for(string letter : output) {
        cout << letter << " ";
    }
    return 0;
}
