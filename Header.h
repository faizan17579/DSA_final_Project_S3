#pragma once
#include <iostream>
class node {
public:
char data;
node* next;
node();
node(char x);

};
class vertex {
public:
	node* head;
	vertex();
};
class queue;
class stack;
class stacknode;
class filenode;
class filestack;
class treenode;
class BSTtree;
class graph {
public:
int score;
int size;
vertex** maze;
graph();
graph(int x);
void createMaze();
void printMaze();
int  createpath(int n,int x,int y);
void addEdge(int x, int y,int x2,int y2,char z);
void removeEdge(int x, int y, int x2, int y2);
queue movecar(queue q,stack *s,stack *h,int le,string nm,int pa,int level);
queue movecarresume(queue q, stack* s, stack* h, int le, string nm,int xr,int yr,int pa,int levl);
queue addobstacle(int x,int y,queue q,char p,int l);
void addcoin(int x, int y,char p);
void addcoinauto(int x, int y, char p);
void stats(stack s,string name,int sc);
void displayandsavetopscorer();
void addpathauto();
queue addobstaclelevelauto(int x, int y, queue q);
queue autosolve(queue q, stack* s, stack* h);

};
class stacknode {
public:
	char data;
    stacknode* next;
   stacknode();
   stacknode(char x);
};
//stack to store health or collectables
class stack {
public:
	stacknode* top;
	stack();
   void push(char x);
	char pop();
	void remove(char x);
	int calculate();
	bool search(char x);
	bool isEmpty();
	void emptystack();
	void print();
	void calc();
	

	
};
class queuenode {
public:
	char data;
    queuenode* next;
    queuenode();
    queuenode(char x);
};
//queue to store obstacles
class queue {
public:
	queuenode* front;
	queuenode* rear;
	char frontelement();
	queue();
	void enqueue(char x);
	char dequeue();
	
	bool isEmpty();
	
};

class filenode {
public:
	string name;
	int score;
	filenode* next;
	filenode();
	filenode(string x,int y);
};
//filelist to store top scorer
class filelist {
public:
	filenode* head;
	filelist();
	void add(string x,int y);
	void sort();
};
class treenode {
	public:
	string name;
	int score;
	treenode* left;
	treenode* right;
	treenode();
	treenode(string n,int x);
};
//tree to store top scorer
class BSTtree {
	
	public:
		BSTtree();
		treenode* root;
		void insert(string n,int x);
		void inorder(treenode* root);
		void inorder();

};



