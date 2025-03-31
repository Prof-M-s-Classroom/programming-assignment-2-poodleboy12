[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Beigehon Talebzadeh]`  
### **Student ID:** `[824866530]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
My RPG game is about a pet and the way it behaves. 
The decision tree in the story.txt talks about how the pet is either a dog or a cat. 
Also talks about whether the pet is friendly or not. 
If the pet is not friendly, it explains why the dog or cat is not friendly. 
If the pet is friendly, it explains why the dog and cat is friendly. 
The game finishes when you get to a leaf node when you left and right children are -1 or if the game tells you your only option is to go right or left but go the opposite direction.
Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function] `The myGame GameDecisionTree template is declared. 
 You declare the filename and decide which file you will use, same thing with the delimiter. 
 Then you load the story data from the file which is the delimiter and filename. 
 Then myGame starts playing the game.
- **`GameDecisionTree.h`** → `[Explain what this file contains] `
 Template class GameDecisionTree, declares the node template pointer root treated as the head. 
 You start with the loadStoryFromFile method after getting your inputs of the filename and delimiter.
 Then uses the input stream to open the ReadFile to access input from the ReadFile. 
 Then declares a vector with variable T called vectorName and string variable line. 
 Then in your GameDecisionTree template class, you declare a string variable named line to access every line in the inputstream with ReadFile. 
 Then use the index variable to find the index of the delimiter for the line.
 Uses substrings to get the word by putting the delimiter's index to avoid printing the delimiter.
 Depending on whether the variable for the value is integer I use atoi to convert the word to a array to get the character so I convert it to a number.
 If it is a string variable I go straight into substring. 
 Then your Story object as type T s with your one string argument and three integer arguments gets mapped into the reference variable for Story s parameter's as their values. 
 Then adds the reference variable for that specific line for each vectorName index. 
 After the loop finishes collecting all the lines in story.txt for all the vectorName indexes after getting rid of the delimiters, you close the ReadFile file. 
 Then you create an unordered map of events and node pointers. 
 Then initialize root with key value 1. 
 Then with um filled in I go to buildTree starting at event 1. 
 Then assign current to the UM index. 
 Then see if there is no children then I exit the buildTree method. 
 Else if you recursively add the children for those events for the right and left child. 
 For the special case it has more than one parent because it is the same type of behavior after it reaches it no matter what your nodes were before. 
 In the playGame method you declare a currentNode type T template Node pointer and initialize it to the root node. 
 Then you keep looping through the while loop until currentNode becomes nullptr. 
 Inside the loop the currentNode template pointer object points to T type object data of description to print the current node's sentence. 
 Then does a if condiiton to see whether the currentNode template pointer object points to T type object data of leftEventNumber and rightEventNumber are -1 to exit the while loop if those two are -1. 
 Otherwise you keep going with your program by declaring a integer variable called path and then you get an integer input for your path of 1 to go left and 2 to go right otherwise you have to try again because you won't go anywhere. 
 Also if a node says go left only or right only but you decide to go the opposite direction your currentNode becomes nullptr and your game is over.
- **`Node.h`** → `[Explain what this file contains]  
 `The entire Node template class is public except for endif, NODE_H. 
 Declares the type T data. 
 Then declares node pointers left and right for them to hold data.
 Also declares a Node constructor with a parameter as a type declared as T value which inside initializes data which contains a value for a node to hold and initializes node pointers left and right to nullptr.
- **`Story.h`** → `[Explain what this file contains] 
 `The entire Story class is public except for endif, STORY_H. 
 Declares string variable description and int variables eventNumber, leftEventNumber, and rightEventNumber. 
 Also declares a Story default constructor and a Story parameterized constructor with parameters string desc, int num, int leftNum, and int rightNum.
- **`story.txt`** → `[Explain how the game loads story events from this file] `
 Uses the input stream to open the ReadFile to access input from the ReadFile. 
 Then in your GameDecisionTree template class, you declare a string variable named line to access every line in the inputstream ReadFile then use the index variable to find the index of the delimiter for the line.
 Uses substrings to get the word by putting the delimiter's index to avoid printing the delimiter and depending on whether the variable for the value is integer you use atoi to convert the word to a array to get the character so you convert it to a number and if it is a string variable you go straight into substring.

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file? 
 Each line is read getting the four values. 
 I used the constructor T s(secondValue, firstValue, thirdValue, fourthValue) to declare the Story object from the data read from the text file. 
- How are nodes linked based on left and right event numbers? 
 The 1st node has a left child leftEventNumber of 2 and a right child rightEventNumber of 3. 
 The 2nd node has a left child leftEventNumber of 4 and a right child rightEventNumber of 5. 
 The 3rd node has a left child leftEventNumber of 5 and a right child rightEventNumber of 6. 
 The fourth node is a leaf node without children. 
 The fifth node has a left child leftEventNumber of 7 and a right child rightEventNumber of 8. 
 The 6th node has a left child leftEventNumber of 9 and a right child rightEventNumber of 10. 
 The seventh node has a left child leftEventNumber of 11 and right child rightEventNumber of 12. 
 The eighth node has a left child leftEventNumber of 13 and a right child rightEventNumber of 14. 
 The ninth node has a left child leftEventNumber of 15 and a right child rightEventNumber of 16. 
 The tenth node is a leaf node. 
 The eleventh node has a left child leftEventNumber of 17. 
 The twelfth node has a right child rightEventNumber of 18. 
 The thirteenth node is a leaf node. 
The fourteenth node has a right child rightEventNumber of 19. 
The fifteenth node has a right child rightEventNumber of 20. 
The sixteenth node has a right child rightEventNumber of 21. 
The seventeenth node is a leaf node. 
The eighteenth node is a leaf node. 
The nineteenth node is a leaf node. 
The 20th node is a leaf node. 
The 21st node is a leaf node.
- What happens if an event has `-1` as left or right children? 
 If both events have children that are -1 then the node will print the description and the loop will end then print game over. 
If a node has one of the children as -1, you go the path it tells you otherwise your currentNode becomes nullptr and the while loop terminates then ends the game.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  If your node has two children the integer input path is 1 it goes left and if it is 2 it goes right, otherwise you have to try again. If the node has one child it has to go the path the one child is otherwise it terminates.
- What happens when the player reaches a leaf node? You print the leaf node's statement then both children are -1 so it exits the while loop according to the if branch.
- Explain the special case where multiple events lead to the same outcome. The 5th node the special case explains the same reason why both cats are dogs are friendly for same reasons. Because the 1st node just asks what pet you have for both of them, then the 5th node's parent whether it is a cat or dog then it answers why it is friendly. 

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter? 
 I declare an index variable to find the delimiter's index to hold the index.
 Then you use word to collect the statement before the delimiter with a substring also depending whether it is a string variable you leave it at substring.
 But if it is a integer variable you use the atoi method to convert it from a string to an integer and you do it around every delimiter in the sentence.
- How do you ensure nodes are properly linked? 
 For every node you recursively add its children. 
 Starting at the root you know that you'll reach every ancestor of the root will be reached.  
- Any challenges faced while handling file input? 
 I got mixed up with the substring syntax from java compared to C++ and fixed the syntax to C++. 
 I also struggled at first figuring out what the Story object was. 

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
I first got mixed up that the Story constructor and Node constructor got initialized, so I accidentally assigned for example description to itself description. 
I got mixed up with the substring syntax from java compared to C++ which was giving us a memory leak and fixed the syntax to C++. 
I also lost track of how many braces they were at first so I just ignored the braces for branches with one line so it was easier to keep track of the braces. 
I also struggled at first figuring out what the Story object was.
Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
The integer variable path collects input of an integer. 
If path equals 1 you go to the left child, else if path equals 2 you go to the right child, and else you have to try again because you don't go anywhere. 
Your on your first node asks choose your pet.
You choose to go to path 1 a cat which is node 2 
Then again you choose to go to path 1 which is node 4 which describes the cat's behavior as selfish.
Since it is a leaf node it exits the program.
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n) because the while loop iterates N times and same thing for the two for loops iterate N times and the sum of them is 3N which coefficients don't matter and becomes N.`  
- **Searching for an event in the tree** → `O(1) because I used the unordered map that has a key value pair that points you directly to that event.`  
- **Game traversal efficiency** → `O(n) because the while loop iterates N times.`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
I tested the situation where a node has one child so I could go one path but then tested it going the opposite path then made sure to the game ended because the currentNode became nullptr.
Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)
I created an unordered map of events and node pointers.
Then I used the built-in method to insert to add the events and node pointers. 
Then initialize root with key value 1. 
Then with um filled in you go to buildTree starting at event 1. 
Then I assign current to the UM index. 
Then I see if there is no children then you exit the buildTree method. 
Else if you recursively add the children for those events for the right and left child. 
For the special case it has more than one parent because it is the same type of behavior after it reaches it no matter what your nodes were before.

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
