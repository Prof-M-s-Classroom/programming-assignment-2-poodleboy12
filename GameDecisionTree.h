#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <cstdlib>
using namespace std;
template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    void buildTree(unordered_map<int, Node<T>*> um, int index){
        Node<T> * current = um[index];
        if (current->data.leftEventNumber == -1 && current->data.rightEventNumber == -1) {
            return;
        }
        if (current->data.leftEventNumber != -1 && current->left == nullptr) {
            current->left = um[current->data.leftEventNumber];
            buildTree(um, current->data.leftEventNumber);
        }
        if (current->data.rightEventNumber != -1 && current->right == nullptr) {
            current->right = um[current->data.rightEventNumber];
            buildTree(um, current->data.rightEventNumber);
        }
    }
public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {

    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter){

        cout << "Opening file" << endl;
        ifstream ReadFile(filename);
        if (!ReadFile.is_open()) {
            cout << "Error message, didn't open" << endl;
            return;
        }
        vector<T> vectorName;
        string line;
        while (getline(ReadFile, line)) {
           // cout << line << endl; // Replace this cout to delimit to break up the 4 pieces to make its class story.
           int index = line.find(delimiter);
           string word = line.substr(0, index);
           int firstValue = atoi(word.c_str());
           int nextIndex = index + 1;
           index = line.find(delimiter, nextIndex);
           string secondValue = line.substr(nextIndex, index - nextIndex);
           nextIndex = index + 1;
           index = line.find(delimiter, index + 1);
           word = line.substr(nextIndex, index - nextIndex);
           int thirdValue = atoi(word.c_str());
           nextIndex = index + 1;
           word = line.substr(nextIndex);
           int fourthValue = atoi(word.c_str());
           T s(secondValue, firstValue, thirdValue, fourthValue); // Story object. You need to make Story and map it to T.
           // Make the Story object and map it to T, then store inside the value for Node, and then build the tree.

           vectorName.push_back(s);
        }
        // What T is? The template type for the game decision tree. We sort of know this is a story.
        // Should not be a T vector.
        ReadFile.close();
        unordered_map<int, Node<T> *> um; // the * pointer to a node.
        for (int i = 0; i < vectorName.size(); ++i) {
            um.insert(make_pair(vectorName[i].eventNumber, new Node<T> (vectorName[i])));
        }
       for (const auto& currentEvent : vectorName) {
           um[currentEvent.eventNumber] = new Node<T>(currentEvent);
       }
        root = um[1]; // key value pair 1, not a index of an array.
        buildTree(um, 1);

        /* Debugging passing the delimiter as a parameter instead of hard-coding it. */
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){
        Node<T>* currentNode = root;

        while (currentNode != nullptr) {
            cout << currentNode->data.description << endl;
            // If both left and right children are -1, it's a leaf node
            if ((currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1)) {
                break;
            }

            // Player chooses a path.
            int path;
            cout << "Enter path: ";
           cin >> path;

            if (path == 1)
                currentNode = currentNode->left;
             else if (path == 2)
                currentNode = currentNode->right;
             else
                cout << "Error. Try again." << endl;


        }
        cout << "Game Over!" << endl;
    }
};

#endif // GAMEDECISIONTREE_H