#include <iostream>
#include <string>
using namespace std;

struct Enemy {
    string name;
    int health;
    int attack_power;
    Enemy(string name, int health, int attack_power) {
        this->name = name;
        this->health = health;
        this->attack_power = attack_power;
    }
};


class Node {
public:
    Enemy* data = nullptr;
    Node* next = nullptr;

};

class linked_list {
    Node head;
public:
    void add(Enemy* data) { 
        if (head.data == nullptr) {
            head.data = data; 
        }
        else {
            Node* temp = &head;
            Node* node = new Node; node->data = data;
            while (temp->next != nullptr) {
                temp = temp->next;   
            }
            temp->next = node;
        }
    }
    void show() {
        if (head.data == nullptr) {
            cout << "empty" << endl;
        }
        else {
            unsigned char down = '¡';
            Node* temp = &head;
            cout << temp->data->name <<": health=" << temp->data->health << ", attack =" << temp->data->attack_power << endl << down << endl;
            while (temp->next != nullptr) {
                temp = temp->next;
                cout << temp->data->name << ": health=" << temp->data->health << ", attack =" << temp->data->attack_power << endl << down << endl;
            };
        }
        
    
    }
};

int main() {
    Enemy Brown("Mr Brown", 120,12);
    Enemy Simchi("A. Simchi", 550, 999999999);
    Enemy A_Gainer("A_Gainer", 430, 999999999);
    Enemy James_Wright("James Wright", 225,500000);

    linked_list enemy_Roster;
    enemy_Roster.add(&Brown);
    enemy_Roster.add(&Simchi);
    enemy_Roster.add(&A_Gainer);
    enemy_Roster.add(&James_Wright);
    enemy_Roster.show();
    return 0;
}

