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
        if (current->data.leftEventNumber != -1) {
            current->left = um[current->data.leftEventNumber];
            buildTree(um, current->data.leftEventNumber);
        }
        if (current->data.rightEventNumber != -1) {
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
           index = line.find(delimiter, index + 1);
           string secondValue = line.substr(nextIndex, index);
           nextIndex = index + 1;
           index = line.find(delimiter, index + 1);
           word = line.substr(nextIndex, index);
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

        root = um[1]; // key value pair 1, not a index of an array.
        buildTree(um, 1);

       /*  while (node != nullptr) { // Start traversing the tree
          // use atoi
// concept for building the tree is the picture you took, character read character by character and stringstream start appending it. read it character by character.
// also you have to know whether to go left or right and no backtracking.
// havent built it because the story class object isnt there.
        } */
        /* Debugging passing the delimiter as a parameter instead of hard-coding it. */
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){
      ifstream File("story.txt");
      string instruction;
      while(getline(File, instruction)) {
          cout << instruction << endl;

      }
       File.close();



    }
};

#endif // GAMEDECISIONTREE_H