#pragma once
#ifndef THIS_HEADER_H
#define THIS_HEADER_H

#include<iostream>
using namespace std;

//Binary tree node.
template<typename T>
struct BinaryTreeNode {
	T data;
	struct *lchild, *rchild;
};

template<typename T, int N>
class BinaryTree {
private:
	BinaryTreeNode<T> *RootNode;
public:
	BinaryTree() {};
	//Initialize a binary tree using a list. 
	//rootnode: specifies the value for a root node.
	//type: "RLD" (preorder), "LDR" (in-order), "LRD" (post-order)
	BinaryTree(T(&values)[N], T rootnode, string type) {
		this->RootNode = new BinaryTreeNode<T>();
		switch (type)
		{
		case "RLD":

		case "LDR":

		case "LRD":

		default:
			cout<<"Please provide type=\"RLD\", or \"LDR\", or \"LRD\"."<<endl;
			break;
		}
	}
};

#endif