#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

class Combatant {
public:
    int id;
    string name;
    int hp;
    int atk;

    Combatant() {
        id = 0;
        name = "";
        hp = 0;
        atk = 0;
    }

    Combatant(int i, string n, int h, int a) {
        id = i;
        name = n;
        hp = h;
        atk = a;
    }
};

class Node {
public:
    Combatant x;
    Node *left;
    Node *right;

    Node(Combatant a) {
        x = a;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, Combatant c) {
    if(root == NULL) {
        return new Node(c);
    }
    if(c.id < root->x.id) 
	root->left = insertBST(root->left, c);
    else 
	root->right = insertBST(root->right, c);
    return root;
}

Node* leftMost(Node* root) {
    while(root && root->left) root = root->left;
    return root;
}

Node* minNode(Node* root) {
    while(root && root->left) 
	root = root->left;
    return root;
}

Node* deleteNode(Node* root, int id) {
    if(root == NULL) return NULL;

    if(id < root->x.id) {
        root->left = deleteNode(root->left, id);
    }
    else if(id > root->x.id) {
        root->right = deleteNode(root->right, id);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if(root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        else {
            Node* temp = minNode(root->right);
            root->x = temp->x;
            root->right = deleteNode(root->right, temp->x.id);
        }
    }

    return root;
}

void show(Node* root) {
    if(root==NULL) return;
    show(root->left);
    cout<<root->x.name<<"("<<root->x.hp<<") ";
    show(root->right);
}

int deal(Combatant &att, Combatant &def) {
    int extra = rand() % 5;
    int dmg = att.atk + extra;
    def.hp -= dmg;
    return dmg;
}

int emptyTree(Node* r) {
    return r==NULL;
}

int main() {

    

    Node* p = NULL;
    Node* e = NULL;

    p = insertBST(p, Combatant(1,"Burair",40,9));
    p = insertBST(p, Combatant(2,"Hyder",38,8));
    p = insertBST(p, Combatant(3,"Ali",36,7));
    p = insertBST(p, Combatant(4,"Ammar",45,10));
    p = insertBST(p, Combatant(5,"Hyder2",34,6));

    e = insertBST(e, Combatant(10,"Goblin",30,6));
    e = insertBST(e, Combatant(11,"Michael",35,7));
    e = insertBST(e, Combatant(12,"Traver",40,8));
    e = insertBST(e, Combatant(13,"Jack",28,5));
    e = insertBST(e, Combatant(14,"Joilian",32,6));

    int round = 1;

    while(!emptyTree(p) && !emptyTree(e)) {

        cout<<"\nRound "<<round<<"\n";

        cout<<"Heroes: ";
        show(p);
        cout<<"\n";

        cout<<"Enemies: ";
        show(e);
        cout<<"\n";

        Node* h = leftMost(p);
        Node* m = leftMost(e);

        cout<<"\n"<<h->x.name<<" attacks "<<m->x.name<<"\n";
        int a = deal(h->x, m->x);
        cout << m->x.name << " loses " << a << " HP. Now at " << m->x.hp << "\n";

        if(m->x.hp <= 0) {
            cout<<m->x.name<<" is knocked out!\n";
            e = deleteNode(e, m->x.id);
            if(emptyTree(e)) break;
            m = leftMost(e);
        }

        cout<<m->x.name<<" hits back "<<h->x.name<<"\n";
        int b = deal(m->x, h->x);
        cout << h->x.name << " loses " << b << " HP. Now at " << h->x.hp << "\n";

        if(h->x.hp <= 0) {
            cout<<h->x.name<<" is knocked out!\n";
            p = deleteNode(p, h->x.id);
        }

        round++;
    }

    if(emptyTree(p)) cout<<"\nEnemies win!\n";
    else cout<<"\nHeroes win!\n";

    return 0;
}
