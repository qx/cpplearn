#include <iostream>
#include "numeric"
#include "vector"
#include "memory"

using namespace std;

struct Dog {
public:
    string price;

    Dog() = default;

    Dog(string price) {
        this->price = price;
        cout << this->price << " create" << endl;
    }

    ~Dog() {
        cout << this->price << " destory" << endl;
    }
};

class Ball {
public:
    int price;
    string namestr;

    Ball(int price, string namestr) {
        this->price = price;
        this->namestr = namestr;
//        cout << "Ball create" << endl;
    }

    ~Ball() {

        cout << namestr << " Ball destory" << endl;
    }
};

class Player {
public:
    string name;
    Ball *ball;
    Dog dog;
    Dog *dog2;

    Player(string namestr) {
        name = namestr;
        ball = new Ball(11, namestr);
        dog = Dog(string("dog-struct").append(namestr));
        dog2 = new Dog(string("dog-point-").append(namestr));
    }

    ~Player() {
        cout << "Player destory " << name << endl;
//        if (ball != NULL) {
//            delete ball;
//        }
    }
};

int main() {
    vector<shared_ptr<Player>> players;


    for (int i = 0; i < 3; ++i) {
        string name = string("a").append(to_string(i));
        players.push_back(make_shared<Player>(name));
    }

    for (int j = 0; j < players.size(); ++j) {
        players[j].reset();
    }
    cout << "-----------------------------------" << endl;
//    std::vector<int> infos{33,33,44,55,66};
//
//    std::accumulate(infos.begin(), infos.end(), 0, [&](int index, int const& value)-> int
//    {
//        cout<< value <<endl;
//        cout<< index <<endl;
//
//        return index + 1;
//    });
    return 0;
}