#include <iostream>
#include <cstring>
#include <limits>
#include <stdlib.h> 
#include <ctime>
#include <random>


// template <typename T> 
class Node {

public:
	Node **next;


	// Constructor
	Node(int value, int level) {

		this-> value = value;

		next = new Node*[level+1];
		memset(next, 0, sizeof(Node*)*(level+1));
	}

	int value;		


};








// template <typename T> 
class SkipList {

private:

	int lvl_max;
	float p ; // probability
	int cur_lvl;
	Node *header;
	// Node* NIL;


public:

	// SkipList() = default;
	SkipList(float p, int lvl_max) {
		this->p = p;

		this->lvl_max = lvl_max;
		cur_lvl = 0;
		header = new Node(std::numeric_limits<int>::min(), lvl_max);
		// NIL = new Node(std::numeric_limits<int>::max(), lvl_max);
	}

	// ~SkipList(); //TO BE DONE

	int RandLevel() {

		std::random_device rd; 
    	std::mt19937 gen(rd()); 
    	std::uniform_int_distribution<> distr(0, 10000);
    	float k = (float)distr(gen) / (10000);

		int lvl = 0;
		while (k <= p && lvl < lvl_max) {

			lvl++;
			k = (float)distr(gen) / (10000);
		}

		return lvl;

	}

	Node* CreateNode(int value, int level) {

		Node *node = new Node(value, level);
		return node;
	}

	void InsertNode(int value) {

		Node *cur = header;
		

		Node *update[lvl_max+1];
		memset(update, 0, sizeof(Node*)*(lvl_max+1));



		for (int i = cur_lvl; i>=0; i--) {

			while (cur->next[i] != NULL && cur->next[i]->value < value) {

				cur = cur->next[i];
			}
			update[i] = cur;

		}

			

		cur = cur->next[0];



		if (cur == NULL || cur->value != value ) {

			int random_level = RandLevel();

			if (random_level > cur_lvl) {

				for (int i = cur_lvl +1; i < random_level+1 ; i++) {

					update[i] = header;

				}

				cur_lvl = random_level;
			}




		Node* node = CreateNode(value, random_level);


		for (int i = 0; i <= random_level; i++) {

			node->next[i] = update[i]->next[i];
			update[i]->next[i] = node;
		}





		}
	}


	void print_list() {



		for (int i = cur_lvl; i>=0; i--) {
					Node* cur = header;
			cur = cur->next[i];
			while (cur != NULL) {

				std::cout << cur->value << ' ';
				cur = cur->next[i];


			}
			std::cout << "\n";
		}
	}






};


int main() {


	SkipList s(0.5, 10);
	
	s.InsertNode(1);
	s.InsertNode(2);
	s.InsertNode(3);
	s.InsertNode(4);
	s.InsertNode(5);
	s.InsertNode(6);
	s.InsertNode(7);
	s.InsertNode(8);
	s.InsertNode(9);
	s.InsertNode(10);

	s.print_list();

}





