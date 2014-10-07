/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_
using namespace std;

namespace ods {

template<class T>
class DLList {
protected:
	struct Node {
		T x;
		Node *prev, *next;
	};
	Node dummy;
	int n;
	void remove(Node *w);
	Node* addBefore(Node *w, T x);
	Node* getNode(int i);
public:
	DLList();
	virtual ~DLList();
	int size() { return n; }
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) { add(size(), x); }
	virtual T remove(int i);
	virtual void clear();
    virtual bool IsPalindrome();
    virtual void Rotate(int r);
    virtual void Absorb(DLList<T>& l2);
    virtual DLList<T> deal();

};
    
template<class T>
DLList<T> DLList<T>::deal(){
    DLList<T> l2;
    int temp = size();
    if(temp>1){
        
        Node* nextNode = dummy.next->next;
        Node* currentNode = &l2.dummy;
    for(int i=0; i<temp; i++){
        if(i%2 !=0){
            cout << " number of process " << i << endl;
            Node* temp = nextNode->next->next;
            // update the existing list
            nextNode->prev->next = nextNode->next;
            nextNode->next->prev = nextNode->prev;
  
             currentNode->next = nextNode;
             nextNode->next = &l2.dummy;
             nextNode->prev = currentNode;
             l2.dummy.prev = nextNode;
             currentNode = currentNode->next;
             nextNode = temp;
             n--;
             l2.n ++;
        }
    }
    }
    
    return l2;
}
    
template<class T>
    void DLList<T>::Rotate(int r){
        
        Node* current = dummy.next;
        
        for(int i=0; i<r; i++){
            
            Node* temp2 = current->next;
            
            current->prev = dummy.prev;
            dummy.prev->next = current;
            
            dummy.next = current->next;
            current->next->prev = &dummy;
            
            current->next = &dummy;
            dummy.prev= current;
            
            current = temp2;
        }
        

        
    }

template<class T>
    void DLList<T>::Absorb(DLList<T>& l2){
        
        //cout << "last of list is : " << get(3) << endl;

        
        if(l2.size() !=0){
            
            dummy.prev->next = l2.dummy.next; 
            l2.dummy.next->prev = dummy.prev;
            dummy.prev = l2.dummy.prev;
            l2.dummy.prev->next = &dummy;
//
            l2.dummy.next = &l2.dummy;
            l2.dummy.prev = &l2.dummy;
//            
            n+= l2.size();
            //l2.clear();
            
        }
        
 //       cout << "last of list is : " << get(3) << endl;

    }

    

template<class T>
bool DLList<T>::IsPalindrome(){
        //initialize two pointers for comparision
        Node* start = dummy.next;
        Node* end = dummy.prev;
        int n=0;
        
            n = size()/2;
        
        for(int i=0;i<n;i++){
            if(start->x != end->x ){
                return false;
            }
            else {
               // cout << "in else testing" << endl;
                //replace start and end to the middle point
                start = start->next;
                end = end->prev;
            }
        }
        
        return true;
    }

    

template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
	Node* p;
	if (i < n / 2) {
		p = dummy.next;
		for (int j = 0; j < i; j++)
			p = p->next;
	} else {
		p = &dummy;
		for (int j = n; j > i; j--)
			p = p->prev;
	}
	return (p);
}


template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	Node *u = dummy.next;
	while (u != &dummy) {
		Node *w = u->next;
		delete u;
		u = w;
	}
    dummy.next = &dummy;
    dummy.prev = &dummy;
	n = 0;
}



template<class T>
void DLList<T>::remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}


template<class T>
T DLList<T>::get(int i) {
    return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->x;
	remove(w);
	return x;
}
    


} /* namespace ods */
#endif /* DLLIST_H_ */
