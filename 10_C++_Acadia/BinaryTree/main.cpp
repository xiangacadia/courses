//
//  main.cpp
//  BinaryTree
//
//  Created by Xiang Jiang on 2014-10-21.
//  Copyright (c) 2014 Xiang Jiang. All rights reserved.
//

#include "TreeSet.h"

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Start testing" << endl;
    
    cout << "*******************************" << endl;
    cout << "Adding strings" << endl;
    
    TreeSet mset;
    
    cout << "Adding characters d,g,b,h,e,c,a" << endl;
    
    mset.add("d");
    mset.add("g");
    mset.add("b");
    mset.add("h");
    mset.add("e");
    mset.add("c");
    mset.add("a");
    
    string str[7];
    mset.toArray(str);
    cout << "The result is:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    
    if (str[0]=="d" && str[1]=="b" && str[2]=="a" && str[3]=="c" && str[4]=="g" && str[5]=="e" && str[6]=="h") {
        cout << "--Succeed--: building network" << endl;
    }
    else{
        cout << "--Failed--: building network" << endl;
    }
    
    
    cout << "*******************************" << endl;
    cout << "Removing root node 'd' " << endl;
    mset.remove("d");
    mset.toArray(str);
    
    
    cout << "The result is:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    
    if (str[0]=="c" && str[1]=="b" && str[2]=="a" && str[3]=="g" && str[4]=="e" && str[5]=="h") {
        cout << "--Succeed--: Removing root node 'd'" << endl;
    }
    else{
        cout << "--Failed--: Removing root node 'd'" << endl;
    }
    
    cout << "*******************************" << endl;
    cout << "Checking whether 'd' is in the Tree " << endl;

    
    if (mset.contains("d") == false ) {
        cout << "--Succeed--: Checking the existance of 'd'" << endl;
    }
    else{
        cout << "--Failed--: Checking the existance of 'd'" << endl;
    }
    
    cout << "*******************************" << endl;
    cout << "Removing node 'g'" << endl;
    mset.remove("g");
    mset.toArray(str);
    cout << "The result is:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    if (str[0]=="c" && str[1]=="b" && str[2]=="a" && str[3]=="e" && str[4]=="h") {
        cout << "--Succeed--: Removing root node 'g'" << endl;
    }
    else{
        cout << "--Failed--: Removing root node 'g'" << endl;
    }
    
    cout << "*******************************" << endl;
    cout << "Checking whether 'g' is in the Tree " << endl;
    
    
    if (mset.contains("g") == false ) {
        cout << "--Succeed--: Checking the existance of 'g'" << endl;
    }
    else{
        cout << "--Failed--: Checking the existance of 'g'" << endl;
    }
    
    cout << "*******************************" << endl;
    cout << "Checking whether 'h' is in the Tree " << endl;
    
    
    if (mset.contains("h") == true ) {
        cout << "--Succeed--: Checking the existance of 'h'" << endl;
    }
    else{
        cout << "--Failed--: Checking the existance of 'h'" << endl;
    }
    
    cout << "*******************************" << endl;
    cout << "Checking whether 'e' is in the Tree " << endl;
    
    
    if (mset.contains("e") == true ) {
        cout << "--Succeed--: Checking the existance of 'e'" << endl;
    }
    else{
        cout << "--Failed--: Checking the existance of 'e'" << endl;
    }

    cout << "*******************************" << endl;
    cout << "Checking the size of the Tree " << endl;
    cout << "The size of the tree is:" << mset.size() << endl;
    if (mset.size() == 5 ) {
        cout << "--Succeed--: The size of the tree is correct" << endl;
    }
    else{
        cout << "--Failed--: The size of the tree is incorrect" << endl;
    }
    
    cout << "*******************************" << endl;
    cout << "Checking whether the tree is empty " << endl;
    if (mset.isEmpty() == false ) {
        cout << "--Succeed--: The checking for tree is correct" << endl;
    }
    else{
        cout << "--Failed--: The checking for tree is incorrect" << endl;
    }

    cout << "*******************************" << endl;
    cout << "Clear the tree" << endl;
    mset.clear();
    if (mset.isEmpty() == true ) {
        cout << "--Succeed--: The delete of the tree is correct" << endl;
    }
    else{
        cout << "--Failed--: The delete of the tree is incorrect" << endl;
    }

    
    return 0;
}
