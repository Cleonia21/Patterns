//
// Created by Cleonia on 21.09.2022.
//

/*
Паттерн Фасад
    При разбиении сложной системы на подсистемы, более мелкие и простые, возникает проблема высокой связанности
подсистем и сложность взаимодействия пользователя с большим количеством опций подсистем. Фасад является интерейсом
над подсистемами и позволяет минимизиравать эти проблеммы, но при этом не лишает пользователя
возможности использования подсистем.
*/

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// musician представляет абстрактного музыканта
class Musician {
    string name;

protected:
    explicit Musician(string _name) {
        name = _name;
    }

    // output реализует вывод текста от имени музыканта
    void output(const string &text) {
        cout << name << " " << text << "." << endl;
    }
};

// Конкретные музыканты:

class Vocalist : public Musician {
public:
    explicit Vocalist(string name) : Musician(name) {}

    void SingCouplet(int coupletNumber) {
        string text = "спел куплет №";
        ostringstream oss;
        oss << coupletNumber;
        text += oss.str();
        output(text);
    }

    void SingChorus() {
        Musician::output("спел припев");
    }
};

class Guitarist : public Musician {
public:
    explicit Guitarist(string name) : Musician(name) {}

    void PlayCoolOpening() {
        output("начинает с крутого вступления");
    }

    void PlayCoolRiffs() {
        output("играет крутые риффы");
    }

    void PlayAnotherCoolRiffs() {
        output("играет другие крутые риффы");
    }

    void PlayIncrediblyCoolSolo() {
        output("выдает невероятно крутое соло");
    }

    void PlayFinalAccord() {
        output("заканчивает песню мощным аккордом");
    }
};

class Bassist : public Musician {
public:
    explicit Bassist(string name) : Musician(name) {}

    void FollowTheDrums() {
        output("следует за барабанами");
    }

    void ChangeRhythm(const string& typeRhythm) {
        output("перешел на ритм " + typeRhythm + "a");
    }

    void StopPlaying() {
        output("заканчивает играть");
    }
};

class Drummer : public Musician {
public:
    explicit Drummer(string name) : Musician(name) {}

    void StartPlaying() {
        output("начинает играть");
    }

    void StopPlaying() {
        output("заканчивает играть");
    }

};

// Фасад - знаменитая рок группа
class BlackSabbath {
    Vocalist  vocalist;
    Guitarist guitarist;
    Bassist   bassist;
    Drummer   drummer;
public:
    BlackSabbath() : vocalist("Оззи Осборн"), guitarist("Тони Айомми"),
        bassist("Гизер Батлер"), drummer("Билл Уорд") {}

    void PlayCoolSong() {
        guitarist.PlayCoolOpening();
        drummer.StartPlaying();
        bassist.FollowTheDrums();
        guitarist.PlayCoolRiffs();
        vocalist.SingCouplet(1);
        bassist.ChangeRhythm("припев");
        guitarist.PlayAnotherCoolRiffs();
        vocalist.SingChorus();
        bassist.ChangeRhythm("куплет");
        guitarist.PlayCoolRiffs();
        vocalist.SingCouplet(2);
        bassist.ChangeRhythm("припев");
        guitarist.PlayAnotherCoolRiffs();
        vocalist.SingChorus();
        bassist.ChangeRhythm("куплет");
        guitarist.PlayIncrediblyCoolSolo();
        guitarist.PlayCoolRiffs();
        vocalist.SingCouplet(3);
        bassist.ChangeRhythm("припев");
        guitarist.PlayAnotherCoolRiffs();
        vocalist.SingChorus();
        bassist.ChangeRhythm("куплет");
        guitarist.PlayCoolRiffs();
        bassist.StopPlaying();
        drummer.StopPlaying();
        guitarist.PlayFinalAccord();
    }
};

int main() {
    BlackSabbath group;
    group.PlayCoolSong();
}

