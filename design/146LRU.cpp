#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class LRUCache{
	struct node{
		int key;
		int val;
		node *next;
		node *prev;
		node(int k, int v): key(k), val(v),next(NULL),prev(NULL) {}
	};
	int cap;
	node *head;
	node *tail;
	unordered_map<int, node *> key2Node;

	public:
	LRUCache(int capacity) {
		cap = capacity;
		head = NULL;
		tail = NULL;
		key2Node.clear();		
	}

	int get(int key) {
		if(key2Node.count(key)>0){
			//hit
			// move to front
            if(key2Node[key]->prev)
			    key2Node[key]->prev->next = key2Node[key]->next;
			if(key2Node[key]->next)
                key2Node[key]->next->prev = key2Node[key]->prev;
			key2Node[key]->prev= NULL;
			key2Node[key]->next = head;
			head->prev = key2Node[key];
			head = key2Node[key];
			return key2Node[key]->val;
		}else{
			//miss
			return -1;
		}
	}

	void set(int key, int value) {
		//for the first item
        if(key2Node.size()==0){
            node *n = new node(key,value);
            head = n;
            tail = n;
        }
        if(key2Node.count(key)>0){
			//already exist
			key2Node[key]->val = value; //update the value
		}else{
			// new item
			if(key2Node.size()<cap){
				node *n = new node(key,value);
				if(head){
                    n->next = head;
				    head->prev = n;
                }
				head = n;
				key2Node[key] = n;
			}else{
				// full already. need to remove an item from cache
				if(tail->prev)
                    tail->prev->next = NULL;
				node *tmp = tail;
                tail = tail->prev;
				key2Node.erase(tmp->key);
                delete(tmp);

				// create and node at the begining
				node *n = new node(key,value);
				if(head){
                    n->next = head;
				    head->prev = n;
                }
				head = n;
				key2Node[key] = n;
			}
		}		
	}
};


int main(){
	LRUCache *lru = new LRUCache(1);
	lru->set(1,1);
	lru->set(2,2);
	cout << lru->get(1)<< endl;
	return 1;
}
