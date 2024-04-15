// Purpose: This file contains the main function of the program.
// Faizan Rasheed 22i-2734
// Zaid Masood 22i-8793
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <chrono>
using namespace std;
#include "Header.h"
#include <fstream>
#include <sstream>
//constructor of node
node::node() {
	data = '\0';
	next = NULL;
}
node::node(char x) {
	data = x;
	next = NULL;
}
//constructor of vertex containing head of node
vertex::vertex() {

	head = NULL;
}
//constructor of graph containing maze and size of maze
graph::graph() {
	score = 0;
	size = 0;
	maze = NULL;
}
graph::graph(int x) {
    score = 0;
	size = x;
	maze = NULL;
}
//constructor of stacknode used to create stack
stacknode::stacknode() {
	data = '\0';
	next = NULL;
}
stacknode::stacknode(char x) {
	data = x;
	next = NULL;
}
//constructor of stack containing top of stack and used to take eye on score or collectables
stack::stack() {
top = NULL;

}
// push function used to push data in stack
void stack::push(char x) {
	stacknode* n = new stacknode(x);
	if (top == NULL) {
		top = n;
	}
	else {
		n->next = top;
		top = n;
	}
}
//pop function used to pop data from stack
char stack::pop() {
	stacknode* temp = top;
	top = top->next;
	return temp->data;
}
//function to print stack
void stack::print() {
	stacknode* temp = top;
	cout << setw(121);
	while (temp) {
		cout<<temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//function to search data in stack
bool stack::search(char x) {
	stacknode* temp = top;
	while (temp) {
		if (temp->data == x) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}
//function to empty stack
void stack::emptystack() {
	top = NULL;
}
//function to remove data from stack
void stack::remove(char x) {
	stacknode* temp = top;
	stacknode* temp2 = top->next;
	if (top->data == x) {
		top = top->next;
	}
	else {
		while (temp2) {
			if (temp2->data == x) {
				temp->next = temp2->next;
				break;
			}
			temp = temp->next;
			temp2 = temp2->next;
		}
	}

}
//function to calculate score
int stack::calculate() {
	stacknode* temp = top;
	int c = 0;
	while (temp) {
		if (temp->data == '$') {
			c++;
		}
		else if (temp->data == '?') {
			c++;
		}
		else if (temp->data == '*') {
			c++;
		}
		temp = temp->next;
	}
	return c;
}
//function to check stack is empty or not
bool stack::isEmpty() {
	if (top == NULL) {
		return true;
	}
	else {
		return false;
	}
}

// function to calculate num of collectables
void stack::calc() {
	int c1=0;
    int c2=0;
	int c3 = 0;
	stacknode* temp = top;
	while (temp) {
		if (temp->data == '$') {
			c1++;
		}
		else if (temp->data == '?') {
			c2++;
		}
		else if (temp->data == '*') {
			c3++;
		}
		temp = temp->next;
	}
	cout<<"Coins $: "<<c1<<endl;
    cout<<"Trophies ?: "<<c2<<endl;
	cout <<"Igniter *: " << c3 << endl;

}
// constrructor of treenode
treenode::treenode() {
	name = " ";
	score = 0;
	left = NULL;
	right = NULL;
}
// constructor of treenode containing name and score
treenode::treenode(string x, int y) {
	name = x;
	score = y;
	left = NULL;
	right = NULL;
}
//constructor of BSTtree
BSTtree::BSTtree() {
	root = NULL;
}
//function to insert data in BSTtree
void BSTtree::insert(string x, int y) {
	treenode* n = new treenode(x, y);
	if (root == NULL) {
		root = n;
	}
	else {
		treenode* temp = root;
		while (temp) {
			if (y < temp->score) {
				if (temp->left == NULL) {
					temp->left = n;
					break;
				}
				else {
					temp = temp->left;
				}
			}
			else if (y > temp->score) {
				if (temp->right == NULL) {
					temp->right = n;
					break;
				}
				else {
					temp = temp->right;
				}
			}
			else {
				break;
			}
		}
	}
}
void BSTtree::inorder() {
	inorder(root);
}
//function to print inorder traversal of BSTtree
void BSTtree::inorder(treenode* root) {
	static int c = 1;
	if (root == NULL) {
		return;
	}
	else {
		inorder(root->right);
		cout << "                                         "<<c<< ": "<<root->name << "        " << root->score << endl;
		c++;
		inorder(root->left);
	}
}

//constructor of filenode for filelist
filenode::filenode() {
	name = " ";
    score = 0;
	next = NULL;
}
filenode::filenode(string x,int y) {
	name = x;
	score = y;
	next = NULL;
}
//constructor of filelist
filelist::filelist() {
	head= NULL;
}
//function to add data in filelist

void filelist::add(string x,int y) {
	filenode* n = new filenode(x,y);
	if (head == NULL) {
		head = n;
	}
	else {
		filenode* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
	}
}
//function to sort filelist
void filelist::sort() {
	filenode* temp = head;
	while (temp) {
		filenode* temp2 = temp->next;
		while (temp2) {
			if (temp->score < temp2->score) {
				string x = temp->name;
				int y = temp->score;
				temp->name = temp2->name;
				temp->score = temp2->score;
				temp2->name = x;
				temp2->score = y;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}

}

char queue::frontelement() {
	return front->data;
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// function to creatw maze
void graph::createMaze() {
	
	maze=new vertex*[size];
for (int i = 0; i < size; i++) {
		maze[i] = new vertex[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <size; j++) {
			
			maze[i][j].head = new node('.');

		}
	}
	maze[0][size - 1].head->data = 'E';

}
static int step = 0;

// function to print maze
void graph::printMaze() {
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << endl;

	cout << endl;
	cout << "                  Score: " << score <<"                                                                      "<<"                    Steps: "<<step<<endl;
	//SetConsoleTextAttribute(hConsole, BACKGROUND_RED);

	cout << "                                                +---------------------------------------------------------+" << endl;
	
	for (int i = 0; i < size; i++) {
		cout << "                                                |";
		
		
		for (int j = 0; j < size; j++) {
			
		     setColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			if (maze[i][j].head->data == '\0') {
				
				// Change background color to blue
				
				cout << " ";
				
				
			}
			
			else if (maze[i][j].head->data == '?') {
				setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else if (maze[i][j].head->data == '@' || maze[i][j].head->data == '#') {
				setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			else if (maze[i][j].head->data == '$') {
				setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else if (maze[i][j].head->data == '+') {
				//SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else if (maze[i][j].head->data == '*') {
				setColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			else if (maze[i][j].head->data == '.') {
				

				
			setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else if (maze[i][j].head->data == 'C') {
				setColor(FOREGROUND_GREEN);
				
			}
			
			cout << maze[i][j].head->data<<"  ";
			
			
			
		}

		setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "|" << endl;
	}

	cout << "                                                +---------------------------------------------------------+" << endl;
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
// function to create path using add edge func  in graph
int graph::createpath(int n,int x,int y) {
	bool flag = false;
	//path 1
	int i=0;
	int j=0;
	int ra = 0;
	if(n==0){
		flag=true;
		i = size - 1;
		j = size /2;
		maze[i][j].head->data = 'C';
		
		srand(time(0));
		ra = 1 + (rand() % 3);
	}
	else if (n == 1) {
		 i = size-1;
		 j = size/2;
		  ra = 1 ;

		
	}
	else if (n == 2) {
		  i= size-1;
		  j = size/2;
		 
		  ra = 2 ;

		
	}
	else if (n == 3) {
		 i = size-1;
		 j = size/2;
		 maze[x][y].head->data = 'C';

		 ra = 3;;
		
	}

 
;
	if (ra == 1) {
		//main path
		addEdge(i, j, i, j - 1, '\0');
		addEdge(i, j, i, j - 2, '\0');
		addEdge(i, j, i, j - 3, '\0');
		addEdge(i, j, i, j - 4, '\0');
		addEdge(i, j, i - 1, j - 4, '\0');
		addEdge(i, j, i - 2, j - 4, '\0');
		addEdge(i, j, i - 3, j - 4, '\0');
		addEdge(i, j, i - 4, j - 4, '\0');
		addEdge(i, j, i - 4, j - 3, '\0');
		addEdge(i, j, i - 4, j - 2, '\0');
		addEdge(i, j, i - 4, j - 1, '\0');
		addEdge(i, j, i - 4, j, '\0');
		addEdge(i, j, i - 4, j + 1, '\0');
		addEdge(i, j, i - 4, j + 2, '\0');
		addEdge(i, j, i - 4, j + 3, '\0');
		addEdge(i, j, i - 4, j + 4, '\0');
		addEdge(i, j, i - 5, j + 4, '\0');
		addEdge(i, j, i - 6, j + 4, '\0');
		addEdge(i, j, i - 7, j + 4, '\0');
		addEdge(i, j, i - 8, j + 4, '\0');
		addEdge(i, j, i - 9, j + 4, '\0');
		addEdge(i, j, i - 10, j + 4, '\0');
		addEdge(i, j, i - 11, j + 4, '\0');
		addEdge(i, j, i - 12, j + 4, '\0');
		addEdge(i, j, i - 13, j + 4, '\0');
		addEdge(i, j, i - 14, j + 4, '\0');
		addEdge(i, j, i - 14, j + 5, '\0');
		addEdge(i, j, i - 14, j + 6, '\0');
		addEdge(i, j, i - 15, j + 6, '\0');
		addEdge(i, j, i - 15, j + 7, '\0');
		addEdge(i, j, i - 15, j + 8, '\0');
		addEdge(i, j, i - 15, j + 9, '?');
		addEdge(i, j, i - 16, j + 9, '\0');
		addEdge(i, j, i - 17, j + 9, '\0');
		maze[18][4].head->data = '+';
		maze[17][6].head->data = '+';
		maze[15][6].head->data = '+';
		maze[15][4].head->data = '+';
		maze[13][3].head->data = '+';
		maze[13][9].head->data = '+';
		maze[13][7].head->data = '+';
		maze[13][12].head->data = '+';
		maze[11][3].head->data = '+';
		maze[11][9].head->data = '+';
		maze[11][7].head->data = '+';
		maze[5][14].head->data = '+';
		maze[4][16].head->data = '+';
		maze[3][14].head->data = '+';
		maze[2][17].head->data = '+';
		maze[2][12].head->data = '+';
		maze[1][10].head->data = '+';
		maze[1][9].head->data = '+';
		maze[0][7].head->data = '+';
		maze[9][7].head->data = '+';
		maze[9][9].head->data = '+';
		maze[9][10].head->data = '+';
		maze[7][9].head->data = '+';
		maze[7][10].head->data = '+';
		maze[5][9].head->data = '+';
		maze[5][10].head->data = '+';
	
		

		//alternate path(1)
		addEdge(14, 5, 14, 4, '\0');
		addEdge(14, 5, 14, 3, '\0');
		addEdge(14, 5, 14, 2, '\0');
		addEdge(14, 5, 13, 2, '\0');
		addEdge(14, 5, 12, 2, '\0');
		addEdge(14, 5, 11, 2, '\0');
		addEdge(14, 5, 10, 2, '\0');
		addEdge(14, 5, 10, 3, '\0');
		addEdge(14, 5, 10, 4, '\0');
		addEdge(14, 5, 10, 5, '\0');
		addEdge(14, 5, 10, 6, '\0');
		addEdge(14, 5, 10, 7, '\0');
		addEdge(14, 5, 9, 8, '\0');
		addEdge(14, 5, 8, 8, '\0');
		addEdge(14, 5, 7, 8, '\0');
		addEdge(14, 5, 6, 8, '\0');
		addEdge(14, 5, 5, 8, '\0');
		addEdge(14, 5, 4, 8, '\0');
		addEdge(14, 5, 3, 8, '\0');
		addEdge(14, 5, 2, 8, '\0');
		addEdge(14, 5, 1, 8, '\0');
		addEdge(14, 5, 0, 8, '\0');
		addEdge(14, 5, 0, 9, '\0');
		addEdge(14, 5, 0, 10, '\0');
		addEdge(14, 5, 0, 11, '\0');
		addEdge(14, 5, 0, 12, '\0');
		addEdge(14, 5, 0, 13, '\0');
		addEdge(14, 5, 0, 14, '\0');
		addEdge(14, 5, 0, 15, '\0');
		addEdge(14, 5, 0, 16, '\0');
		addEdge(14, 5, 0, 17, '\0');
		addEdge(14, 8, 13, 8, '\0');
		addEdge(14, 8, 12, 8, '?');
		addEdge(14, 8, 11, 8, '\0');
		addEdge(14, 8, 10, 8, '\0');

		//alternate path(2)
		addEdge(10, 7, 10, 8, '\0');
		addEdge(10, 7, 10, 9, '\0');
		addEdge(10, 7, 10, 10, '\0');
		addEdge(10, 7, 10, 11, '\0');
		addEdge(10, 7, 9, 11, '\0');
		addEdge(10, 7, 8, 11, '\0');
		addEdge(10, 7, 7, 11, '\0');
		addEdge(10, 7, 6, 11, '\0');
		addEdge(10, 7, 5, 11, '\0');
		addEdge(10, 7, 4, 11, '\0');
		addEdge(10, 7, 3, 11, '\0');
		addEdge(10, 7, 2, 11, '\0');
		addEdge(10, 7, 1, 11, '\0');
		addEdge(10, 7, 1, 12, '\0');
		addEdge(10, 7, 1, 13, '\0');
		addEdge(10, 7, 1, 14, '\0');
		addEdge(10, 7, 1, 15, '\0');
		addEdge(10, 7, 1, 16, '\0');
		addEdge(10, 7, 1, 17, '\0');
		addEdge(10, 7, 0, 17, '\0');
		addEdge(6, 8, 6, 9, '\0');
		addEdge(6, 8, 6, 10, '?');
		maze[13][13].head->data = '*';
		maze[10][2].head->data = '*';
		maze[3][8].head->data = '*';
		if (!flag) {
			maze[x][y].head->data = 'C';
		}


	}
	else if (ra == 2) {
		//main path
		addEdge(i, j, i, j + 1, '\0');
		addEdge(i, j, i, j + 2, '\0');
		addEdge(i, j, i, j + 3, '\0');
		addEdge(i, j, i, j + 4, '\0');
		addEdge(i, j, i - 1, j + 4, '\0');
		addEdge(i, j, i - 2, j + 4, '\0');
		addEdge(i, j, i - 3, j + 4, '\0');
		addEdge(i, j, i - 4, j + 4, '\0');
		addEdge(i, j, i - 4, j + 3, '\0');
		addEdge(i, j, i - 4, j + 2, '\0');
		addEdge(i, j, i - 4, j + 1, '\0');
		addEdge(i, j, i - 4, j, '\0');
		addEdge(i, j, i - 4, j - 1, '\0');
		addEdge(i, j, i - 4, j - 2, '\0');
		addEdge(i, j, i - 4, j - 3, '\0');
		addEdge(i, j, i - 4, j - 4, '\0');
		addEdge(i, j, i - 4, j - 5, '\0');
		addEdge(i, j, i - 4, j - 6, '\0');
		addEdge(i, j, i - 4, j - 7, '\0');
		addEdge(i, j, i - 4, j - 8, '\0');
		addEdge(i, j, i - 5, j - 8, '\0');
		addEdge(i, j, i - 6, j - 8, '\0');
		addEdge(i, j, i - 7, j - 8, '\0');
		addEdge(i, j, i - 8, j - 8, '\0');
		addEdge(i, j, i - 9, j - 8, '\0');
		addEdge(i, j, i - 10, j - 8, '\0');
		addEdge(i, j, i - 11, j - 8, '\0');
		addEdge(i, j, i - 12, j - 8, '\0');
		addEdge(i, j, i - 13, j - 8, '\0');
		addEdge(i, j, i - 14, j - 8, '\0');
		addEdge(i, j, i - 15, j - 8, '\0');
		addEdge(i, j, i - 16, j - 8, '\0');
		addEdge(i, j, i - 17, j - 8, '\0');
		addEdge(i, j, i - 18, j - 8, '\0');
		addEdge(i, j, i - 18, j - 7, '\0');
		addEdge(i, j, i - 18, j - 6, '\0');
		addEdge(i, j, i - 18, j - 5, '\0');
		addEdge(i, j, i - 18, j - 4, '?');
		addEdge(i, j, i - 18, j - 3, '\0');
		addEdge(i, j, i - 18, j - 2, '\0');
		addEdge(i, j, i - 18, j - 1, '\0');
		addEdge(i, j, i - 18, j, '\0');
		addEdge(i, j, i - 18, j + 1, '\0');
		addEdge(i, j, i - 18, j + 2, '\0');
		addEdge(i, j, i - 18, j + 3, '\0');
		addEdge(i, j, i - 18, j + 4, '\0');
		addEdge(i, j, i - 18, j + 5, '\0');
		addEdge(i, j, i - 18, j + 6, '\0');
		addEdge(i, j, i - 18, j + 7, '\0');
		addEdge(i, j, i - 18, j + 8, '\0');
		maze[17][12].head->data = '+';
		maze[15][12].head->data = '+';
		maze[13][8].head->data = '+';
		maze[13][6].head->data = '+';
		maze[11][8].head->data = '+';
		maze[9][16].head->data = '+';
		maze[3][16].head->data = '+';
		maze[1][17].head->data = '+';
		maze[1][2].head->data = '+';
		maze[6][2].head->data = '+';
		maze[5][9].head->data = '+';
		maze[3][11].head->data = '+';
		maze[7][2].head->data = '+';
		maze[5][2].head->data = '+';
		//alternate path(1)
		addEdge(6, 1, 6, 2, '\0');
		addEdge(6, 1, 6, 3, '\0');
		addEdge(6, 1, 6, 4, '\0');
		addEdge(6, 1, 6, 5, '\0');
		addEdge(6, 1, 6, 6, '\0');
		addEdge(6, 1, 6, 7, '\0');
		addEdge(6, 1, 6, 8, '\0');
		addEdge(6, 1, 6, 9, '\0');
		addEdge(6, 1, 6, 10, '\0');
		addEdge(6, 1, 5, 10, '\0');
		addEdge(6, 1, 4, 10, '?');
		addEdge(6, 1, 3, 10, '\0');
		addEdge(6, 1, 2, 10, '\0');
		addEdge(6, 1, 2, 11, '\0');
		addEdge(6, 1, 2, 12, '\0');
		addEdge(6, 1, 2, 13, '\0');
		addEdge(6, 1, 2, 14, '\0');
		addEdge(6, 1, 2, 15, '\0');
		addEdge(6, 1, 2, 16, '\0');
		addEdge(6, 1, 2, 17, '\0');
		addEdge(6, 1, 2, 18, '\0');
		addEdge(6, 1, 1, 18, '\0');
		//alternate path(2)
		addEdge(14, 7, 13, 7, '\0');
		addEdge(14, 7, 12, 7, '?');
		addEdge(14, 7, 11, 7, '\0');
		addEdge(14, 7, 10, 7, '\0');
		addEdge(14, 7, 10, 8, '\0');
		addEdge(14, 7, 10, 9, '\0');
		addEdge(14, 7, 10, 10, '\0');
		addEdge(14, 7, 10, 11, '\0');
		addEdge(14, 7, 10, 12, '\0');
		addEdge(14, 7, 10, 13, '\0');
		addEdge(14, 7, 10, 14, '\0');
		addEdge(14, 7, 10, 15, '\0');
		addEdge(14, 7, 10, 16, '\0');
		addEdge(14, 7, 10, 17, '\0');
		addEdge(14, 7, 9, 17, '\0');
		addEdge(14, 7, 8, 17, '\0');
		addEdge(14, 7, 7, 17, '\0');
		addEdge(14, 7, 6, 17, '?');
		addEdge(14, 7, 5, 17, '\0');
		addEdge(14, 7, 4, 17, '\0');
		addEdge(14, 7, 3, 17, '\0');
		addEdge(14, 7, 2, 17, '\0');
		maze[15][0].head->data = '+';
		maze[13][2].head->data = '+';
		maze[0][0].head->data = '+';
		maze[4][1].head->data = '*';
		maze[6][10].head->data = '*';
		maze[10][12].head->data = '*';
		if (!flag) {
			maze[x][y].head->data = 'C';
		}

	}
	else if (ra == 3) {
		//main path
		addEdge(i, j, i - 1, j, '\0');
		addEdge(i, j, i - 2, j, '\0');
		addEdge(i, j, i - 3, j, '\0');
		addEdge(i, j, i - 4, j, '\0');
		addEdge(i, j, i - 5, j, '\0');
		addEdge(i, j, i - 6, j, '\0');
		addEdge(i, j, i - 7, j, '\0');
		addEdge(i, j, i - 8, j, '\0');
		addEdge(i, j, i - 9, j, '\0');
		addEdge(i, j, i - 10, j, '\0');
		addEdge(i, j, i - 11, j, '\0');
		addEdge(i, j, i - 12, j, '\0');
		addEdge(i, j, i - 13, j, '\0');
		addEdge(i, j, i - 13, j + 1, '\0');
		addEdge(i, j, i - 13, j + 2, '?');
		addEdge(i, j, i - 13, j + 3, '\0');
		addEdge(i, j, i - 13, j + 4, '\0');
		addEdge(i, j, i - 13, j + 5, '\0');
		addEdge(i, j, i - 13, j + 6, '\0');
		addEdge(i, j, i - 13, j + 7, '\0');
		addEdge(i, j, i - 13, j + 8, '\0');
		addEdge(i, j, i - 14, j + 8, '?');
		addEdge(i, j, i - 15, j + 8, '\0');
		addEdge(i, j, i - 16, j + 8, '\0');
		addEdge(i, j, i - 17, j + 8, '\0');
		addEdge(i, j, i - 18, j + 8, '\0');
		maze[17][10].head->data = '+';
		maze[17][14].head->data = '+';
		maze[6][10].head->data = '+';
		maze[6][14].head->data = '+';
		maze[6][16].head->data = '+';
		maze[4][16].head->data = '+';
		maze[3][16].head->data = '+';
		maze[1][16].head->data = '+';
		maze[13][8].head->data = '+';
		maze[11][8].head->data = '+';
		maze[11][3].head->data = '+';
		maze[3][3].head->data = '+';
		
		//alternate path(1)
		addEdge(i, j, i, j + 1, '\0');
		addEdge(i, j, i, j + 2, '\0');
		addEdge(i, j, i, j + 3, '\0');
		addEdge(i, j, i, j + 4, '\0');
		addEdge(i, j, i, j + 5, '\0');
		addEdge(i, j, i, j + 6, '\0');
		addEdge(i, j, i - 1, j + 6, '\0');
		addEdge(i, j, i - 2, j + 6, '\0');
		addEdge(i, j, i - 3, j + 6, '\0');
		addEdge(i, j, i - 4, j + 6, '\0');
		addEdge(i, j, i - 5, j + 6, '\0');
		addEdge(i, j, i - 6, j + 6, '?');
		addEdge(i, j, i - 7, j + 6, '\0');
		addEdge(i, j, i - 8, j + 6, '\0');
		addEdge(i, j, i - 9, j + 6, '\0');
		addEdge(i, j, i - 10, j + 6, '\0');
		addEdge(i, j, i - 11, j + 6, '\0');
		addEdge(i, j, i - 12, j + 6, '\0');
		//alternate path(2)
		addEdge(12, 9, 12, 8, '\0');
		addEdge(12, 9, 12, 7, '\0');
		addEdge(12, 9, 12, 6, '\0');
		addEdge(12, 9, 12, 5, '\0');
		addEdge(12, 9, 12, 4, '\0');
		addEdge(12, 9, 12, 3, '\0');
		addEdge(12, 9, 12, 2, '\0');
		addEdge(12, 9, 11, 2, '\0');
		addEdge(12, 9, 10, 2, '?');
		addEdge(12, 9, 9, 2, '\0');
		addEdge(12, 9, 8, 2, '\0');
		addEdge(12, 9, 7, 2, '\0');
		addEdge(12, 9, 6, 2, '\0');
		addEdge(12, 9, 5, 2, '\0');
		addEdge(12, 9, 4, 2, '\0');
		addEdge(12, 9, 3, 2, '\0');
		addEdge(12, 9, 2, 2, '\0');
		addEdge(12, 9, 2, 3, '\0');
		addEdge(12, 9, 2, 4, '\0');
		addEdge(12, 9, 2, 5, '\0');
		addEdge(12, 9, 2, 6, '\0');
		addEdge(12, 9, 2, 7, '?');
		addEdge(12, 9, 2, 8, '\0');
		addEdge(12, 9, 2, 9, '\0');
		addEdge(12, 9, 2, 10, '\0');
		addEdge(12, 9, 2, 11, '\0');
		addEdge(12, 9, 2, 12, '\0');
		addEdge(12, 9, 2, 13, '\0');
		addEdge(12, 9, 2, 14, '\0');
		addEdge(12, 9, 2, 15, '\0');
		addEdge(12, 9, 2, 16, '\0');
		maze[4][2].head->data = '*';
		maze[12][8].head->data = '*';
		maze[8][15].head->data = '*';
		if (!flag) {
			maze[x][y].head->data = 'C';
		}

	}



	return ra;

}

// function to add edge in graph
void graph::addEdge(int x, int y, int x2, int y2, char z) {
node* temp = maze[x][y].head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	node * n = new node(z);
	temp->next = n,
	maze[x2][y2].head->data = z;
	
}
// function to remove edge in graph
void graph::removeEdge(int x, int y, int x2, int y2) {
	node* temp = maze[x][y].head;
	while (temp->next != maze[x2][y2].head) {
		temp = temp->next;
	}
	temp->next = maze[x2][y2].head->next;
	maze[x2][y2].head->next = NULL;
}
// defination for arrow keys
#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77
// function to move car in maze

queue graph::movecar(queue q,stack *s,stack *h,int le,string nm,int pa,int level) {
	static int i = size - 1;
	static int j = size / 2;
	int xp = size - 1;
	int yp = size / 2;
	
	cout << "                 Trade                                                                                                Your Health" << endl;
	h->print();
     cout << endl; 
	 cout << "            T to used Igniter *                                          W" << endl;
	 cout << "            to Remove Obstaclte                                      A       D                                        Your Collections" << endl;
	 cout << "                                                                         S" << endl;
	 s->print();
	 cout<<endl;
	 cout<<  "            Press q to quit                                           LEVEL : "<<level<<"                                Press V to Save and back "<<endl;
	 cout << endl;
	 if (level == 1) {
		 cout << "                                                        Steps Greater than 50 will result in plenty  " << endl;
	 }
	 else if (level == 2) {
		 cout << "                                                             Steps Greater than 45 will result in plenty  " << endl;
	 }
	 else if (level == 3) {
		 cout << "                                                             Steps Greater than 40 will result in plenty  " << endl;
	 }
	 // queue to store obstacles
	 queue q1;
	 queue q2;
	 q2.enqueue('S');
	 if (pa == 0) {
		 return q1;
	 }
	
	// condition to check if game is over
	if (h->isEmpty()) {
		cout << "Game Ended Your Health is Finished" << endl;
		i = xp;
		j = yp;
		return q1;
	}
	if (level == 1) {
		if (step > 50) {
			score--;
		}
	}
	else if (level == 2) {
		if (step >45) {
			score--;
		}
	}
	else if (level == 3) {
		if (step > 40) {
			score--;
		}
	}
		char x;
		x = _getch();
	
		// used to move up
	if ( x == 's' ||x==KEY_DOWN){
    int k = i;
		node * temp = maze[xp][yp].head;
		temp = temp->next;
		while (temp) {
			if (i == size - 1) {
				return q;
			}
			if (temp->data == maze[k + 1][j].head->data) {
				maze[i][j].head->data = '\0';
				maze[i + 1][j].head->data = 'C';
				i++;
				step++;
				continue;
			}
			else if(maze[k+1][j].head->data=='$'|| maze[k + 1][j].head->data == '?'){
				//q.enqueue('$');
				s->push(maze[i + 1][j].head->data);
				if(maze[k + 1][j].head->data == '?') {
					score = score + 5;

				}
				else {
					score = score + 1;
				}
               step++;
				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'C';
				i++;
				return q;
			}
			else if(maze[k + 1][j].head->data == '@'|| maze[k + 1][j].head->data == '#') {
				
				//q.enqueue('+');
				h->remove('*'); // remove health
                score = score - 1;
				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'C';
				i++;
				step++;
				return q;
			}
			else if (maze[k+1][j].head->data == '*') {
				//q.enqueue('$');
				s->push(maze[k+1][j].head->data); // push obstacles in stack
				maze[i][j].head->data = '\0';
				maze[k+1][j].head->data = 'C';
				i++;
				step++;
				return q;
			}
			else if (maze[k + 1][j].head->data == 'E') {
				cout << "You Won" << endl;
				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'W';
				i = xp;
				j = yp;
				return q1;
			}
			temp = temp->next;
		}
		
	}
	// used to move left
	else if (x == 'a'||x==KEY_LEFT) {
		int y= j;
		node * temp = maze[xp][yp].head;
		temp = temp->next;
		while (temp) {
			if(temp->data==maze[i][y-1].head->data){
				maze[i][y].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				continue;
			}
else if (maze[i][y - 1].head->data == '$'|| maze[i][y - 1].head->data == '?') {
				//q.enqueue('$');
			
				s->push(maze[i][y - 1].head->data);// push obstacles in stack
				if (maze[i][y-1].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}
				
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				return q;
			}
             else if (maze[i][y - 1].head->data == '*') {
				//q.enqueue('$');
				s->push(maze[i][y - 1].head->data);// push obstacles in stack
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				return q;
			}
			else if (maze[i][y - 1].head->data == '@'||maze[i][y - 1].head->data == '#') {
				//q.enqueue('+');
				h->remove('*');// remove health
				if (maze[y - 1][j].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				return q;
			}
			else if (maze[i][y - 1].head->data == 'E') {
				cout << "You Won" << endl;
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'W';
				i = xp;
				j = yp;
				return q1;
			}

			temp = temp->next;
		
		}
 
	
	}
	// used to move right
	else if (x == 'd'||x==KEY_RIGHT) {
      int y = j;	
node * temp = maze[xp][yp].head;
temp = temp->next;
while (temp) {
	if (j == size - 1) {
		return q;
	}
	if (temp->data == maze[i][y + 1].head->data) {
		maze[i][j].head->data = '\0';
		maze[i][y + 1].head->data = 'C';
		j++;
		step++;
		continue;
	}
else if (maze[i][y + 1].head->data == '$'|| maze[i][y + 1].head->data == '?') {
		//q.enqueue('$');
        s->push(maze[i][y + 1].head->data); // push obstacles in stack
		if (maze[i][y+1].head->data == '?') {
			score = score + 5;
		}
		else {
			score = score + 1;
		}
		
		maze[i][j].head->data = '\0';
		maze[i][y + 1].head->data = 'C';
		j++;
		step++;
		return q;
	}
else if (maze[i][y + 1].head->data == '*' ) {
		//q.enqueue('$');
		s->push(maze[i][y + 1].head->data);
		maze[i][j].head->data = '\0';
		maze[i][y + 1].head->data = 'C';
		j++;
		step++;
		return q;
	}
	else if (maze[i][y + 1].head->data == '@'||maze[i][y + 1].head->data == '#') {
		//q.enqueue('+');
		h->remove('*');
		score = score - 1;
		maze[i][j].head->data = '\0';
		maze[i][y + 1].head->data = 'C';
		j++;
		step++;
		return q;
	}
else if (maze[i][y + 1].head->data == 'E') {
		cout << "You Won" << endl;
		maze[i][j].head->data = '\0';
		maze[i][y + 1].head->data = 'W';
		i = xp;
		j = yp;
		return q1;
	}
temp = temp->next;
}
	
	}
	// used to move down
	else if (x == 'w'||x==KEY_UP) {
		int k = i;
node * temp = maze[xp][yp].head;
temp = temp->next;
while (temp) {
	if (i == 0) {
		return q;
	}
	if (temp->data == maze[k - 1][j].head->data) {
		maze[i][j].head->data = '\0';
		maze[k - 1][j].head->data = 'C';
		i--;
		step++;
		continue;
	}
else if (maze[k - 1][j].head->data == '$'|| maze[k - 1][j].head->data == '?') {
		//q.enqueue('$');
        s->push(maze[k - 1][j].head->data); // push obstacles in stack
		if (maze[k - 1][j].head->data == '?') {
			score=score+5;
		}
		else {
			score = score + 1;
		}
		
		maze[i][j].head->data = '\0';
		maze[k - 1][j].head->data = 'C';
		i--;
		step++;
		return q;
	}
	else if (maze[k - 1][j].head->data == '@'||maze[k - 1][j].head->data == '#') {
		h->remove('*');
		//q.enqueue('+');
        score = score - 1;
		maze[i][j].head->data = '\0';
		maze[k - 1][j].head->data = 'C';
		i--;
		step++;
		return q;
	}
	else if (maze[k - 1][j].head->data == '*') {
		//q.enqueue('$');
		s->push(maze[k - 1][j].head->data);
		maze[i][j].head->data = '\0';
		maze[k - 1][j].head->data = 'C';
		i--;
		step++;
		return q;
	}
else if (maze[k - 1][j].head->data == 'E') {
		cout << "You Won" << endl;
		maze[i][j].head->data = '\0';
		maze[k - 1][j].head->data = 'W';
		i = xp;
		j = yp;
		return q1;
	}
temp = temp->next;
}
	
	}
	// condition to use igniter
	else if (x == 't') {
		int h = i;
		int g = j;
		if (s->search('*')) {
			if (maze[i][g + 1].head->data == '#' || maze[i][g + 1].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[i][g + 1].head->data = 'C';
				s->remove('*');
				step++;
				j++;
			}
			else if (maze[h - 1][j].head->data == '#' || maze[h-1][j].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[h-1][j].head->data = 'C';
				s->remove('*');
				step++;
				i--;
			}
			else if (maze[h + 1][j].head->data == '#' || maze[h+1][j].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[h+1][j].head->data = 'C';
				s->remove('*');
				step++;
				i++;
			}
			else if (maze[i][g - 1].head->data == '#' || maze[i][g - 1].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[i][g - 1].head->data = 'C';
				s->remove('*');
				step++;
				j--;
			}
		}
		else {
			cout << "NO Igniter" << endl;
		}

		}
		// condition to		Quit game
	else if (x=='q') {
		cout << "You Quit" << endl;
		i = xp;
		j = yp;
		return q1;
	}
	// condition to save game
	else if (x == 'v'){
		cout << "You Saved" << endl;
		int life=h->calculate();
		fstream f2;
		f2.open("save.txt",ios::app);
		f2 << nm << "," << score << "," << pa << "," << i << "," << j << "," << life<<"," << step<<","<<level;
		stacknode* temp = s->top;
		while (temp) {
			f2 << "," << temp->data;
			temp = temp->next;
		}
		f2 << endl;
		f2.close();
		return q2;
	}
else {
		//cout<<"invalid input"<<endl;
		return q;
	}
	// random function to add obstacles
	q=addobstacle(i, j, q,x,le);
	// random function to add coins
	addcoin(i, j,x);
	// showing current indexes
	cout<<i<<" "<<j<<endl;
    return q;
}
// function to move car when resume game
queue graph::movecarresume(queue q, stack* s, stack* h, int le, string nm,int xr,int yr,int pa,int levl) {
	static int i = xr;
	static int j = yr;
	int xp = size - 1;
	int yp = size/2;

	cout << "                 Trade                                                                                                Your Health" << endl;
	h->print();
	cout << endl;
	cout << "            T to used Igniter *                                          W" << endl;
	cout << "            to Remove Obstaclte                                      A       D                                        Your Collections" << endl;
	cout << "                                                                         S" << endl;
	s->print();
	cout << endl;
	cout << "            Press q to quit                                           LEVEL : " << levl << "                                Press V to Save and back " << endl;
	cout << endl;
	if (levl == 1) {
		cout << "                                                        Steps Greater than 50 will result in plenty  " << endl;
	}
	else if (levl == 2) {
		cout << "                                                        Steps Greater than 45 will result in plenty  " << endl;
	}
	else if (levl == 3) {
		cout << "                                                        Steps Greater than 40 will result in plenty  " << endl;
	}
		queue q1;
	queue q2;
	q2.enqueue('S');


	// condition to check if game is over
	if (h->isEmpty()) {
		cout << "Game Ended Your Health is Finished" << endl;
		i = xp;
		j = yp;
		return q1;
	}
	if (levl == 1) {
		if (step > 50) {
			score--;
		}
	}
	else if (levl == 2) {
		if (step > 45) {
			score--;
		}
	}
	else if (levl == 3) {
		if (step > 40) {
			score--;
		}
	}
	char x;
	x = _getch();
	// used to move up
	if (x == 's' || x == KEY_DOWN) {
		int k = i;
		node* temp = maze[xp][yp].head;
		temp = temp->next;
		while (temp) {
			if (i == size - 1) {
				return q;
			}
			if (temp->data == maze[k + 1][j].head->data) {
				maze[i][j].head->data = '\0';
				maze[i + 1][j].head->data = 'C';
				i++;
				step++;
				continue;
			}
			else if (maze[k + 1][j].head->data == '$' || maze[k + 1][j].head->data == '?') {
				//q.enqueue('$');
				s->push(maze[i + 1][j].head->data);// push obstacles in stack
				if (maze[k + 1][j].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}

				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'C';
				i++;
				step++;
				return q;
			}
			else if (maze[k + 1][j].head->data == '@' || maze[k + 1][j].head->data == '#') {

				//q.enqueue('+');
				h->remove('*');
				score = score - 1;
				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'C';
				i++;
				step++;
				return q;
			}
			else if (maze[k + 1][j].head->data == '*') {
				//q.enqueue('$');
				s->push(maze[k + 1][j].head->data);
				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'C';
				i++;
				step++;
				return q;
			}
			else if (maze[k + 1][j].head->data == 'E') {
				cout << "You Won" << endl;
				maze[i][j].head->data = '\0';
				maze[k + 1][j].head->data = 'W';
				i = xp;
				j = yp;
				return q1;
			}
			temp = temp->next;
		}

	}
	// used to move left
	else if (x == 'a' || x == KEY_LEFT) {
		int y = j;
		node* temp = maze[xp][yp].head;
		temp = temp->next;
		while (temp) {
			if (temp->data == maze[i][y - 1].head->data) {
				maze[i][y].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				continue;
			}
			else if (maze[i][y - 1].head->data == '$' || maze[i][y - 1].head->data == '?') {
				//q.enqueue('$');

				s->push(maze[i][y - 1].head->data); // push obstacles in stack
				if (maze[i][y - 1].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}

				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				return q;
			}
			else if (maze[i][y - 1].head->data == '*') {
				//q.enqueue('$');
				s->push(maze[i][y - 1].head->data);
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				return q;
			}
			else if (maze[i][y - 1].head->data == '@' || maze[i][y - 1].head->data == '#') {
				//q.enqueue('+');
				h->remove('*');
				if (maze[y - 1][j].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'C';
				j--;
				step++;
				return q;
			}
			else if (maze[i][y - 1].head->data == 'E') {
				cout << "You Won" << endl;
				maze[i][j].head->data = '\0';
				maze[i][y - 1].head->data = 'W';
				i = xp;
				j = yp;
				return q1;
			}

			temp = temp->next;

		}


	}
	// used to move right
	else if (x == 'd' || x == KEY_RIGHT) {
		int y = j;
		node* temp = maze[xp][yp].head;
		temp = temp->next;
		while (temp) {
			if (j == size - 1) {
				return q;
			}
			if (temp->data == maze[i][y + 1].head->data) {
				maze[i][j].head->data = '\0';
				maze[i][y + 1].head->data = 'C';
				j++;
				step++;
				continue;
			}
			else if (maze[i][y + 1].head->data == '$' || maze[i][y + 1].head->data == '?') {
				//q.enqueue('$');
				s->push(maze[i][y + 1].head->data);
				if (maze[i][y + 1].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}

				maze[i][j].head->data = '\0';
				maze[i][y + 1].head->data = 'C';
				j++;
				step++;
				return q;
			}
			else if (maze[i][y + 1].head->data == '*') {
				//q.enqueue('$');
				s->push(maze[i][y + 1].head->data);
				maze[i][j].head->data = '\0';
				maze[i][y + 1].head->data = 'C';
				j++;
				step++;
				return q;
			}
			else if (maze[i][y + 1].head->data == '@' || maze[i][y + 1].head->data == '#') {
				//q.enqueue('+');
				h->remove('*');
				score = score - 1;
				maze[i][j].head->data = '\0';
				maze[i][y + 1].head->data = 'C';
				j++;
				step++;
				return q;
			}
			else if (maze[i][y + 1].head->data == 'E') {
				cout << "You Won" << endl;
				maze[i][j].head->data = '\0';
				maze[i][y + 1].head->data = 'W';
				i = xp;
				j = yp;
				return q1;
			}
			temp = temp->next;
		}

	}
	// used to move down
	else if (x == 'w' || x == KEY_UP) {
		int k = i;
		node* temp = maze[xp][yp].head;
		temp = temp->next;
		while (temp) {
			if (i == 0) {
				return q;
			}
			if (temp->data == maze[k - 1][j].head->data) {
				maze[i][j].head->data = '\0';
				maze[k - 1][j].head->data = 'C';
				i--;
				step++;
				continue;
			}
			else if (maze[k - 1][j].head->data == '$' || maze[k - 1][j].head->data == '?') {
				//q.enqueue('$');
				s->push(maze[k - 1][j].head->data);
				if (maze[k - 1][j].head->data == '?') {
					score = score + 5;
				}
				else {
					score = score + 1;
				}

				maze[i][j].head->data = '\0';
				maze[k - 1][j].head->data = 'C';
				i--;
				step++;
				return q;
			}
			else if (maze[k - 1][j].head->data == '@' || maze[k - 1][j].head->data == '#') {
				h->remove('*');
				//q.enqueue('+');
				score = score - 1;
				maze[i][j].head->data = '\0';
				maze[k - 1][j].head->data = 'C';
				i--;
				step++;
				return q;
			}
			else if (maze[k - 1][j].head->data == '*') {
				//q.enqueue('$');
				s->push(maze[k - 1][j].head->data);
				maze[i][j].head->data = '\0';
				maze[k - 1][j].head->data = 'C';
				i--;
				step++;
				return q;
			}
			else if (maze[k - 1][j].head->data == 'E') {
				cout << "You Won" << endl;
			   maze[i][j].head->data = '\0';
			   maze[k - 1][j].head->data = 'W';
				i = xp;
				j = yp;
				return q1;
			}
			temp = temp->next;
		}

	}
	// condition to use igniter
	else if (x == 't') {
		int h = i;
		int g = j;
		if (s->search('*')) {
			if (maze[i][g + 1].head->data == '#' || maze[i][g + 1].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[i][g + 1].head->data = 'C';
				s->remove('*');
				j++;
				step++;
			}
			else if (maze[h - 1][j].head->data == '#' || maze[h - 1][j].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[h - 1][j].head->data = 'C';
				s->remove('*');
				i--;
				step++;
			}
			else if (maze[h + 1][j].head->data == '#' || maze[h + 1][j].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[h + 1][j].head->data = 'C';
				s->remove('*');
				i++;
				step++;
			}
			else if (maze[i][g - 1].head->data == '#' || maze[i][g - 1].head->data == '@') {
				maze[i][j].head->data = '\0';
				maze[i][g - 1].head->data = 'C';
				s->remove('*');
				j--;
				step++;
			}
		}
		else {
			cout << "NO Igniter" << endl;
		}

	}
	// condition to quit game
	else if (x == 'q') {
		cout << "You Quit" << endl;
		i = xp;
		j = yp;
		return q1;
	}
	// condition to save game
	else if (x == 'v') {
		cout << "You Saved" << endl;
		int life = h->calculate();

		fstream f2;
		f2.open("save.txt", ios::app);
		// saving in file
		f2 << nm << "," << score << "," << pa << "," << i << "," << j << "," << life<<","<<step<<","<<levl;
		stacknode * temp = s->top;
		while (temp) {
			f2 << "," << temp->data;
			temp = temp->next;
		}
		f2 << endl;
		f2.close();
		return q2;
	}
	else {
		//cout<<"invalid input"<<endl;
		return q;
	}
	// random function to add obstacles
	q = addobstacle(i, j, q, x, le);
	// random function to add coins
	addcoin(i, j, x);
	// showing current indexes
	cout << i << " " << j << endl;
	return q;
}

// queue class
queuenode::queuenode() {
	data = '\0';
	next = NULL;
}
queuenode::queuenode(char x) {
	data = x;
	next = NULL;
}
// constructor for queue
queue::queue() {
	front = NULL;
	rear = NULL;
}
// function to enqueue
void queue::enqueue(char x) {
	queuenode* n = new queuenode(x);
	if (front == NULL) {
		front = n;
		rear = n;
	}
	else {
		rear->next = n;
		rear = n;
	}
}
// function to dequeue
char queue::dequeue() {
	queuenode* temp = front;
	front = front->next;
	return temp->data;


}
// function to check if queue is empty
bool queue::isEmpty() {
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}
}
// function to add obstacles in maze
queue graph::addobstacle(int x, int y, queue q, char p,int l) {
	// random function to add obstacles
	int n = 0;
	if (l == 1) {
		n = 1 + (rand() % 4);
	}
	else if (l == 2) {
		n = 1 + (rand() % 3);
	}
	else if (l == 3) {
		n = 1 + (rand() % 2);


	}
	if (n == 1) {
		char g = q.dequeue();
		q.enqueue(g);

			if (p == 'w'||p==KEY_UP) {
				if (x <= 14 && x >= 4) {
				if (maze[x + 1][y].head->data == maze[x - 4][y].head->data) {
					if (maze[x + 1][y].head->data == '.' || maze[x - 4][y].head->data == '.') {
						return q;
					}
					maze[x - 4][y].head->data = g;

					return q;
				}
				else {
					return q;
				}
			}
				else {
					return q;
				}



		}

			else if (p == 's'||p==KEY_DOWN) {
				if (x <= 14 && x >= 5) {
				char g = q.dequeue();
				q.enqueue(g);

				if (maze[x - 1][y].head->data == maze[x + 4][y].head->data) {
					if (maze[x - 1][y].head->data == '.' || maze[x + 4][y].head->data == '.') {
						return q;
					}
					maze[x + 4][y].head->data = g;

					return q;
				}
				else {
					return q;
				}
			}
				else {
					return q;
				}



		}
			else if (p == 'a'||p==KEY_LEFT) {
				if (y <= 14 && y >= 4) {
					char g = q.dequeue();
					q.enqueue(g);

					if (maze[x][y + 1].head->data == maze[x][y - 4].head->data) {
						if (maze[x][y + 1].head->data == '.' || maze[x][y - 4].head->data == '.') {
							return q;
						}
						maze[x][y - 4].head->data = g;

						return q;
					}
					else {
						return q;
					}
				}
				else
				{
					return q;
				}
			}
			else if (p == 'd'||p==KEY_RIGHT) {
				if (y <= 14 && y >= 5) {
					char g = q.dequeue();
					q.enqueue(g);

					if (maze[x][y - 1].head->data == maze[x][y + 4].head->data) {
						if (maze[x][y - 1].head->data == '.' || maze[x][y + 4].head->data == '.') {
							return q;
						}
						maze[x][y + 4].head->data = g;

						return q;
					}
					else {
						return q;
					}
				}
				else {
					return q;
				}
			}
			else {
            return q;

			}

	}
	else {
		return q;
	}

}
// function to add obstacles in maze auto 
queue graph::addobstaclelevelauto(int x, int y, queue q) {

	// random function to add obstacles
	int n = 1 + (rand() % 3);
	if (n == 1) {
		char g = q.dequeue();
		q.enqueue(g);


		if (x <= 14 && x >= 4) {
			if (maze[x + 1][y].head->data == maze[x - 4][y].head->data) {
				if (maze[x + 1][y].head->data == '.' || maze[x - 4][y].head->data == '.') {
					return q;
				}
				maze[x - 4][y].head->data = g;

				return q;
			}
			else {
				return q;
			}
		}
		else {
			return q;
		}


		if (x <= 14 && x >= 5) {
			char g = q.dequeue();
			q.enqueue(g);

			if (maze[x - 1][y].head->data == maze[x + 4][y].head->data) {
				if (maze[x - 1][y].head->data == '.' || maze[x + 4][y].head->data == '.') {
					return q;
				}
				maze[x + 4][y].head->data = g;

				return q;
			}
			else {
				return q;
			}
		}
		else {
			return q;
		}

		if (y <= 14 && y >= 4) {
			char g = q.dequeue();
			q.enqueue(g);

			if (maze[x][y + 1].head->data == maze[x][y - 4].head->data) {
				if (maze[x][y + 1].head->data == '.' || maze[x][y - 4].head->data == '.') {
					return q;
				}
				maze[x][y - 4].head->data = g;

				return q;
			}
			else {
				return q;
			}
		}
		else
		{
			return q;
		}

		if (y <= 14 && y >= 5) {
			char g = q.dequeue();
			q.enqueue(g);

			if (maze[x][y - 1].head->data == maze[x][y + 4].head->data) {
				if (maze[x][y - 1].head->data == '.' || maze[x][y + 4].head->data == '.') {
					return q;
				}
				maze[x][y + 4].head->data = g;

				return q;
			}
			else {
				return q;
			}
		}
		else {
			return q;
		}
	}
	return q;
}
// function to add coins in maze
void graph::addcoin(int x, int y, char p) {
	//random function to add coins
	int n = 1 + (rand() % 2);
	if (n == 1) {
		if (p == 'w') {
			if (x <= 14 && x >= 4) {
				if (maze[x + 1][y].head->data == maze[x - 4][y].head->data) {
					if (maze[x + 1][y].head->data == '.' || maze[x - 4][y].head->data == '.') {
						return;
					}
					maze[x - 4][y].head->data = '$';

					return;
				}
				else {
					return;
				}
			}
			else {
				return;
			}

		}
		else if (p == 's')
		{
			if (x <= 14 && x >= 5) {
				if (maze[x - 1][y].head->data == maze[x + 4][y].head->data) {
					if (maze[x - 1][y].head->data == '.' || maze[x + 4][y].head->data == '.') {
						return;
					}
					maze[x + 4][y].head->data = '$';

					return;
				}
				else {
					return;
				}
			}


		}
		else if (p == 'a') {
			if (y <= 14 && y >= 4) {
				if (maze[x][y + 1].head->data == maze[x][y - 4].head->data) {
					if (maze[x][y + 1].head->data == '.' || maze[x][y - 4].head->data == '.') {
						return;
					}
					maze[x][y - 4].head->data = '$';

					return;
				}
				else {
					return;
				}
			}
			else
			{
				return;
			}
		}
		else if (p == 'd') {
			if (y <= 14 && y >= 5) {
				if (maze[x][y - 1].head->data == maze[x][y + 4].head->data) {
					if (maze[x][y - 1].head->data == '.' || maze[x][y + 4].head->data == '.') {
						return;
					}
					maze[x][y + 4].head->data = '$';

					return;
				}
				else {
					return;
				}
			}
			else {
				return;
			}
		}
		else {
			return;

		}
	}
	    else {
		return;
	}
	}
// add path for auto mode
void graph::addpathauto() {
	int i = size - 1;
	int j = size / 2;
	addEdge(i, j, i, j - 1, '\0');
	addEdge(i, j, i, j - 2, '\0');
	addEdge(i, j, i, j - 3, '\0');
	addEdge(i, j, i, j - 4, '\0');
	addEdge(i, j, i - 1, j - 4, '\0');
	addEdge(i, j, i - 2, j - 4, '\0');
	addEdge(i, j, i - 3, j - 4, '\0');
	addEdge(i, j, i - 4, j - 4, '\0');
	addEdge(i, j, i - 4, j - 3, '\0');
	addEdge(i, j, i - 4, j - 2, '\0');
	addEdge(i, j, i - 4, j - 1, '\0');
	addEdge(i, j, i - 4, j, '\0');
	addEdge(i, j, i - 4, j + 1, '\0');
	addEdge(i, j, i - 4, j + 2, '\0');
	addEdge(i, j, i - 4, j + 3, '\0');
	addEdge(i, j, i - 4, j + 4, '\0');
	addEdge(i, j, i - 5, j + 4, '\0');
	addEdge(i, j, i - 6, j + 4, '\0');
	addEdge(i, j, i - 7, j + 4, '\0');
	addEdge(i, j, i - 8, j + 4, '\0');
	addEdge(i, j, i - 9, j + 4, '\0');
	addEdge(i, j, i - 10, j + 4, '\0');
	addEdge(i, j, i - 11, j + 4, '\0');
	addEdge(i, j, i - 12, j + 4, '\0');
	addEdge(i, j, i - 13, j + 4, '\0');
	addEdge(i, j, i - 14, j + 4, '\0');
	addEdge(i, j, i - 14, j + 5, '\0');
	addEdge(i, j, i - 14, j + 6, '\0');
	addEdge(i, j, i - 15, j + 6, '\0');
	addEdge(i, j, i - 15, j + 7, '\0');
	addEdge(i, j, i - 15, j + 8, '\0');
	addEdge(i, j, i - 15, j + 9, '?');
	addEdge(i, j, i - 16, j + 9, '\0');
	addEdge(i, j, i - 17, j + 9, '\0');
	maze[13][13].head->data = '?';
	maze[18][4].head->data = '+';
	maze[17][6].head->data = '+';
	maze[15][6].head->data = '+';
	maze[15][4].head->data = '+';
	maze[13][3].head->data = '+';
	maze[13][9].head->data = '+';
	maze[13][7].head->data = '+';
	maze[13][12].head->data = '+';
	maze[11][3].head->data = '+';
	maze[11][9].head->data = '+';
	maze[11][7].head->data = '+';
	maze[5][14].head->data = '+';
	maze[4][16].head->data = '+';
	maze[3][14].head->data = '+';
	maze[2][17].head->data = '+';
	maze[2][12].head->data = '+';
	maze[1][10].head->data = '+';
	maze[1][9].head->data = '+';
	maze[0][7].head->data = '+';
	maze[9][7].head->data = '+';
	maze[9][9].head->data = '+';
	maze[9][10].head->data = '+';
	maze[7][9].head->data = '+';
	maze[7][10].head->data = '+';
	maze[5][9].head->data = '+';
	maze[5][10].head->data = '+';



	//alternate path(1)
	addEdge(14, 5, 14, 4, '\0');
	addEdge(14, 5, 14, 3, '\0');
	addEdge(14, 5, 14, 2, '\0');
	addEdge(14, 5, 13, 2, '\0');
	addEdge(14, 5, 12, 2, '\0');
	addEdge(14, 5, 11, 2, '\0');
	addEdge(14, 5, 10, 2, '\0');
	addEdge(14, 5, 10, 3, '\0');
	addEdge(14, 5, 10, 4, '\0');
	addEdge(14, 5, 10, 5, '\0');
	addEdge(14, 5, 10, 6, '\0');
	addEdge(14, 5, 10, 7, '\0');
	addEdge(14, 5, 9, 8, '\0');
	addEdge(14, 5, 8, 8, '\0');
	addEdge(14, 5, 7, 8, '\0');
	addEdge(14, 5, 6, 8, '\0');
	addEdge(14, 5, 5, 8, '\0');
	addEdge(14, 5, 4, 8, '\0');
	addEdge(14, 5, 3, 8, '\0');
	addEdge(14, 5, 2, 8, '\0');
	addEdge(14, 5, 1, 8, '\0');
	addEdge(14, 5, 0, 8, '\0');
	addEdge(14, 5, 0, 9, '\0');
	addEdge(14, 5, 0, 10, '\0');
	addEdge(14, 5, 0, 11, '\0');
	addEdge(14, 5, 0, 12, '\0');
	addEdge(14, 5, 0, 13, '\0');
	addEdge(14, 5, 0, 14, '\0');
	addEdge(14, 5, 0, 15, '\0');
	addEdge(14, 5, 0, 16, '\0');
	addEdge(14, 5, 0, 17, '\0');
	addEdge(14, 8, 13, 8, '\0');
	addEdge(14, 8, 12, 8, '?');
	addEdge(14, 8, 11, 8, '\0');
	addEdge(14, 8, 10, 8, '\0');

	//alternate path(2)
	addEdge(10, 7, 10, 8, '\0');
	addEdge(10, 7, 10, 9, '\0');
	addEdge(10, 7, 10, 10, '\0');
	addEdge(10, 7, 10, 11, '\0');
	addEdge(10, 7, 9, 11, '\0');
	addEdge(10, 7, 8, 11, '\0');
	addEdge(10, 7, 7, 11, '\0');
	addEdge(10, 7, 6, 11, '\0');
	addEdge(10, 7, 5, 11, '\0');
	addEdge(10, 7, 4, 11, '\0');
	addEdge(10, 7, 3, 11, '\0');
	addEdge(10, 7, 2, 11, '\0');
	addEdge(10, 7, 1, 11, '\0');
	addEdge(10, 7, 1, 12, '\0');
	addEdge(10, 7, 1, 13, '\0');
	addEdge(10, 7, 1, 14, '\0');
	addEdge(10, 7, 1, 15, '\0');
	addEdge(10, 7, 1, 16, '\0');
	addEdge(10, 7, 1, 17, '\0');
	addEdge(10, 7, 0, 17, '\0');
	addEdge(6, 8, 6, 9, '\0');
	addEdge(6, 8, 6, 10, '?');


	maze[13][13].head->data = '*';
	maze[10][2].head->data = '*';
	maze[3][8].head->data = '*';
	int t=1 + (rand() % 3);
	if (t == 1) {
		addEdge(i, j, i - 14, j + 4, '#');
		addEdge(i, j, i - 10, j + 4, '#');
		addEdge(i, j, i - 6, j + 4, '#');
	}
	else if(t==2) {
		addEdge(14, 5, 14, 3, '#');
		addEdge(14, 5, 10, 3, '#');
		addEdge(14, 5, 10, 8, '#');
		addEdge(14, 5, 6, 8, '#');
		addEdge(14, 5, 6, 11, '#');
	}
	else if(t==3) {
		addEdge(10, 7, 10, 9, '#');
		addEdge(10, 7, 6, 9, '#');
		addEdge(10, 7, 6, 11, '#');
		addEdge(10, 7, 1, 11, '#');
	}
	
}
// function to add coins in maze auto
void graph::addcoinauto(int x, int y, char p) {
	int n = 1 + (rand() % 2);
	if (n == 1) {
		if (p == 'w') {
			if (x <= 14 && x >= 4) {
				if (maze[x + 1][y].head->data == '.' || maze[x - 4][y].head->data == '.') {
					return;
				}
				else {
					maze[x - 4][y].head->data = '$';

					return;
				}

			}
			else {
				return;
			}

		}
		else if (p == 'd') {
			if (y <= 14 && y >= 5) {
				if (maze[x][y - 1].head->data == '.' || maze[x][y + 4].head->data == '.') {
					return;
				}
				else {
					maze[x][y + 4].head->data = '$';

					return;
				}

			}
			else {
				return;
			}
		}
	}
	else {
		return;

	}

}
// function to solve maze in auto mode
queue graph::autosolve(queue q, stack* s, stack* h) {
	//shorest path
	
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;
	int x4 = 0;
	int y4 = 0;
	int x5 = 0;
	int y5 = 0;

	int i = 0;
	int j = 0;
	// calculating indexes of coins
	// calculating  which path is shortest according to coins and obstacles
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (maze[i][j].head->next != NULL) {
				if (count == 0) {
					x1 = i;
					y1 = j;
					count++;
				}
				else if (count == 1) {
					x2 = i;
					y2 = j;
					count++;
				}
				else if (count == 2) {
					x3 = i;
					y3 = j;
					count++;
				}
				else if (count == 3) {
					x4 = i;
					y4 = j;
					count++;
				}
				else if (count == 4) {
					x5 = i;
					y5 = j;
					count++;
				}
				else {
					continue;
				}

			}
		}
	}
	printMaze();
	//indexes at which adjancy list is created
	cout << x2 << " " << y2 << endl;
    cout << x3 << " " << y3 << endl;
	cout << x5 << " " << y5 << endl;
	node* p1 = maze[x5][y5].head;
	node *p3=maze[x3][y3].head;
	node *p4=maze[x2][y2].head;
	int t1 = 0;
	// calculation of coins in each path
	while (p1) {
		if (p1->data == '*' || p1->data == '?'||p1->data=='#') {
						t1++;
		}
		p1=p1->next;
	}
	cout<< t1 << endl;

	int t3 = 0;
	while (p3) {
		
		if (p3->data == '*' || p3->data == '?'|| p3->data == '#') {
						t3++;
		}
		p3=p3->next;
	}
	
	cout<< t3 << endl;

	int t4 = 0;
	while (p4) {
	
		if (p4->data == '*' || p4->data == '?'||p4->data == '#') {
						t4++;
		}
		p4=p4->next;
	}

	cout<< t4 << endl;
	

	int tx = x5;
	int ty = y5;
	// condition to check which path is shortest
	if (t1 > t4 && t1 > t3) {
		cout<<"So this Path is the shortest from index "<<endl;
		node *temp = maze[x5][y5].head;
		while (temp) {
			if (x5 == x3 && y5 == y3) {
				node *t = maze[x3][y3].head;
				while (t) {
					if (y5 ==18) { goto gt; }
						if (maze[x5][ty + 1].head->data == '\0' || maze[x5][ty + 1].head->data == '*' || maze[x5][ty + 1].head->data == '?' || maze[x5][ty + 1].head->data == '$' || maze[x5][ty + 1].head->data == '#' || maze[x5][ty + 1].head->data == 'E') {
							if (maze[x5][ty + 1].head->data == '$') {
								score++;
								s->push('$');
							}
							else if (maze[x5][ty + 1].head->data == '?') {
								score = score + 5;
								s->push('?');
							}
							else if (maze[x5][ty + 1].head->data == '#') {
								score = score - 1;
								h->remove('*');
							}
							else if (maze[x5][ty + 1].head->data == 'E') {
								
								maze[x5][y5].head->data = '_';
								maze[x5][ty + 1].head->data = 'C';
								step++;
								system("cls");
								printMaze();
								cout << "                                                                                                                       Your Health" << endl;
								h->print();
								cout << endl;
								cout << "                                                                            " << endl;
								s->print();
								cout << "You Won" << endl;
								return q;
							}

							maze[x5][y5].head->data = '_';
							maze[x5][ty + 1].head->data = 'C';
							addcoinauto(x5, y5, 'd');
							y5++;
							step++;
							ty = y5;
							system("cls");

							printMaze();
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
							Sleep(500);
							temp = temp->next;

							continue;
						}

					else 
				  gt:		if (maze[tx - 1][y5].head->data == '\0' || maze[tx - 1][y5].head->data == '*' || maze[tx - 1][y5].head->data == '?'|| maze[tx-1][ty].head->data == '$' || maze[tx-1][ty].head->data == '#'||maze[tx-1][ty].head->data=='E') {
						if (maze[tx - 1][y5].head->data == '$') {
							score++;
							s->push('$');
						}
						else if (maze[tx - 1][y5].head->data == '?') {
							score = score + 5;
							s->push('?');
						}
						else if (maze[tx - 1][y5].head->data == '#') {
							score = score - 1;
							h->remove('*');
						}
						else if (maze[tx - 1][y5].head->data == 'E') {
							
							maze[x5][y5].head->data = '_';
							maze[tx - 1][y5].head->data = 'C';
							step++;
							system("cls");
							printMaze();
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
							cout << "You Won" << endl;
							Sleep(500);

							return q;
						}
						addcoinauto(x5, y5, 'w');
						maze[x5][y5].head->data = '-';
						maze[tx - 1][y5].head->data = 'C';
						step++;
						x5--;
						tx = x5;
						system("cls");
						printMaze();
						cout << "                                                                                                                       Your Health" << endl;
						h->print();
						cout << endl;
						cout << "                                                                            " << endl;
						Sleep(500);
						temp = temp->next;
						continue;

					}
				}
			}

			if (maze[x5][ty - 1].head->data == '\0') {
				maze[x5][y5].head->data = '_';
				maze[x5][ty - 1].head->data = 'C';
				y5--;
				step++;
				ty = y5;
				addcoinauto(x5, y5, 'd');
				system("cls");
				addobstaclelevelauto(x5, y5, q);
				printMaze();
				cout << "                                                                                                                       Your Health" << endl;
				h->print();
				cout << endl;
				cout << "                                                                            " << endl;
				Sleep(500);
				temp = temp->next;

				continue;
			}
			else if (maze[tx - 1][y5].head->data == '\0') {
				maze[x5][y5].head->data = '_';
				maze[tx - 1][y5].head->data = 'C';
				step++;
				x5--;
				tx = x5;
				addcoinauto(x5, y5, 'w');
				system("cls");

				printMaze();
				cout << "                                                                                                                       Your Health" << endl;
				h->print();
				cout << endl;
				cout << "                                                                            " << endl;
				Sleep(500);
				temp = temp->next;
				;
				continue;
			}
			else if (maze[x5][ty + 1].head->data == '\0') {
				maze[x5][y5].head->data = '_';
				maze[x5][ty + 1].head->data = 'C';
				y5++;
				step++;
				ty = y5;
				system("cls");

				printMaze();
				cout << "                                                                                                                       Your Health" << endl;
				h->print();
				cout << endl;
				cout << "                                                                            " << endl;
				Sleep(500);
				temp = temp->next;
				addcoinauto(x5, y5, 'w');
				continue;
			}

		}

	}
	
	else if (t3 > 1 && t3 > t4) {
		ty = y5;
		tx = x5;
		node* temp = maze[x5][y5].head;
		while (temp) {
			if (x5 == 10 && y5 == 2) {
				node* t = maze[x3][y3].head;
				while (t) {
					if (y5 == 18) { goto gt1; }
					if (maze[x5][ty + 1].head->data == '\0' || maze[x5][ty + 1].head->data == '*' || maze[x5][ty + 1].head->data == '?' || maze[x5][ty + 1].head->data == '$' || maze[x5][ty + 1].head->data == '#'||maze[x5][ty+1].head->data=='E') {
						if (maze[x5][ty + 1].head->data == '$') {
							score++;
						}
						else if (maze[x5][ty + 1].head->data == '?') {
							score = score + 5;
							s->push('?');
						}
						else if (maze[x5][ty + 1].head->data == '#') {
							score = score - 1;
							h->remove('*');
						}
						else if (maze[x5][ty + 1].head->data == 'E') {
							
							maze[x5][y5].head->data = '_';
							maze[x5][ty + 1].head->data = 'C';
							step++;
							system("cls");
							printMaze();
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
							cout << "You Won" << endl;
							return q;
						}
						maze[x5][y5].head->data = '_';
						maze[x5][y5].head->data = '_';
						maze[x5][ty + 1].head->data = 'C';
						step++;
						y5++;
						ty = y5;
						addcoinauto(x5, y5, 'd');
						system("cls");

						printMaze();
						cout << "                                                                                                                       Your Health" << endl;
						h->print();
						cout << endl;
						cout << "                                                                            " << endl;
						Sleep(500);
						temp = temp->next;

						continue;
					}
					else 
						gt1:	if (maze[tx - 1][y5].head->data == '\0' || maze[tx - 1][y5].head->data == '*' || maze[tx - 1][y5].head->data == '?' || maze[tx - 1][ty].head->data == '$' || maze[tx - 1][ty].head->data == '#'||maze[tx-1][ty].head->data=='E') {
						if (maze[tx - 1][y5].head->data == '$') {
								score++;
							}
						else if (maze[tx - 1][y5].head->data == '?') {
								score = score + 5;
								s->push('?');

							}
						else if (maze[tx - 1][y5].head->data == '#') {
								score = score - 1;
								h->remove('*');
							}
						else if (maze[tx - 1][y5].head->data == 'E') {
							
								
								maze[x5][y5].head->data = '_';
								maze[tx - 1][y5].head->data = 'C';
								step++;
								system("cls");
								printMaze();
								cout << "                                                                                                                       Your Health" << endl;
								h->print();
								cout << endl;
								cout << "                                                                            " << endl;
								cout << "You Won" << endl;
								return q;
							}
							maze[x5][y5].head->data = '_';
							addcoinauto(x5, y5, 'w');
							maze[x5][y5].head->data = '-';
							maze[tx - 1][y5].head->data = 'C';
							step++;
							system("cls");
							printMaze();
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
						
							x5--;
							tx = x5;
							
							Sleep(500);

							temp = temp->next;
							continue;
						maze[x5][y5].head->data = '_';
							addcoinauto(x5, y5, 'w');
							maze[x5][y5].head->data = '-';
							maze[tx - 1][y5].head->data = 'C';
							step++;
							x5--;
							tx = x5;
							system("cls");
							printMaze();
							
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
							Sleep(500);

							temp = temp->next;
							continue;

					}
					}
				}
			if (maze[x5][ty - 1].head->data == '\0' || maze[x5][ty-1].head->data == '*' || maze[x5][ty-1].head->data == '?' || maze[x5][ty-1].head->data == '$' || maze[x5][ty-1].head->data == '#') {
			       	maze[x5][y5].head->data = '_';
					maze[x5][ty - 1].head->data = 'C';
					addcoinauto(x5, y5, 'a');
					y5--;
					step++;
					ty = y5;
					system("cls");
					printMaze();
					cout << "                                                                                                                       Your Health" << endl;
					h->print();
					cout << endl;
	
					cout << "                                                                            " << endl;
					Sleep(500);
					temp = temp->next;

					continue;
				}
				else if (maze[tx - 1][y5].head->data == '\0'|| maze[tx - 1][y5].head->data == '*' || maze[tx - 1][y5].head->data == '?' || maze[tx - 1][ty].head->data == '$' || maze[tx - 1][ty].head->data == '#') {
					maze[x5][y5].head->data = '_';
					maze[tx - 1][y5].head->data = 'C';
					addcoinauto(x5, y5, 'w');
					x5--;
					step++;
					tx = x5;
					system("cls");

					printMaze();
					cout << "                                                                                                                       Your Health" << endl;
					h->print();
					cout << endl;
					cout << "                                                                            " << endl;
					Sleep(500);
					//temp = temp->next;
					
					continue;
				}
				else if (maze[x5][ty + 1].head->data == '\0') {
					maze[x5][y5].head->data = '_';
					maze[x5][ty + 1].head->data = 'C';
					y5++;
					step++;
					ty = y5;
					system("cls");

					printMaze();
					cout << "                                                                                                                       Your Health" << endl;
					h->print();
					cout << endl;
					cout << "                                                                            " << endl;
					Sleep(500);
					temp = temp->next;
					continue;
				}

			}

		}
	else if (t4 > 1 && t4 > t3) {
		ty = y5;
		tx = x5;
		node* temp = maze[x5][y5].head;
		while (temp) {
			if (x5 == 10 && y5 == 2) {
				node* t = maze[x3][y3].head;
				while (t) {
					if (y5 == 18) { goto gt2; }
					if (maze[x5][ty + 1].head->data == '\0' || maze[x5][ty + 1].head->data == '*' || maze[x5][ty + 1].head->data == '?' || maze[x5][ty + 1].head->data == '$' || maze[x5][ty + 1].head->data == '#'|| maze[x5][ty + 1].head->data == 'E') {
						if (maze[x5][ty + 1].head->data == '$') {
							score++;
						}
						else if (maze[x5][ty + 1].head->data == '?') {
							score = score + 5;
							s->push('?');
						}
						else if (maze[x5][ty + 1].head->data == '#') {
							score = score - 1;
							h->remove('*');
						}
						else if (maze[x5][ty + 1].head->data == 'E') {
							maze[x5][y5].head->data = '_';
							maze[x5][ty + 1].head->data = 'C';
							step++;
							system("cls");
							printMaze();
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
							cout << "You Won" << endl;
							return q;
						}
						maze[x5][y5].head->data = '_';
						maze[x5][y5].head->data = '_';
						maze[x5][ty + 1].head->data = 'C';
						addcoinauto(x5, y5, 'd');
						y5++;
						step++;
						ty = y5;
						system("cls");

						printMaze();
						system("cls");
						printMaze();
						cout << "                                                                                                                       Your Health" << endl;
						h->print();
						cout << endl;
						cout << "                                                                            " << endl;
						Sleep(500);
						temp = temp->next;

						continue;
					}
					else 
						gt2:	if (maze[tx - 1][y5].head->data == '\0' || maze[tx - 1][y5].head->data == '*' || maze[tx - 1][y5].head->data == '?' || maze[tx - 1][y5].head->data == '$' || maze[tx - 1][y5].head->data == '#'|| maze[tx-1][y5].head->data == 'E') {
						if (maze[tx - 1][y5].head->data == '$') {
							score++;
						}
						else if (maze[tx - 1][y5].head->data == '?') {
							score = score + 5;
							s->push('?');
						}
						else if (maze[tx - 1][y5].head->data == '#') {
							score = score - 1;
							h->remove('*');
						}
						else if (maze[tx - 1][y5].head->data == 'E') {
							step++;
							system("cls");
							printMaze();
							cout << "                                                                                                                       Your Health" << endl;
							h->print();
							cout << endl;
							cout << "                                                                            " << endl;
							cout << "You Won" << endl;
							return q;
						}
						maze[x5][y5].head->data = '_';
						addcoinauto(x5, y5, 'w');
						maze[x5][y5].head->data = '-';
						maze[tx - 1][y5].head->data = 'C';
						step++;
						x5--;
						tx = x5;
						system("cls");
						printMaze();
						system("cls");
						printMaze();
						cout << "                                                                                                                       Your Health" << endl;
						h->print();
						cout << endl;
						cout << "                                                                            " << endl;
						Sleep(500);

						temp = temp->next;
						continue;

					}
				}
			}
			if (maze[x5][ty - 1].head->data == '\0' || maze[x5][ty - 1].head->data == '*' || maze[x5][ty - 1].head->data == '?' || maze[x5][ty - 1].head->data == '$' || maze[x5][ty - 1].head->data == '#') {
				maze[x5][y5].head->data = '_';
				maze[x5][ty - 1].head->data = 'C';
				addcoinauto(x5, y5, 'a');
				y5--;
				step++;
				ty = y5;
				system("cls");
				printMaze();
				system("cls");
				printMaze();
				cout << "                                                                                                                       Your Health" << endl;
				h->print();
				cout << endl;
				cout << "                                                                            " << endl;
				Sleep(500);
				temp = temp->next;

				continue;
			}
			else if (maze[tx - 1][y5].head->data == '\0' || maze[tx - 1][y5].head->data == '*' || maze[tx - 1][y5].head->data == '?' || maze[tx - 1][ty].head->data == '$' || maze[tx - 1][ty].head->data == '#') {
				maze[x5][y5].head->data = '_';
				maze[tx - 1][y5].head->data = 'C';
				addcoinauto(x5, y5, 'w');
				step++;
				x5--;
				tx = x5;
				system("cls");

				printMaze();
				system("cls");
				printMaze();
				cout << "                                                                                                                       Your Health" << endl;
				h->print();
				cout << endl;
				cout << "                                                                            " << endl;
				
				Sleep(500);
				//temp = temp->next;
				;
				continue;
			}
			else if (maze[x5][ty + 1].head->data == '\0') {
				maze[x5][y5].head->data = '_';
				maze[x5][ty + 1].head->data = 'C';
				step++;
				y5++;
				ty = y5;
				system("cls");

				printMaze();
				system("cls");
				printMaze();
				cout << "                                                                                                                       Your Health" << endl;
				h->print();
				cout << endl;
				cout << "                                                                            " << endl;
				Sleep(500);
				temp = temp->next;
				continue;
			}	
			
		}
	}
	
	return q;

	
}
// total summary of game
void graph::stats(stack s,string name,int sc) {
	cout<<"Your name is "<<name<<endl;
	cout<<"Your score is "<<sc<<endl;
	cout<<"Your item list is "<<endl;
	cout << "Total Steps " << step<<endl;
	
	s.calc();
    ofstream fout;
	fout.open("stats.txt",ios::app);
	fout << name <<","<< sc << endl;
	fout.close();

}
// store highest score in binary search tree and file
void graph::displayandsavetopscorer() {
    BSTtree f;
	ifstream fin;
	filelist fi;
	fin.open("stats.txt");
	string line;
while (getline(fin, line)) {
		stringstream ss(line);
		string name;
		string score;
		getline(ss, name, ',');
		getline(ss, score, ',');
		fi.add(name, stoi(score));
		f.insert(name, stoi(score));
		
	}
	fin.close();
    fi.sort();
	int i = 1;
	filenode * temp = fi.head;
	ofstream fout;
    fout.open("stats.txt");
    while (temp) {
    fout << temp->name << "," << temp->score << endl;
	i++;
	temp = temp->next;
	}
	fout.close();
	f.inorder();

	
}

void log() {
	setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "                                   ___________              __    ________                   ________        .__              " << endl;
	cout << "                                   \\__    ___/___ ___  ____/  |_  \\_______\\___ __ __________ \\ ______\\_______|__|__  __ ____   " << endl;
	cout << "                                     |    |_/ __ \\  \\/  /\\   __\\  /   |   \\  \\/ / / __ \\_  __ \\    |  \\_  __ \\  \\  \\/ // __ \\  " << endl;
	cout << "                                     |    |\\  ___/ >    <  |  |  /    |    \\   /  \\ ___/|  | \\/    `   \\  | \\/  |\\   /\\  ___/" << endl;
	cout << "                                     |____| \\___  >__/\\_ \\ |__|  \\_______  /\\_/    \\___ >__| /_______  /__|  |__| \\_/  \\___  >" << endl;
	cout << "                                                \\/      \\/               \\/            \\/            \\/                    \\/ " << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
// display menu function
void displayMenu() {
	setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "                                   ___________              __    ________                   ________        .__              " << endl;
	cout << "                                   \\__    ___/___ ___  ____/  |_  \\_______\\___ __ __________ \\ ______\\_______|__|__  __ ____   " << endl;
	cout<<  "                                     |    |_/ __ \\  \\/  /\\    __\\ /   |   \\  \\/ / / __ \\_  __ \\    |  \\_  __ \\  \\  \\/ // __ \\  " << endl;
	cout<<  "                                     |    |\\  ___/ >    <  |  |  /    |    \\   /  \\ ___/|  | \\/    `   \\  | \\/  |\\   /\\  ___/" << endl;
	cout<<  "                                     |____| \\___  >__/\\_ \\ |__|  \\_______  /\\_/    \\___ >__| /_______  /__|  |__| \\_/  \\___  >" << endl;
	cout<<  "                                                \\/      \\/               \\/            \\/            \\/                    \\/ " << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << 								"			                                             p. Play									" << endl;
	cout << 								"			                                             i. Instructions							" << endl;
	cout <<                                 "			                                             q. Quit									" << endl;
	cout<<                                  "                                                                     h.Highest score                          "<<endl;
	cout<<                                  "                                                                     c.Controls                              "<<endl;
}
// instructions function
void showInstructions() {
	setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "              ___________              __  ________                        .___      .__            " << endl;
	cout << "             \\__    ___/___ ___  ____/  |_\\_____  \\___  __ ___________  __| _/______|__|__  __ ____ " << endl;
	cout << "                |    |_/ __ \\  \\/  /\\   __\\/    |   \\  \\/ // __ \\_  __ \\/ __ |\\_  __ \\  \\  \\/ // __ \\" << endl;
	cout << "                |    |\\  ___/ >    <  |  | /    |    \\   /\\  ___/|  | \\/ /_/ | |  | \\/  |\\   /\\  ___/" << endl;
	cout << "                |____| \\___  >__/\\_ \\ |__| \\_______  /\\_/  \\___  >__|  \\____ | |__|  |__| \\_/  \\___  >" << endl;
	cout << "		                 \\/      \\/              \\/          \\/           \\/                     \\/ " << endl;
	cout << "						Instructions" << endl;
	cout << "						============" << endl;
	cout << "						1. Use 'w' to move up" << endl;
	cout << "						2. Use 's' to move down" << endl;
	cout << "						3. Use 'a' to move left" << endl;
	cout << "						4. Use 'd' to move right" << endl;
	cout << "						5. Use 'p' to pause the game" << endl;
	cout << "						6. Use 'q' to quit the game" << endl;
	cout << "						7. Use 'r' to resume the game" << endl;
	cout << "						8. Use 'i' to display instructions" << endl;
}
// queue make function consist of obstacles which are randomly generated
queue make() {
		queue q;
	q.enqueue('#');
	q.enqueue('@');
	q.enqueue('#');
	q.enqueue('@');
	q.enqueue('#');
	q.enqueue('@');
	q.enqueue('#');
	return q;

}
// stack make function consist of health which are randomly generated
stack makestack() {
	stack s;
	s.push('*');
	s.push('*');
	s.push('*');
	s.push('*');
	s.push('*');


	return s;

}

	

int main() {
	graph g(19);
	g.createMaze();
	int lev = 0;
	queue q = make();
	bool contr = false;
	string name;
	int le = 0;
	stack s = makestack();
	stack score;
	cout << "lets play";
	bool falsee = false;
	while (true) {

		Sleep(1000);
	men:system("cls");
		g.createMaze();
		//setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		displayMenu();
		srand(time(NULL));
		char x;
		x = _getch();

		g.score = 0;
		system("cls");
		log();
		system("color 0A");

		if (x == 'p') {
			cout << "                                                                       1.MANUAL" << endl;
			cout << "                                                                       2.AUTOMATIC" << endl;
			cout << " 		                                                       3.RESUME" << endl;
			cout << "                                                                       4.Back" << endl;
			cout << endl;



			int z;
			cin >> z;


			if (z == 1) {
				cout << "                                                                     Select the mode" << endl;
				cout << "                                                                        1.Easy" << endl;
				cout << "                                                                        2.Medium" << endl;
				cout << "                                                                        3.Hard" << endl;
				cout << "                                                                        4.Back" << endl;
				int y;
				cin >> y;
				le = y;
				switch (y) {
				case 1:
				{
					cout << "                                                                        LEVEL 1" << endl;
					cout << "                                                                        LEVEL 2" << endl;
					cout << "                                                                        LEVEL 3" << endl;
					int levels;

					cin >> levels;
					cout << "Enter your name" << endl;
					//string name;
					cin >> name;
					lev = g.createpath(0, 0, 0);
					s = makestack();
					q = make();
					score.push('\0');
					while (true) {
						//Sleep(80);
						system("cls");

						//g.displayandsavetopscorer();
						g.printMaze();
						q = g.movecar(q, &score, &s, 1, name, lev,levels);
						if (q.isEmpty()) {
							system("cls");
							//g.displayandsavetopscorer();
							g.printMaze();
							q = g.movecar(q, &score, &s, 1, name, 0,levels);
							cout<<endl;
							setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "                                                                         Game Over" << endl;
							setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							
							g.stats(score, name, g.score);
							step = 0;
							cout << "  m.If you want to return to main menu" << endl;
							cout << "  q.If you want to quit" << endl;
							char x;
							x = _getch();
							if (x == 'm') {
								score.emptystack();
								srand(time(NULL));
								s.emptystack();

								goto men;
							}
							else if (x == 'q') {
								exit(0);
							}
							else {
								cout << "Invalid input" << endl;
								continue;

							}
						}
						else if (q.frontelement() == 'S')
						{
							cout << "                                                     Your Game is paused" << endl;
							Sleep(2000);
							q = make();
							goto men;

						}
					}
				}
				case 2: {
					cout << "                                                                        LEVEL 1" << endl;
					cout << "                                                                        LEVEL 2" << endl;
					cout << "                                                                        LEVEL 3" << endl;
					int levels;

					cin >> levels;
					cout << "Enter your name" << endl;
					//string name;
					cin >> name;
					lev = g.createpath(0, 0, 0);
					s = makestack();
					q = make();
					score.push('\0');
					while (true) {

						//Sleep(80);
						system("cls");

						//g.displayandsavetopscorer();
						g.printMaze();
						q = g.movecar(q, &score, &s, 2, name, lev,levels);
						if (q.isEmpty()) {
							system("cls");
							g.printMaze();
							q = g.movecar(q, &score, &s, 2, name, 0,levels);
							//change color of txt game over
							cout << endl;
							setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "                                                                         Game Over" << endl;
							setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

							g.stats(score, name, g.score);
							step = 0;
							falsee = true;
							score.emptystack();
							cout << "  m.If you want to return to main menu" << endl;
							cout << "  q.If you want to quit" << endl;
							char x;
							x = _getch();
							if (x == 'm') {
								score.emptystack();
								srand(time(NULL));
								s.emptystack();
								goto men;
							}
							else if (x == 'q') {
								exit(0);
							}
							else {
								cout << "Invalid input" << endl;
								continue;

							}
						}
						else if (q.frontelement() == 'S')
						{
							cout << "                                                     Your Game is paused" << endl;
							Sleep(2000);
							q = make();
							goto men;

						}
					}
				}
				case 3: {
					cout << "                                                                        LEVEL 1" << endl;
					cout << "                                                                        LEVEL 2" << endl;
					cout << "                                                                        LEVEL 3" << endl;
					int levels;

					cin >> levels;
					cout << "Enter your name" << endl;
					//string name; 
					cin >> name;
					lev = g.createpath(0, 0, 0);
					s = makestack();
					q = make();
					score.push('\0');
					//start=std::chrono::steady_clock::now();
					while (true) {
						
						//	Sleep(80);
						system("cls");

						//g.displayandsavetopscorer();
						g.printMaze();
						q = g.movecar(q, &score, &s, 3, name,lev,levels);


						if (q.isEmpty()) {
							//end = std::chrono::steady_clock::now();
							system("cls");
							g.printMaze();
							q = g.movecar(q, &score, &s, 3, name, 0,levels);
							cout <<endl;
							setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "                                                                         Game Over" << endl;
							setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							g.stats(score, name, g.score);
							step = 0;
							falsee = true;
							score.emptystack();
							cout << "  m.If you want to return to main menu" << endl;
							cout << "  q.If you want to quit" << endl;
							char x;
							x = _getch();
							if (x == 'm') {
								srand(time(NULL));
								score.emptystack();
								s.emptystack();
								goto men;
							}
							else if (x == 'q') {
								exit(0);
							}
							else {
								cout << "Invalid input" << endl;
								continue;

							}
						}
						else if (q.frontelement() == 'S')
						{
							cout << "                                                     Your Game is paused" << endl;
							Sleep(2000);
							q = make();
							goto men;




						}
					}
				}
				case 4: {
					goto men;
				}

				}
			}
			else if (z == 2) {
				g.createMaze();
				g.addpathauto();
				g.printMaze();
				q = g.autosolve(q, &score, &s);
				step = 0;
				cout << "Game Over" << endl;
				cout << "Your score is " << g.score << endl;

				break;

			}
			else if (z == 3) {
				bool tr = false;
				string name;
				cout << "Enter your name" << endl;
				cin >> name;
				int scor = 0;
				int leve = 0;
				int xc = 0;
				int yc = 0;
				int health = 0;
				int steps=0;
				int levelc = 0;
				char a[5];
				fstream fin;
				fin.open("save.txt");
				while (fin) {
					string line;

					getline(fin, line);
					stringstream ss(line);
					string name1;
					string score1;
					string level1;
					string x1;
					string y1;
					string he;
					string  f;
					string  g;
					string  h;
					string  i;
					string  j;
					string st;
					string l;
					getline(ss, name1, ',');
					getline(ss, score1, ',');
					getline(ss, level1, ',');
					getline(ss, x1, ',');
					getline(ss, y1, ',');
					getline(ss, he, ',');
					getline(ss, st, ',');
					getline(ss, l, ',');
					getline(ss, f, ',');
					getline(ss, g, ',');
					getline(ss, h, ',');
					getline(ss, i, ',');
					getline(ss, j, ',');

					if (name1 == name) {
						scor = stoi(score1);
						leve = stoi(level1);
						xc = stoi(x1);
						yc = stoi(y1);
						health = stoi(he);
						steps = stoi(st);
						levelc = stoi(l);
						a[0] = f[0];
						a[1] = g[0];
						a[2] = h[0];
						a[3] = i[0];
						a[4] = j[0];
						tr = true;
					}
					else {
						continue;
					}
				}
				fin.close();
				if (tr) {
					cout << "Record founded" << endl;
				}
				else {
					cout << "Record not founded" << endl;
					continue;
				}
				for (int i = 0; i < 5; i++) {
					if (a[i] == '\0') {
						continue;
					}
					score.push(a[i]);

				}
				
			
				int y = 5 - health;
				lev = g.createpath(leve, xc, yc);
				for (int i = 0; i < y; i++) {
					s.remove('*');
				}
				step = steps;
				g.score = scor;
				while (true) {
					system("cls");
					g.printMaze();
					
					q = g.movecarresume(q, &score, &s, leve, name, xc, yc, lev,levelc);
					if (q.isEmpty()) {
						cout << "Game Over" << endl;
						g.stats(score, name, g.score);
						step = 0;
						cout << "  m.If you want to return to main menu" << endl;
						cout << "  q.If you want to quit" << endl;
						char x;
						x = _getch();
						if (x == 'm') {
							score.emptystack();
							srand(time(NULL));
							falsee = true;
							goto men;
						}
						else if (x == 'q') {
							exit(0);
						}
						else {
							cout << "Invalid input" << endl;
							continue;

						}
					}
					else if (q.frontelement() == 'S')
					{
						cout << "                                                     Your Game is paused" << endl;
						Sleep(2000);
						q = make();
						goto men;

					}



				}
			}
			else if (z == 4) {
				goto men;
			}
			else {
				cout << "Invalid Input" << endl;
				continue;
			}
		}
		else if (x == 'i') {
			system("cls");
			showInstructions();
			Sleep(1500);
			continue;
		}
		else if (x == 'c') {
			cout << "DO you want to change the controls" << endl;
			cout << "1.for arrow keys" << endl;
			cout << "2.for A/S/D/W" << endl;
			int y;
			cin >> y;
			if (y == 1) {
				cout << "Controls changed" << endl;
				contr = true;
				continue;
			}
			else if (y == 2) {
				cout << "Controls changed" << endl;
				contr = false;
				continue;
			}
			else {
				cout << "Invalid input" << endl;
				continue;
			}
		}
		else if (x == 'h') {
			system("cls");
			cout << "                                            Your top scorer are " << endl;
			cout << "                                            Name      score" << endl;
			g.displayandsavetopscorer();
			Sleep(3000);
			continue;
		}
		else if (x == 'q') {
			return 0;
		}
		else {
			cout << "Invalid input" << endl;
			continue;
		}
	}





	return 0;

}